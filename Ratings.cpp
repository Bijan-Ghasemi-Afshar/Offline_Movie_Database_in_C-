/*
 * Ratings.h and Ratings.cpp which implement a class called Rating which stores 
 * the information about an individual user rating of a movie (i.e. the 
 * information contained in a single line in ratings.txt) and a class called 
 * Ratings, which holds a vector of Rating objects (or other suitable STL 
 * container). Both classes must overload the operators required for stream 
 * based I/O and have an appropriate set of constructors and interface 
 * methods etc .
 */

#include "Ratings.h"
#include "TimeCode.h"
#include <string>
#include <iostream>
#include <fstream>
#include <valarray>

Rating::Rating(TimeCode &tc, string user, string movie, int rating){
    
    timeCode = TimeCode(tc.getDay(), tc.getMonth(), tc.getYear(), tc.getHours(),
            tc.getMinute(), tc.getSecond());
    this->user = user;
    this->movie = movie;
    this->rating = rating;
    
}

Rating::Rating(){

    timeCode = TimeCode();
    user = "";
    movie = "";
    rating = 0;
}

std::ostream& operator<<(std::ostream &os, const Rating &r){
    
    os << r.timeCode << ',' << '"' << r.user << '"' << ',' << '"' << r.movie << '"' 
            << ',' << r.rating << std::endl;
    
    return os;
}

std::istream& operator>>(std::istream &is, Rating &r){
    
    int day, month, year, hour, minute, second, rating;
    string user, movie;
    char c1, c2, c3, c4, c5, c6;
    
    if(is >> day >> c1 >> month >> c1 >> year >> c2 >> hour >> c3 >> minute >>
            c3 >> second >> c4 >> c5 >>user >> c5 >> movie >> c5 >> rating){
        
        if(c1 == '/' && c2 == 'T' && c3 == ':' && c4 == 'Z' && c5 == ','){
            
//            c1 == '/' && c2 == 'T' && c3 == ':' && c4 == 'Z' && c5 == ',' && 
//                c6 == '"'
            
//            r.timeCode = TimeCode tc(day, month, year, hour, minute, second);
//            r.user = user;
//            r.movie = movie;
//            r.rating = rating;
            
            TimeCode tc(day, month, year, hour, minute, second);
            r = Rating(tc, user, movie, rating);
            std::cout << "Object created" << std::endl;
        } else {
            std::cout << "dfs" << std::endl;
        }         
    } else {
        std::cout << "Help me" << std::endl;
    }
    
    return is;
}



Ratings::Ratings(){}

std::ostream& operator<<(std::ostream &os, const Ratings &r){
    
    for(int i=0; i<r.getSize(); i++){
        os << r.getRating(i);
    }
    
    return os;
}

std::istream& operator>>(std::istream &is, Ratings &r){
    
    ifstream file;
    string user, movie, data;
    int day, month, year, hour, minute, second, rating, counter, secondCounter = 1;    

    file.open("ratings.txt");

    while(!file.eof()){
        
        switch(counter){
            case 1:
                std::getline(file, data, '/');               
                day=stoi(data);
                break;
                
            case 2:                
                std::getline(file, data, '/');                
                month= stoi(data);
                break;
                
            case 3:
                std::getline(file, data, 'T');                
                year= stoi(data);
                break;
            
            case 4:
                std::getline(file, data, ':');                
                hour= stoi(data);
                break;
            
            case 5:                
                std::getline(file, data, ':');                
                minute= stoi(data);
                break;
                
            case 6:                
                std::getline(file, data, 'Z');                      
                second = stoi(data);
                break;
                
            case 7:                
                std::getline(file, data, ',');
                std::getline(file, data, '\"');
                std::getline(file, data, '\"');                
                user=data;
                break;
    
            case 8:                
                std::getline(file, data, ',');
                std::getline(file, data, '\"');
                std::getline(file, data, '\"');                
                movie=data;
                break;
    
            case 9:                
                std::getline(file, data, ',');
                file >> data;                
                rating=stoi(data);
                break;
        } 
        counter = counter + 1;
        
        if(counter == 10){                        
            TimeCode timeCode(day, month, year, hour, minute, second);
            Rating ratingObj(timeCode, user, movie, rating);
            r.addRating(ratingObj);
            secondCounter = secondCounter + 1;
            if(secondCounter == 22905){
                break;
            }           
            counter = 1;
        }
    }
    
    file.close();
    
    return is;
}


