
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public BinaryTree<Data>{
                      // Must extend BinaryTree<Data>

private:

  // ...

protected:

  // using BinaryTree<Data>::???;
  using BinaryTree<Data>::size;
  

  // ...

  struct NodeVec : virtual public BinaryTree<Data>::Node{ // Must extend Node

  public: 
    friend class BinaryTreeVec<Data>;

  private:

    // ...

  protected:

    // ...
    using BinaryTree<Data>::Node::key;
    int index;
    Vector<NodeVec*>* vectorPointer = nullptr;

  public:

    // ...

    virtual ~NodeVec();

    NodeVec& operator = (const NodeVec&) = delete;
    NodeVec& operator = (NodeVec&&) noexcept = delete;

    virtual bool IsLeaf() const noexcept;
    virtual bool HasLeftChild() const noexcept;
    virtual bool HasRightChild() const noexcept;

    NodeVec& LeftChild() override;
    NodeVec& RightChild() override;

    NodeVec& LeftChild() const override;
    NodeVec& RightChild() const override;

  };

  Vector<NodeVec*>* vector = nullptr;

public:

  // Default constructor
  // BinaryTreeVec() specifiers;
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a LinearContainer
  BinaryTreeVec(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(const BinaryTreeVec<Data>&);

  // Move constructor
  // BinaryTreeVec(argument) specifiers;
  BinaryTreeVec(BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;
  ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec<Data>& operator = (const BinaryTreeVec<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeVec<Data>& operator = (BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BinaryTreeVec<Data>&) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator != (const BinaryTreeVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  NodeVec& Root() const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
  void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)
  using typename MappableContainer<Data>::MapFunctor;

  // type MapBreadth(arguments) specifiers; // Override BreadthMappableContainer member
  void MapBreadth(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)
  using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldBreadth(arguments) specifiers; // Override BreadthFoldableContainer member
  void FoldBreadth(FoldFunctor, const void*, void*) const override;

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
