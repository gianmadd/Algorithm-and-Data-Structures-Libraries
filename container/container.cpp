
namespace lasd {

/* ************************************************************************** */

// ...
//DictionaryContainer
template <typename Data>
void DictionaryContainer<Data>::Insert(const LinearContainer<Data>& otherLinearContainer){
    for(int i = 0; i<otherLinearContainer.Size(); i++){
        Insert(otherLinearContainer[i]);
    }
}

template <typename Data>
void DictionaryContainer<Data>::Insert(LinearContainer<Data>&& otherLinearContainer) noexcept {
    for(int i = 0; i<otherLinearContainer.Size(); i++){
        Insert(std::move(otherLinearContainer[i]));
    }
}

template <typename Data>
void DictionaryContainer<Data>::Remove(const LinearContainer<Data>& otherLinearContainer){
    for(int i = 0; i<otherLinearContainer.Size(); i++){
        Remove(otherLinearContainer[i]);
    }
}

// LinearContainer

template <typename Data>
bool LinearContainer<Data>::operator == (const LinearContainer<Data>& secondLinearContainer) const noexcept{
    if(size != secondLinearContainer.size)
        return false;
    else{
        for(unsigned int i = 0; i<size; i++){
            if ((*this)[i] != secondLinearContainer[i])
                return false;
        }
        return true;
    }
}

template <typename Data>
bool LinearContainer<Data>::operator != (const LinearContainer<Data>& secondLinearContainer) const noexcept{
    if ((*this) == secondLinearContainer)
        return false;
    else 
        return true;
}

template <typename Data>
Data& LinearContainer<Data>::Front() const {
    if (size == 0)
        throw std::length_error("errore");
    else
        return (*this)[0];
}

template <typename Data>
Data& LinearContainer<Data>::Back() const {
    if (size == 0)
        throw std::length_error("errore");
    return (*this)[size-1];
}

/* ************************************************************************** */

// FoldableContainer

template <typename Data>
void TestExists(const Data& myData, const void* otherData, void* returnValue) noexcept{
    if (myData == *(static_cast<const Data*>(otherData))){
        *(static_cast<bool*>(returnValue)) = true;
    }   
}

template <typename Data>
bool FoldableContainer<Data>::Exists(const Data& myData) const noexcept {
    bool returnValue = false;
    Fold(&TestExists<Data>, &myData, &returnValue);
    return returnValue;
}

// PreOrderMappableContainer

template <typename Data>
void PreOrderMappableContainer<Data>::Map(MapFunctor mapFunctor, void* startValue){
    MapPreOrder(mapFunctor, startValue);
}

// PreOrderFoldableContainer

template <typename Data>
void PreOrderFoldableContainer<Data>::Fold(FoldFunctor foldFunctor, const void* toFindValue, void* startValue) const{
    FoldPreOrder(foldFunctor, toFindValue, startValue);
}


// PostOrderMappableContainer

template <typename Data>
void PostOrderMappableContainer<Data>::Map(MapFunctor mapFunctor, void* startValue){
    MapPostOrder(mapFunctor, startValue);
}

// PostOrderFoldableContainer

template <typename Data>
void PostOrderFoldableContainer<Data>::Fold(FoldFunctor foldFunctor, const void* toFindValue, void* startValue) const{
    FoldPostOrder(foldFunctor, toFindValue, startValue);
}

// InOrderMappableContainer

template <typename Data>
void InOrderMappableContainer<Data>::Map(MapFunctor mapFunctor, void* startValue){
    MapInOrder(mapFunctor, startValue);
}

// InOrderFoldableContainer

template <typename Data>
void InOrderFoldableContainer<Data>::Fold(FoldFunctor foldFunctor, const void* toFindValue, void* startValue) const{
    FoldInOrder(foldFunctor, toFindValue, startValue);
}

// BreadthMappableContainer

template <typename Data>
void BreadthMappableContainer<Data>::Map(MapFunctor mapFunctor, void* startValue){
    MapBreadth(mapFunctor, startValue);
}

// BreadthFoldableContainer

template <typename Data>
void BreadthFoldableContainer<Data>::Fold(FoldFunctor foldFunctor, const void* toFindValue, void* startValue) const{
    FoldBreadth(foldFunctor, toFindValue, startValue);
}


/* ************************************************************************** */

}
