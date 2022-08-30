
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data>,
                 virtual protected List<Data> {
                  // Must extend Queue<Data>,
                  //             List<Data>

private:

  // ...

protected:

  // using List<Data>::???;
  using List<Data>::size;
  using List<Data>::head;
  using List<Data>::tail;

  // ...

public:

  // Default constructor
  // QueueLst() specifier;
  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  // QueueLst(argument) specifiers; // A queue obtained from a LinearContainer
  QueueLst(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // QueueLst(argument);
  QueueLst(const QueueLst<Data>&);

  // Move constructor
  // QueueLst(argument);
  QueueLst(QueueLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~QueueLst() specifier;
  virtual ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  QueueLst<Data>& operator = (const QueueLst<Data>&);

  // Move assignment
  // type operator=(argument);
  QueueLst<Data>& operator = (QueueLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const QueueLst<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const QueueLst<Data>&) const noexcept;

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

  // type Clear() specifiers; // Override Container member
  void Clear() override;


};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
