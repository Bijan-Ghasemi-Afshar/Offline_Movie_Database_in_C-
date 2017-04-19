/*
 * main.cpp is the main part of the program, and should initialise the 
 * MovieDatabase and Ratings objects, using movies.txt and ratings.txt, and 
 * then process the ratings to update each Movie in the database..
 */

/* 
 * File:   main.cpp
 * Author: bijan
 *
 * Created on 13 April 2017, 12:14
 */


#include "Movie.h"
#include "MovieDatabase.h"
#include "TimeCode.h"
#include "Ratings.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

void updateMovieRatings(Ratings &r, Movie &m){
        
    Rating rating;
    int total = 0, sum = 0, average = 0;
       
    
    for(int i=0; i<r.getSize(); i++){
        
        rating = r.getRating(i);
        
        if(m.getName().compare(rating.getMovie()) == 0){  
            total++;           
            sum += rating.getRating();            
        }                
        
    }

    if(total != 0){
        average = sum/total;
    }            
    
    m.setNumberOfRatings(total);
    m.setRating(average);            
    
}

MovieDatabase extractFilmNoirs(MovieDatabase &md){
    
    MovieDatabase movieDatabase;
    
    for(int i=0; i<md.getSize(); i++){
        if(md.getMovie(i).getGenre().find("Film-Noir") != std::string::npos){
            movieDatabase.addMovie(md.getMovie(i));
        }
    }        
    
    return movieDatabase;   
}

MovieDatabase extractSciFi(MovieDatabase &md){
    
    MovieDatabase movieDatabase;
    
    for(int i=0; i<md.getSize(); i++){
        if(md.getMovie(i).getGenre().find("Sci-Fi") != std::string::npos){
            movieDatabase.addMovie(md.getMovie(i));
        }
    }        
    
    return movieDatabase;   
}

int main(){    
    
    /*
     * Initialising the MovieDatabase and Ratings from movies.txt and 
     * ratings.txt and updating the movie ratings from the ratings database
     */
    MovieDatabase movieDB;
    Ratings ratings;    
    
    cin >> movieDB;
    cin >> ratings;       
    
    for(int i=0; i<movieDB.getSize(); i++){
        updateMovieRatings(ratings, movieDB.getMovie(i));
    }               
    
    // Performing the main 6 tasks of the program    
    /*
     * TASK 1: Sort the movies in ascending order of release date and display 
     * on the console.
     */    
//    movieDB.sortMovies();
//    
//    cout << movieDB;
    
          
    // TASK 2: Display the third longest Film-Noir.    
//    
//    MovieDatabase movDB2 = extractFilmNoirs(movieDB);        
//    
//    movDB2.sortFilmNoirs();
//    
//    cout << "Film-Noirs: \n\n";
//    
//    cout << movDB2<< endl;        
//    
//    cout << movDB2.getMovie(movDB2.getSize() - 3) << endl;  
    
    
    // TASK 3: Display the 10th highest rated Sci-Fi movie.        
//    MovieDatabase movDB3 = extractSciFi(movieDB);        
//    
//    movDB3.sortRating();
//    
//    cout << "Sci-Fi: \n\n";
//    
//    cout << movDB3 << endl;        
//    
//    cout << movDB3.getMovie(movDB3.getSize() - 10) << endl;  
    
        
    // TASK 4: Display the highest rated ﬁlm.
    movieDB.findHighestRated();
    
    
    // TASK 5: Display the ﬁlm with the longest title.
    movieDB.findLongestTitle();
    
    
    // TASK 6: Display the chronologically 101st user rating.
    movieDB.sortMovies();
    
    cout << movieDB.getMovie(100) << endl;
    
    
    return 0;
}

