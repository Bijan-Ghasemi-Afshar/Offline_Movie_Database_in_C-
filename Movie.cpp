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

#include <string>
#include "Movie.h"

using namespace std;

Movie::Movie(std::string nm, int year , std::string clasf,
    std::string gnr, int duration , int numberOfRatings, int rating ){

    name = nm;
    this->year = year;
    classification = clasf;
    genre = gnr;
    this->duration = duration;
    this->numberOfRatings = numberOfRatings;
    this->rating = rating;
}


std::ostream& operator<<(std::ostream &os, const Movie &m){
    os << '"' << m.getName() << '"' << ',' << m.getYear() << ',' << '"' <<
            m.getClassification() << '"' << ',' << '"' << m.getGenre() << '"'
            << ',' << m.getDuration() << ',' << m.getNumberOfRatings() << ','
            << m.getRating() << endl;
    return os;
}

std::istream& operator>>(std::istream &is, Movie &m){

    string name, classification, genre;
    int year, duration, numberOfRatings, rating;

    if(is >> name >> year >> classification >> genre >> duration >> numberOfRatings >> rating){

        m = Movie(name, year, classification, genre, duration, numberOfRatings, rating);

    }
    else {
        is.clear(ios_base::failbit);
    }

    return is;

}



