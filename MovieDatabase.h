/*
 * MovieDatabase.h and MovieDatabase.cpp,which implement a class called
 * MovieDatabase, which contains a vector (or other suitable STL container) of
 * Movie objects. This class should overload the stream I/O operators, such
 * that a MovieDatabase can be read in from movies.txt and displayed on the
 * console in exactly the same format. The class must provide additional
 * constructors and accessor methods etc., as appropriate, and to answer
 * generic queries.
 */

/*
 * File:   MovieDatabase.h
 * Author: bijan
 *
 * Created on 14 April 2017, 12:39
 */

#include <vector>
#include <algorithm>
#include "Movie.h"

#ifndef MOVIEDATABASE_H
#define MOVIEDATABASE_H


class MovieDatabase{

private:
    std::vector<Movie> movieDatabase;

public:

    inline int getSize() const{
        return movieDatabase.size() ;
    }

    inline Movie& getMovie(int index){
        return movieDatabase[index];
    }

    inline bool addMovie(Movie& m){
        movieDatabase.push_back(m);
        return true;
    }    
        
    MovieDatabase();
    
    // Sorts movie into ascending order of release date
    void sortMovies(){
        std::sort(movieDatabase.begin(), movieDatabase.end());
    }
    
    void sortFilmNoirs(){                
        for(int i=0; i<movieDatabase.size(); i++){
            for(int j=i; j<movieDatabase.size(); j++){
                if(movieDatabase[i].getDuration() > 
                        movieDatabase[j].getDuration()){
                    Movie container = movieDatabase[i];
                    movieDatabase[i] = movieDatabase[j];
                    movieDatabase[j] = container;
                }
            }
        }        
    }
    
    void sortRating(){                
        for(int i=0; i<movieDatabase.size(); i++){
            for(int j=i; j<movieDatabase.size(); j++){
                if(movieDatabase[i].getRating() > 
                        movieDatabase[j].getRating()){
                    Movie container = movieDatabase[i];
                    movieDatabase[i] = movieDatabase[j];
                    movieDatabase[j] = container;
                }
            }
        }        
    }
    
    void findHighestRated(){
        int max = 0, index;
        for(int i=0; i<movieDatabase.size(); i++){
            if(max < movieDatabase[i].getRating()){
                index = i;
                max = movieDatabase[i].getRating();
            }
        }
        std::cout << movieDatabase[index] << std::endl;
    }
    
    void findLongestTitle(){
        int max = 0, index;
        for(int i=0; i<movieDatabase.size(); i++){
            if(max < movieDatabase[i].getName().length()){
                index = i;
                max = movieDatabase[i].getName().length();
            }
        }
        std::cout << movieDatabase[index] << std::endl;
    }
    
    friend std::ostream& operator<<(std::ostream &os, MovieDatabase &md);

    friend std::istream& operator>>(std::istream &is, MovieDatabase &md);

};

#endif /* MOVIEDATABASE_H */


