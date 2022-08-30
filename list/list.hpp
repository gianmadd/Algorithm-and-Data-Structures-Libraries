
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public LinearContainer<Data>,
             virtual public PreOrderMappableContainer<Data>,
             virtual public PostOrderMappableContainer<Data>,
             virtual public PreOrderFoldableContainer<Data>,
             virtual public PostOrderFoldableContainer<Data> { 
              // Must extend LinearContainer<Data>,
              //             PreOrderMappableContainer<Data>,
              //             PostOrderMappableContainer<Data>,
              //             PreOrderFoldableContainer<Data>,
              //             PostOrderFoldableContainer<Data>

private:

  // ...

protected:

  // using LinearContainer<Data>::???;
  using LinearContainer<Data>::size;


  struct Node {

    // Data
    // ...
    Data key;
    Node* next = nullptr;

    /* ********************************************************************** */

    // Specific constructors
    // ...
    Node() = default;
    Node(const Data&);
    Node(Data&&) noexcept;


    /* ********************************************************************** */

    // Copy constructor
    // ...
    Node(const Node&);

    // Move constructor
    // ...
    Node(Node&&) noexcept;

    /* ********************************************************************** */

    // Destructor
    // ...
    ~Node();

    /* ********************************************************************** */

    // Comparison operators
    // ...
    bool operator == (const Node&) const noexcept;
    bool operator != (const Node&) const noexcept;

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  // ...
  Node* head = nullptr;
  Node* tail = nullptr;

public:

  // Default constructor
  // List() specifiers;
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a LinearContainer
  List(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;
  List(const List<Data>&);

  // Move constructor
  // List(argument) specifiers;
  List(List<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;
  virtual ~List();

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  List<Data>& operator = (const List<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  List<Data>& operator = (List<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const List<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const List<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type InsertAtFront(argument) specifier; // Copy of the value
  void InsertAtFront(const Data&);
  // type InsertAtFront(argument) specifier; // Move of the value
  void InsertAtFront(Data&&);
  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  void RemoveFromFront();
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)
  Data FrontNRemove(); //Data e non Data& perchè il valore viene rimosso quindi serve una copia

  // type InsertAtBack(argument) specifier; // Copy of the value
  void InsertAtBack(const Data&);
  // type InsertAtBack(argument) specifier; // Move of the value
  void InsertAtBack(Data&&);

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
  void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type Front() specifiers; // Override LinearContainer member (must throw std::length_error when empty)
  Data& Front() const override;
  // type Back() specifiers; // Override LinearContainer member (must throw std::length_error when empty)
  Data& Back() const override;
  // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)
  Data& operator [] (unsigned int) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFunctor;
  using typename MappableContainer<Data>::MapFunctor;

  // type Map(arguments) specifiers; // Override MappableContainer member
  virtual void Map(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderMappableContainer)

  // type MapPreOrder(arguments) specifiers; // Override PreOrderMappableContainer member
  virtual void MapPreOrder(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderMappableContainer)

  // type MapPostOrder(arguments) specifiers; // Override PostOrderMappableContainer member
  virtual void MapPostOrder(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderFoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Override FoldableContainer member
  virtual void FoldPreOrder(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderFoldableContainer)

  // type FoldPostOrder(arguments) specifiers; // Override FoldableContainer member
  virtual void FoldPostOrder(FoldFunctor, const void*, void*) const override;

protected:

  // Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer)

  // type MapPreOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  virtual void MapPreOrder(MapFunctor, void*, Node*);
  // type MapPostOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  virtual void MapPostOrder(MapFunctor, void*, Node*);
  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  virtual void FoldPreOrder(FoldFunctor, const void*, void*, Node*) const;
  // type FoldPostOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  virtual void FoldPostOrder(FoldFunctor, const void*, void*, Node*) const;
  
};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
