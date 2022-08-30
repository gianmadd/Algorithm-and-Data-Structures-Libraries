
namespace lasd {

/* ************************************************************************** */

// ...
template <typename Data>
BST<Data>::BST(const LinearContainer<Data>& otherLinearContainer){

    for(int i = 0; i<otherLinearContainer.Size(); i++)
        Insert(otherLinearContainer[i]);

}

/* ************************************************************************** */

template <typename Data>
BST<Data>& BST<Data>::operator = (const BST<Data>& otherBst){
    BinaryTreeLnk<Data>::operator = (otherBst);
    return (*this);
}

template <typename Data>
BST<Data>& BST<Data>::operator = (BST<Data>&& otherBst) noexcept {
    BinaryTreeLnk<Data>::operator = (std::move(otherBst));
    return (*this);
}

template <typename Data>
bool BST<Data>::operator == (const BST<Data>& otherBst) const noexcept{
    if(size != otherBst.size)
        return false;
    else
        if(size == 0)
            return true;

        else{
            BTInOrderIterator<Data> myIterator(*this); 
            BTInOrderIterator<Data> otherIterator(otherBst);

            while(!myIterator.Terminated()){
                if(*myIterator != *otherIterator)
                    return false;
                ++myIterator;
                ++otherIterator;
            }

            return true;
        }
}

template <typename Data>
bool BST<Data>::operator != (const BST<Data>& otherBst) const noexcept{
    if(*this == otherBst)
        return false;
    else
        return true;
}

/* ************************************************************************** */

template <typename Data>
const Data& BST<Data>::Min() const{
    return const_cast<Data&>(static_cast<const Data&>(this)->Min());
}

template <typename Data>
Data& BST<Data>::Min(){
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    else{
        return (FindPointerToMin(root))->key;
    }
}

template <typename Data>
Data BST<Data>::MinNRemove(){
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    else{
        return DataNDelete(DetachMin(root));
    }
}

template <typename Data>
void BST<Data>::RemoveMin(){
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    else
        delete DetachMin(root);
    
}

/* ************************************************************************** */

template <typename Data>
const Data& BST<Data>::Max() const{
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    return const_cast<Data&>(static_cast<const Data&>(this)->Max());
}

template <typename Data>
Data& BST<Data>::Max(){
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    else{
        return (FindPointerToMax(root))->key;
    }
}

template <typename Data>
Data BST<Data>::MaxNRemove(){
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    else{
        return DataNDelete(DetachMax(root));
    }
}

template <typename Data>
void BST<Data>::RemoveMax(){
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    else
        delete DetachMax(root);
}

/* ************************************************************************** */

template <typename Data>
const Data& BST<Data>::Predecessor(const Data& data) const{
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    return const_cast<Data&>(static_cast<const Data&>(this)->Predecessor());
}

template <typename Data>
Data& BST<Data>::Predecessor(const Data& data){
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    else{
        struct BST<Data>::NodeLnk* const* result = FindPointerToPredecessor(root, data);
        if(result != nullptr)
            return (*(result))->key;
        else
            throw std::length_error("Error : Predecessor not found.");
    }
}

template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& data){
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    else{
        struct BST<Data>::NodeLnk** tempPredecessor = FindPointerToPredecessor(root, data);
        if(tempPredecessor != nullptr)
            return DataNDelete(Detach(*tempPredecessor));
        else
            throw std::length_error("Error : Predecessor not found.");

    }
}

template <typename Data>
void BST<Data>::RemovePredecessor(const Data& data){
    if(size == 0)
        throw std::length_error("Error : BST is Empty."); 
    else{
        struct BST<Data>::NodeLnk** tempPredecessor = FindPointerToPredecessor(root, data);
        if(tempPredecessor != nullptr)
            delete Detach(*tempPredecessor);
        else
            throw std::length_error("Error : Predecessor not found.");
    } 
}

/* ************************************************************************** */

template <typename Data>
const Data& BST<Data>::Successor(const Data& data) const{
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    return const_cast<Data&>(static_cast<const Data&>(this)->Successor());
}

template <typename Data>
Data& BST<Data>::Successor(const Data& data){
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    else{
        struct BST<Data>::NodeLnk* const* result = FindPointerToSuccessor(root, data);
        if(result != nullptr)
            return (*(result))->key;
        else
            throw std::length_error("Error : Successor not found.");
        
    }
}

template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& data){
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    else{
        struct BST<Data>::NodeLnk** tempSuccessor = FindPointerToSuccessor(root, data);
        if(tempSuccessor != nullptr)
            return DataNDelete(Detach(*tempSuccessor));
        else
            throw std::length_error("Error : Successor not found.");
    }
}

template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& data){
    if(size == 0)
        throw std::length_error("Error : BST is Empty.");
    else{
        struct BST<Data>::NodeLnk** tempSuccessor = FindPointerToSuccessor(root, data);
        if(tempSuccessor != nullptr)
            delete Detach(*tempSuccessor);
        else
            throw std::length_error("Error : Successor not found.");
            
    }
}

/* ************************************************************************** */

template <typename Data>
bool BST<Data>::Insert(const Data& data){

    struct BST<Data>::NodeLnk*& tempPointer = FindPointerTo(root, data);
    if(tempPointer == nullptr){
        tempPointer = new struct BST<Data>::NodeLnk(data);
        size = size + 1;
        return true;
    }
    else
        return false;

}

template <typename Data>
bool BST<Data>::Insert(Data&& data){
    //..

    struct BST<Data>::NodeLnk*& tempPointer = FindPointerTo(root, data);
    if(tempPointer == nullptr){
        tempPointer = new struct BST<Data>::NodeLnk(std::move(data));
        size = size + 1;
        return true;
    }
    else
        return false;
}

template <typename Data>
bool BST<Data>::Remove(const Data& data){
    //..

    int tempSize = size;
    delete Detach(FindPointerTo(root, data));
    return (tempSize != size);

}

template <typename Data>
bool BST<Data>::Exists(const Data& data) const noexcept{
    if(size == 0)
        return false;
    else{

        struct BST<Data>::NodeLnk* resultExists = FindPointerTo(root, data);

        if(resultExists != nullptr)
            return true;
        else
            return false;
    }
}

/* ************************************************************************** */

template <typename Data>
Data BST<Data>::DataNDelete(struct BST<Data>::NodeLnk* nodeLnk){
 
    Data tempKey = nodeLnk->key;
    delete nodeLnk;
    return tempKey;

}

template <typename Data>
struct BST<Data>::NodeLnk* BST<Data>::Detach(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{

    if(nodeLnk == nullptr)
        return nullptr;
    
    if(nodeLnk->left != nullptr && nodeLnk->right != nullptr){
        //entrambi i figli
        struct BST<Data>::NodeLnk* temp = DetachMin(nodeLnk->right);
        std::swap(nodeLnk->key, temp->key);
        return temp;
    }
    else
        if(nodeLnk->left != nullptr)
            //solo figlio sx
            return Skip2Left(nodeLnk);
        else if(nodeLnk->right != nullptr)
        //solo figlio dx
            return Skip2Right(nodeLnk);
        else
            return DetachMin(nodeLnk);

    
}

template <typename Data>
struct BST<Data>::NodeLnk* BST<Data>::DetachMin(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{

    if(size != 0){
        return Skip2Right(FindPointerToMin(nodeLnk));
    }
    return nullptr;

}

template <typename Data>
struct BST<Data>::NodeLnk* BST<Data>::DetachMax(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{
    
    if(size != 0){
        return Skip2Left(FindPointerToMax(nodeLnk));
    }
    return nullptr;

}

/* ************************************************************************** */

template <typename Data>
struct BST<Data>::NodeLnk* BST<Data>::Skip2Left(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{
    struct BST<Data>::NodeLnk* leftChild = nullptr;
    if(nodeLnk != nullptr){
        std::swap(leftChild, nodeLnk->left);
        std::swap(leftChild, nodeLnk);
        size = size - 1;
    }
    return leftChild;
}

template <typename Data>
struct BST<Data>::NodeLnk* BST<Data>::Skip2Right(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{
    struct BST<Data>::NodeLnk* rightChild = nullptr;
    if(nodeLnk != nullptr){
        std::swap(rightChild, nodeLnk->right);
        std::swap(rightChild, nodeLnk);
        size = size - 1;
    }
    return rightChild;
}

/* ************************************************************************** */

template <typename Data>
struct BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{
    return const_cast<struct BST<Data>::NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(nodeLnk));
}

template <typename Data>
struct BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(struct BST<Data>::NodeLnk* const& nodeLnk) const noexcept{

    struct BST<Data>::NodeLnk* const* pointerToMin = &nodeLnk;
    struct BST<Data>::NodeLnk* temp = nodeLnk;

    if(temp != nullptr){
        while(temp->left != nullptr){
            pointerToMin = &(temp->left);
            temp = temp->left;
        }
    }
    return *pointerToMin;
}

template <typename Data>
struct BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{
    return const_cast<struct BST<Data>::NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMax(nodeLnk));
}

template <typename Data>
struct BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(struct BST<Data>::NodeLnk* const& nodeLnk) const noexcept{

    struct BST<Data>::NodeLnk* const* pointerToMax = &nodeLnk;
    struct BST<Data>::NodeLnk* temp = nodeLnk;

    if(temp != nullptr){
        while(temp->right != nullptr){
            pointerToMax = &(temp->right);
            temp = temp->right;
        }
    }
    return *pointerToMax;
}

/* ************************************************************************** */

template <typename Data>
struct BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(struct BST<Data>::NodeLnk*& nodeLnk, const Data& data) noexcept{
    return const_cast<struct BST<Data>::NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(nodeLnk, data));
}

template <typename Data>
struct BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(struct BST<Data>::NodeLnk* const& nodeLnk, const Data& data) const noexcept{
    
    struct BST<Data>::NodeLnk* const* pointerToNode = &nodeLnk;
    struct BST<Data>::NodeLnk* temp = nodeLnk;

    while(temp != nullptr){
        if(temp->key == data)
            temp = nullptr;
        else
            if(temp->key < data){
                pointerToNode = &(temp->right);
                temp = temp->right;
            }
            else{
                pointerToNode = &(temp->left);
                temp = temp->left;
            } 
    }
    return *pointerToNode;
}

/* ************************************************************************** */

template <typename Data>
struct BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(struct BST<Data>::NodeLnk*& nodeLnk, const Data& data) noexcept{
    return const_cast<struct BST<Data>::NodeLnk**>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(nodeLnk, data));
}

template <typename Data>
struct BST<Data>::NodeLnk* const* BST<Data>::FindPointerToPredecessor(struct BST<Data>::NodeLnk* const& nodeLnk, const Data& data) const noexcept{
    
    struct BST<Data>::NodeLnk* const* temporaryPredecessor = &nodeLnk;
    struct BST<Data>::NodeLnk* const* pointerToPredecessor = nullptr;

    while(true){

        struct BST<Data>::NodeLnk& temp = **temporaryPredecessor;

        if(temp.key == data)
            if(temp.left != nullptr)
                return &FindPointerToMax(temp.left);
            else
                return pointerToPredecessor;
        else{
            if(temp.key < data){
                pointerToPredecessor = temporaryPredecessor;
                if(temp.right != nullptr)
                    temporaryPredecessor = &temp.right;
                else
                    return pointerToPredecessor;
            }
            else{
                if(temp.left != nullptr)
                    temporaryPredecessor = &temp.left;
                else
                    return pointerToPredecessor;
            }
        }
    } 
}

template <typename Data>
struct BST<Data>::NodeLnk** BST<Data>::FindPointerToSuccessor(struct BST<Data>::NodeLnk*& nodeLnk, const Data& data) noexcept{
    return const_cast<struct BST<Data>::NodeLnk**>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(nodeLnk, data));
}

template <typename Data>
struct BST<Data>::NodeLnk* const* BST<Data>::FindPointerToSuccessor(struct BST<Data>::NodeLnk* const& nodeLnk, const Data& data) const noexcept{
    
    struct BST<Data>::NodeLnk* const* temporarySuccessor = &nodeLnk;
    struct BST<Data>::NodeLnk* const* pointerToSuccessor = nullptr;

    while(true){

        struct BST<Data>::NodeLnk& temp = **temporarySuccessor;

        if(temp.key == data)
            if(temp.right != nullptr)
                return &FindPointerToMin(temp.right);
            else
                return pointerToSuccessor;
        else{
            if(temp.key < data){
                if(temp.right != nullptr)
                    temporarySuccessor = &temp.right;
                else
                    return pointerToSuccessor;
            }
            else{
                pointerToSuccessor = temporarySuccessor;
                if(temp.left != nullptr)
                    temporarySuccessor = &temp.left;
                else
                    return pointerToSuccessor; 
            }
        }
    }
   
}

/* ************************************************************************** */


}

/* ************************************************************************** */


