
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>,
                 virtual protected Vector<Data> {
                  // Must extend Queue<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
  using Vector<Data>::size;
  using Vector<Data>::components;
  
  unsigned int head = 0;
  unsigned int tail = 0;

  // ...

public:

  // Default constructor
  // QueueVec() specifier;
  QueueVec();

  /* ************************************************************************ */

  // Specific constructor
  // QueueVec(argument) specifiers; // A queue obtained from a LinearContainer
  QueueVec(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // QueueVec(argument);
  QueueVec(const QueueVec<Data>&);

  // Move constructor
  // QueueVec(argument);
  QueueVec(QueueVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;
  virtual ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  QueueVec<Data>& operator = (const QueueVec<Data>&);

  // Move assignment
  // type operator=(argument);
  QueueVec<Data>& operator = (QueueVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const QueueVec<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const QueueVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (constant version; must throw std::length_error when empty)
  const Data& Head() const override;
  // type Head() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data& Head() override;
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override;
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override;
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  void Enqueue(const Data&) override;
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
  void Enqueue(Data&&) override;

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
  // type SwapVectors(arguments) specifiers;
  void SwapVectors(QueueVec<Data>&); 

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
