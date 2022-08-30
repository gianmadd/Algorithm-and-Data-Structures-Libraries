
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Queue : virtual public Container {
              // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~Queue() specifiers
  virtual ~Queue() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  Queue<Data>& operator = (const Queue<Data>&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  Queue<Data>& operator = (Queue<Data>&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const Queue<Data>&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const Queue<Data>&) const noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions

  // type Head() specifiers; // (constant version; concrete function must throw std::length_error when empty)
  virtual const Data& Head() const = 0; 
  // type Head() specifiers; // (concrete function must throw std::length_error when empty)
  virtual Data& Head() = 0;
  // type Dequeue() specifiers; // (concrete function must throw std::length_error when empty)
  virtual void Dequeue() = 0;
  // type HeadNDequeue() specifiers; // (concrete function must throw std::length_error when empty)
  virtual Data HeadNDequeue() = 0;
  // type Enqueue(argument) specifiers; // Copy of the value
  virtual void Enqueue(const Data&) = 0;
  // type Enqueue(argument) specifiers; // Move of the value
  virtual void Enqueue(Data&&) = 0;

};

/* ************************************************************************** */

}

#endif
