#ifndef DATUM_H_INCLUDED
#define DATUM_H_INCLUDED

#include "iostream"

class Datum{
    int ev;
    int honap;
    int nap;
    int ora;
    int perc;
public:
    Datum(int ev, int honap, int nap, int ora, int perc) :ev(ev), honap(honap), nap(nap), ora(ora), perc(perc) {}
    int getEv() const{return ev;}
    int getHonap() const{return honap;}
    int getNap() const{return nap;}
    int getOra() const{return ora;}
    int getPerc() const{return perc;}

    bool operator==(Datum& rhs) const;
};

std::ostream& operator<<(std::ostream& os, const Datum& d);


#endif // DATUM_H_INCLUDED
