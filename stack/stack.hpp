
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack : public virtual Container{
              // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~Stack() specifiers
  virtual ~Stack() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  Stack<Data>& operator = (const Stack<Data>&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  Stack<Data>& operator = (Stack<Data>&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const Stack<Data>&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const Stack<Data>&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Top() specifiers; // (constant version; concrete function must throw std::length_error when empty)
  virtual const Data& Top() const = 0;
  // type Top() specifiers; // (concrete function must throw std::length_error when empty)
  virtual Data& Top() = 0;
  // type Pop() specifiers; // (concrete function must throw std::length_error when empty)
  virtual void Pop() = 0;
  // type TopNPop() specifiers; // (concrete function must throw std::length_error when empty)
  virtual Data TopNPop() = 0;
  // type Push(argument) specifiers; // Copy of the value
  virtual void Push(const Data&)= 0;
  // type Push(argument) specifiers; // Move of the value
  virtual void Push(Data&&) = 0;




};

/* ************************************************************************** */

}

#endif
