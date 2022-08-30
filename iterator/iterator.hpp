
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Iterator {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~Iterator() specifiers
  virtual ~Iterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  Iterator<Data>& operator = (const Iterator<Data>&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  Iterator<Data>& operator = (Iterator<Data>&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const Iterator<Data>&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const Iterator<Data>&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type operator*() specifiers; // (concrete function must throw std::out_of_range when terminated)
  virtual Data& operator*() const = 0;  

  // type Terminated() specifiers; // (concrete function should not throw exceptions)
  virtual bool Terminated() const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class ForwardIterator : public virtual Iterator<Data>{ // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ForwardIterator() specifiers
  virtual ~ForwardIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  ForwardIterator<Data>& operator = (const ForwardIterator<Data>&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  ForwardIterator<Data>& operator = (ForwardIterator<Data>&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const ForwardIterator<Data>&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const ForwardIterator<Data>&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type operator++() specifiers; // (concrete function must throw std::out_of_range when terminated)
  virtual ForwardIterator<Data>& operator++() = 0;

};

/* ************************************************************************** */

template <typename Data>
class BackwardIterator { // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BackwardIterator() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type operator--() specifiers; // (concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BidirectionalIterator {
                              // Must extend ForwardIterator<Data>,
                              //             BackwardIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BidirectionalIterator() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Terminated() specifiers; // Override Iterator member

  // type ForwardTerminated() specifiers; // (concrete function should not throw exceptions)

  // type BackwardTerminated() specifiers; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class ResettableIterator : virtual public Iterator<Data>{ // Must extend Iterator<Data>
//è necessario memorizzare la radice per poter ritornare allo stato iniziale (current uguale a radice e stack vuoto)

private:

protected:

public:

  // Destructor
  // ~ResettableIterator() specifiers
  virtual ~ResettableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  ResettableIterator<Data>& operator = (const ResettableIterator<Data>&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  ResettableIterator<Data>& operator = (ResettableIterator<Data>&&) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const ResettableIterator<Data>&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const ResettableIterator<Data>&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Reset() specifiers; // (concrete function should not throw exceptions)
  virtual void Reset() noexcept = 0;

};

/* ************************************************************************** */

}

#endif
