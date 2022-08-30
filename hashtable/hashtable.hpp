
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hash {

public:

  // type operator()(argument) specifiers; // (concrete function should not throw exceptions)
  unsigned long operator()(const Data&) const noexcept;

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public DictionaryContainer<Data>,
                  virtual public MappableContainer<Data>,
                  virtual public FoldableContainer<Data> { 
                  // Must extend DictionaryContainer<Data>,
                  //             MappableContainer<Data>,
                  //             FoldableContainer<Data>

private:

  // ...

protected:

  // using DictionaryContainer<Data>::???;
  using DictionaryContainer<Data>::size;

  // ...
  //size = 

  unsigned long A;
  unsigned long B;
  unsigned int tableSize = 64;
  unsigned long primeNumber = 65537;
  Hash<Data> hash;
  
  //oggetto di tipo Hash<Data>
  //attributo numero primo usato per indicizzazione
  //la tabella e il numero di elementi hanno size diverse potenzialmente
  

public:

  HashTable();

  // Destructor
  // ~HashTable() specifiers
  virtual ~HashTable() = default; 

  /* ************************************************************************ */

protected:
  //Copy constructor
  HashTable(const HashTable<Data>&);

  //Move constructor
  HashTable(HashTable<Data>&&) noexcept;

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  HashTable<Data>& operator = (const HashTable<Data>&);

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  HashTable<Data>& operator = (HashTable<Data>&&) noexcept;

  /* ************************************************************************ */

public:
  // Comparison operators
  //non implementare qui perchè non è richiesto il confronto tra hashtable implementate in modo diverso 
  // type operator==(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator == (const HashTable<Data>&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.
  bool operator != (const HashTable<Data>&) const noexcept = delete;

  /* ************************************************************************ */
  
  // Specific member function

  // type Resize(argument) specifiers; // Resize the hashtable to a given size
  virtual void Resize(const unsigned int&) = 0;

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  //prende il dato, chiama () di hash, inserisce l'encoding nella funzione universale e restituisce l'hashing di indirizzamento
  unsigned long HashKey(const Data&) const noexcept;

  //si potrebbero implementare in modo protetto parte di copy e move assignment/constructors (per gli attributi già definiti e 
  //comuni ad entrambi le implementazioni di HashTable)

  unsigned long Random(const int&);

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
