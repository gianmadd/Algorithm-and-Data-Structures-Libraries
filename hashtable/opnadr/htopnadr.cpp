#include <cmath>

namespace lasd {

/* ************************************************************************** */

// ...
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(){

    InitVector(flagVector);
    InitVector(vector);

}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned int& newSize){
    
    // unsigned int tempSize = 64;

    // if(newSize > 64){
    //     int exponent = 6;
    //     while(newSize > std::pow(2,exponent))
    //         exponent = exponent + 1;
    //     tempSize = std::pow(2,exponent);
    // }

    unsigned int exponent = CalculateExponent(newSize);

    unsigned int tempSize = std::pow(2, exponent);

    tableSize = tempSize;
    vector.Resize(tableSize);
    flagVector.Resize(tableSize);

    InitVector(flagVector);
    InitVector(vector);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const LinearContainer<Data>& otherLinearContainer){

    // unsigned int tempSize = 64;

    // if(otherLinearContainer.Size() > 64){
    //     int exponent = 6;
    //     while(otherLinearContainer.Size() > std::pow(2,exponent))
    //         exponent = exponent + 1;
    //     tempSize = std::pow(2,exponent);
    // }

    unsigned int exponent = CalculateExponent(otherLinearContainer.Size());

    unsigned int tempSize = std::pow(2, exponent);
    
    tableSize = tempSize;
    vector.Resize(tableSize);
    flagVector.Resize(tableSize);
    InitVector(flagVector);
    InitVector(vector);

    DictionaryContainer<Data>::Insert(otherLinearContainer);

    
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const unsigned int& newSize, const LinearContainer<Data>& otherLinearContainer){

    // unsigned int tempSize = 64;

    // if(newSize > 64){
    //     int exponent = 6;
    //     while(newSize > std::pow(2,exponent))
    //         exponent = exponent + 1;
    //     tempSize = std::pow(2,exponent);
    // }

    unsigned int exponent = CalculateExponent(newSize);

    unsigned int tempSize = std::pow(2, exponent);

    tableSize = tempSize;
    vector.Resize(tableSize);
    flagVector.Resize(tableSize);

    InitVector(flagVector);
    InitVector(vector);

    DictionaryContainer<Data>::Insert(otherLinearContainer);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& otherHashTableOpnAdr) : HashTable<Data>::HashTable(otherHashTableOpnAdr){
    vector = otherHashTableOpnAdr.vector;
    flagVector = otherHashTableOpnAdr.flagVector;
    counterDeleted = otherHashTableOpnAdr.counterDeleted;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& otherHashTableOpnAdr) noexcept : HashTable<Data>::HashTable(std::move(otherHashTableOpnAdr)){
    std::swap(vector, otherHashTableOpnAdr.vector);
    std::swap(flagVector, otherHashTableOpnAdr.flagVector);
    std::swap(counterDeleted, otherHashTableOpnAdr.counterDeleted);
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator = (const HashTableOpnAdr<Data>& otherHashTableOpnAdr){

    HashTableOpnAdr<Data>* tempHashOpnAdr = new HashTableOpnAdr(otherHashTableOpnAdr);

    std::swap(*this, *tempHashOpnAdr);

    delete tempHashOpnAdr;
    return *this;
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator = (HashTableOpnAdr<Data>&& otherHashTableOpnAdr) noexcept{

    HashTable<Data>::operator = (std::move(otherHashTableOpnAdr));

    std::swap(vector, otherHashTableOpnAdr.vector);
    std::swap(flagVector, otherHashTableOpnAdr.flagVector);
    std::swap(counterDeleted, counterDeleted);

    return *this;
}

template <typename Data>
void SpecificFoldComparisonOpnAdr(const Data& data, const void* otherHashTableOpnAdr, void* result){
    if(!((static_cast<const HashTableOpnAdr<Data>*>(otherHashTableOpnAdr))->Exists(data)))
        *(static_cast<bool*>(result)) = false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator == (const HashTableOpnAdr<Data>& otherHashTableOpnAdr) const noexcept{
    //tramite fold

    if(size != otherHashTableOpnAdr.size)
        return false;
    else
        if(size == 0)
            return true;
        else{
            bool defaultValue = true;
        
            Fold(SpecificFoldComparisonOpnAdr<Data>, &otherHashTableOpnAdr, &defaultValue);

            if(defaultValue)
                otherHashTableOpnAdr.Fold(SpecificFoldComparisonOpnAdr<Data>, this, &defaultValue);

            return defaultValue;
                         
        }
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator != (const HashTableOpnAdr<Data>& otherHashTableOpnAdr) const noexcept{
    if(*this == otherHashTableOpnAdr)
        return false;
    else
        return true;
}

template <typename Data>
void SpecificMapResizeOpnAdr(const Data& data, void* hashTableOpnAdr){
    (static_cast<HashTableOpnAdr<Data>*>(hashTableOpnAdr))->Insert(data);
}

template <typename Data>
void HashTableOpnAdr<Data>::Resize(const unsigned int& newSize){

    // unsigned int tempSize = 64;

    // if(newSize > 64){
    //     int exponent = 6;
    //     while(newSize > std::pow(2,exponent))
    //         exponent = exponent + 1;
    //     tempSize = std::pow(2,exponent);
    // }

    unsigned int exponent = CalculateExponent(newSize);

    unsigned int tempSize = std::pow(2, exponent);

    HashTableOpnAdr<Data>* tempHashTableOpnAdr = new HashTableOpnAdr(tempSize);

    Map(SpecificMapResizeOpnAdr<Data>, tempHashTableOpnAdr);

    std::swap(*this, *tempHashTableOpnAdr);

    delete tempHashTableOpnAdr;


}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& newData){

    if((size + counterDeleted) >= tableSize/2)
        Resize(tableSize * 2);

    unsigned int freeIndex = 0;

    // if(!Exists(newData))
    //     freeIndex = FindEmpty(newData, freeIndex);
    // else
    //     freeIndex = tableSize;

    // if(freeIndex == tableSize)
    //     return false; // caso in cui il dato è trovato prima di trovare cella libera   
    // else{ 

    //     vector[freeIndex] = newData;
    //     flagVector[freeIndex] = 1;
    //     size = size + 1;
        
    //     return true;
    // }

    freeIndex = FindEmpty(newData, freeIndex);

    if(freeIndex == tableSize)
        return false;
    else{
        unsigned int tempValue = HashKey(newData, freeIndex);
        vector[tempValue] = newData;
        flagVector[tempValue] = 1;
        size = size + 1;

        unsigned int indexIfAlreadyExists = 0;

        freeIndex = freeIndex + 1;

        indexIfAlreadyExists = Find(newData, freeIndex);

        tempValue = HashKey(newData, indexIfAlreadyExists);

        if(indexIfAlreadyExists != tableSize)
            if(flagVector[tempValue] == 1)  
                Remove(newData, indexIfAlreadyExists);
        
        return true;
    }

}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& newData){

    if((size + counterDeleted) >= tableSize/2)
        Resize(tableSize * 2);

    unsigned int freeIndex = 0;

    // if(!Exists(newData))
    //     freeIndex = FindEmpty(newData, freeIndex);
    // else
    //     freeIndex = tableSize;

    // if(freeIndex == tableSize)
    //     return false; // caso in cui il dato è trovato prima di trovare cella libera   
    // else{ 

    //     vector[freeIndex] = std::move(newData);
    //     flagVector[freeIndex] = 1;
    //     size = size + 1;
        
    //     return true;

    // }

    freeIndex = FindEmpty(newData, freeIndex);

    if(freeIndex == tableSize)
        return false;
    else{
        unsigned int tempValue = HashKey(newData, freeIndex);
        vector[tempValue] = std::move(newData);
        flagVector[tempValue] = 1;
        size = size + 1;

        unsigned int indexIfAlreadyExists = 0;

        freeIndex = freeIndex + 1;

        indexIfAlreadyExists = Find(newData, freeIndex);

        tempValue = HashKey(newData, indexIfAlreadyExists);

        if(indexIfAlreadyExists != tableSize)
            if(flagVector[tempValue] == 1)  
                Remove(newData, indexIfAlreadyExists);
        
        return true;
    }
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& newData){

    unsigned int i = 0;

    if(Remove(newData, i))
        return true;
    else
        return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& data) const noexcept{

    unsigned int i = 0;

    if(Find(data, i) == tableSize)
        return false;
    else
        return true;
} 

template <typename Data>
void HashTableOpnAdr<Data>::Map(MapFunctor mapFunctor, void* parameter){
    for(int i = 0; i<tableSize; i++){
        if(flagVector[i] == 1)
            mapFunctor(vector[i], parameter);
    }
}

template <typename Data>
void HashTableOpnAdr<Data>::Fold(FoldFunctor foldFunctor, const void* parameter, void* accumulator) const{
    for(int i = 0; i<tableSize; i++){
        if(flagVector[i] == 1)
            foldFunctor(vector[i], parameter, accumulator);
    }
}

template <typename Data>
void HashTableOpnAdr<Data>::Clear(){
    HashTableOpnAdr<Data>* tempHashTableOpnAdr = new HashTableOpnAdr<Data>();

    std::swap(*this, *tempHashTableOpnAdr);

    delete tempHashTableOpnAdr;
}

//Auxiliary functions

template <typename Data>
void HashTableOpnAdr<Data>::InitVector(Vector<short>& vector){
    for (int i = 0; i<vector.Size(); i++)
        vector[i] = 0;
}

template <typename Data>
void HashTableOpnAdr<Data>::InitVector(Vector<int>& vector){
    for (int i = 0; i<vector.Size(); i++)
        vector[i] = 0;
}

template <typename Data>
void HashTableOpnAdr<Data>::InitVector(Vector<double>& vector){
    for (int i = 0; i<vector.Size(); i++)
        vector[i] = 0;
}

template <typename Data>
void HashTableOpnAdr<Data>::InitVector(Vector<std::string>& vector){
    for (int i = 0; i<vector.Size(); i++)
        vector[i] = "";
}

template <typename Data>
unsigned int HashTableOpnAdr<Data>::Find(const Data& data, unsigned int& index) const noexcept{

    unsigned int tempValue = 0;

    while(index < tableSize){
        tempValue = HashKey(data, index);

        if(vector[tempValue] == data)
            if(flagVector[tempValue] == 1)
                return tempValue;

        index = index + 1;
    }
    
    return tableSize;
    
}

template <typename Data>
unsigned int HashTableOpnAdr<Data>::FindEmpty(const Data& data, unsigned int& index) const noexcept{

    unsigned int tempValue = 0;

    while(index < tableSize){
        tempValue = HashKey(data, index);

        if(flagVector[tempValue] == 0 || flagVector[tempValue]==2)
            return index;
        else
            if(vector[tempValue] == data && flagVector[tempValue]==1)
                return tableSize;
            else
                index = index + 1;
    }

    return tableSize;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data, unsigned int& i){

    unsigned int index = Find(data, i);

    if(index != tableSize){
        size = size - 1;
        counterDeleted = counterDeleted + 1;
        flagVector[index] = 2;

        unsigned int numberOfElements = size + counterDeleted;

        if(tableSize > 64)
            Resize(tableSize / 2);

        return true;

    } else
        return false;

} 

template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const Data& data, unsigned int& index) const noexcept{
    // h(k,i) = (h(k) + c * i)mod(n) 
    //c ed n coprimi (n è sempre potenza di 2)
 
    return ((HashTable<Data>::HashKey(data) + (primeNumber * index)) % tableSize);
}

template <typename Data>
unsigned int HashTableOpnAdr<Data>::CalculateExponent(const unsigned int& newSize){
    if(newSize <= 64)
        return 6;
    else
        return static_cast<unsigned int>(std::ceil(std::log2(newSize)));
}

}

/* ************************************************************************** */


