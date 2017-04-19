/*
 * Ratings.h and Ratings.cpp which implement a class called Rating which stores 
 * the information about an individual user rating of a movie (i.e. the 
 * information contained in a single line in ratings.txt) and a class called 
 * Ratings, which holds a vector of Rating objects (or other suitable STL 
 * container). Both classes must overload the operators required for stream 
 * based I/O and have an appropriate set of constructors and interface 
 * methods etc .
 */

/* 
 * File:   Rating.h
 * Author: bijan
 *
 * Created on 17 April 2017, 13:53
 */

#include <string>
#include <vector>
#include <iostream>
#include "TimeCode.h"

using namespace std;

#ifndef RATING_H
#define RATING_H


class Rating{
    
private:
    TimeCode timeCode;
    string user, movie;
    int rating;
    
    
public:
    
    Rating(TimeCode &tc, string user, string movie, int rating);
    
    Rating();
    
    inline TimeCode getTimeCode() const{
        return timeCode;
    }
    
    inline string getUser() const{
        return user;
    }
    
    inline string getMovie() const{
        return movie;
    }
    
    inline int getRating() const{
        return rating;
    }
    
    friend std::ostream& operator<<(std::ostream &os, const Rating &r);

    friend std::istream& operator>>(std::istream &is, Rating &r);
    
};



class Ratings{
    
private:
    std::vector<Rating> ratings;
    
public:
    
    Ratings();
    
    inline int getSize() const{
        return ratings.size() ;
    }

    inline Rating getRating(int index) const{
        return ratings[index];
    }

    inline void addRating(Rating& r){
        ratings.push_back(r);        
    }
    
    friend std::ostream& operator<<(std::ostream &os, const Ratings &r);

    friend std::istream& operator>>(std::istream &is, Ratings &r);
    
};


#endif /* RATING_H */

