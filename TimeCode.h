/*
 * TimeCode.h and TimeCode.cpp, which implement a class called TimeCode, which 
 * records the time and date of a user rating of a Movie. The stream I/O 
 * operators must be overloaded, using a restricted UTC representation of a 
 * time code, in the format dd/mm/yyyyTHH:MM:SSZ. The class must support 
 * appropriate overloaded relational and arithmetic operators and a conversion 
 * to int assigning a unique, ordered value to all valid time codes. 
 */

/* 
 * File:   TimeCode.h
 * Author: bijan
 *
 * Created on 16 April 2017, 18:11
 */

#include <string>
#include <sstream>

#ifndef TIMECODE_H
#define TIMECODE_H


class TimeCode{
    
private:
    int day, month, year, hour, minute, second;
    
public:
    
    TimeCode(int day, int month, int year, int hour, int minute, int second);
    
    TimeCode();
    
    inline int getDay() const{
        return day;
    }
    
    inline int getMonth() const{
        return month;
    }
    
    inline int getYear() const{
        return year;
    }
    
    inline int getHours() const{
        return hour;
    }
    
    inline int getMinute() const{
        return minute;
    }
    
    inline int getSecond() const{
        return second;
    }
    
    inline operator int() const;
        
    friend std::ostream& operator<<(std::ostream &os, const TimeCode &tc);

    friend std::istream& operator>>(std::istream &is, TimeCode &tc);
            
};

// *************************Please Test A Lot***********************
inline TimeCode::operator int() const{ 
    int newYear = year - 1900;
    int days = day + (month * 31) + (newYear * 365);        
    
    return days;    
}


inline bool operator<(const TimeCode &a, const TimeCode &b)
{    
    return int(a) < int(b);
}

inline bool operator<=(const TimeCode &a, const TimeCode &b)
{    
    return !(a > b);
}

inline bool operator>(const TimeCode &a, const TimeCode &b)
{    
    return int(a) > int(b);
}

inline bool operator>=(const TimeCode &a, const TimeCode &b)
{    
    return !(a < b);
}

inline bool operator==(const TimeCode &a, const TimeCode &b)
{    
    return int(a) == int(b);
}

inline bool operator!=(const TimeCode &a, const TimeCode &b)
{    
    return !(a == b);
}

inline TimeCode operator+(const TimeCode& a, const TimeCode &b)
{
    return TimeCode(0, 0, 0, 0, 0, int(a) + int(b));
}

inline TimeCode operator-(const TimeCode& a, const TimeCode &b)
{
    return TimeCode(0, 0, 0, 0, 0, int(a) - int(b));
}

inline TimeCode operator*(const TimeCode& a, int n)
{
    return TimeCode(0, 0, 0, 0, 0, int(a)*n);
}

inline TimeCode operator*(int n, const TimeCode& a)
{
    return TimeCode(0, 0, 0, 0, 0, int(a)*n);
}

inline TimeCode operator/(const TimeCode& a, int n)
{
    return TimeCode(0, 0, 0, 0, 0, int(a)/n);
}

inline int operator%(const TimeCode& a, int n)
{
    return int(a)%n;
}


#endif /* TIMECODE_H */
