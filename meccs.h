#ifndef MECCS_H_INCLUDED
#define MECCS_H_INCLUDED

#include "string.h"
#include "datum.h"

class Meccs{
    char* helyszin;
    Datum datum;
    char* ellenfel;
public:
    //Meccs() :helyszin(NULL), ellenfel(NULL), datum(0,0,0,0,0) {}
    Meccs(const char* hely, const char* ellen, int ev, int honap, int nap, int ora, int perc) :datum(Datum(ev, honap, nap, ora, perc)) {
        helyszin=new char[strlen(hely)+1];
        strcpy(helyszin, hely);
        ellenfel=new char[strlen(ellen)+1];
        strcpy(ellenfel, ellen);
    }
    void kiir();
    char* getHelyszin() const{return helyszin;}
    Datum getDatum() const{return datum;}
    char* getEllenfel() const{return ellenfel;}
    Meccs& operator=(const Meccs& rhs);
    ~Meccs(){
        delete[] helyszin;
        delete[] ellenfel;
    }

};

std::ostream& operator<<(std::ostream& os, const Meccs& m);

#endif // MECCS_H_INCLUDED
