#include "27800_mertziya_ModifiedPriorityQueue.h"



bool sortCondition(Building b1, Building b2){
    
    

    if(b1.value.x == b2.value.x){
        if(b1.value.side == 'L' && b2.value.side == 'R'){
            return true;
        }
        else if(b1.value.side == 'R' && b2.value.side == 'L'){
            return false;
        }
        else if(b1.value.side == 'L' && b2.value.side == 'L'){
            if(b1.value.y > b2.value.y){  
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(b1.value.y < b2.value.y){
                return true;
            }else{
                return false;
            }
        }
    }
  
    
    if(b1.value.x < b2.value.x){ // main sorting condition
        return true;
    }
    else{
        return false;
    }
}


void SpecialSort(vector<Building> & locations){ // sorts the array.
    sort(locations.begin(), locations.end(), sortCondition);
}


void readInput(string filename, vector<Building> & locations, MPQ & heap){
    ifstream input;
    input.open(filename.c_str());
    if(! input.fail()){
        string line;
        bool firstLine = true;
        int i = 0;
        while(getline(input,line)){
            istringstream lineSS(line);
            if(! firstLine){
                int x1, x2, y;
                lineSS >> x1 >> y >> x2;
                Value value1, value2;
                value1.x=x1;value1.y=y;value1.side='L';
                value2.x=x2;value2.y=y;value2.side='R';
                Building b1, b2;
                b1.value=value1;
                b1.label=i+1;
                b2.value=value2;
                b2.label=i+1;
                locations.push_back(b1);
                locations.push_back(b2);
                i++;
            }
            
            else {
                Building constant;
                constant.value.x=-1; constant.value.y=-1; constant.value.side='-'; constant.label=0;
                locations.push_back(constant);
                int size;
                lineSS >> size;
                heap.setBuildingSize(size);
                firstLine = false;
            }
            
        }
    }
}



void printOutput(vector<vector<int>> array){
    
    for(int i = 0; i < array.size(); i++){
        cout << array.at(i).at(0) << " " << array.at(i).at(1) << endl;
    }
    
}





void readInput(string filename, vector<Building> & locations, MPQ & heap); //it reads the "input.txt" file and
// sets BuildingSize of the MPQ heap element. AND sends the data of the "input.txt" file to locations array with size= heap.BuildingSize * 2


bool sortCondition(Building b1, Building b2); // it is a condition for sort() method.
// it needs to sort the array by the ascending order of x's

// However, there are 3 edge cases

// 1st Edge case is, when a Right side of a building has same x value with left side of a building. in that case 'L' (left) one
// should always come before the 'R' (right) one.
// we can solve that edge case by--> [if x values are same sort according to signs('L' or 'R')].

// 2nd Edge case is, when 2 building has same x value and same sign which is equal to 'L'
// if there is a condition like that we can solve it by sorting locations' y value by DESCENDING order.

// 3rd Edge case is, when 2 building has same x value and same sign which is equal to 'R'
// if there is a condition like that we can solve it by sorting locations' y value by ASCENDING order.



void SpecialSort(vector<Building> & locations); // it sorts the locations array according to sortCondition function.

void printOutput(vector<vector<int>> array);

int main(){
    
    MPQ skyline;
    vector<Building> locations; // 0th value is a garbage value.
    
    readInput("testCase9.txt", locations, skyline); // filename should be equal to "input.txt".
    SpecialSort(locations);
    skyline.buildHeap();
    
    vector<vector<int>> output; // output can have a maximum amount of rows = buildingsize+1.
    
    for(int i = 1; i < locations.size(); i++){
        vector<int> row;
        if(i == 1){
            if(locations.at(i).value.x == 0){
                skyline.insert(locations.at(i).value, locations.at(i).label);
                row.push_back(locations.at(i).value.x);
                row.push_back(locations.at(i).value.y);
                output.push_back(row);
                
            }
            else{
                skyline.insert(locations.at(i).value, locations.at(i).label);
                row.push_back(0);
                row.push_back(0);
                output.push_back(row);
                
                vector<int> specialRow;
                
                specialRow.push_back(locations.at(i).value.x);
                specialRow.push_back(skyline.GetMax().y);
                output.push_back(specialRow);
            }
        
        }
        
        else if(locations.at(i).value.side == 'L'){
            int prevValue = skyline.GetMax().y;
            skyline.insert(locations.at(i).value, locations.at(i).label);
            if(prevValue != skyline.GetMax().y){
                row.push_back(locations.at(i).value.x);
                row.push_back(skyline.GetMax().y);
                output.push_back(row);
               
            }
            
        }
        else if(locations.at(i).value.side == 'R'){
            int prevValue = skyline.GetMax().y;
            skyline.Remove(locations.at(i).label);
            if(prevValue != skyline.GetMax().y){
                row.push_back(locations.at(i).value.x);
                row.push_back(skyline.GetMax().y);
                output.push_back(row);
            }
        }
        
    }
    

    printOutput(output);
    return 0;
    
}

