
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"
#include "../../bst/bst.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr : virtual public HashTable<Data> { // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::size;
  using HashTable<Data>::tableSize;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::A;
  using HashTable<Data>::B;
  using HashTable<Data>::primeNumber;
  using HashTable<Data>::hash;

  Vector<BST<Data>> vector;

  // ...

public:

  // Default constructor
  // HashTableClsAdr() specifiers;
  HashTableClsAdr();

  /* ************************************************************************ */

  // Specific constructors
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size
  HashTableClsAdr(const unsigned int&);
  // HashTableClsAdr(argument) specifiers; // A hash table obtained from a LinearContainer
  HashTableClsAdr(const LinearContainer<Data>&);
  // HashTableClsAdr(argument) specifiers; // A hash table of a given size obtained from a LinearContainer
  HashTableClsAdr(const unsigned int&, const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(const HashTableClsAdr<Data>&);

  // Move constructor
  // HashTableClsAdr(argument) specifiers;
  HashTableClsAdr(HashTableClsAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableClsAdr() specifiers;
  ~HashTableClsAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr<Data>& operator = (const HashTableClsAdr<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  HashTableClsAdr<Data>& operator = (HashTableClsAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const HashTableClsAdr<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const HashTableClsAdr<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from HashTable)

  // type Resize(argument) specifiers; // Resize the hashtable to a given size
  void Resize(const unsigned int&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifiers; // Override DictionaryContainer member (Copy of the value)
  bool Insert(const Data&) override;
  // type Insert(argument) specifiers; // Override DictionaryContainer member (Move of the value)
  bool Insert(Data&&) override;
  // type Remove(argument) specifiers; // Override DictionaryContainer member
  bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  bool Exists(const Data&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  using typename MappableContainer<Data>::MapFunctor;
  void Map(MapFunctor, void*) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // type Fold(argument) specifiers; // Override FoldableContainer member
  using typename FoldableContainer<Data>::FoldFunctor;
  void Fold(FoldFunctor, const void*, void*) const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member
  void Clear();

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
