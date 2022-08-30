
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

#include <stdexcept>
#include <functional>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  // ...
  unsigned int size = 0;

public:

  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  Container& operator = (const Container&) = delete;

  // Move assignment
  Container& operator = (Container&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const Container&) const noexcept = delete;
  bool operator != (const Container&) const noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions

  virtual bool Empty() const noexcept{
    if (size == 0)
        return true;
    else
        return false;
  }
  virtual unsigned int Size() const noexcept{
    return size;
  }
  virtual void Clear() = 0;

};

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public Container{ // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer& operator = (const LinearContainer&) = delete;

  // Move assignment
  LinearContainer& operator = (LinearContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const LinearContainer&) const noexcept;
  bool operator != (const LinearContainer&) const noexcept;
  /* ************************************************************************ */

  // Specific member functions

  virtual Data& Front() const;
  virtual Data& Back() const;

  // Random Access Operator
  virtual Data& operator [] (const unsigned int) const = 0;

};

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container{ // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~TestableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  TestableContainer& operator = (const TestableContainer&) = delete;

  // Move assignment
  TestableContainer& operator = (TestableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const TestableContainer&) const noexcept = delete;  
  bool operator != (const TestableContainer&) const noexcept = delete;
  /* ************************************************************************ */

  // Specific member functions

  virtual bool Exists(const Data&) const noexcept = 0;
};

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data>{ // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~DictionaryContainer() specifiers
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  DictionaryContainer<Data>& operator = (const DictionaryContainer<Data>&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  DictionaryContainer<Data>& operator = (DictionaryContainer<Data>&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const DictionaryContainer<Data>&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const DictionaryContainer<Data>&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Insert(argument) specifiers; // Copy of the value
  virtual bool Insert(const Data&) = 0;
  // type Insert(argument) specifiers; // Move of the value
  virtual bool Insert(Data&&) = 0;
  // type Remove(argument) specifiers;
  virtual bool Remove(const Data&) = 0;

  // type Insert(argument) specifiers; // Copy of the value; From LinearContainer
  virtual void Insert(const LinearContainer<Data>&);
  // type Insert(argument) specifiers; // Move of the value; From LinearContainer
  virtual void Insert(LinearContainer<Data>&&) noexcept;
  // type Remove(argument) specifiers; // From LinearContainer
  virtual void Remove(const LinearContainer<Data>&);


};

/* ************************************************************************** */

template <typename Data>
class MappableContainer : virtual public Container{ // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer& operator = (const MappableContainer&) = delete;

  // Move assignment
  MappableContainer& operator = (MappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const MappableContainer&) const noexcept = delete;
  bool operator != (const MappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  typedef std::function<void(Data&, void*)> MapFunctor;

  // Map
  virtual void Map(MapFunctor, void*) = 0;

};

/* ************************************************************************** */

template <typename Data>
class FoldableContainer : virtual public TestableContainer<Data>{ // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~FoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  FoldableContainer& operator = (const FoldableContainer&) = delete;

  // Move assignment
  FoldableContainer& operator = (FoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const FoldableContainer&) const noexcept = delete;
  bool operator != (const FoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  typedef std::function<void(const Data&, const void*, void*)> FoldFunctor;

  // Fold
  virtual void Fold(FoldFunctor, const void*, void*) const = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  // Exists
  virtual bool Exists(const Data&) const noexcept override ;
};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : virtual public MappableContainer<Data>{ // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderMappableContainer& operator = (const PreOrderMappableContainer&) = delete;

  // Move assignment
  PreOrderMappableContainer& operator = (PreOrderMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const PreOrderMappableContainer&) const noexcept = delete;
  bool operator != (const PreOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  using typename MappableContainer<Data>::MapFunctor;

  // MapPreOrder
  virtual void MapPreOrder(MapFunctor, void*) = 0;
  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // Map
  virtual void Map(MapFunctor, void*) override;
};

/* ************************************************************************** */

template <typename Data>
class PreOrderFoldableContainer : virtual public FoldableContainer<Data>{ // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PreOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderFoldableContainer& operator = (const PreOrderFoldableContainer&) = delete;

  // Move assignment
  PreOrderFoldableContainer& operator = (PreOrderFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const PreOrderFoldableContainer&) const noexcept = delete;
  bool operator != (const PreOrderFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  using typename FoldableContainer<Data>::FoldFunctor;

  // FoldPreOrder
  virtual void FoldPreOrder(FoldFunctor, const void*, void*) const = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // Fold
  virtual void Fold(FoldFunctor, const void*, void*) const override;

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual public MappableContainer<Data>{ // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderMappableContainer& operator = (const PostOrderMappableContainer&) = delete;

  // Move assignment
  PostOrderMappableContainer& operator = (PostOrderMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const PostOrderMappableContainer&) const noexcept = delete;
  bool operator != (const PostOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  using typename MappableContainer<Data>::MapFunctor;

  // MapPostOrder
  virtual void MapPostOrder(MapFunctor, void*) = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // Map
  virtual void Map(MapFunctor, void*) override;


};

/* ************************************************************************** */

template <typename Data>
class PostOrderFoldableContainer : virtual public FoldableContainer<Data>{ // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PostOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderFoldableContainer& operator = (const PostOrderFoldableContainer&) = delete;
  
  // Move assignment
  PostOrderFoldableContainer& operator = (PostOrderFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const PostOrderFoldableContainer&) const noexcept = delete;
  bool operator != (const PostOrderFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  using typename FoldableContainer<Data>::FoldFunctor;

  // FoldPostOrder
  virtual void FoldPostOrder(FoldFunctor, const void*, void*) const = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // Fold
  virtual void Fold(FoldFunctor, const void*, void*) const override;
};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer : virtual public MappableContainer<Data>{ // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderMappableContainer() specifiers
  virtual ~InOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  InOrderMappableContainer& operator = (const InOrderMappableContainer&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  InOrderMappableContainer& operator = (InOrderMappableContainer&&) noexcept = delete;


  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const InOrderMappableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const InOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // using typename MappableContainer<Data>::MapFunctor;
  using typename MappableContainer<Data>::MapFunctor;

  // type MapInOrder(arguments) specifiers;
  virtual void MapInOrder(MapFunctor, void*) = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFunctor, void*) override;

};

/* ************************************************************************** */

template <typename Data>
class InOrderFoldableContainer : virtual public FoldableContainer<Data>{ // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderFoldableContainer() specifiers
  virtual ~InOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  InOrderFoldableContainer& operator = (const InOrderFoldableContainer&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  InOrderFoldableContainer& operator = (InOrderFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const InOrderFoldableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const InOrderFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldInOrder(arguments) specifiers;
  virtual void FoldInOrder(FoldFunctor, const void*, void*) const = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // type Fold(argument) specifiers; // Override FoldableContainer member
  virtual void Fold(FoldFunctor, const void*, void*) const override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer : virtual public MappableContainer<Data>{ // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthMappableContainer() specifiers
  virtual ~BreadthMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  BreadthMappableContainer& operator = (const BreadthMappableContainer&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  BreadthMappableContainer& operator = (BreadthMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const BreadthMappableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const BreadthMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // using typename MappableContainer<Data>::MapFunctor;
  using typename MappableContainer<Data>::MapFunctor;

  // type MapBreadth(arguments) specifiers;
  virtual void MapBreadth(MapFunctor, void*) = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member
  virtual void Map(MapFunctor, void*) override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer : virtual public FoldableContainer<Data>{ // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthFoldableContainer() specifiers
  virtual ~BreadthFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  BreadthFoldableContainer& operator = (const BreadthFoldableContainer&) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  BreadthFoldableContainer& operator = (BreadthFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator == (const BreadthFoldableContainer&) const noexcept = delete;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator != (const BreadthFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // using typename FoldableContainer<Data>::FoldFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldBreadth(arguments) specifiers;
  virtual void FoldBreadth(FoldFunctor, const void*, void*) const = 0;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // type Fold(argument) specifiers; // Override FoldableContainer member
  virtual void Fold(FoldFunctor, const void*, void*) const override;

};

/* ************************************************************************** */

}

#include "container.cpp"

#endif
