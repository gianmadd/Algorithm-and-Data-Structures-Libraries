
// ...


#include <iostream>
#include <string>

#include <climits>
#include <random>

#include "../zlasdtest/test.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"

void TestPrint(){
    std::cout << std::endl << "Available Tests" << std::endl;
    std::cout << "1) Professor Test" << std::endl;
    std::cout << "2) Student Test" << std::endl;
    std::cout << "3) Exit" << std::endl;
}

void DataStructurePrint(){
    std::cout << std::endl << "Available Data Structures" << std::endl;
    std::cout << "1) Hash Table - Closed Addressing" << std::endl;
    std::cout << "2) Hash Table - Open Addressing" << std::endl;
    std::cout << "3) Exit " << std::endl;
}

void TypePrint(){
    std::cout << std::endl << "Available Types" << std::endl;
    std::cout << "1) Integers" << std::endl;
    std::cout << "2) Floats" << std::endl;
    std::cout << "3) Strings " << std::endl;
    std::cout << "4) Exit " << std::endl;
}

void DataStructureOperationPrint(){
    std::cout << std::endl << "Available Operations" << std::endl;
    std::cout << "1) Print all the Elements " << std::endl;
    std::cout << "2) Check existance of a Value" << std::endl;
    std::cout << "3) Specific Fold" << std::endl;
    std::cout << "4) Insert a Value " << std::endl;
    std::cout << "5) Remove a Value" << std::endl;
    std::cout << "6) Exit" << std::endl;
}

/* ************************************************************************** */

const unsigned int NumberOfElements(){

    int n = 0;
    bool exitNumberOfElements = false;

    std::cout << "How many element do you want to be your list made of? : ";
    std::cin >> n;

    while (std::cin.fail() || n < 0){
                    std::cin.clear(); 
                    std::cin.ignore(INT_MAX, '\n'); 
                    std::cout << "You can only enter positive numbers, retry." << std::endl;
                    std::cout << "How many element do you want to be your list made of? : ";
                    std::cin >> n;
    }

    const unsigned int numberoOfElementsChoiche = n;
    return numberoOfElementsChoiche;
}

int RandomInt(){
  std::default_random_engine genx(std::random_device{}());
  std::uniform_int_distribution<int> distx(-200, 200);
  return distx(genx);
}

double RandomFloat(){
    double n = static_cast<double>(RandomInt())/100 + RandomInt();
    return n;
}

std::string RandomString(){    

    std::string alphabet = "0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string result;

    std::default_random_engine genx(std::random_device{}());
    std::uniform_int_distribution<int> distx(0, alphabet.length()-1);

    int limit = distx(genx);
    
    for (int i = 0; i<limit; i++){
        result = result + alphabet.at(distx(genx));
    }

    return result;

}

const unsigned int Value(lasd::HashTable<int>& hashTable){

    int n = 0;
    bool exitValue = false;

    std::cout << "Insert an integer value : ";
    std::cin >> n;

    while (std::cin.fail()){
                    std::cin.clear(); 
                    std::cin.ignore(INT_MAX, '\n'); 
                    std::cout << "Insert an integer value : ";
                    std::cin >> n;
    }

    const int value = n;
    return value;
}

const double Value(lasd::HashTable<double>& hashTable){

    double n = 0;
    bool exitValue = false;

    std::cout << "Insert a float value : ";
    std::cin >> n;

    while (std::cin.fail()){
                    std::cin.clear(); 
                    std::cin.ignore(INT_MAX, '\n'); 
                    std::cout << "Insert a float value : ";
                    std::cin >> n;
    }

    const double value = n;
    return value;
}

const std::string Value(lasd::HashTable<std::string>& hashTable){

    std::string n;
    bool exitValue = false;

    std::cout << "Insert a value : ";
    std::cin >> n;

    const std::string value = n;
    return value;
}

/* ************************************************************************** */

void HashFillingInt(lasd::HashTable<int>& hashTable, unsigned int n){
    for(unsigned int i = 0; i<n; i++){
        hashTable.Insert(RandomInt());
    }
}

void HashFillingFloat(lasd::HashTable<double>& hashTable, unsigned int n){
    for(unsigned int i = 0; i<n; i++){
        hashTable.Insert(RandomFloat());
    }
}


void HashFillingString(lasd::HashTable<std::string>& hashTable, unsigned int n){
    for(unsigned int i = 0; i<n; i++){
        hashTable.Insert(RandomString());
    }
}

/* ************************************************************************** */

template <typename Data>
void MapPrintElement(const Data& data, void* startValue){
    std::cout << data << " | ";
}

void SpecificFoldInt(const int& data, const void* value, void* accumulator){
    if(data < *(static_cast<const int*>(value)))
        *(static_cast<int*>(accumulator)) = *(static_cast<int*>(accumulator)) * data;

}

void SpecificFoldFloat(const double& data, const void* value, void* accumulator){
    if(data > *(static_cast<const double*>(value)))
        *(static_cast<double*>(accumulator)) = *(static_cast<double*>(accumulator)) + data;

}

void SpecificFoldString(const std::string& data, const void* value, void* accumulator){
    if(data.length() <= *(static_cast<const int*>(value)))
        *(static_cast<std::string*>(accumulator)) = *(static_cast<std::string*>(accumulator)) + data;
    
}

void SpecificFold(lasd::HashTable<int>& hashTable){

    int result = 1;
    void* resultPassed = &result;

    int value;
    std::cout << "Enter an integer value : ";
    std::cin >> value;

    const void* valuePassed = &value;
    // try{
        hashTable.Fold(SpecificFoldInt, valuePassed, resultPassed);
        std::cout << std::endl << "The result of the fold is : " << *(static_cast<int*>(resultPassed)) << std::endl << std::endl;
    // } catch(...){
    //     std::cout << std::endl << "Exception thrown : The tree is empty." << std::endl << std::endl;
    // }
    
}

void SpecificFold(lasd::HashTable<double>& hashTable){

    double result = 0;
    void* resultPassed = &result;

    double value;
    std::cout << "Enter a value : ";
    std::cin >> value;

    const void* valuePassed = &value;
    // try{
        hashTable.Fold(SpecificFoldFloat, valuePassed, resultPassed);
        std::cout << std::endl << "The result of the fold is : " << *(static_cast<double*>(resultPassed)) << std::endl << std::endl;
    // } catch(...){
    //     std::cout << std::endl << "Exception thrown : The tree is empty." << std::endl << std::endl;
    // }
}

void SpecificFold(lasd::HashTable<std::string>& hashTable){

    std::string result = "";
    void* resultPassed = &result;

    int value;
    std::cout << "Enter an integer value : ";
    std::cin >> value;

    const void* valuePassed = &value;
    // try{
        hashTable.Fold(SpecificFoldString, valuePassed, resultPassed);
        std::cout << std::endl << "The result of the fold is : " << *(static_cast<std::string*>(resultPassed)) << std::endl << std::endl;
    // } catch(...){
    //     std::cout << std::endl << "Exception thrown : The tree is empty." << std::endl << std::endl;
    // }
}


/* ************************************************************************** */

template <typename Data>
void HashTest(lasd::HashTable<Data>& hashTable){

    bool exitTest = false;
    int choiceTest = 0;

    do{
        DataStructureOperationPrint();

        std::cout << "Select an option: ";
        std::cin >> choiceTest;
        while (std::cin.fail())
        {
            std::cin.clear(); 
            std::cin.ignore(INT_MAX, '\n'); 
            std::cout << "You can only enter numbers, retry." << std::endl;
            std::cout << "Select an option: ";
            std::cin >> choiceTest;
        }

        switch (choiceTest)
        {
        case 1:{
            //print (map)
            hashTable.Map(MapPrintElement<Data>, 0);
            break;
        }

        case 2:{
            //existance 
            if(hashTable.Exists(Value(hashTable)))  
                std::cout << std::endl << "The value has been found!" << std::endl << std::endl;
            else
                std::cout << std::endl << "The value has not been found!" << std::endl << std::endl;
            break;
        }

        case 3:{
            //fold
            SpecificFold(hashTable);
            break;
        }

        case 4:{
            //insert
            if(hashTable.Insert(Value(hashTable)))
                std::cout << std::endl << "Insert of the value completed!" << std::endl << std::endl;
            else
                std::cout << std::endl << "Error : the value is already in the HashTable!" << std::endl << std::endl;

            break;
        }

        case 5:{
            //remove
            if(hashTable.Remove(Value(hashTable)))
                std::cout << std::endl << "Remove of the value completed!" << std::endl << std::endl;
            else
                std::cout << std::endl << "Error : value not found in the HashTable!" << std::endl << std::endl;
            break;
        }

        case 6:{
            exitTest = true;
            break;
        }   
        
        default:
            break;
        }
    } while(!exitTest);

}

/* ************************************************************************** */









void HashTableClsAdrCreation(){
    bool exitType = false;
    int choiceType = 0;  
    
    do{
        TypePrint();
        std::cout << "Select an option: ";
        std::cin >> choiceType;
        while (std::cin.fail())
        {
            std::cin.clear(); 
            std::cin.ignore(INT_MAX, '\n'); 
            std::cout << "You can only enter numbers, retry." << std::endl;
            std::cout << "Select an option: ";
            std::cin >> choiceType;
        }

        switch (choiceType)
        {
        case 1: {
            const unsigned int numberOfElements = NumberOfElements();
            lasd::HashTableClsAdr<int> hashTable{};
            HashFillingInt(hashTable, numberOfElements);
            HashTest(hashTable);
        break; }
        
        case 2: {
            const unsigned int numberOfElements = NumberOfElements();
            lasd::HashTableClsAdr<double> hashTable{};
            HashFillingFloat(hashTable, numberOfElements);
            HashTest(hashTable);
        break; }
        case 3: {;
            const unsigned int numberOfElements = NumberOfElements();
            lasd::HashTableClsAdr<std::string> hashTable{};
            HashFillingString(hashTable, numberOfElements);
            HashTest(hashTable);
        break; } 
        
        case 4: {
            exitType = true;
        } break;

        default:
            break;
        }
    } while (!exitType);  
}

void HashTableOpnAdrCreation(){
    bool exitType = false;
    int choiceType = 0;  
    
    do{
        TypePrint();
        std::cout << "Select an option: ";
        std::cin >> choiceType;
        while (std::cin.fail())
        {
            std::cin.clear(); 
            std::cin.ignore(INT_MAX, '\n'); 
            std::cout << "You can only enter numbers, retry." << std::endl;
            std::cout << "Select an option: ";
            std::cin >> choiceType;
        }

        switch (choiceType)
        {
        case 1: {
            const unsigned int numberOfElements = NumberOfElements();
            lasd::HashTableOpnAdr<int> hashTable{64};
            HashFillingInt(hashTable, numberOfElements);
            HashTest(hashTable);
        break; }
        
        case 2: {
            const unsigned int numberOfElements = NumberOfElements();
            lasd::HashTableOpnAdr<double> hashTable{64};
            HashFillingFloat(hashTable, numberOfElements);
            HashTest(hashTable);
        break; }

        case 3: {;
            const unsigned int numberOfElements = NumberOfElements();
            lasd::HashTableOpnAdr<std::string> hashTable{64};
            HashFillingString(hashTable, numberOfElements);
            HashTest(hashTable);
        break; } 
        
        case 4: {
            exitType = true;
        } break;

        default:
            break;
        }
    } while (!exitType);  
}

/* ************************************************************************** */

void ProfessorTest(){
    lasdtest();
}

void StudentTest(){
    std::cout << "---------- Student's Test ----------" << std::endl;

    bool exitDS = false;
    int choiceDS = 0;
        
    do{ 
        DataStructurePrint();

        std::cout << "Select an option: ";
        std::cin >> choiceDS;

        while (std::cin.fail()){
            std::cin.clear(); 
            std::cin.ignore(INT_MAX, '\n'); 
            std::cout << std::endl << "You can only enter numbers, retry." << std::endl;
            std::cout << "Select an option: ";
            std::cin >> choiceDS;
        }
        
        switch (choiceDS)
        {
        case 1:{
            HashTableClsAdrCreation();
        } break;

        case 2:{
            HashTableOpnAdrCreation();    
        } break;

        case 3:{
            exitDS = true;
        } break;

        default:
            break;
        }
        
    } while (!exitDS);
}

void Menu(){
    std::cout << "Welcome!" << std::endl;

    std::cout << std::endl;

    bool exit = false;
    int choice = 0;

    do
    {
        TestPrint();

        std::cout << "Select an option: ";
        std::cin >> choice;

        while (std::cin.fail()){
            std::cin.clear(); 
            std::cin.ignore(INT_MAX, '\n'); 
            std::cout << std::endl << "You can only enter numbers, retry." << std::endl;
            TestPrint();
            std::cout << "Select an option: ";
            std::cin >> choice;
        }

        switch (choice)
        {
        case 1:
            ProfessorTest();
            break;
        
        case 2:{
            StudentTest();
            break;}

        case 3:
            exit = true;
            break;

        default:
            break;
        }

    } while (!exit);
    std::cout << std::endl << "Goodbye!" << std::endl << std::endl;

}
