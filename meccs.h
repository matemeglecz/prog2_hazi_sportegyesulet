#ifndef MECCS_H_INCLUDED
#define MECCS_H_INCLUDED

#include "string.h"
#include "datum.h"
#include <iostream>

class Meccs{
    char* helyszin;
    Datum datum;
    char* ellenfel;
public:
    Meccs(const char* hely = "", const char* ellen= "", int ev = 0, int honap = 0, int nap = 0, int ora = 0, int perc = 0) :datum(Datum(ev, honap, nap, ora, perc)) {
        helyszin=new char[strlen(hely)+1];
        strcpy(helyszin, hely);
        ellenfel=new char[strlen(ellen)+1];
        strcpy(ellenfel, ellen);
    }
    void kiir(std::ostream& os = std::cout);
    char* getHelyszin() const{return helyszin;}
    Datum getDatum() const{return datum;}
    char* getEllenfel() const{return ellenfel;}
    Meccs& operator=(const Meccs& rhs);
    ~Meccs(){
        delete[] helyszin;
        delete[] ellenfel;
        std::cout << "wtf" <<std::endl;
    }

};

std::ostream& operator<<(std::ostream& os, const Meccs& m);

#endif // MECCS_H_INCLUDED
