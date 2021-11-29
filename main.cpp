#include <iostream>
#include "City.h"
#include "PQ.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <assert.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

//Function forward declarations
bool buildCityList(vector<City> & cityList, const string fileName);
int prims(vector<City> & cityList);


//Main 
int main(){
    const string fileName = "city-pairs.txt";
    vector<Destination> destinationArray;
    vector<City> cityList;
    vector<PQ> priorityList;
    vector<string> visitedList;
    
    if (!buildCityList(cityList, fileName)){
        cout << "Error opening file \"" << fileName << "\"" << '\n';
        return 1;
    }
    for (City i: cityList){
        cout << i.name << '\n';
        for (Destination j: i.destination){
            cout << '\t' << j.destinationName << ", " << j.distance << '\n';
        }
    }
    return 0;
}

/*This function builds a list of unique cities based on the first in each line
 * of the input file.  Each City object's destination list
 * is also populated.  It returns false if the file name is unable to be opened.
 */
bool buildCityList(vector<City> & cityList, const string fileName){
    ifstream infile (fileName);
    if (!infile.is_open())
        return false;
    
    string cityName;
    string destinationName;
    int distance;

    /*The following code block reads in city names and stores them in a vector.
     * Each string read in is checked for uniqueness with the std::find()
     * function before being added.  The destination and distance values are
     * also read in and stored in the City object's destination list.
     */
    do{
        infile >> cityName;
        bool flag = false;
        int i = 0;
        for (auto &i: cityList){
            if (i.name == cityName){
                flag = true;
                infile >> destinationName >> distance;
                Destination *newDestination = new Destination(destinationName, distance);
                i.destination.push_back(*newDestination);
            }
        }
        if (flag == false){
            City *newCity = new City(cityName);
            cityList.push_back(*newCity);
            infile >> destinationName >> distance;
            Destination *newDestination = new Destination(destinationName, distance);
            cityList.back().destination.push_back(*newDestination);
        }
        infile.ignore(1000, '\n');
    }while (!infile.eof());
    return true;
}


/* This function implements Prim's greedy algorithm for finding a minimum 
 * spanning tree (MST).  For simplicity, the resulting tree will be represented
 * as a matrix where each square representing a nonexistent or not-utilized edge
 * contains a 0 and each edge used in the the MST displays the edge's weight.
 * The function keeps a running total of the overall weight as edges are added
 * to the MST.
 */
int prims(vector<City> & cityList){
}


