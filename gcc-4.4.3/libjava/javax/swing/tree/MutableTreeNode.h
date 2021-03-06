
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_tree_MutableTreeNode__
#define __javax_swing_tree_MutableTreeNode__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace javax
  {
    namespace swing
    {
      namespace tree
      {
          class MutableTreeNode;
          class TreeNode;
      }
    }
  }
}

class javax::swing::tree::MutableTreeNode : public ::java::lang::Object
{

public:
  virtual void insert(::javax::swing::tree::MutableTreeNode *, jint) = 0;
  virtual void remove(jint) = 0;
  virtual void remove(::javax::swing::tree::MutableTreeNode *) = 0;
  virtual void setUserObject(::java::lang::Object *) = 0;
  virtual void removeFromParent() = 0;
  virtual void setParent(::javax::swing::tree::MutableTreeNode *) = 0;
  virtual ::javax::swing::tree::TreeNode * getParent() = 0;
  virtual jint getIndex(::javax::swing::tree::TreeNode *) = 0;
  virtual ::javax::swing::tree::TreeNode * getChildAt(jint) = 0;
  virtual jint getChildCount() = 0;
  virtual jboolean getAllowsChildren() = 0;
  virtual jboolean isLeaf() = 0;
  virtual ::java::util::Enumeration * children() = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __javax_swing_tree_MutableTreeNode__
