
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data> { // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::size;
  using HashTable<Data>::tableSize;
  using HashTable<Data>::A;
  using HashTable<Data>::B;
  using HashTable<Data>::primeNumber;
  using HashTable<Data>::hash;

  unsigned int counterDeleted = 0;
  Vector<Data> vector{64};
  Vector<short> flagVector{64}; // 0 -> free , 1 -> not free , 2 -> deleted


  // ...

public:

  // Default constructor
  // HashTableOpnAdr() specifiers;
  HashTableOpnAdr();

  /* ************************************************************************ */

  // Specific constructors
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size
  HashTableOpnAdr(const unsigned int&);
  // HashTableOpnAdr(argument) specifiers; // A hash table obtained from a LinearContainer
  HashTableOpnAdr(const LinearContainer<Data>&);
  // HashTableOpnAdr(argument) specifiers; // A hash table of a given size obtained from a LinearContainer
  HashTableOpnAdr(const unsigned int&, const LinearContainer<Data>&);

  /* ************************************************************************ */

  // Copy constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(const HashTableOpnAdr<Data>&);

  // Move constructor
  // HashTableOpnAdr(argument) specifiers;
  HashTableOpnAdr(HashTableOpnAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  // ~HashTableOpnAdr() specifiers;
  ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr<Data>& operator = (const HashTableOpnAdr<Data>&);

  // Move assignment
  // type operator=(argument) specifiers;
  HashTableOpnAdr<Data>& operator = (HashTableOpnAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const HashTableOpnAdr<Data>&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const HashTableOpnAdr<Data>&) const noexcept;

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

// public:
protected:

  // Auxiliary member functions
  void InitVector(Vector<short>&);
  void InitVector(Vector<int>&);
  void InitVector(Vector<double>&);
  void InitVector(Vector<std::string>&);

  // type Find(argument) specifiers;
  unsigned int Find(const Data&, unsigned int&) const noexcept;
  // type FindEmpty(argument) specifiers;
  unsigned int FindEmpty(const Data&, unsigned int&) const noexcept;
  // type Remove(argument) specifiers;
  bool Remove(const Data&, unsigned int&);

  //funzione HashKey a due parametri
  unsigned long HashKey(const Data&, unsigned int&) const noexcept;

  unsigned int CalculateExponent(const unsigned int&);

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
