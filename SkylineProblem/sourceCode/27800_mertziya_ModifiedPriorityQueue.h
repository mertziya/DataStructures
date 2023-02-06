#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;



struct Value{
    int x; // x value of the left or right side of building.
    int y; // y value of the right or left side of building.
    char side; // L for left,   R for right.
};

struct Building{
    Value value;
    int label; // it is the id of the building.  --> used as index
};





class MPQ{
private:
    
    int buildingSize;
    
    vector<Building> heap;
    
public:
    
    
    MPQ();
    ~MPQ();
    void setBuildingSize(int size);
    int getBuildingSize();
    
    
    void insert(Value Value, int Label);
    Value Remove(int Label);
    Value GetMax();
    bool isEmpty();
    void buildHeap();
};


