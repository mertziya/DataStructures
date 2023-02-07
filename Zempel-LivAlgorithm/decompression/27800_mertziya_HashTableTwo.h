#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#define CAPACITY 4096
using namespace std;




struct dictionaryElement{
  
    string key; // defines the string element that comes from the input file.
    int code;   // defines the corresponding code for key.
    
};


class HashTable{
private:
    
    vector<dictionaryElement> dictionary; // initially stores ASCII values between 0-255
    
    int UpdateCode = 256; //
    
public:
    
    HashTable(); // initially starts the dictionary with ASCII values.
    
    bool exists(int code); // returns true if the given integer value exist in the dictionary.
    
    void insert(string key); // inserts the given string value into dictionary.
    
    string find(const int & Code); // it finds the code from the dictionary and returns the string corresponding value as result.
};
