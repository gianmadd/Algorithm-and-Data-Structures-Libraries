
namespace lasd {

/* ************************************************************************** */

// ...

// Default
template <typename Data>
QueueVec<Data>::QueueVec(){
    components = new Data[1];
    this->size += 1;
}

// Copy Constructor (LinearContainer)
template <typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& otherLinearContainer){
    this->size = otherLinearContainer.Size() + 1;
    components = new Data[this->size];
    for(int i = 0; i<otherLinearContainer.Size(); i++){
        components[i] = otherLinearContainer[i];
    }

    this->tail = otherLinearContainer.Size();

}

// Copy Constructor 
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& otherQueueVec){
    this->size = otherQueueVec.size;
    components = new Data[this->size];
    std::copy(otherQueueVec.components, otherQueueVec.components + otherQueueVec.size, components);
    this->head = otherQueueVec.head;
    this->tail = otherQueueVec.tail;
}

// Move Constructo
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& otherQueueVec) noexcept{
    std::swap(components, otherQueueVec.components);
    std::swap(this->size, otherQueueVec.size);
    std::swap(this->head, otherQueueVec.head);
    std::swap(this->tail, otherQueueVec.tail);


}


// Assignment Operators

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (const QueueVec<Data>& otherQueueVec){
    QueueVec<Data>* temp = new QueueVec(otherQueueVec);
    std::swap(components, temp->components);
    std::swap(this->size, temp->size);
    std::swap(this->head, temp->head);
    std::swap(this->tail, temp->tail);

    delete temp;
    return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (QueueVec<Data>&& otherQueueVec) noexcept{
    std::swap(components, otherQueueVec.components);
    std::swap(this->size, otherQueueVec.size);
    std::swap(this->head, otherQueueVec.head);
    std::swap(this->tail, otherQueueVec.tail);

    return *this;
}


// Comparison Operators 

template <typename Data>
bool QueueVec<Data>::operator == (const QueueVec<Data>& otherQueueVec) const noexcept{

    if (this->Size() == otherQueueVec.Size()){

        unsigned int tempIndex = otherQueueVec.head;

        for (int i = this->head; i != this->tail; i = ((i+1)%(this->size))){

            if(components[i] != otherQueueVec.components[tempIndex])    
                return false;
            else
                tempIndex = (tempIndex + 1) % otherQueueVec.size;
            
            }

            return true;
        }
    return false;
    
}

template <typename Data>
bool QueueVec<Data>::operator != (const QueueVec<Data>& otherQueueVec) const noexcept{
    if (*this == otherQueueVec)
        return false;
    else
        return true;
}


// Specific Member Functions (inherited from Queue)

template <typename Data>
const Data& QueueVec<Data>::Head() const{

    if(this->head == this->tail)
        throw std::length_error("Error : Queue is empty");
    else
        return components[this->head];

}

template <typename Data>
Data& QueueVec<Data>::Head(){

    if(this->head == this->tail)
        throw std::length_error("Error : Queue is empty");
    else
        return components[this->head];
}

template <typename Data>
void QueueVec<Data>::Dequeue(){
    if(this->Size() == 0)
        throw std::length_error("Error : Queue is empty");
    else{

        //...

        this->head = (this->head + 1) % this->size;

        Reduce();

    }
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
    if(this->Size() == 0)
        throw std::length_error("Error : Stack is empty");
    else{

        //...

        Data data = components[this->head];

        this->head = (this->head + 1) % this->size;

        Reduce();

        return data;

    }
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& newData){


    Expand();

    //...

    components[this->tail] = newData;

    this->tail = (this->tail + 1) % this->size;
  
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& newData) {

    Expand();

    //...

    std::swap(components[this->tail], newData);

    this->tail = (this->tail + 1) % this->size;

}

template <typename Data>
bool QueueVec<Data>::Empty() const noexcept{
    
    if (this->head == this->tail)
        return true;
    else
        return false;
}

template <typename Data>
unsigned int QueueVec<Data>::Size() const noexcept{
    if(this->head <= this->tail)
        return (this->tail - this->head);
    else 
        return (this->size - this->head - this->tail);

}

template <typename Data>
void QueueVec<Data>::Clear(){

    this->head = 0;
    this->tail = 0;

    Vector<Data>::Resize(1);
}

template <typename Data>
void QueueVec<Data>::Expand(){

    if(this->tail == ((this->head - 1) % this->size)){

    QueueVec<Data>* temp = new QueueVec<Data>();
        
    temp->Vector<Data>::Resize(this->size * 2);

    SwapVectors(*temp);

    delete temp;
    }

}

template <typename Data>
void QueueVec<Data>::Reduce(){

    if((this->Size()) <= (this->size/4)){

        QueueVec<Data>* temp = new QueueVec<Data>();

        temp->Vector<Data>::Resize(this->size / 2);

        SwapVectors(*temp);

        delete temp;
         
    }

}

template <typename Data>
void QueueVec<Data>::SwapVectors(QueueVec<Data>& otherQueueVec){

    unsigned int index = 0;

    for(int i = this->head; i != this->tail; i = ((i+1) % (this->size))){
        std::swap(components[i], otherQueueVec.components[index]);
        index++;
    }

    otherQueueVec.head = 0;
    otherQueueVec.tail = index;

    std::swap(components, otherQueueVec.components);
    std::swap(this->size, otherQueueVec.size);
    std::swap(this->head, otherQueueVec.head);
    std::swap(this->tail, otherQueueVec.tail);

}

/* ************************************************************************** */

}
