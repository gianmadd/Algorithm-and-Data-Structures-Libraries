
namespace lasd {

/* ************************************************************************** */

// ...

template <typename Data>
BinaryTreeVec<Data>::NodeVec::~NodeVec(){
    if(HasLeftChild())
        delete (*vectorPointer)[index*2 + 1];
    
    if(HasRightChild())
        delete (*vectorPointer)[index*2 + 2];
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept{
    if(!this->HasLeftChild() && !this->HasRightChild())
        return true;
    else
        return false;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
    if((this->index*2 + 1) < vectorPointer->Size())
        return true;
    else
        return false;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
    if((this->index*2 + 2) < vectorPointer->Size())
        return true;
    else
        return false;
}

template <typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild(){
    if(!HasLeftChild())
        throw std::out_of_range("Error : Left Child Missing");
    else
        return *((*vectorPointer)[(index*2)+1]);
}

template <typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild(){
    if(!HasRightChild())
        throw std::out_of_range("Error : Left Child Missing");
    else
        return *((*vectorPointer)[(index*2)+2]);
}

template <typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const{
    if(!HasLeftChild())
        throw std::out_of_range("Error : Left Child Missing");
    else
        return *((*vectorPointer)[(index*2)+1]);
}

template <typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const{
    if(!HasRightChild())
        throw std::out_of_range("Error : Left Child Missing");
    else
        return *((*vectorPointer)[(index*2)+2]);
}

/* ************************************************************************** */

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& otherLinearContainer){
    vector = new Vector<NodeVec*>(otherLinearContainer.Size());
    this->size = vector->Size();
    for(int i = 0; i<this->size; i++){
        (*vector)[i] = new NodeVec();
        ((*vector)[i])->vectorPointer = this->vector;
        ((*vector)[i])->index = i;
        ((*vector)[i])->key = otherLinearContainer[i];
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& otherBinaryTreeVec){
    vector = new Vector<NodeVec*>(otherBinaryTreeVec.Size());
    this->size = vector->Size();
    for(int i = 0; i<this->size; i++){
        (*vector)[i] = new NodeVec();
        ((*vector)[i])->vectorPointer = this->vector;
        ((*vector)[i])->index = i;
        ((*vector)[i])->key = ((*(otherBinaryTreeVec.vector))[i])->key;
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& otherBinaryTreeVec) noexcept{
    std::swap(this->size, otherBinaryTreeVec.size);
    std::swap(this->vector, otherBinaryTreeVec.vector);
}

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){

    Clear();

    delete this->vector;

}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator = (const BinaryTreeVec<Data>& otherBinaryTreeVec){

    BinaryTreeVec<Data>* temp = new BinaryTreeVec<Data>(otherBinaryTreeVec);

    std::swap(this->size, temp->size);
    std::swap(this->vector, temp->vector);

    delete temp;
    return (*this);

}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator = (BinaryTreeVec<Data>&& otherBinaryTreeVec) noexcept{

    std::swap(this->size, otherBinaryTreeVec.size);
    std::swap(this->vector, otherBinaryTreeVec.vector);

    return (*this);
    
}

template <typename Data>
bool BinaryTreeVec<Data>::operator == (const BinaryTreeVec<Data>& otherBinaryTreeVec) const noexcept{
    if(this->size != otherBinaryTreeVec.size)
        return false;
    else{
        for(int i = 0; i<this->size; i++){
            if( *((*this->vector)[i]) != *((*otherBinaryTreeVec.vector)[i]))
                return false;
        }
        return true;
    }
} 

template <typename Data>
bool BinaryTreeVec<Data>::operator != (const BinaryTreeVec<Data>& otherBinaryTreeVec) const noexcept{
    if(*this == otherBinaryTreeVec)
        return false;
    else
        return true;
} 

template <typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const{
    if(this->size == 0)
        throw std::length_error("Error : BinaryTreeVec is Empty.");
    else
        return (*(*vector)[0]);
}

template <typename Data>
void BinaryTreeVec<Data>::Clear(){

    if(this->size > 0)
        delete (*vector)[0];

    this->size = 0;

}

template <typename Data>
void BinaryTreeVec<Data>::MapBreadth(MapFunctor mapFunctor, void* startValue){
    for(int i = 0; i<this->size; i++){
        mapFunctor((*((*vector)[i])).Element(), startValue);
    }
}

template <typename Data>
void BinaryTreeVec<Data>::FoldBreadth(FoldFunctor foldFunctor, const void* startValue, void* accumulator) const{
    for(int i = 0; i<this->size; i++){
        foldFunctor((*((*vector)[i])).Element(), startValue, accumulator);
    }
}

/* ************************************************************************** */

}
