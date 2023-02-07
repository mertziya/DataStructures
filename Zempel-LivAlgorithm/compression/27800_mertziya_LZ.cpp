#include "27800_mertziya_LZ.h"



Dictionary::Dictionary(){
    for(int i = 0; i < 256; i++){
        unsigned char ascii(i);
        dictionary_element element;
        element.key = ascii;
        element.code = i;
        dictionary.push_back(element);
    }
}



bool Dictionary::exists(const string & str){
    if(str.size() == 1){return true;}
    else{
        for(int i = 256; i < dictionary.size(); i++){
            if(dictionary.at(i).key == str){
                return true;
            }
        }
        return false;
    }
}



void Dictionary::insert(string & Key, int & Code){
    dictionary_element temp;
    temp.key = Key;
    temp.code = Code;
    dictionary.push_back(temp);
}



int Dictionary::find(const string &str){
   
    for(int i = 0; i < dictionary.size(); i++){
        if(str == dictionary.at(i).key){
            return i;
        }
    }
    return -1;
}



Dictionary::~Dictionary(){
    dictionary.clear();
}
