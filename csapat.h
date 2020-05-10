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
    Csapat(const char* nev = "", int alapletszam = 0, const char* edzonev = "") :alapletszam(alapletszam) {
        csapatnev=new char[strlen(nev)+1];
        strcpy(csapatnev, nev);
        edzo=new char[strlen(edzonev)+1];
        strcpy(edzo, edzonev);
    }


    Csapat(const Csapat& cs){*this=cs;}

    virtual void kiir(std::ostream& os = std::cout);

    char* getNev() const{return csapatnev;}
    int getLetszam() const{return alapletszam;}
    char* getEdzo() const{return edzo;}
    Lista<Meccs> getMeccsek() const {return meccsek;}
    Csapat& operator=(const Csapat& rhs);
    void addMeccs(Meccs* uj);
    void torolMeccs(int torlendo);
    void kiirMeccsek(std::ostream& os = std::cout);
    //friend std::istream& operator>>(std::istream& is, const Csapat& cs);
    virtual ~Csapat();
};

std::ostream& operator<<(std::ostream& os, const Csapat& cs);
//std::istream& operator>>(std::istream& is, const Csapat& cs);

#endif // CSAPAT_H_INCLUDED
