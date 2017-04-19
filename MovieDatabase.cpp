/*
 * MovieDatabase.h and MovieDatabase.cpp,which implement a class called
 * MovieDatabase, which contains a vector (or other suitable STL container) of
 * Movie objects. This class should overload the stream I/O operators, such
 * that a MovieDatabase can be read in from movies.txt and displayed on the
 * console in exactly the same format. The class must provide additional
 * constructors and accessor methods etc., as appropriate, and to answer
 * generic queries.
 */


#include <iostream>
#include <string>
#include <vector>
#include "MovieDatabase.h"
#include <fstream>

using namespace std;

MovieDatabase::MovieDatabase(){}


std::ostream& operator<<(std::ostream &os, MovieDatabase &md){

    for(int i=0; i<md.getSize(); i++){
        os << md.getMovie(i);
    }

    return os;
}


std::istream& operator>>(std::istream &is, MovieDatabase &md){

    ifstream file;
    string data, name, calssification, genre;
    int year, duration, numberOfRatings, rating, counter;    

    file.open("movies.txt");

    while(!file.eof()){
        
        switch(counter){
            case 1:
                std::getline(file, data, '\"');
                std::getline(file, data, '\"');
                name=data;
                break;
                
            case 2:                
                std::getline(file, data, ',');
                std::getline(file, data, ',');
                year= stoi(data);
                break;
                
            case 3:
                std::getline(file, data, '\"');
                std::getline(file, data, '\"');
                calssification=data;
                break;
            
            case 4:
                std::getline(file, data, '\"');
                std::getline(file, data, '\"');
                genre=data;
                break;
            
            case 5:                
                std::getline(file, data, ',');
                std::getline(file, data, ',');
                duration=stoi (data);
                break;
                
            case 6:                
                std::getline(file, data, ',');                
                numberOfRatings=stoi(data);
                break;
                
            case 7:                
                file >> data;
                rating=stoi(data);
                break;
        } 
        counter = counter + 1;
        
        if(counter == 8){
            Movie m(name, year, calssification, genre, duration, 
                    numberOfRatings, rating);
            md.addMovie(m);
            counter = 1;
        }
    }
    
    file.close();


    return is;

}


