
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public BinaryTree<Data> {
                      // Must extend BinaryTree<Data>

private:

  // ...

protected:

  // using BinaryTree<Data>::???;
  using BinaryTree<Data>::size;

  // ...

  struct NodeLnk : virtual public BinaryTree<Data>::Node{ // Must extend Node

  public:
    friend class BinaryTreeLnk<Data>;

  private:

    // ...

  public:

    // ...
    NodeLnk* left = nullptr;
    NodeLnk* right = nullptr;
    using BinaryTree<Data>::Node::key;

  public:

    // ...
    virtual ~NodeLnk();

    NodeLnk(const Data&, NodeLnk*, NodeLnk*);

    NodeLnk(const Data&);
    NodeLnk(Data&&) noexcept;

    NodeLnk(const NodeLnk&);
    NodeLnk(NodeLnk&&) noexcept;

    NodeLnk& operator = (const NodeLnk&) = delete;
    NodeLnk& operator = (NodeLnk&&) noexcept = delete;

    virtual bool IsLeaf() const noexcept;
    virtual bool HasLeftChild() const noexcept;
    virtual bool HasRightChild() const noexcept;

    NodeLnk& LeftChild() override;
    NodeLnk& RightChild() override;

    NodeLnk& LeftChild() const override;
    NodeLnk& RightChild() const override;

  };

protected:

  NodeLnk* root = nullptr;


public:

  // Default constructor
  // BinaryTreeLnk() specifiers;
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeLnk(argument) specifiers; // A binary tree obtained from a LinearContainer
  BinaryTreeLnk(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(const BinaryTreeLnk<Data>&);

  // Move constructor
  // BinaryTreeLnk(argument) specifiers;
  BinaryTreeLnk(BinaryTreeLnk<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeLnk() specifiers;
  virtual ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk<Data>& operator = (const BinaryTreeLnk<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BinaryTreeLnk<Data>& operator = (BinaryTreeLnk<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators 
  // dovrebbero essere già implementate a livello più generale in BinaryTree
  // type operator==(argument) specifiers;
  bool operator == (const BinaryTreeLnk<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const BinaryTreeLnk<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)
  NodeLnk& Root() const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
  void Clear() override;


  // Auxiliary function
  struct BinaryTreeLnk<Data>::NodeLnk* TreeFromLinearContainer(const LinearContainer<Data>& , int);

};


/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
