
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/lst/stacklst.hpp"

#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public PreOrderMappableContainer<Data>, 
                   virtual public PostOrderMappableContainer<Data>,
                   virtual public InOrderMappableContainer<Data>,
                   virtual public BreadthMappableContainer<Data>,
                   virtual public PreOrderFoldableContainer<Data>,
                   virtual public PostOrderFoldableContainer<Data>,
                   virtual public InOrderFoldableContainer<Data>,
                   virtual public BreadthFoldableContainer<Data> {
                   // Must extend PreOrderMappableContainer<Data>,
                   //             PostOrderMappableContainer<Data>,
                   //             InOrderMappableContainer<Data>,
                   //             BreadthMappableContainer<Data>,
                   //             PreOrderFoldableContainer<Data>,
                   //             PostOrderFoldableContainer<Data>,
                   //             InOrderFoldableContainer<Data>,
                   //             BreadthFoldableContainer<Data>

private:

  // ...

protected:

  // using InOrder/BreadthMappableContainer<Data>::???;
  using InOrderMappableContainer<Data>::size;

  // ...

public:

  struct Node {

  private:

    // ...

  protected:

    // ...
    Data key;

  public:

    // friend class BinaryTree<Data>;
    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~Node() specifiers
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types should not be possible.
    Node& operator = (const Node&) = delete;

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types should not be possible.
    Node& operator = (Node&&) noexcept = delete;

    /* ********************************************************************** */

    // Comparison operators

  protected: 

    // type operator==(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
    bool operator == (const Node&) const noexcept;
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
    bool operator != (const Node&) const noexcept;

    /* ********************************************************************** */

  public:

    // Specific member functions

    // type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions)
    Data& Element() noexcept;
    // type Element() specifiers; // Immutable access to the element (concrete function should not throw exceptions)
    const Data& Element() const noexcept;

    // type IsLeaf() specifiers; // (concrete function should not throw exceptions)
    virtual bool IsLeaf() const noexcept = 0;
    // type HasLeftChild() specifiers; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept = 0;
    // type HasRightChild() specifiers; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept = 0;

    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual Node& LeftChild() = 0;
    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    virtual Node& RightChild() = 0;

    virtual Node& LeftChild() const = 0;
    
    virtual Node& RightChild() const = 0;

  };

  /* ************************************************************************ */

public:

  // Destructor
  // ~BinaryTree() specifiers
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  BinaryTree<Data>& operator = (const BinaryTree<Data>&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  BinaryTree<Data>& operator = (BinaryTree<Data>&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator == (const BinaryTree<Data>&) const noexcept;
  // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator != (const BinaryTree<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)
  virtual Node& Root() const = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFunctor;
  using typename MappableContainer<Data>::MapFunctor;

  // type Map(arguments) specifiers; // Override MappableContainer member
  void Map(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  void Fold(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderMappableContainer)

  // type MapPreOrder(arguments) specifiers; // Override PreOrderMappableContainer member
  void MapPreOrder(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderFoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Override PreOrderFoldableContainer member
  void FoldPreOrder(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderMappableContainer)

  // type MapPostOrder(arguments) specifiers; // Override PostOrderMappableContainer member
  void MapPostOrder(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderFoldableContainer)

  // type FoldPostOrder(arguments) specifiers; // Override PostOrderFoldableContainer member
  void FoldPostOrder(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderMappableContainer)

  // type MapInOrder(arguments) specifiers; // Override InOrderMappableContainer member
  void MapInOrder(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderFoldableContainer)

  // type FoldInOrder(arguments) specifiers; // Override InOrderFoldableContainer member
  void FoldInOrder(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

  // type MapBreadth(arguments) specifiers; // Override BreadthMappableContainer member
  void MapBreadth(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)

  // type FoldBreadth(arguments) specifiers; // Override BreadthFoldableContainer member
  void FoldBreadth(FoldFunctor, const void*, void*) const override;

protected:

  // Auxiliary member functions (for PreOrderMappableContainer)

  // type MapPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  void MapPreOrder(MapFunctor, void*, Node&);

  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderFoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  void FoldPreOrder(FoldFunctor, const void*, void*, Node&) const;

  /* ************************************************************************ */

  // Auxiliary member functions (for PostOrderMappableContainer)

  // type MapPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  void MapPostOrder(MapFunctor, void*, Node&);

  /* ************************************************************************ */

  // Auxiliary member functions (for PostOrderFoldableContainer)

  // type FoldPostOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  void FoldPostOrder(FoldFunctor, const void*, void*, Node&) const;

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderMappableContainer)

  // type MapInOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  void MapInOrder(MapFunctor, void*, Node&);

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderFoldableContainer)

  // type FoldInOrder(arguments) specifiers; // Accessory function executing from one node of the tree
  void FoldInOrder(FoldFunctor, const void*, void*, Node&) const;

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthMappableContainer)

  // type MapBreadth(arguments) specifiers; // Accessory function executing from one node of the tree
  void MapBreadth(MapFunctor, void*, Node&);

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthFoldableContainer)

  // type FoldBreadth(arguments) specifiers; // Accessory function executing from one node of the tree
  void FoldBreadth(FoldFunctor, const void*, void*, Node&) const;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>,
                           virtual public ResettableIterator<Data> {
                           // Must extend ForwardIterator<Data>,
                           //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  struct BinaryTree<Data>::Node* root = nullptr;
  struct BinaryTree<Data>::Node* current = nullptr;
  StackLst<struct BinaryTree<Data>::Node*>* stack = nullptr;

public:

  // Specific constructors
  // BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTPreOrderIterator(const BinaryTree<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(const BTPreOrderIterator<Data>&);

  // Move constructor
  // BTPreOrderIterator(argument) specifiers;
  BTPreOrderIterator(BTPreOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;
  virtual ~BTPreOrderIterator();
  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator<Data>& operator = (const BTPreOrderIterator<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPreOrderIterator<Data>& operator = (BTPreOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BTPreOrderIterator<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const BTPreOrderIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data& operator*() const;

  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept;
  //dovrebbe essere current==nullptr nel caso in cui current sia un puntatore


  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  BTPreOrderIterator<Data>& operator++();

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept;

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : virtual public ForwardIterator<Data>,
                            virtual public ResettableIterator<Data> {
                            // Must extend ForwardIterator<Data>,
                            //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  struct BinaryTree<Data>::Node* root = nullptr;
  struct BinaryTree<Data>::Node* current = nullptr;
  StackLst<struct BinaryTree<Data>::Node*>* stack = nullptr;

public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTPostOrderIterator(const BinaryTree<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(const BTPostOrderIterator<Data>&);

  // Move constructor
  // BTPostOrderIterator(argument) specifiers;
  BTPostOrderIterator(BTPostOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;
  virtual ~BTPostOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator<Data>& operator = (const BTPostOrderIterator<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTPostOrderIterator<Data>& operator = (BTPostOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BTPostOrderIterator<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const BTPostOrderIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data& operator*() const;

  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  BTPostOrderIterator<Data>& operator++();

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept;

  // Auxiliary Function (Leftmost Leaf)
  void LeftmostLeaf(struct BinaryTree<Data>::Node*);

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  struct BinaryTree<Data>::Node* root = nullptr;
  struct BinaryTree<Data>::Node* current = nullptr;
  StackLst<struct BinaryTree<Data>::Node*>* stack = nullptr;

public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree
  BTInOrderIterator(const BinaryTree<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;
  BTInOrderIterator(const BTInOrderIterator<Data>&);

  // Move constructor
  // BTInOrderIterator(argument) specifiers;
  BTInOrderIterator(BTInOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;
  virtual ~BTInOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator<Data>& operator = (const BTInOrderIterator<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTInOrderIterator<Data>& operator = (BTInOrderIterator<Data>&&) noexcept;
  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BTInOrderIterator<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const BTInOrderIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data& operator*() const;

  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  BTInOrderIterator<Data>& operator++();

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept;

  // Auxiliary Function (Leftmost Leaf)
  void LeftmostChild(struct BinaryTree<Data>::Node*);

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...
  struct BinaryTree<Data>::Node* root = nullptr;
  struct BinaryTree<Data>::Node* current = nullptr;
  QueueLst<struct BinaryTree<Data>::Node*>* queue = nullptr;

public:

  // Specific constructors
  // BTBreadthIterator(argument) specifiers; // An iterator over a given binary tree
  BTBreadthIterator(const BinaryTree<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;
  BTBreadthIterator(const BTBreadthIterator<Data>&);

  // Move constructor
  // BTBreadthIterator(argument) specifiers;
  BTBreadthIterator(BTBreadthIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;
  virtual ~BTBreadthIterator();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator<Data>& operator = (const BTBreadthIterator<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  BTBreadthIterator<Data>& operator = (BTBreadthIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const BTBreadthIterator<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const BTBreadthIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)
  Data& operator*() const;

  // type Terminated() specifiers; // (should not throw exceptions)
  bool Terminated() const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)
  BTBreadthIterator<Data>& operator++();

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)
  void Reset() noexcept;

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
