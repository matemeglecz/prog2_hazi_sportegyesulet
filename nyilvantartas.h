#ifndef NYILVANTARTAS_H_INCLUDED
#define NYILVANTARTAS_H_INCLUDED


#include "csapat.h"
#include "lista.h"
#include <string>
using namespace std;

class Nyilvantartas{
    Lista<Csapat> csapatok;
public:
    Nyilvantartas() {};
    void mentes(const char* file = "nyilvantartas.txt");
    void beolvas(const char* file = "nyilvantartas.txt");
    int keresEskiir(const string nev);
    void listaz();
    Lista<Csapat> getCsapatok() const {return csapatok;}
    void addMeccs(int hanyadik, Meccs*);
    void add(Csapat* uj);
    void torolElem(const string nev, int hanyadik);
    ~Nyilvantartas() {csapatok.torol();
    std::cout<<"nyilvan torol"<<std::endl;
    }


};


#endif // NYILVANTARTAS_H_INCLUDED
