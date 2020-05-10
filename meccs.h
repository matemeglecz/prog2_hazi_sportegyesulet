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
    Meccs(string hely = "", string ellen= "", int ev = 0, int honap = 0, int nap = 0, int ora = 0, int perc = 0) :helyszin(hely), datum(Datum(ev, honap, nap, ora, perc)), ellenfel(ellen) {
//        helyszin=new char[strlen(hely)+1];
//        strcpy(helyszin, hely);
//        ellenfel=new char[strlen(ellen)+1];
//        strcpy(ellenfel, ellen);
    }
    void kiir(std::ostream& os=std::cout);
    string getHelyszin() const{return helyszin;}
    Datum getDatum() const{return datum;}
    string getEllenfel() const{return ellenfel;}
    Meccs& operator=(const Meccs& rhs);
    ~Meccs(){
//        delete[] helyszin;
//        delete[] ellenfel;
        std::cout << "wtf" <<std::endl;
    }

};

std::ostream& operator<<(std::ostream& os, const Meccs& m);

#endif // MECCS_H_INCLUDED
