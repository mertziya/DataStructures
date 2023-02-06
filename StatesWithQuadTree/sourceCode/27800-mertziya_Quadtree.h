#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;


struct treeNodes{
    
    int x_coordinate;
    int y_coordinate;
    string city_name;
    treeNodes * NE;
    treeNodes * NW;
    treeNodes * SE;
    treeNodes * SW;
    
};


class quadTree{
private:
    
    treeNodes * root;
    int x_max;  // max value of x coordinate
    int y_max;  // max value of y coordinate
                // according to file least value of x and y should be 0.
    
    vector<vector<string>> checks; // --> for storing which cities are searched and which are inside the circle.
    vector<vector<string>> covers; // since the length of the text file is not known,
                           // array was not the best option.
                           // also linked lists would make the code too long.
                           //
                           // --> since this vectors will include only the necessary elements,
                           // it will not change the execution time.
    
    bool checks_first = true; // for creating a column for checks vector
                              // in the search() function.
    
    bool covers_first = true; // for creating a column for covers vector in the search() function
    
    int vector_iter_checks = 0; // for updating the rows inside the checks vector.
    int vector_iter_covers = 0; // for updating the rows inside the covers vector.
    
    void pretty_print(treeNodes * _root);
    void search(int x_coord, int y_coord, int radius, treeNodes * _root);
    
    
public:
    quadTree(); // Makes the root variable = NULL.
    ~quadTree(); // deletes each node.
    void terminator(treeNodes * _root); // deletes each node
    
    void readCities(string filename); // reads the file and inserts datas into quadtree
    void readQueries(string filename); // reads the file ans searches the datas.
    
    treeNodes * createNode(string c_name, int x_coord, int y_coord); // creates and insert some datas into nodes.
    
    string compare(const treeNodes *_root,const int & x, const int & y);
    
    void insert(const string city, const int x, const int y); // insert should go into 3 variabled readCities.
    
    void pretty_print();
    
    void search(int x_coord, int y_coord, int radius);
    
    void print_search();
};

