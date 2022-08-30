
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : public virtual Stack<Data>,
                 protected virtual List<Data> {
                  // Must extend Stack<Data>,
                  //             List<Data>

private:

  // ...

protected:

  // using List<Data>::???;
  using List<Data>::size;
  using List<Data>::head;

  // ...

public:

  // Default constructor
  // StackLst() specifier;
  StackLst() = default; 

  /* ************************************************************************ */

  // Specific constructor
  // StackLst(argument) specifiers; // A stack obtained from a LinearContainer
  StackLst(const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // StackLst(argument);
  StackLst(const StackLst<Data>&);

  // Move constructor
  // StackLst(argument);
  StackLst(StackLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~StackLst() specifier;
  virtual ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);
  StackLst<Data>& operator = (const StackLst<Data>&);

  // Move assignment
  // type operator=(argument);
  StackLst<Data>& operator = (StackLst<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const StackLst<Data>&) const noexcept;

  // type operator!=(argument) specifiers;
  bool operator != (const StackLst<Data>&) const noexcept;

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

  // type Clear() specifiers; // Override Container member
  void Clear() override;


};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
