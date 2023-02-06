#include "27800_mertziya_ModifiedPriorityQueue.h"



MPQ::MPQ(){
    if(heap.size() == 0){
        Building insert;
        insert.value.y=0; insert.value.x=0; insert.value.side='B'; // 'B' stands for bottom should not be deleted
        insert.label=0;
        heap.push_back(insert);
    }
}

MPQ::~MPQ(){
    heap.clear();
}


void MPQ::setBuildingSize(int size){
    buildingSize = size;
}

int MPQ::getBuildingSize(){
    return buildingSize;
}

bool MPQ::isEmpty(){
    if(heap.size() == 0){
        return true;
    }
    else{return false;}
}


void MPQ::insert(Value Value, int Label){
    heap.at(Label).value=Value;
    heap.at(Label).label=Label;
    
}


Value MPQ::Remove(int Label){
    Value value = heap.at(Label).value;
    heap.at(Label).value.x=0; heap.at(Label).value.y=0; heap.at(Label).value.side='U';
    return value;
}


Value MPQ::GetMax(){
    int max = 0;
    int max_label=0;
    for(int i = 0; i < heap.size(); i++){
        if(heap.at(i).value.y > max){
            max = heap.at(i).value.y;
            max_label = heap.at(i).label;
        }
    }
    return (heap.at(max_label).value);
}


void MPQ::buildHeap(){
    // 0th value is already initialized.
    for(int i = 1; i < buildingSize+1; i++){
        Building garbage;
        garbage.value.y = 0; garbage.value.x=0; garbage.value.side='U'; garbage.label = i;
        heap.push_back(garbage);
    }
    // assigns some garbage values to heap to determine its size
    // it is important to set size, because we will use labels to retrieve data with O(1) complexity.
}
