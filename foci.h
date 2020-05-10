#ifndef FOCI_H_INCLUDED
#define FOCI_H_INCLUDED

#include "csapat.h"
//#include "lista.h"

class Foci :public Csapat{
    char* masodedzo;
public:
    Foci(const char* nev="", int alapletszam=0,const char* edzonev="",const char* medzo="") :Csapat(nev, alapletszam, edzonev) {
        masodedzo=new char[strlen(medzo)+1];
        strcpy(masodedzo, medzo);
    }

    Foci& operator=(const Foci& rhs);
    Foci(const Foci& f){*this=f;}

    void kiir(std::ostream& os = std::cout);

    char* getMasodedzo() const {return masodedzo;}
    ~Foci() {
        delete[] masodedzo;
        std::cout<<"focitorol"<<std::endl;
    }
};

std::ostream& operator<<(std::ostream& os, const Foci& k);

#endif // FOCI_H_INCLUDED
