
namespace lasd {

/* ************************************************************************** */

// ...

// Constructors

// Given Size
template <typename Data>
Vector<Data>::Vector(const unsigned int mySize){
    components = new Data[mySize];
    size = mySize;
}   

// Copy Constructor (LinearContainer)
template <typename Data>
Vector<Data>::Vector(const LinearContainer<Data>& otherLinearContainer){
    size = otherLinearContainer.Size();
    components = new Data[size];
    for(int i = 0; i < size; i++){
        components[i] = otherLinearContainer[i];
    }
}

// Copy Constructor
template <typename Data>
Vector<Data>::Vector(const Vector<Data>& otherVector){
    size = otherVector.size;
    components = new Data[size];
    std::copy(otherVector.components, otherVector.components + otherVector.size, components);
}

// Move Constructor
template <typename Data>
Vector<Data>::Vector(Vector<Data>&& otherVector) noexcept{
    std::swap(components, otherVector.components);
    std::swap(size, otherVector.size);
}

// Decostructor
template <typename Data>
Vector<Data>::~Vector(){
    delete[] components;
}

/* ************************************************************************** */


// Assignment Operators

template <typename Data>
Vector<Data>& Vector<Data>::operator = (const Vector<Data>& otherVector){
    Vector<Data>* temp = new Vector<Data>(otherVector);
    std::swap(*this, *temp);
    delete temp;
    return *this;
}

template <typename Data>
Vector<Data>& Vector<Data>::operator = (Vector<Data>&& otherVector) noexcept{
    std::swap(size, otherVector.size);
    std::swap(components, otherVector.components);
    return *this;
}

/* ************************************************************************** */

// Comparison Operators

template <typename Data>
bool Vector<Data>::operator == (const Vector<Data>& otherVector) const noexcept{
    int i = 0;

    if(size != otherVector.size)
        return false;
    else  {
         while (i < size){
            if (components[i] != otherVector[i])
                return false;
            i++;
        }
    }  
    return true;
}

template <typename Data>
bool Vector<Data>::operator != (const Vector<Data>& otherVector) const noexcept{
    if ((*this) == otherVector)
        return false;
    else 
        return true;
}

/* ************************************************************************** */

// Specific Members Functions

// Resize
template <typename Data>
void Vector<Data>::Resize(unsigned int newSize){
    if (size == newSize)
        return;
    else if (newSize == 0){
        Clear();
    } else {
        Data* temp = new Data[newSize];
        if(size > newSize){
            for(unsigned int i = 0; i < newSize; i++){
                std::swap(components[i], temp[i]);
            }
        } else{
            for(unsigned int i = 0; i < size; i++){
                std::swap(components[i], temp[i]);
            }
        }
        size = newSize;
        std::swap(components, temp);
        delete[] temp;
        temp = nullptr;
    }
}

// inherited from Container
template <typename Data>
void Vector<Data>::Clear(){
    size = 0;
    delete[] components;
    components = nullptr;
}

//inherited from LinearContainer
template <typename Data>
Data& Vector<Data>::Front() const{
    if (size == 0)
        throw std::length_error("Error : Vector is empty.");
    else
        return components[0];
}

template <typename Data>
Data& Vector<Data>::Back() const{
    if (size == 0)
        throw std::length_error("Error : Vector is empty.");
    else
        return components[size - 1];
}

// Operator []
template <typename Data>
Data& Vector<Data>::operator [] (const unsigned int i) const{
    if(i >= size || i < 0)
        throw std::out_of_range("Error : Index out of accepted range.");
    else    
        return components[i];
}

/* ************************************************************************** */

// Specific Member Functions

//inherited from MappableContainer
template <typename Data>
void Vector<Data>::Map(MapFunctor mapFunctor, void* startValue){
    MapPreOrder(mapFunctor, startValue);
}

//inherited from PreOrderMappableContainer
template <typename Data>
void Vector<Data>::MapPreOrder(MapFunctor mapFunctor, void* startValue){
    for(int i = 0; i < size; i++){
        mapFunctor(components[i], startValue);
    }
}

//inherited from PostOrderMappableContainer
template <typename Data>
void Vector<Data>::MapPostOrder(MapFunctor mapFunctor, void* startValue){
    for(int i = size-1; i >= 0; i--){
        mapFunctor(components[i], startValue);
    }
}

//inherited from FoldableContainer
template <typename Data>
void Vector<Data>::Fold(FoldFunctor foldFunctor, const void* parameter1, void* parameter2) const {
    FoldPreOrder(foldFunctor, parameter1, parameter2);
}

//inherited from PreOrderFoldableContainer
template <typename Data>
void Vector<Data>::FoldPreOrder(FoldFunctor foldFunctor, const void* parameter, void* startValue) const{
    for(int i = 0; i < size; i++){
        foldFunctor(components[i], parameter, startValue);
    }
}

//inherited from PostOrderFoldableContainer
template <typename Data>
void Vector<Data>::FoldPostOrder(FoldFunctor foldFunctor, const void* parameter, void* startValue) const{
    for(int i = size-1; i >= 0; i--){
        foldFunctor(components[i], parameter, startValue);
    }
}

/* ************************************************************************** */

}
