
namespace lasd {

/* ************************************************************************** */

// ...

// Copy Constructor (LinearContainer)
template <typename Data>
QueueLst<Data>::QueueLst(const LinearContainer<Data>& otherLinearContainer){
    for(int i = 0; i<otherLinearContainer.Size(); i++){
        this->InsertAtBack(otherLinearContainer[i]);
    }
}

// Copy Constructor 
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data>& otherQueueLst){
    if(otherQueueLst.size != 0){

        struct List<Data>::Node* tempOtherQueueLst = otherQueueLst.head;

        while (tempOtherQueueLst != nullptr){
            this->InsertAtBack(tempOtherQueueLst->key);
            tempOtherQueueLst = tempOtherQueueLst->next;
        }

    }
}

// Move Constructor 
template <typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data>&& otherQueueLst) noexcept{
    std::swap(this->size, otherQueueLst.size);
    std::swap(this->head, otherQueueLst.head);
    std::swap(this->tail, otherQueueLst.tail);
}

/* ************************************************************************** */


// Assignment Operators 

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator =(const QueueLst<Data>& otherQueueLst){

    QueueLst<Data>* temp = new QueueLst(otherQueueLst);

    std::swap(this->size, temp->size);
    std::swap(this->head, temp->head);
    std::swap(this->tail, temp->tail);

    delete temp;
    return (*this);
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator =(QueueLst<Data>&& otherQueueLst) noexcept{
    std::swap(this->size, otherQueueLst.size);
    std::swap(this->head, otherQueueLst.head);
    std::swap(this->tail, otherQueueLst.tail);

    return (*this);
}


/* ************************************************************************** */

// Comparison Operators

template <typename Data>
bool QueueLst<Data>::operator == (const QueueLst<Data>& otherQueueLst) const noexcept{
    if(List<Data>::operator==(otherQueueLst) == true)
        return true;
    else
        return false;
}

template <typename Data>
bool QueueLst<Data>::operator != (const QueueLst<Data>& otherQueueLst) const noexcept{
    if (*this == otherQueueLst){
        return false;
    } else{
        return true;
    }
}


/* ************************************************************************** */

//Specific Member Functions (inherited from Queue)

template <typename Data>
const Data& QueueLst<Data>::Head() const{
    if(size == 0){
        throw std::length_error("Error : Queue is empty");
    }
    else{
        return List<Data>::Front();
    }
}

template <typename Data>
Data& QueueLst<Data>::Head(){
    if(size == 0){
        throw std::length_error("Error : Queue is empty");
    }
    else{
        return List<Data>::Front();
    }
}

template <typename Data>
void QueueLst<Data>::Dequeue(){
    if(size == 0)
        throw std::length_error("Error : Queue is empty");
    else
        List<Data>::RemoveFromFront();
}

template <typename Data>
Data QueueLst<Data>::HeadNDequeue(){
    if(size == 0)
        throw std::length_error("Error : Queue is empty");
    else{
        return List<Data>::FrontNRemove();
    }
}

template <typename Data>
void QueueLst<Data>::Enqueue(const Data& newData){
    List<Data>::InsertAtBack(newData);
}

template <typename Data>
void QueueLst<Data>::Enqueue(Data&& newData){
    List<Data>::InsertAtBack(newData);
}

/* ************************************************************************** */


// Specific Member Functions (inherited from Container)
template <typename Data>
void QueueLst<Data>::Clear(){
    
    while (this->head != nullptr){
        this->Dequeue();
    }

    tail = nullptr;
    
}


/* ************************************************************************** */

}
