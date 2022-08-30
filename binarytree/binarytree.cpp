
// #include "..."

namespace lasd {

/* ************************************************************************** */

// ...

// NODE
template <typename Data>
bool BinaryTree<Data>::Node::operator == (const Node& otherNode) const noexcept{

    if(this->key == otherNode.key){
        if(!this->HasLeftChild() && !this->HasRightChild()){
            if (otherNode.HasLeftChild() || otherNode.HasRightChild())
                return false;
            else
                return true;
        }
        else if (this->HasLeftChild() && !this->HasRightChild()){
            if (otherNode.HasLeftChild() && !otherNode.HasRightChild())
                if (this->LeftChild() == otherNode.LeftChild())
                    return true;
            return false;
        }
        else if (!this->HasLeftChild() && this->HasRightChild()){
            if (!otherNode.HasLeftChild() && otherNode.HasRightChild())
                if (this->RightChild() == otherNode.RightChild())
                    return true;
            return false;
        }
        else {
            if (otherNode.HasLeftChild() && otherNode.HasRightChild())
                if (this->LeftChild() == otherNode.LeftChild())
                    if (this->RightChild() == otherNode.RightChild())
                        return true;
            return false;
        }
    }
    return false;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator != (const Node& otherNode) const noexcept{
    if (*this == otherNode)
        return false;
    else
        return true;
}

template <typename Data>
Data& BinaryTree<Data>::Node::Element() noexcept{
    return this->key;
}

template <typename Data>
const Data& BinaryTree<Data>::Node::Element() const noexcept{
    return this->key;
}





// TREE

template <typename Data>
bool BinaryTree<Data>::operator == (const BinaryTree<Data>& otherBinaryTree) const noexcept{
    if(this->size != otherBinaryTree.size)
        return false;
    else
        if(this->size == 0)
            return true;
        else
            if(this->Root() == otherBinaryTree.Root())
                return true;
    return false;
}

template <typename Data>
bool BinaryTree<Data>::operator != (const BinaryTree<Data>& otherBinaryTree) const noexcept{
    if (*this == otherBinaryTree)
        return false;
    else 
        return true;
}

template <typename Data>
void BinaryTree<Data>::Map(MapFunctor mapFunctor, void* startValue){
    if(size != 0)
        MapBreadth(mapFunctor, startValue, Root());
}

template <typename Data>
void BinaryTree<Data>::Fold(FoldFunctor foldFunctor, const void* startValue, void* accumulator) const{
    if(size != 0)
        FoldBreadth(foldFunctor, startValue, accumulator, Root());
}

template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor mapFunctor, void* startValue){
    if(size != 0)
        MapPreOrder(mapFunctor, startValue, Root());
}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor foldFunctor, const void* startValue, void* accumulator) const{
    if(size != 0)
        FoldPreOrder(foldFunctor, startValue, accumulator, Root());
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor mapFunctor, void* startValue){
    if(size != 0)
        MapPostOrder(mapFunctor, startValue, Root());
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor foldFunctor, const void* startValue, void* accumulator) const{
    if(size != 0)
        FoldPostOrder(foldFunctor, startValue, accumulator, Root());
}

template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor mapFunctor, void* startValue){
    if(size != 0)
        MapInOrder(mapFunctor, startValue, Root());
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor foldFunctor, const void* startValue, void* accumulator) const{
    if(size != 0)
        FoldInOrder(foldFunctor, startValue, accumulator, Root());
}

template <typename Data>
void BinaryTree<Data>::MapBreadth(MapFunctor mapFunctor, void* startValue){
    if(size != 0)
        MapBreadth(mapFunctor, startValue, Root());
}

template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor foldFunctor, const void* startValue, void* accumulator) const{
    if(size != 0)
        FoldBreadth(foldFunctor, startValue, accumulator, Root());
}


/* ************************************************************************** */


template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor mapFunctor, void* startValue, Node& startNode){

    mapFunctor(startNode.Element(), startValue);

    if(startNode.HasLeftChild())
        MapPreOrder(mapFunctor, startValue, startNode.LeftChild());
    
    if(startNode.HasRightChild())  
        MapPreOrder(mapFunctor, startValue, startNode.RightChild());
    

}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor foldFunctor, const void* startValue, void* accumulator, Node& startNode) const{

    foldFunctor(startNode.Element(), startValue, accumulator);

    if(startNode.HasLeftChild())
        FoldPreOrder(foldFunctor, startValue, accumulator, startNode.LeftChild());
    
    if(startNode.HasRightChild())  
        FoldPreOrder(foldFunctor, startValue, accumulator, startNode.RightChild());

}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor mapFunctor, void* startValue, Node& startNode){
    
    if(startNode.HasLeftChild())
        MapPostOrder(mapFunctor, startValue, startNode.LeftChild());
    
    if(startNode.HasRightChild())  
        MapPostOrder(mapFunctor, startValue, startNode.RightChild());

    mapFunctor(startNode.Element(), startValue);

}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor foldFunctor, const void* startValue, void* accumulator, Node& startNode) const{

    if(startNode.HasLeftChild())
        FoldPostOrder(foldFunctor, startValue, accumulator, startNode.LeftChild());
    
    if(startNode.HasRightChild())  
        FoldPostOrder(foldFunctor, startValue, accumulator, startNode.RightChild());

    foldFunctor(startNode.Element(), startValue, accumulator);   

}

template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor mapFunctor, void* startValue, Node& startNode){
    
    if(startNode.HasLeftChild())
        MapInOrder(mapFunctor, startValue, startNode.LeftChild());
    
    mapFunctor(startNode.Element(), startValue);

    if(startNode.HasRightChild())  
        MapInOrder(mapFunctor, startValue, startNode.RightChild());

}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor foldFunctor, const void* startValue, void* accumulator, Node& startNode) const{

    if(startNode.HasLeftChild())
        FoldInOrder(foldFunctor, startValue, accumulator, startNode.LeftChild());
    
    foldFunctor(startNode.Element(), startValue, accumulator);

    if(startNode.HasRightChild())  
        FoldInOrder(foldFunctor, startValue, accumulator, startNode.RightChild());

}

template <typename Data>
void BinaryTree<Data>::MapBreadth(MapFunctor mapFunctor, void* startValue, Node& startNode){
    
    BTBreadthIterator<Data> iterator(*this);

    while(!iterator.Terminated()){
        mapFunctor(*iterator, startValue);
        ++iterator;
    }

}

template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor foldFunctor, const void* startValue, void* accumulator, Node& startNode) const{

    BTBreadthIterator<Data> iterator(*this);

    while(!iterator.Terminated()){
        foldFunctor(*iterator, startValue, accumulator);
        ++iterator;
    }

}

/* ************************************************************************** */




// BTPreOrderIterator

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& otherBinaryTree){
    if(otherBinaryTree.Size() != 0){
        this->root = &(otherBinaryTree.Root());
        this->current = this->root;
        stack = new StackLst<struct BinaryTree<Data>::Node*>();
    }
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& otherBTPreOrderIterator){

    this->root = otherBTPreOrderIterator.root;
    this->current = otherBTPreOrderIterator.current;
    stack = new StackLst<struct BinaryTree<Data>::Node*>(*(otherBTPreOrderIterator.stack));

}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& otherBTPreOrderIterator) noexcept{

    std::swap(this->root, otherBTPreOrderIterator.root);
    std::swap(this->current, otherBTPreOrderIterator.current);
    std::swap(this->stack, otherBTPreOrderIterator.stack);

}

template <typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator(){
    delete this->stack;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator = (const BTPreOrderIterator<Data>& otherBTPreOrderIterator){

    BTPreOrderIterator<Data>* temp = new BTPreOrderIterator<Data>(otherBTPreOrderIterator);

    std::swap(this->root, temp->root);
    std::swap(this->current, temp->current);
    std::swap(this->stack, temp->stack);

    delete temp;

    return (*this);

}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator = (BTPreOrderIterator<Data>&& otherBTPreOrderIterator) noexcept {

    std::swap(this->root, otherBTPreOrderIterator.root);
    std::swap(this->current, otherBTPreOrderIterator.current);
    std::swap(this->stack, otherBTPreOrderIterator.stack);

    return (*this);
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator == (const BTPreOrderIterator<Data>& otherBTPreOrderIterator) const noexcept {
    if(this->root == otherBTPreOrderIterator.root)
        if (this->current == otherBTPreOrderIterator.current)
            if (this->stack == otherBTPreOrderIterator.stack)
                return true;
    return false;

}

template <typename Data>
bool BTPreOrderIterator<Data>::operator != (const BTPreOrderIterator<Data>& otherBTPreOrderIterator) const noexcept {
    if (*this == otherBTPreOrderIterator)
        return true;
    else
        return false;
}

template <typename Data>
Data& BTPreOrderIterator<Data>::operator*() const{
    if(this->Terminated())
        throw std::out_of_range("Error : Iterator is Terminated");
    else    
        return current->Element();
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept{
    if(this->current == nullptr)
        return true;
    else
        return false;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++(){

    if(Terminated())
        throw std::out_of_range("Error : Iterator is Terminated");


    // if(stack->Empty())
    //     current = nullptr;

    // else{
    //     if(current->IsLeaf())
    //         if(!stack->Empty())
    //             current = stack->TopNPop();
    //         else{
    //             current = nullptr;
    //             return (*this);
    //         }
                
    //     else if(current->HasLeftChild()){
    //         if(current->HasRightChild())
    //             stack->Push(&(current->RightChild()));
    //         current = &(current->LeftChild());
    //     } else 
    //         if(current->HasRightChild())
    //             current = &(current->RightChild());
    // }

    if(current->HasLeftChild()){
        if(current->HasRightChild())
            stack->Push(&current->RightChild());    
        current = &(current->LeftChild());
    }  
    else
        if(current->HasRightChild())
            current = &(current->RightChild());
        else
            if(!stack->Empty())
                current = stack->TopNPop();
            else
                current = nullptr;
    
    return (*this);
}

template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    this->current = this->root;
    if(this->stack != nullptr)
        this->stack->Clear();
}


/* ************************************************************************** */

// BTPostOrderIterator

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& otherBinaryTree){
    if(otherBinaryTree.Size() != 0){
        this->root = &(otherBinaryTree.Root());
        this->current = this->root;
        stack = new StackLst<struct BinaryTree<Data>::Node*>();
        LeftmostLeaf(root);
    } 
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& otherBTPostOrderIterator){
    this->root = otherBTPostOrderIterator.root;
    this->current = otherBTPostOrderIterator.current;
    stack = new StackLst<struct BinaryTree<Data>::Node*>(*(otherBTPostOrderIterator.stack));
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& otherBTPostOrderIterator) noexcept{
    std::swap(this->root, otherBTPostOrderIterator.root);
    std::swap(this->current, otherBTPostOrderIterator.current);
    std::swap(this->stack, otherBTPostOrderIterator.stack);
}

template <typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator(){
    delete this->stack;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator = (const BTPostOrderIterator<Data>& otherBTPostOrderIterator){
    BTPostOrderIterator<Data>* temp = new BTPostOrderIterator<Data>(otherBTPostOrderIterator);

    std::swap(this->root, temp->root);
    std::swap(this->current, temp->current);
    std::swap(this->stack, temp->stack);

    delete temp;

    return (*this);
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator = (BTPostOrderIterator<Data>&& otherBTPostOrderIterator) noexcept {
    std::swap(this->root, otherBTPostOrderIterator.root);
    std::swap(this->current, otherBTPostOrderIterator.current);
    std::swap(this->stack, otherBTPostOrderIterator.stack);

    return (*this);
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator == (const BTPostOrderIterator<Data>& otherBTPostOrderIterator) const noexcept {
    if(this->root == otherBTPostOrderIterator.root)
        if (this->current == otherBTPostOrderIterator.current)
            if (this->stack == otherBTPostOrderIterator.stack)
                return true;
    return false;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator != (const BTPostOrderIterator<Data>& otherBTPostOrderIterator) const noexcept {
    if(*this == otherBTPostOrderIterator)
        return false;
    else
        return true;
}

template <typename Data>
Data& BTPostOrderIterator<Data>::operator*() const{
    if(this->Terminated())
        throw std::out_of_range("Error : Iterator is Terminated");
    else    
        return current->Element();
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept{
    if(this->current == nullptr)
        return true;
    else
        return false;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++(){

    if(Terminated())
        throw std::out_of_range("Error : Iterator is Terminated");

    if(stack->Empty())
        current = nullptr;
    
    else{
        

        if(stack->Top()->HasRightChild())
            if(current == &(stack->Top()->RightChild()))
                current = stack->TopNPop();
            else
                LeftmostLeaf(&(stack->Top()->RightChild()));
        else
            current = stack->TopNPop();

    }

    return (*this);
      
}

template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    if(stack != nullptr){
        stack->Clear();
        LeftmostLeaf(root);
    }
}
 
template <typename Data>
void BTPostOrderIterator<Data>::LeftmostLeaf(struct BinaryTree<Data>::Node* startNode){

    current = startNode;

    while(!current->IsLeaf()){

        if (current->HasLeftChild()){
            stack->Push(current);
            current = &(current->LeftChild());
        }  
        else if (current->HasRightChild()){
                stack->Push(current);
                current = &(current->RightChild());
        }

    }  
}


/* ************************************************************************** */

// BTInOrderIterator

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& otherBinaryTree){
    if(otherBinaryTree.Size() != 0){
        this->root = &(otherBinaryTree.Root());
        this->current = this->root;
        stack = new StackLst<struct BinaryTree<Data>::Node*>();
        LeftmostChild(root);
    }  
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& otherBTInOrderIterator){
    this->root = otherBTInOrderIterator.root;
    this->current = otherBTInOrderIterator.current;
    stack = new StackLst<struct BinaryTree<Data>::Node*>(*(otherBTInOrderIterator.stack));
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& otherBTInOrderIterator) noexcept{
    std::swap(this->root, otherBTInOrderIterator.root);
    std::swap(this->current, otherBTInOrderIterator.current);
    std::swap(this->stack, otherBTInOrderIterator.stack);
}

template <typename Data>
BTInOrderIterator<Data>::~BTInOrderIterator(){
    delete this->stack;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator = (const BTInOrderIterator& otherBTInOrderIterator){
    BTInOrderIterator<Data>* temp = new BTInOrderIterator<Data>(otherBTInOrderIterator);

    std::swap(this->root, temp->root);
    std::swap(this->current, temp->current);
    std::swap(this->stack, temp->stack);

    delete temp;

    return (*this);
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator = (BTInOrderIterator&& otherBTInOrderIterator) noexcept {
    std::swap(this->root, otherBTInOrderIterator.root);
    std::swap(this->current, otherBTInOrderIterator.current);
    std::swap(this->stack, otherBTInOrderIterator.stack);

    return (*this);
}   

template <typename Data>
bool BTInOrderIterator<Data>::operator == (const BTInOrderIterator<Data>& otherBTInOrderIterator) const noexcept {
    if(this->root == otherBTInOrderIterator.root)
        if (this->current == otherBTInOrderIterator.current)
            if (this->stack == otherBTInOrderIterator.stack)
                return true;
    return false;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator != (const BTInOrderIterator<Data>& otherBTInOrderIterator) const noexcept {
    if(*this == otherBTInOrderIterator)
        return false;
    else
        return true;
}

template <typename Data>
Data& BTInOrderIterator<Data>::operator*() const{
    if(this->Terminated())
        throw std::out_of_range("Error : Iterator is Terminated");
    else    
        return current->Element();
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept{
    if(this->current == nullptr)
        return true;
    else
        return false;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++(){
    // if(Terminated())
    //     throw std::out_of_range("Error : Iterator is Terminated");
    
    // if(stack->Empty() && current != root && current->IsLeaf())
    // //dà problemi nel caso di un albero con radice, un figlio sx, e un figlio dx che ha altri figli (errore sul figlio dx nel momento in cui è current)
    //     current = nullptr;
    
    // else{
    //     if(current->HasRightChild()){
    //         LeftmostChild(&(current->RightChild()));
    //     } else 
    //         if(!stack->Empty())
    //             current = stack->TopNPop();   
    //         else
    //             current = nullptr;
    // }

    if(Terminated())
        throw std::out_of_range("Error : Iterator is Terminated");
    
    if(current->HasRightChild())
        LeftmostChild(&(current->RightChild()));
    else
        if(!stack->Empty())
            current = stack->TopNPop(); 
        else
            current = nullptr;


    
    return (*this);
    
    return (*this);
}

template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    if(this->stack != nullptr){
        stack->Clear();
        LeftmostChild(root);
    }
    
}

template <typename Data>
void BTInOrderIterator<Data>::LeftmostChild(struct BinaryTree<Data>::Node* startNode){

    current = startNode;

    if(current != nullptr){
        while(current->HasLeftChild()){
            stack->Push(current);
            current = &(current->LeftChild());
        }
    }
} 


/* ************************************************************************** */

// BTBreadthIterator

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& otherBinaryTree){
    if(otherBinaryTree.Size() != 0){
        this->root = &(otherBinaryTree.Root());
        this->current = this->root;
        queue = new QueueLst<struct BinaryTree<Data>::Node*>();
    }  
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& otherBTBreadthIterator){
    this->root = otherBTBreadthIterator.root;
    this->current = otherBTBreadthIterator.current;
    queue = new QueueLst<struct BinaryTree<Data>::Node*>(*(otherBTBreadthIterator.queue));
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& otherBTBreadthIterator) noexcept{
    std::swap(this->root, otherBTBreadthIterator.root);
    std::swap(this->current, otherBTBreadthIterator.current);
    std::swap(this->queue, otherBTBreadthIterator.queue);
}

template <typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator(){
    delete this->queue;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator = (const BTBreadthIterator& otherBTBreadthIterator){
    BTPreOrderIterator<Data>* temp = new BTBreadthIterator<Data>(otherBTBreadthIterator);

    std::swap(this->root, temp->root);
    std::swap(this->current, temp->current);
    std::swap(this->queue, temp->queue);

    delete temp;

    return (*this);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator = (BTBreadthIterator&& otherBTBreadthIterator) noexcept {
    std::swap(this->root, otherBTBreadthIterator.root);
    std::swap(this->current, otherBTBreadthIterator.current);
    std::swap(this->queue, otherBTBreadthIterator.queue);

    return (*this);
}

template <typename Data>
bool BTBreadthIterator<Data>::operator == (const BTBreadthIterator<Data>& otherBTBreadthIterator) const noexcept {
    if(this->root == otherBTBreadthIterator.root)
        if (this->current == otherBTBreadthIterator.current)
            if (this->queue == otherBTBreadthIterator.queue)
                return true;
    return false;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator != (const BTBreadthIterator<Data>& otherBTBreadthIterator) const noexcept {
    if (*this == otherBTBreadthIterator)
        return true;
    else
        return false;
}

template <typename Data>
Data& BTBreadthIterator<Data>::operator*() const{
    if(this->Terminated())
        throw std::out_of_range("Error : Iterator is Terminated");
    else    
        return current->Element();
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept{
    if(this->current == nullptr)
        return true;
    else
        return false;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++(){
    
    if(Terminated())
        throw std::out_of_range("Error : Iterator is Terminated");
    
        if(current->HasLeftChild())
            queue->Enqueue(&(current->LeftChild()));

        if(current->HasRightChild())
            queue->Enqueue(&(current->RightChild()));
        
        if(!queue->Empty())
            current = queue->HeadNDequeue();
        else
            current = nullptr;

    return (*this);
    
}

template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    this->current = this->root;
    if(this->queue != nullptr)
        this->queue->Clear();
}

}
