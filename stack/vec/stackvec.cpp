
namespace lasd {

/* ************************************************************************** */

// ...

// Default
template <typename Data>
StackVec<Data>::StackVec(){
    components = new Data[1];
    this->size += 1;
}

// Copy Constructor (LinearContainer)
template <typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& otherLinearContainer){
    this->size = otherLinearContainer.Size();
    components = new Data[this->size];
    for(int i = 0; i<this->size; i++){
        components[i] = otherLinearContainer[i];
    }
    this->head = this->size;
}

// Copy Constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& otherStackVec){
    this->size = otherStackVec.size;
    components = new Data[size];
    std::copy(otherStackVec.components, otherStackVec.components + otherStackVec.size, components);
    head = otherStackVec.head;
}

// Move Constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& otherStackVec) noexcept{
    std::swap(components, otherStackVec.components);
    std::swap(this->size, otherStackVec.size);
    std::swap(this->head, otherStackVec.head);
}

/* ************************************************************************** */


// Assignment Operators

template <typename Data>
StackVec<Data>& StackVec<Data>::operator = (const StackVec<Data>& otherStackVec){
    StackVec<Data>* temp = new StackVec(otherStackVec);
    std::swap(components, temp->components);
    std::swap(this->size, temp->size);
    std::swap(this->head, temp->head);

    delete temp;
    return (*this);

}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator = (StackVec<Data>&& otherStackVec) noexcept{
    std::swap(components, otherStackVec.components);
    std::swap(this->size, otherStackVec.size);
    std::swap(this->head, otherStackVec.head);
    return (*this);
}

/* ************************************************************************** */


// Comparison Operators

template <typename Data>
bool StackVec<Data>::operator == (const StackVec<Data>& otherStackVec) const noexcept{
    if(this->head == otherStackVec.head){
        for(int i = 0; i<this->Size(); i++){
            if (components[i] != otherStackVec.components[i])
                return false;
        return true;
        }
    }
    return false;
}

template <typename Data>
bool StackVec<Data>::operator != (const StackVec<Data>& otherStackVec) const noexcept{
    if (*this == otherStackVec)
        return false;
    else
        return true;
}


/* ************************************************************************** */

// Specific Member Functions (inherited from Stack)

template <typename Data>
const Data& StackVec<Data>::Top() const{
    if(this->head == 0)
        throw std::length_error("Error : Stack is empty");
    else
        return components[this->head - 1];
}

template <typename Data>
Data& StackVec<Data>::Top(){
    if(this->head == 0)
        throw std::length_error("Error : Stack is empty");
    else
        return components[this->head - 1];
}

template <typename Data>
void StackVec<Data>::Pop() {
    if(this->Size() == 0)
        throw std::length_error("Error : Stack is empty");
    else{

        //...
        
        this->head = this->head - 1;

        Reduce();

    }
}

template <typename Data>
Data StackVec<Data>::TopNPop(){
    if(this->Size() == 0)
        throw std::length_error("Error : Stack is empty");
    else{

        //...

        Data data = components[this->head - 1];

        this->head = this->head - 1;

        Reduce();

        return data;
    }
}

template <typename Data>
void StackVec<Data>::Push(const Data& newData) {
    Expand();

    components[this->head] = newData;

    this->head = this->head + 1;

    //...
}

template <typename Data>
void StackVec<Data>::Push(Data&& newData) {
    Expand();

    std::swap(components[this->head], newData);

    this->head = this->head + 1;

    //...
}

/* ************************************************************************** */

// Specific Member Functions (inherited from Container)

template <typename Data>
bool StackVec<Data>::Empty() const noexcept{
    if(this->head == 0){
        return true;
    }
    else{
        return false;
    }
}

template <typename Data>
unsigned int StackVec<Data>::Size() const noexcept{
    return this->head;
}

template <typename Data>
void StackVec<Data>::Clear(){
    if(this->head != 0){
        this->head = 0;
        Vector<Data>::Resize(1);
    }
}


/* ************************************************************************** */

// Specific Member Functions

template <typename Data>
void StackVec<Data>::Expand(){
    if(this->head == this->size){
        Vector<Data>::Resize(this->size*2);
    }
}

template <typename Data>
void StackVec<Data>::Reduce(){
    if(this->head <= this->size/4){
        Vector<Data>::Resize(this->size/2);
    }
}

/* ************************************************************************** */



}
