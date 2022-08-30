
namespace lasd {

/* ************************************************************************** */

// ...

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){
    delete right;
    delete left;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& data, NodeLnk* leftNode, NodeLnk* rightNode){
    key = data;
    left = leftNode;
    right = rightNode;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& otherData){
    this->key = otherData;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& otherData) noexcept{
    std::swap(this->key, otherData);
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const struct BinaryTreeLnk<Data>::NodeLnk& otherNodeLnk){
    this->key = otherNodeLnk.key;

    if(otherNodeLnk.HasLeftChild())
        this->left = new NodeLnk(otherNodeLnk.LeftChild());

    if(otherNodeLnk.HasRightChild())
        this->right = new NodeLnk(otherNodeLnk.RightChild());

}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(struct BinaryTreeLnk<Data>::NodeLnk&& otherNodeLnk) noexcept{
    std::swap(this->key, otherNodeLnk.key);
    std::swap(this->left, otherNodeLnk.left);
    std::swap(this->right, otherNodeLnk.right);
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept{
    if(this->left == nullptr && this->right == nullptr)
        return true;
    else
        return false;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
    if(this->left != nullptr)
        return true;
    else
        return false;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{
    if(this->right != nullptr)
        return true;
    else
        return false;
}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild(){
    if(!this->HasLeftChild())
        throw std::out_of_range("Error : Left Child Missing");
    else
        return *(this->left);
}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild(){
    if(!this->HasRightChild())
        throw std::out_of_range("Error : Right Child Missing");
    else
        return *(this->right);
}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
    if(!this->HasLeftChild())
        throw std::out_of_range("Error : Left Child Missing");
    else
        return *(this->left);
}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
    if(!this->HasRightChild())
        throw std::out_of_range("Error : Right Child Missing");
    else
        return *(this->right);
}


/* ************************************************************************** */

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& otherLinearContainer){
    
    if(otherLinearContainer.Size() == 0)
        return;

    else{

        int currentIndex = 0;

        root = TreeFromLinearContainer(otherLinearContainer, currentIndex);

        this->size = otherLinearContainer.Size();

    }

}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& otherBinaryTreeLnk){
    if(otherBinaryTreeLnk.size != 0)
        this->root = new NodeLnk(otherBinaryTreeLnk.Root());
    this->size = otherBinaryTreeLnk.size;

}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& otherBinaryTreeLnk) noexcept{
    std::swap(otherBinaryTreeLnk.size, size);
    std::swap(otherBinaryTreeLnk.root, root);
}

template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk(){
    delete this->root;
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator = (const BinaryTreeLnk<Data>& otherBinaryTreeLnk){

    BinaryTreeLnk<Data>* temp = new BinaryTreeLnk(otherBinaryTreeLnk);

    std::swap(root, temp->root);
    std::swap(this->size, temp->size);

    delete temp;
    return (*this);
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator = (BinaryTreeLnk<Data>&& otherBinaryTreeLnk) noexcept{

    std::swap(root, otherBinaryTreeLnk.root);
    std::swap(this->size, otherBinaryTreeLnk.size);

    return (*this);
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator == (const BinaryTreeLnk<Data>& otherBinaryTreeLnk) const noexcept{
    if(this->Root() == otherBinaryTreeLnk.Root())
        return true;
    else
        return false;
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator != (const BinaryTreeLnk<Data>& otherBinaryTreeLnk) const noexcept{
    if(*this == otherBinaryTreeLnk)
        return false;
    else
        return true;
}

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const{
    if(this->size == 0)
        throw std::length_error("Error : Tree is Empty");
    else
        return *(this->root);
}

template <typename Data>
void BinaryTreeLnk<Data>::Clear(){
    delete this->root;
    this->root = nullptr;
    this->size = 0;
}

//Auxiliary function (tree building from a linear container)

template <typename Data>
struct BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::TreeFromLinearContainer(const LinearContainer<Data>& linearContainer, int currentIndex){

    NodeLnk* tempLeft = nullptr;
    NodeLnk* tempRight = nullptr;

    if(linearContainer.Size() > (currentIndex*2 + 1))
        tempLeft = TreeFromLinearContainer(linearContainer, (currentIndex*2 + 1));

    if(linearContainer.Size() > (currentIndex*2 + 2))  
        tempRight = TreeFromLinearContainer(linearContainer, (currentIndex*2 + 2));

    NodeLnk* node = new NodeLnk(linearContainer[currentIndex]);
    node->left = tempLeft;
    node->right = tempRight;

    return node;
    
}


}
