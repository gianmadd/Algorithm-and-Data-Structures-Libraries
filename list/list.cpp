
namespace lasd {

/* ************************************************************************** */

// ...

//NODE


// Copy constructor
template <typename Data>
List<Data>::Node::Node(const Node& otherNode){
    key = otherNode.key;
    next = otherNode.next;
}

// Move Constructor
template <typename Data>
List<Data>::Node::Node(Node&& otherNode) noexcept {
    std::swap(key, otherNode.key);
    std::swap(next, otherNode.next);
}

// Deconstructor
template <typename Data>
List<Data>::Node::~Node(){
    delete next;
}

// Specific Constructor
template <typename Data>
List<Data>::Node::Node(const Data& newData){
    this->key = newData;
}

template <typename Data>
List<Data>::Node::Node(Data&& newData) noexcept {
    std::swap(this->key, newData);
}

// Comparison Operators
template <typename Data>
bool List<Data>::Node::operator == (const Node& otherNode) const noexcept{
    if(this->key == otherNode.key){
        if((next == nullptr && otherNode.next==nullptr) || (next==otherNode.next)){
            return true;
        }
    }
    return false;   
}

template <typename Data>
bool List<Data>::Node::operator != (const Node& otherNode) const noexcept{
    if (*this == otherNode)
        return false;
    else 
        return true;
}

/* ************************************************************************** */

//LIST


// Copy Constructor (LinearContainer)
template <typename Data>
List<Data>::List(const LinearContainer<Data>& otherLinearContainer){

    for(int i = 0; i<otherLinearContainer.Size(); i++){
        this->InsertAtBack(otherLinearContainer[i]);
    }

}

// Copy Constructor
template <typename Data>
List<Data>::List(const List<Data>& otherList){

    Node* tempOtherList = otherList.head;
    while(tempOtherList != nullptr){
        this->InsertAtBack(tempOtherList->key);
        tempOtherList = tempOtherList->next;
    }

    tempOtherList = nullptr;

}

// Move Constructor
template <typename Data>
List<Data>::List(List<Data>&& otherList) noexcept{

    std::swap(this->size, otherList.size); 
    std::swap(this->head, otherList.head);
    std::swap(this->tail, otherList.tail);
}


// Deconstructor
template <typename Data>
List<Data>::~List(){
    tail = nullptr;
    delete head;
    head = nullptr;
}

/* ************************************************************************** */

// Assignment Operator (Copy)
template <typename Data>
List<Data>& List<Data>::operator = (const List<Data>& otherList){
    List<Data>* temp = new List(otherList);
    std::swap(head, temp->head);
    std::swap(tail, temp->tail);
    std::swap(this->size, temp->size);

    delete temp;
    return (*this);
}  
    
// // Assignment Operator (Move)
template <typename Data>
List<Data>& List<Data>::operator = (List<Data>&& otherList) noexcept{
    
    std::swap(this->size, otherList.size);
    std::swap(this->head, otherList.head);
    std::swap(this->tail, otherList.tail);
    return (*this);
}

/* ************************************************************************** */

// Comparison Operators
template <typename Data>
bool List<Data>::operator == (const List<Data>& otherList) const noexcept{
    if ((this->size == 0) && (otherList.size == 0))
        return true;
    if (this->size == otherList.size){
        Node* temp = head;
        Node* tempOtherList = otherList.head;
        while(temp != nullptr){
            if (temp->key != tempOtherList->key){
                temp = nullptr;
                tempOtherList = nullptr;
                return false;
            }
            temp = temp->next;
            tempOtherList = tempOtherList->next;
        }
        temp = nullptr;
        tempOtherList = nullptr;
    } else {
        return false;
    }
    return true;
}

template <typename Data>
bool List<Data>::operator != (const List<Data>& otherList) const noexcept{
    if ((*this) == otherList)
        return false;
    else
        return true;
}

/* ************************************************************************** */


// Specific Member Functions

// Insert at Front
template <typename Data>
void List<Data>::InsertAtFront(const Data& newData){
    Node* newNode = new Node(newData);
    
    newNode->next = head;
    if(this->size == 0){
        tail = newNode;
    }
    head = newNode;
    this->size = this->size + 1;
}

template <typename Data>
void List<Data>::InsertAtFront(Data&& newData){
    Node* newNode = new Node(newData);
    
    newNode->next = head;
    if(this->size == 0){
        tail = newNode;
    }
    head = newNode;
    this->size = this->size + 1;
} 

// Remove from Front
template <typename Data>
void List<Data>::RemoveFromFront(){
    if(head == nullptr){
        throw std::length_error("Error : List is empty.");
    } 
    else{
        Node* temp = head;
        if(this->size == 1){
            tail = nullptr;
        }
        head = head->next;
        temp->next = nullptr;
        delete temp;
        this->size = this->size - 1;
    }
}

// Front and Remove
template <typename Data>
Data List<Data>::FrontNRemove(){
    if(head == nullptr)
        throw std::length_error("Error : List is empty.");
    else{
        Data data = head->key;
        Node* temp = head;
        if(this->size == 1){
            tail = nullptr;
        }
        head = head->next;
        temp->next = nullptr;
        delete temp;
        this->size = this->size - 1;
        return data;
    }
}

// Insert at Back
template <typename Data>
void List<Data>::InsertAtBack(const Data& newData){
    if (this->size == 0)
        InsertAtFront(newData);
    else{
        Node* newNode = new Node(newData);
        
        tail->next = newNode;
        tail = newNode;   
        this->size = this->size + 1; 
    }   
}

template <typename Data>
void List<Data>::InsertAtBack(Data&& newData){
    if (this->size == 0)
        InsertAtFront(newData);
    else{
        Node* newNode = new Node(newData);
        
        tail->next = newNode;
        tail = newNode;   
        this->size = this->size + 1; 
    }  
}

/* ************************************************************************** */

// inherited from Container
template <typename Data>
void List<Data>::Clear(){
    tail = nullptr;
    delete head;
    head = nullptr;
    this->size = 0;
}

// inherited from LinearContainer
template <typename Data>
Data& List<Data>::Front() const{
    if(this->size == 0)
        throw std::length_error("Error : List is empty.");
    else
        return head->key; 
}

template <typename Data>
Data& List<Data>::Back() const{
    if(this->size == 0)
        throw std::length_error("Error : List is empty.");
    else
        return tail->key; 
}

template <typename Data>
Data& List<Data>::operator [] (unsigned int index) const{
    if(index >= this->size || index < 0)
        throw std::out_of_range("Error : Index out of accepted range.");
    else{
        Node* temp = head;
        unsigned int counter = 0;

        while(counter < index){
            temp = temp->next;
            counter = counter + 1;
        }

        Data& tempData = temp->key;
        return tempData;
    }  
}

/* ************************************************************************** */

// inherited from MappableContainer
template <typename Data>
void List<Data>::Map(MapFunctor mapFunctor, void* parameter){
    MapPreOrder(mapFunctor, parameter, head);
}

// inherited from PreOrderMappableContainer
template <typename Data>
void List<Data>::MapPreOrder(MapFunctor mapFunctor, void* parameter){
    MapPreOrder(mapFunctor, parameter, head);
}
// inherited from PostOrderMappableContainer
template <typename Data>
void List<Data>::MapPostOrder(MapFunctor mapFunctor, void* parameter){
    MapPostOrder(mapFunctor, parameter, head);
}
// inherited from FoldableContainer
template <typename Data>
void List<Data>::Fold(FoldFunctor foldFunctor, const void* startValue, void* accumulator) const{
    FoldPreOrder(foldFunctor, startValue, accumulator, head);
}
// inherited from PreOrderFoldableContainer
template <typename Data>
void List<Data>::FoldPreOrder(FoldFunctor foldFunctor, const void* startValue, void* accumulator) const{
    FoldPreOrder(foldFunctor, startValue, accumulator, head);
}
// inherited from PostOrderFoldableContainer
template <typename Data>
void List<Data>::FoldPostOrder(FoldFunctor foldFunctor, const void* startValue, void* accumulator) const{
    FoldPostOrder(foldFunctor, startValue, accumulator, head);
}

// for PreOrderMappableContainer && PostOrderMappableContainer
template <typename Data>
void List<Data>::MapPreOrder(MapFunctor mapFunctor, void* parameter, Node* startNode){
    while(startNode != nullptr){
        mapFunctor(startNode->key, parameter);
        startNode = startNode->next;
    }
}

template <typename Data>
void List<Data>::MapPostOrder(MapFunctor mapFunctor, void* parameter, Node* startNode){
    if (startNode == nullptr){
        return;
    } else{
        MapPostOrder(mapFunctor, parameter, startNode->next);
        mapFunctor(startNode->key, parameter);
    }
}

// for PreOrderFoldableContainer && PostOrderFoldableContainer

template <typename Data>
void List<Data>::FoldPreOrder(FoldFunctor foldFunctor, const void* startValue, void* accumulator, Node* startNode) const{
    while(startNode != nullptr){
        foldFunctor(startNode->key, startValue, accumulator);
        startNode = startNode->next;
    }
}

template <typename Data>
void List<Data>::FoldPostOrder(FoldFunctor foldFunctor, const void* startValue,void* accumulator, Node* startNode) const{
    if (startNode == nullptr){
        return;
    } else{
        FoldPostOrder(foldFunctor, startValue, accumulator, startNode->next);
        foldFunctor(startNode->key, startValue, accumulator);
    }
}






/* ************************************************************************** */

}