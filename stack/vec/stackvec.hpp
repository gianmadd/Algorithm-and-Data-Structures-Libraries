
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>,
                 virtual protected Vector<Data> {
                  // Must extend Stack<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
  unsigned int head = 0;
  using Vector<Data>::size;
  using Vector<Data>::components;

  // ...

public:

  // Default constructor
  // StackVec() specifier;
  StackVec();

  /* ************************************************************************ */

  // Specific constructor
  // StackVec(argument) specifiers; // A stack obtained from a LinearContainer
  StackVec(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // StackVec(argument);
  StackVec(const StackVec<Data>&);

  // Move constructor
  // StackVec(argument);
  StackVec(StackVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~StackVec() specifier;
  virtual ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  StackVec<Data>& operator = (const StackVec<Data>&);

  // Move assignment
  // type operator=(argument);
  StackVec<Data>& operator = (StackVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const StackVec<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const StackVec<Data>&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  // type Top() specifiers; // Override Stack member (constant version; must throw std::length_error when empty)
  const Data& Top() const override;
  // type Top() specifiers; // Override Stack member (must throw std::length_error when empty)
  Data& Top() override;
  // type Pop() specifiers; // Override Stack member (must throw std::length_error when empty)
  void Pop() override;
  // type TopNPop() specifiers; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override;
  // type Push(argument) specifiers; // Override Stack member (copy of the value)
  void Push(const Data&) override;
  // type Push(argument) specifiers; // Override Stack member (move of the value)
  void Push(Data&&) override;
  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member
  bool Empty() const noexcept override;
  // type Size() specifiers; // Override Container member
  unsigned int Size() const noexcept override;
  // type Clear() specifiers; // Override Container member
  void Clear() override;

protected:

  // Auxiliary member functions

  // type Expand() specifiers;
  void Expand();
  // type Reduce() specifiers;
  void Reduce();


};

/* ************************************************************************** */



}

#include "stackvec.cpp"

#endif
