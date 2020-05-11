#ifndef CSAPAT_H_INCLUDED
#define CSAPAT_H_INCLUDED

#include <string>
#include "meccs.h"
#include "lista.h"
#include <string>

class Csapat{
    std::string csapatnev;
    int alapletszam;
    std::string edzo;
    Lista<Meccs> meccsek;
public:
    Csapat(std::string nev = "", int alapletszam = 0, std::string edzonev = "") :csapatnev(nev), alapletszam(alapletszam), edzo(edzonev) {
//        csapatnev=new char[strlen(nev)+1];
//        strcpy(csapatnev, nev);
//        edzo=new char[strlen(edzonev)+1];
//        strcpy(edzo, edzonev);
    }


    //Csapat(const Csapat& cs){*this=cs;}

    virtual void kiir(std::ostream& os = std::cout);

    std::string getNev() const{return csapatnev;}
    int getLetszam() const{return alapletszam;}
    std::string getEdzo() const{return edzo;}
    Lista<Meccs> getMeccsek() const {return meccsek;}
    Csapat& operator=(const Csapat& rhs);
    void addMeccs(Meccs* uj);
    void torolMeccs(int torlendo);
    void kiirMeccsek(std::ostream& os = std::cout);
    friend std::istream& operator>>(std::istream& is, Csapat& cs);
    virtual ~Csapat();
};

std::ostream& operator<<(std::ostream& os, const Csapat& cs);
std::istream& operator>>(std::istream& is, Csapat& cs);

#endif // CSAPAT_H_INCLUDED
