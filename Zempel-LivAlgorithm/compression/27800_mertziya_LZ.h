#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#define CAPACITY 4096

using namespace std;



struct dictionary_element{
    
    string key; // defines the string element that comes from the input file.
    int code; // defines the corresponding code for key.
    
};


class Dictionary{
private:
    vector<dictionary_element> dictionary;  // initially stores ASCII values between 0-255
    
public:
    Dictionary(); // initially starts the dictionary with ASCII values.
    ~Dictionary();
    bool exists(const string & str); // returns true if the given string value exist in the dictionary.
    
    void insert(string & key, int & code); // inserts the given string value with given code value into dictionary.
    
    int find(const string & str); // it finds the str from the dictionary and returns the integer corresponding value as result.
};
