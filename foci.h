#ifndef FOCI_H_INCLUDED
#define FOCI_H_INCLUDED

#include <string>
#include "csapat.h"
//#include "lista.h"

class Foci :public Csapat{
     std::string masodedzo;
public:
    Foci(std::string nev="", int alapletszam=0,std::string edzonev="",std::string medzo="") :Csapat(nev, alapletszam, edzonev), masodedzo(medzo) {}

    Foci& operator=(const Foci& rhs);

    void kiir(std::ostream& os = std::cout);

    std::string getMasodedzo() const {return masodedzo;}
    ~Foci() {}
    friend std::istream& operator>>(std::istream& is, Foci& f);
};

std::ostream& operator<<(std::ostream& os, const Foci& k);
std::istream& operator>>(std::istream& is, Foci& f);

#endif // FOCI_H_INCLUDED
