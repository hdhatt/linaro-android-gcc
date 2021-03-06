// Test the support for users to specify in the annotations a lock that is a
// class/struct member of a function parameter.
// { dg-do compile }
// { dg-options "-Wthread-safety -O" }

#include "thread_annot_common.h"

class Foo {
 public:
  Mutex *mu1_;
  int data_ GUARDED_BY(mu1_);
};

class Bar {
 public:
  Foo *foo_;
  void MyLock(Foo *f) EXCLUSIVE_LOCK_FUNCTION(f->mu1_);
  void MyUnlock(Foo *f) UNLOCK_FUNCTION(f->mu1_);
  void func2(Foo *f) SHARED_LOCKS_REQUIRED(f->mu1_);
  void func3();
};

class SCOPED_LOCKABLE MyMutexLock {
 public:
  MyMutexLock(Foo *f) EXCLUSIVE_LOCK_FUNCTION(f->mu1_)
      : mu_(f->mu1_) {
    this->mu_->Lock();
  }

  ~MyMutexLock() UNLOCK_FUNCTION(){ this->mu_->Unlock(); }

 private:
  Mutex *const mu_;
};

Mutex *mu2;

void func1(Bar *bar, Mutex *mu) EXCLUSIVE_LOCKS_REQUIRED(bar->foo_->mu1_, mu) {
  bar->foo_->data_ = 5;
}

void Bar::func3() {
  func2(foo_);    // { dg-warning "Calling function 'func2' requires lock" }
}

main() {
  Bar *b;

  MutexLock l(mu2);
  func1(b, mu2);  // { dg-warning "Calling function 'func1' requires lock" }
  b->func3();
  func1(b, mu2);  // { dg-warning "Calling function 'func1' requires lock" }
}
