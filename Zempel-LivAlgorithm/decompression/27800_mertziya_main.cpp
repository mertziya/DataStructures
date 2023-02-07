#include "27800_mertziya_HashTableTwo.h"




int main(){
    
    HashTable table;
    
    string compressedFile = "compout"; // wanted like this in the pdf file.
    string decompressedFile = "decompout"; // wanted like this in the pdf file.
    
    ifstream input;
    ofstream output;
    
    input.open(compressedFile.c_str());
    output.open(decompressedFile.c_str());
    
    
    vector<int> codeArray; // holds the integer values that comes from "decompin.txt".
    int code;
    while(!input.eof()){
        input >> code;
        codeArray.push_back(code);
    }
    codeArray.pop_back(); // final element is repetead twive thats why i deleted it.
    
    
    int index = 0;
    while(index < codeArray.size()){
        if(index == 0){
            string temp = table.find(codeArray.at(index));
            output << temp;
            index++;
        }
        else{
            
            
            if(table.exists(codeArray.at(index))){
                // the code that comes from codeArray does exist in the HashTable.
                // thats why insertion to hashTable and output file is implemented like below
                string previous = table.find(codeArray.at(index-1));
                string current = table.find(codeArray.at(index));
                string insertion = previous + current.at(0);
                table.insert(insertion);
                
                output << current;
                
            }
            else{
                // the code that comes from codeArray does NOT exist in the HashTable.
                // thats why insertion to hashTable and output file is implemented like below
                
                string previous = table.find(codeArray.at(index-1));
                string insertion = previous + previous.at(0);
                
                output << insertion;
                table.insert(previous);
            }
            
            index++;
            
        }
        
    }
    
    input.close();
    output.close();
    return 0;
}
