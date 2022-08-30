
namespace lasd {

/* ************************************************************************** */

// ...

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(){
    vector = Vector<BST<Data>>(tableSize);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned int& newSize){
    tableSize = newSize;
    vector = Vector<BST<Data>>(newSize);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data>& otherLinearContainer){
    vector = Vector<BST<Data>>(tableSize);
    DictionaryContainer<Data>::Insert(otherLinearContainer);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const unsigned int& newSize, const LinearContainer<Data>& otherLinearContainer){
    tableSize = newSize;
    vector = Vector<BST<Data>>(newSize);
    DictionaryContainer<Data>::Insert(otherLinearContainer);

}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& otherHashTableClsAdr) : HashTable<Data>::HashTable(otherHashTableClsAdr){
    vector = Vector<BST<Data>>(otherHashTableClsAdr.vector);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& otherHashTableClsAdr) noexcept : HashTable<Data>::HashTable(std::move(otherHashTableClsAdr)){
    std::swap(vector, otherHashTableClsAdr.vector);
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator = (const HashTableClsAdr<Data>& otherHashTableClsAdr){

    HashTableClsAdr<Data>* tempHashClsAdr = new HashTableClsAdr(otherHashTableClsAdr);

    std::swap(*this, *tempHashClsAdr);

    delete tempHashClsAdr;
    return *this;

}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator = (HashTableClsAdr<Data>&& otherHashTableClsAdr) noexcept{

    HashTable<Data>::operator = (std::move(otherHashTableClsAdr));

    std::swap(vector, otherHashTableClsAdr.vector);

    return *this;
}

template <typename Data>
void SpecificFoldComparisonClsAdr(const Data& data, const void* chainingStructure, void* result){
    if(!((static_cast<const BST<Data>*>(chainingStructure))->Exists(data)))
        *(static_cast<bool*>(result)) = false;
}
 
template <typename Data>
bool HashTableClsAdr<Data>::operator == (const HashTableClsAdr<Data>& otherHashTableClsAdr) const noexcept{
    //tramite fold

    if(size != otherHashTableClsAdr.size)
        return false;
    else
        if(size == 0)
            return true;
        else{
            bool defaultValue = true;
            unsigned int sizeValue = 0;

            while(defaultValue && sizeValue < size){
                Fold(SpecificFoldComparisonClsAdr<Data>, &otherHashTableClsAdr, &defaultValue);
                sizeValue = sizeValue + 1;
            }

            if(defaultValue){
                sizeValue = 0;
                while(defaultValue && sizeValue < size){
                    Fold(SpecificFoldComparisonClsAdr<Data>, this, &defaultValue);
                    sizeValue = sizeValue + 1;
                }
            }

            return defaultValue;
                
        }
}

template <typename Data>
bool HashTableClsAdr<Data>::operator != (const HashTableClsAdr<Data>& otherHashTableClsAdr) const noexcept{
    if(*this == otherHashTableClsAdr)
        return false;
    else
        return true;
}

template <typename Data>
void SpecificMapResizeClsAdr(const Data& data, void* hashTableClsAdr){
    (static_cast<HashTableClsAdr<Data>*>(hashTableClsAdr))->Insert(data);
}

template <typename Data>
void HashTableClsAdr<Data>::Resize(const unsigned int& newSize){
    //tramite map

    if(newSize == 0)
        return;

    HashTableClsAdr<Data>* tempHashTableClsAdr = new HashTableClsAdr(newSize);

    Map(SpecificMapResizeClsAdr<Data>, tempHashTableClsAdr);

    std::swap(*this, *tempHashTableClsAdr);

    delete tempHashTableClsAdr;

}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& newData){
    if(vector[HashKey(newData)].Insert(newData)){
        size = size + 1;
        return true;
    } 
    else
        return false;
        
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& newData){
    if(vector[HashKey(newData)].Insert(std::move(newData))){
        size = size + 1;
        return true;
    }
    else
        return false;
        
}

template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& newData){
    if(vector[HashKey(newData)].Remove(newData)){
        size = size - 1;
        return true;
    }
    else
        return false;
        
}

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept{
    if(vector[HashKey(data)].Exists(data))
        return true;
    else
        return false;
} 

template <typename Data>
void HashTableClsAdr<Data>::Map(MapFunctor mapFunctor, void* parameter){
    for(int i = 0; i < tableSize; i++)
        vector[i].Map(mapFunctor, parameter);      
}

template <typename Data>
void HashTableClsAdr<Data>::Fold(FoldFunctor foldFunctor, const void* parameter, void* accumulator) const{
    for(int i = 0; i < this->tableSize; i++)
        vector[i].Fold(foldFunctor, parameter, accumulator);
}

template <typename Data>
void HashTableClsAdr<Data>::Clear(){
    HashTableClsAdr<Data>* tempHashClsAdr = new HashTableClsAdr<Data>();

    std::swap(*this, *tempHashClsAdr);

    delete tempHashClsAdr;

}


//Auxiliary Functions



/* ************************************************************************** */

}
