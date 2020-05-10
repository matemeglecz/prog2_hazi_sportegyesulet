#ifndef NYILVANTARTAS_H_INCLUDED
#define NYILVANTARTAS_H_INCLUDED

#include "csapat.h"
#include "lista.h"

class Nyilvantartas{
    Lista<Csapat> csapatok;
public:
    Nyilvantartas() :csapatok(NULL) {};
    void mentes();
    void beolvas();
    int keresEskiir(const char* nev);
    void listaz();
    void add(Csapat& uj);
    void torolElem(const char* nev, int hanyadik);
    ~Nyilvantartas() {csapatok.torol();}

};


#endif // NYILVANTARTAS_H_INCLUDED
