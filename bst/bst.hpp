
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */
 
template <typename Data>
class BST : virtual public BinaryTreeLnk<Data>,
            virtual public DictionaryContainer<Data> { // Must extend BinaryTreeLnk<Data>

private:

  // ...

protected:

  // using BinaryTreeLnk<Data>::???;
  using BinaryTreeLnk<Data>::size;
  using BinaryTreeLnk<Data>::root;
  // ...

public:

  // Default constructor
  // BST() specifiers;
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BST(argument) specifiers; // A bst obtained from a LinearContainer
  BST(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BST(argument) specifiers;
  BST(const BST<Data>& otherBst) : BinaryTreeLnk<Data>(otherBst){};

  // Move constructor
  // BST(argument) specifiers;
  BST(BST<Data>&& otherBst) noexcept : BinaryTreeLnk<Data>(std::move(otherBst)){};

  /* ************************************************************************ */

  // Destructor
  // ~BST() specifiers;
  virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BST<Data>& operator = (const BST<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BST<Data>& operator = (BST<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators 
  //tramite iteratore inorder
  // type operator==(argument) specifiers;
  bool operator == (const BST<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const BST<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
  const Data& Min() const;
  Data& Min();
  // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  Data MinNRemove();
  // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)
  void RemoveMin();

  // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
  const Data& Max() const;
  Data& Max();
  // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove();
  // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)
  void RemoveMax();

  // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  const Data& Predecessor(const Data&) const;
  Data& Predecessor(const Data&);
  // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data&);
  // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data&);

  // type Successor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  const Data& Successor(const Data&) const;
  Data& Successor(const Data&);
  // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data&);
  // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data&);

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  bool Insert(const Data&) override;
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  bool Insert(Data&&) override;
  // type Remove(argument) specifiers; // Override DictionaryContainer member
  bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  bool Exists(const Data&) const noexcept override;

protected:

  // Auxiliary member functions

  // type DataNDelete(argument) specifiers;
  Data DataNDelete(struct BST<Data>::NodeLnk*);

  // type Detach(argument) specifiers;
  struct BST<Data>::NodeLnk* Detach(struct BST<Data>::NodeLnk*&) noexcept;

  // type DetachMin(argument) specifiers;
  struct BST<Data>::NodeLnk* DetachMin(struct BST<Data>::NodeLnk*&) noexcept;
  // type DetachMax(argument) specifiers;
  struct BST<Data>::NodeLnk* DetachMax(struct BST<Data>::NodeLnk*&) noexcept;

  // type Skip2Left(argument) specifiers;
  struct BST<Data>::NodeLnk* Skip2Left(struct BST<Data>::NodeLnk*&) noexcept;
  // type Skip2Right(argument) specifiers;
  struct BST<Data>::NodeLnk* Skip2Right(struct BST<Data>::NodeLnk*&) noexcept;

  // type FindPointerToMin(argument) specifiers; // Both mutable & unmutable versions
  struct BST<Data>::NodeLnk* const& FindPointerToMin(struct BST<Data>::NodeLnk* const&) const noexcept;
  struct BST<Data>::NodeLnk*& FindPointerToMin(struct BST<Data>::NodeLnk*&) noexcept;
  // type FindPointerToMax(argument) specifiers; // Both mutable & unmutable versions
  struct BST<Data>::NodeLnk* const& FindPointerToMax(struct BST<Data>::NodeLnk* const&) const noexcept;
  struct BST<Data>::NodeLnk*& FindPointerToMax(struct BST<Data>::NodeLnk*&) noexcept;

  // type FindPointerTo(argument) specifiers; // Both mutable & unmutable versions
  struct BST<Data>::NodeLnk* const& FindPointerTo(struct BST<Data>::NodeLnk* const&, const Data&) const  noexcept;
  struct BST<Data>::NodeLnk*& FindPointerTo(struct BST<Data>::NodeLnk*&, const Data&) noexcept;
  
  // type FindPointerToPredecessor(argument) specifiers; // Both mutable & unmutable versions
  struct BST<Data>::NodeLnk* const* FindPointerToPredecessor(struct BST<Data>::NodeLnk* const&, const Data&) const  noexcept;
  struct BST<Data>::NodeLnk** FindPointerToPredecessor(struct BST<Data>::NodeLnk*&, const Data&) noexcept;
  // type FindPointerToSuccessor(argument) specifiers; // Both mutable & unmutable versions
  struct BST<Data>::NodeLnk* const* FindPointerToSuccessor(struct BST<Data>::NodeLnk* const&, const Data&) const  noexcept;
  struct BST<Data>::NodeLnk** FindPointerToSuccessor(struct BST<Data>::NodeLnk*&, const Data&) noexcept;

  /* ************************************************************************ */


};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
