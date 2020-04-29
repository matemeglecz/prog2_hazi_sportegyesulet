#ifndef CSAPAT_H_INCLUDED
#define CSAPAT_H_INCLUDED

#include <string>
#include "meccs.h"
#include "lista.h"

class Csapat{
    char* csapatnev;
    int alapletszam;
    char* edzo;
    Lista<Meccs> meccsek;
public:
    Csapat(const char* nev, int alapletszam, const char* edzonev) :alapletszam(alapletszam) {
        csapatnev=new char[strlen(nev)+1];
        strcpy(csapatnev, nev);
        edzo=new char[strlen(edzonev)+1];
        strcpy(edzo, edzonev);
        //Lista<Meccs> meccsek(NULL);
    }

    virtual void kiir() = 0;
    char* getNev() const{return csapatnev;}
    int getLetszam() const{return alapletszam;}
    char* getEdzo() const{return edzo;}
    Lista<Meccs> getMeccsek() const {return meccsek;}
    Csapat& operator=(const Csapat& rhs);
    void addMeccs(Meccs* uj);
    void torolMeccs(int torlendo);
    void kiirMeccsek();

    virtual ~Csapat();
};

std::ostream& operator<<(std::ostream& os, const Csapat& cs);

#endif // CSAPAT_H_INCLUDED
