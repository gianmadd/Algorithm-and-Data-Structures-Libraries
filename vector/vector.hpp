
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public LinearContainer<Data>,
               virtual public PreOrderMappableContainer<Data>,
               virtual public PostOrderMappableContainer<Data>,
               virtual public PreOrderFoldableContainer<Data>,
               virtual public PostOrderFoldableContainer<Data> {

private:

  // ...

protected:

  // ...
  using LinearContainer<Data>::size;
  Data* components = nullptr;

public:

  // Default constructor
  Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
  Vector(const unsigned int);
  Vector(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector<Data>&);

  // Move constructor
  Vector(Vector<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  Vector<Data>& operator = (const Vector<Data>&) ;
  
  // Move assignment
  Vector<Data>& operator = (Vector<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const Vector<Data>&) const noexcept;
  bool operator != (const Vector<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions
  virtual void Resize(const unsigned int);

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
  virtual void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)
  virtual Data& Front() const override;
  virtual Data& Back() const override;

  // Random Access Operator
  Data& operator [] (unsigned int) const override;
  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  // Map
  void Map(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderMappableContainer)

  // MapPreOrder
  void MapPreOrder(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderMappableContainer)

  // MapPostOrder
  void MapPostOrder(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  // Fold
  void Fold(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from PreOrderFoldableContainer)

  // FoldPreOrder
  void FoldPreOrder(FoldFunctor, const void*, void*) const override; 

  /* ************************************************************************ */

  // Specific member functions (inherited from PostOrderFoldableContainer)

  // FoldPostOrder
  void FoldPostOrder(FoldFunctor, const void*, void*) const override;

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
