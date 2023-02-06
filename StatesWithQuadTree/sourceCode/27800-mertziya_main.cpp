#include "27800-mertziya_Quadtree.h"


int main(){
    quadTree states;
    string cities = "cities.txt";
    string queries = "queries0.txt";
    
    
    states.readCities(cities);
    
    states.pretty_print();
    
    
    
    states.readQueries(queries);
    
    states.print_search();
    
    return 0;
}
