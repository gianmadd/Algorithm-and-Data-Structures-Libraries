
namespace lasd {

/* ************************************************************************** */

// ...
template <>
class Hash<int> {
    public:

        unsigned long operator()(const int& data) const noexcept{
            return (data*data);
        }

};

template <>
class Hash<double> {
    public:

        unsigned long operator()(const double& data) const noexcept{
            long integerPart = floor(data);
            long fractionaryPart = pow(2,24) * (data - integerPart);
            return (integerPart * fractionaryPart);
        }
};

template <>
class Hash<std::string> {
    public:

        unsigned long operator()(const std::string& data) const noexcept{
            unsigned long hash = 5381;
            for(unsigned long i = 0; i < data.length(); i++){
                hash = (hash << 5) + data[i];
            }
            return hash;
        }

};

template <typename Data>
HashTable<Data>::HashTable(){
    A = Random(1);
    B = Random(0);
    tableSize = 64;
}

//Protected constructors and assignments
template <typename Data>
HashTable<Data>::HashTable(const HashTable<Data>& otherHashTable){
    size = otherHashTable.size;
    A = otherHashTable.A;
    B = otherHashTable.B;
    tableSize = otherHashTable.tableSize;
    primeNumber = otherHashTable.primeNumber;
    hash = otherHashTable.hash;
}

template <typename Data>
HashTable<Data>::HashTable(HashTable<Data>&& otherHashTable) noexcept{
    std::swap(size, otherHashTable.size);
    std::swap(A, otherHashTable.A);
    std::swap(B, otherHashTable.B);
    std::swap(tableSize, otherHashTable.tableSize);
    std::swap(primeNumber, otherHashTable.primeNumber);
    std::swap(hash, otherHashTable.hash);
}

template <typename Data>
HashTable<Data>& HashTable<Data>::operator = (const HashTable<Data>& otherHashTable){
    HashTable<Data>* temp = new HashTable(otherHashTable);

    std::swap(*this, *temp);

    delete temp;
    return *this;
}

template <typename Data>
HashTable<Data>& HashTable<Data>::operator = (HashTable<Data>&& otherHashTable) noexcept{
    std::swap(size, otherHashTable.size);
    std::swap(A, otherHashTable.A);
    std::swap(B, otherHashTable.B);
    std::swap(tableSize, otherHashTable.tableSize);
    std::swap(primeNumber, otherHashTable.primeNumber);
    std::swap(hash, otherHashTable.hash);

    return *this;
}

//
template <typename Data>
unsigned long HashTable<Data>::HashKey(const Data& data) const noexcept{
    return (((A * hash(data) +B ) % primeNumber) % tableSize);
}

template <typename Data>
unsigned long HashTable<Data>::Random(const int& startValue){
    std::default_random_engine genx(std::random_device{}());
    std::uniform_int_distribution<unsigned long> distx(startValue, primeNumber - 1);
    return distx(genx);
}

/* ************************************************************************** */

}
