/*
 * TimeCode.h and TimeCode.cpp, which implement a class called TimeCode, which 
 * records the time and date of a user rating of a Movie. The stream I/O 
 * operators must be overloaded, using a restricted UTC representation of a 
 * time code, in the format dd/mm/yyyyTHH:MM:SSZ. The class must support 
 * appropriate overloaded relational and arithmetic operators and a conversion 
 * to int assigning a unique, ordered value to all valid time codes. 
 */

#include <iomanip>
#include <iostream>
#include "TimeCode.h"


TimeCode::TimeCode(int day, int month, int year, int hour, int minute, int second){
    
    if(day>0 && day<32 && month>0 && month<13 && hour>=0 && hour<24 && 
            minute>=0 && minute<60 && second>=0 && second<60){
        
        this->day=day;
        this->month=month;
        this->year=year;
        this->hour=hour;
        this->minute=minute;
        this->second=second;
        
    } else {                
        std::cerr << "Please provide the date and time in the right format" <<
                std::endl;
    }
    
    
}

TimeCode::TimeCode(){
    day=0;
    month=0;
    year=0;
    hour=0;
    minute=0;
    second=0;
}

std::ostream& operator<<(std::ostream &os, const TimeCode &tc){
    
    os << std::setfill('0') << std::setw(2) << tc.day << "/" << 
            std::setfill('0') << std::setw(2) << tc.month << "/" << 
            std::setfill('0') << std::setw(4) << tc.year << "T" << 
            std::setfill('0') << std::setw(2) << tc.hour << 
            ":" << std::setfill('0') << std::setw(2) << tc.minute << ":" << 
            std::setfill('0') << std::setw(2) << tc.second << "Z";
    
    return os;
}

std::istream& operator>>(std::istream &is, TimeCode &tc){
    
    int day, month, year, hour, minute, second;
    char c1, c2, c3, c4;
    
    if(is >> day >> c1 >> month >> c1 >> year >> c2 >> hour >> c3 >> minute >>
            c3 >> second >> c4){
        if(c1 == '/' && c2 == 'T' && c3 == ':' && c4 == 'Z'){
            tc = TimeCode(day, month, year, hour, minute, second);
        } 
    }
    
    
    return is;
}