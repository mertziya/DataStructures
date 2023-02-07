#include "27800_mertziya_HashTableTwo.h"




HashTable::HashTable(){
    
    for(int i = 0; i < 256; i++){
        unsigned char temp(i);
        dictionaryElement element;
        element.key = temp;
        element.code = i;
        dictionary.push_back(element);
    }
    
}


bool HashTable::exists(int code){
    if(code < dictionary.size()){
        return true;
    }
    else {
        return false;
    }
}


void HashTable::insert(string Key){
    
    dictionaryElement element;
    element.key = Key;
    element.code = UpdateCode;
    dictionary.push_back(element);
    UpdateCode++;
    
}



string HashTable::find(const int & Code){
    
    return dictionary.at(Code).key;
}
