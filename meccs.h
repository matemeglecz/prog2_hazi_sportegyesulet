#ifndef MECCS_H_INCLUDED
#define MECCS_H_INCLUDED

#include <string>
#include "datum.h"
using namespace std;

class Meccs{
    string helyszin;
    Datum datum;
    string ellenfel;
public:
    Meccs(string hely = "", string ellen= "", int ev = 0, int honap = 0, int nap = 0, int ora = 0, int perc = 0) :helyszin(hely), datum(Datum(ev, honap, nap, ora, perc)), ellenfel(ellen) {}
    void kiir(std::ostream& os=std::cout);
    string getHelyszin() const{return helyszin;}
    Datum getDatum() const{return datum;}
    string getEllenfel() const{return ellenfel;}
    Meccs& operator=(const Meccs& rhs);
    friend std::istream& operator>>(std::istream& is, Meccs& m);
    ~Meccs(){}

};

std::ostream& operator<<(std::ostream& os, const Meccs& m);
std::istream& operator>>(std::istream& is, Meccs& m);

#endif // MECCS_H_INCLUDED
