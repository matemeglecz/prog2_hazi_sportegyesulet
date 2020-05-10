#ifndef NYILVANTARTAS_H_INCLUDED
#define NYILVANTARTAS_H_INCLUDED


#include "csapat.h"
#include "lista.h"

class Nyilvantartas{
    Lista<Csapat> csapatok;
public:
    Nyilvantartas() :csapatok(NULL) {};
    void mentes(char* file = "nyilvantartas.txt");
    void beolvas(char* file = "nyilvantartas.txt");
    int keresEskiir(const char* nev);
    void listaz();
    //Lista<Csapat>& getCsapatok() {return csapatok;}
    void addMeccs(int hanyadik, Meccs*);
    void add(Csapat* uj);
    void torolElem(const char* nev, int hanyadik);
    ~Nyilvantartas() {csapatok.torol();
    std::cout<<"nyilvan torol"<<std::endl;
    }


};


#endif // NYILVANTARTAS_H_INCLUDED
