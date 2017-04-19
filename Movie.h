/*
 *  Movie.h and Movie.cpp, which implement the class Movie, and possibly 
 * additional support classes or enumerations, as required. A Movie object 
 * records the information about a movie provided in the ﬁle movies.txt. It must
 *  have an appropriate set of constructors and accessor methods, and the stream
 *  input and output operators must be overloaded to allow stream based I/O. 
 * The full set of relational operators should be implemented,such that a 
 * collection of Movie objects could be sorted, in order of release year 
 * (movies with the same release year should appear in alphabetical order). 
 */

/* 
 * File:   Movie.h
 * Author: bijan
 *
 * Created on 10 April 2017, 13:04
 */

#ifndef MOVIE_H
#define MOVIE_H


#include <iostream>
#include <string>

class Movie{
private:

    std::string name, classification, genre;
    int year, duration, numberOfRatings, rating;
    
public:
    
    inline std::string getName() const{
        return name;
    }
    
    inline std::string getClassification() const{
        return classification;
    }
    
    inline std::string getGenre() const{
        return genre;
    }
    
    inline int getYear() const{
        return year;
    }
    
    inline int getDuration() const{
        return duration;
    }
    
    inline int getNumberOfRatings() const{
        return numberOfRatings;
    }
    
    inline int getRating() const{
        return rating;
    }
    
    void setNumberOfRatings(int n){
        numberOfRatings=n;
    }
    
    void setRating(int n){
        rating=n;
    }
    
    Movie(std::string nm, int year, std::string clasf, 
    std::string gnr, int duration, int numberOfRatings, int rating);
                
    friend std::ostream& operator<<(std::ostream &os, const Movie &d);
    
    friend std::istream& operator>>(std::istream &is, Movie &d);
    
};


inline bool operator<(const Movie &a, const Movie &b){
    if(a.getYear() != b.getYear()){
        return a.getYear() < b.getYear();
    } else {        
        if(a.getName().compare(b.getName()) > 0){
            return false;
        } else if(a.getName().compare(b.getName()) == 0){
            return false;
        } else {
            return true;
        }
        
    }
}
    
inline bool operator>(const Movie &a, const Movie &b){
    if(a.getYear() != b.getYear()){
        return a.getYear() > b.getYear();
    } else {        
        if(a.getName().compare(b.getName()) > 0){
            return true;
        } else if(a.getName().compare(b.getName()) == 0){
            return false;
        } else {
            return false;
        }
        
    }
}
    
inline bool operator<=(const Movie &a, const Movie &b){
    return !(a.getYear() > b.getYear());
}
    
inline bool operator>=(const Movie &a, const Movie &b){
    return !(a.getYear() < b.getYear());
}
    
inline bool operator==(const Movie &a, const Movie &b){
    return a.getYear() == b.getYear();
}
    
inline bool operator!=(const Movie &a, const Movie &b){
    return !(a.getYear() == b.getYear());
}


#endif /* MOVIE_H */

