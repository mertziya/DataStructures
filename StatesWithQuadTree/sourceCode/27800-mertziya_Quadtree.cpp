#include "27800-mertziya_Quadtree.h"





quadTree::quadTree():root(NULL){}

void quadTree::terminator(treeNodes *_root){ // deletes each node.
    bool c1 = (_root->SE == NULL);
    bool c2 = (_root->SW == NULL);
    bool c3 = (_root->NE == NULL);
    bool c4 = (_root->NW == NULL);
    if(c1 && c2 && c3 && c4){
        delete _root;
        _root = NULL;
    }
    else{
        
        if(_root->SE != NULL){
            terminator(_root->SE);
        }
        
        if(_root->SW != NULL){
            terminator(_root->SW);
        }
        
        if(_root->NE != NULL){
            terminator(_root->NE);
        }
        
        if(_root->NW != NULL){
            terminator(_root->NW);
        }
    }
}

quadTree::~quadTree(){ // calls the terminator and clears the memory at the end of the code.
    terminator(root);
}



void quadTree::readCities(string filename){ // it reads the "cities.txt file" and inserts.
    ifstream input;
    input.open(filename.c_str());
    
    if(! input.fail()){
        
        string line;
        bool not_first_line = false;
        while(getline(input,line)){
            istringstream lineSS(line);
            if(not_first_line){
                string city_name;
                int x_coord, y_coord;
                lineSS >> city_name >> x_coord >> y_coord;
                insert(city_name, x_coord, y_coord);
            }
            else{
                lineSS >> x_max >> y_max;
                not_first_line = true;
            }
            
        }
    }
    
    else{cout << "Wrong file name." << endl;}
}



void quadTree::readQueries(string filename){ // it reads the "queries.txt" file and searches accordingly.
    ifstream input;
    input.open(filename.c_str());;
    
    if(! input.fail()){
        string line;
        while(getline(input,line)){
            istringstream lineSS(line);
            string e1, e2, e3;
            int x, y, radius;
            lineSS >> e1 >> e2 >> e3;
            
            x = stoi(e1.substr(0,e1.length()));
            y = stoi(e2.substr(0,e1.length()));
            radius = stoi(e3);
            
            search(x, y, radius);
            
        }
    }
    
    else{
        cout << "Wrong file name." << endl;
    }
}




string quadTree::compare(const treeNodes * _root,const int &x, const int &y){
    
    string error_x;
    string error_y;
    
    
    if(x >= _root->x_coordinate){ // i said ">=" according to assignment file.
        if( y >= _root->y_coordinate){
            return "NE";
        }
        else{
            return "SE";
        }
    }
    else{
        if(y >= _root->y_coordinate){
            return "NW";
        }
        else{
            return "SW";
        }
    }
}


treeNodes * quadTree::createNode(string c_name, int x_coord, int y_coord){ // creates a new node.
    treeNodes * node = new treeNodes();
    node->city_name = c_name;
    node->x_coordinate = x_coord;
    node->y_coordinate = y_coord;
    node->NE = NULL;
    node->NW = NULL;
    node->SE = NULL;
    node->SW = NULL;
    return node;
}

void quadTree::insert(const string city, const int x, const int y){
    
   
    
    if(root == NULL){
        root = createNode(city, x, y);
    }
    else{
        treeNodes * inserting_node = createNode(city, x, y);
        treeNodes * root_copy = root;
        bool condition = true;
        
        
        while(condition){
            string region = compare(root_copy, x,y);
            if(region == "SE"){
               
                if(root_copy->SE != NULL){
                    root_copy = root_copy->SE;
                   
                }
                else{
                    root_copy->SE = inserting_node;
                    condition = false;
                }
            }                                                 
            
            else if(region == "SW"){
                if(root_copy->SW != NULL){
                    root_copy = root_copy->SW;
                   
                }
                else{
                    root_copy->SW = inserting_node;
                    condition = false;
                }
            }
            
            else if(region == "NE"){
                if(root_copy->NE != NULL){
                    root_copy = root_copy->NE;
                   
                }
                else{
                    root_copy->NE = inserting_node;
                    condition = false;
                }
            }
            
            else if(region == "NW"){
                if(root_copy->NW != NULL){
                    root_copy = root_copy->NW;
                   
                }
                else{
                    root_copy->NW = inserting_node;
                    condition = false;
                }
            }
        }
    }
}



void quadTree::pretty_print(treeNodes * _root){    //  implemented like pre-order traversal but,
    if(_root != NULL){                             //  instead of root-left-right like approach in the BST
        cout << _root->city_name << endl;          //  the approach is root-(SE to NW).
        pretty_print(_root->SE);                   //
        pretty_print(_root->SW);
        pretty_print(_root->NE);
        pretty_print(_root->NW);
    }
}

void quadTree::pretty_print(){                      // for reaching the pretty_print(treeNodes * _root) function
    pretty_print(root);                             // from the main function.
    cout << endl;
}



void quadTree::search(int x_coord,int y_coord, int radius, treeNodes *_root){
    if(_root == NULL){return;}
    else{
        int x_low = x_coord - radius;
        int x_high = x_coord + radius;
        int y_low = y_coord - radius;
        int y_high = y_coord + radius;
        
        int root_x = _root->x_coordinate;
        int root_y = _root->y_coordinate;
        int radius_square = radius * radius;
        int distance_square = ((root_x - x_coord) * (root_x - x_coord) + (root_y - y_coord) * (root_y - y_coord));
                                //           ^^^^^^^  shortest distance formula ^^^^^^^^
        
        if(covers_first){
            vector<string> push_it;
            covers.push_back(push_it);
            covers_first = false;
        }
        
        if(checks_first){
            vector<string> push_it;
            checks.push_back(push_it);
            checks_first = false;
        }
        
        if(radius_square >= distance_square){
            covers[vector_iter_covers].push_back(_root->city_name);
        }
        
        checks[vector_iter_checks].push_back(_root->city_name);
        
        
        // bool inXXforXX is for a special case when the areas are at the cross directions
        // and that condition needs to be treated differently, thats why i assign this boolean variable.
        
        bool in_NWforSE = ((y_coord >= _root->y_coordinate) && (x_coord <= _root->x_coordinate));
        if(in_NWforSE){
            if(radius_square >= distance_square){
                search(x_coord, y_coord, radius, _root->SE);
            }
        }
        else{
            if(x_high >= _root->x_coordinate && y_low < _root->y_coordinate){
                search(x_coord, y_coord, radius, _root->SE);
            }
        }
        
        //************
        
        bool in_NEforSW = ((y_coord >= _root->y_coordinate) && (x_coord >= _root->x_coordinate));
        if(in_NEforSW){
            if(radius_square >= distance_square){
                search(x_coord, y_coord, radius, _root->SW);
            }
        }
        else{
            if(x_low < _root->x_coordinate && y_low < _root->y_coordinate){
                search(x_coord, y_coord, radius, _root->SW);
            }
        }
        
        //************
        
        bool in_SWforNE = ((y_coord <= _root->y_coordinate) && (x_coord <= _root->x_coordinate));
        if(in_SWforNE){
            if(radius_square >= distance_square){
                search(x_coord, y_coord, radius, _root->NE);
            }
        }
        else{
            if(x_high >= _root->x_coordinate && y_high >= _root->y_coordinate){
                search(x_coord, y_coord, radius, _root->NE);
            }
        }
        
        //************
        
        bool in_SEforNW = ((y_coord <= _root->y_coordinate) && (x_coord >= _root->x_coordinate));
        if(in_SEforNW){
            if(radius_square >= distance_square){
                search(x_coord, y_coord, radius, _root->NW);
            }
        }
        else{
            if(x_low < _root->x_coordinate && y_high >= _root->y_coordinate){
                search(x_coord, y_coord, radius, _root->NW);
            }
        }
        
        
        
    }
    
}


void quadTree::search(int x_coord, int y_coord, int radius){
    search(x_coord, y_coord, radius, root);
    
    vector_iter_checks++;   //
    vector_iter_covers++;   // in the while loop of readQueries()
    covers_first = true;    // all these statements are updated in each step.
    checks_first = true;    //
    
}



void quadTree::print_search(){
    int row_len = (int)checks.size();
    
    
    for(int i = 0; i < row_len; i++){
        int col_len_covers = (int)covers[i].size();
        int col_len_checks = (int)checks[i].size();
        if(col_len_covers == 0){
            cout << "<None>";
        }
        else{
            for(int j = 0; j < col_len_covers; j++){
                if(j != col_len_covers-1){
                    cout << covers[i][j] << ", ";
                }
                else{
                    cout << covers[i][j];
                }
            }
        }
        
        cout << endl;
        
        for(int j = 0; j < col_len_checks; j++){
            if(j != col_len_checks-1){
                cout << checks[i][j] << ", ";
            }
            else{
                cout << checks[i][j];
            }
        }
        
        cout << "\n\n";
        
        
    }
    
}

 
