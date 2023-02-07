#include "27800_mertziya_LZ.h"





int main(){
    Dictionary table;
    
    string compressionFile = "compin"; // wanted like this in the pdf file.
    string compressedFile = "compout"; // wanted like this in the pdf file.
    
    string codestream; // it holds all the information that comes from "compin.txt".
    
    ifstream input;
    ofstream output;
    
    input.open(compressionFile.c_str());
    output.open(compressedFile.c_str());
    
    char ch;
    while (!input.eof()) {
        input.get(ch);
        if(ch != '\n')codestream += ch;
    }
    
    
    
    int count = 0; // it counts each character from the "compin.txt" string
    int index = 256; // if there is a new element it should start inserting from 256.
    
    string p; // previous value that holds the string at index-1.
    char c; // current value that holds the string at index.
    
    string dictCheck; // it holds the p + c at the end of the statements and it becames the new p value,
                      // if the "dictCheck" is not in the table.
    
    
    while(count < codestream.length()){
        if(count == 0){
            c = codestream.at(0);
        }
        else{
            p = codestream.at(count-1);
            c = codestream.at(count);
        }
        
        dictCheck = p + c;
        
        while(table.exists(dictCheck) && (count < codestream.length()-1)){
            count++;
            p = dictCheck;
            c = codestream.at(count);
            dictCheck = p + c;
        }
        
        if(index < CAPACITY){
            table.insert(dictCheck, index);
        }
        
        if(count != codestream.length()){
            output << table.find(p) << ' ';
        }
        
        
        index++;
        count++;
    }
    
  
    input.close();
    output.close();
    
    return 0;
}

