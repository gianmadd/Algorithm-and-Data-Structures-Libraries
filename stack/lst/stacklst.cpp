
namespace lasd {

/* ************************************************************************** */

// ...

// Copy Constructor (LinearContainer)
template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& otherLinearContainer){
    for(int i = 0; i<otherLinearContainer.Size(); i++){
        this->InsertAtBack(otherLinearContainer[i]);
    }
}

// Copy Constructor
template <typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& otherStackLst){
    if(otherStackLst.size != 0){

        struct List<Data>::Node* tempOtherStackLst = otherStackLst.head;

        while (tempOtherStackLst != nullptr){
            this->InsertAtBack(tempOtherStackLst->key);
            tempOtherStackLst = tempOtherStackLst->next;
        }
    }
}

// Move Constructor
template <typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& otherStackLst) noexcept{
    std::swap(this->size, otherStackLst.size);
    std::swap(this->head, otherStackLst.head);
}

/* ************************************************************************** */

// Assignment Operators
template <typename Data>
StackLst<Data>& StackLst<Data>::operator = (const StackLst<Data>& otherStackLst){

    StackLst<Data>* temp = new StackLst(otherStackLst);

    std::swap(this->size, temp->size);
    std::swap(this->head, temp->head);

    delete temp;
    return (*this);
    
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator = (StackLst<Data>&& otherStackLst) noexcept{

    std::swap(this->size, otherStackLst.size);
    std::swap(this->head, otherStackLst.head);

    return (*this);
}

/* ************************************************************************** */


// Comparison Operators
template <typename Data>
bool StackLst<Data>::operator == (const StackLst<Data>& otherStackLst) const noexcept{
    if(List<Data>::operator==(otherStackLst) == true)
        return true;
    else 
        return false;
}

template <typename Data>
bool StackLst<Data>::operator != (const StackLst<Data>& otherStackLst) const noexcept{
    if (*this == otherStackLst){
        return false;
    } else{
        return true;
    }
}

/* ************************************************************************** */

// Specific Member Functions (inherited from Stack)

template <typename Data>
const Data& StackLst<Data>::Top() const {
    if (this->size == 0){
        throw std::length_error("Error : Stack is empty.");
    } else{
        return List<Data>::Front();
    }
}

template <typename Data>
Data& StackLst<Data>::Top(){
if (this->size == 0){
        throw std::length_error("Error : Stack is empty.");
    } else{
        return List<Data>::Front();
    }
}

template <typename Data>
void StackLst<Data>::Pop(){
    if (this->size == 0){
        throw std::length_error("Error : Stack is empty.");
    } else{
        List<Data>::RemoveFromFront();
    }
}

template <typename Data>
Data StackLst<Data>::TopNPop(){
    if(this->size == 0){
        throw std::length_error("Error : Stack is empty.");
    } else{
        return List<Data>::FrontNRemove();
    }

}

template <typename Data>
void StackLst<Data>::Push(const Data& newData) {
    List<Data>::InsertAtFront(newData);
}

template <typename Data>
void StackLst<Data>::Push(Data&& newData) {
    List<Data>::InsertAtFront(newData);
}

/* ************************************************************************** */


// Specific Member Functions (inherited from Container)
template <typename Data>
void StackLst<Data>::Clear(){
    
    while (this->head != nullptr){
        this->Pop();
    }
    
}



/* ************************************************************************** */

}
