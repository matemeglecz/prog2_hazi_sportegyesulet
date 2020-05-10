#include "nyilvantartas.h"
#include "lista.h"
#include <fstream>

void Nyilvantartas::mentes(){
    std::ofstream fout;
    fout.open("test.txt");
    for(Lista<Csapat>::Iterator it=csapatok.begin(); it!=csapatok.end(); it++){
        fout << (*it) << std::endl;

    }

}

void Nyilvantartas::listaz(){
    int hanyadik=1;
    for(Lista<Csapat>::Iterator it=csapatok.begin(); it!=csapatok.end(); it++){
        std::cout << hanyadik++ << ". ";
        it->kiir();
    }
}

void Nyilvantartas::add(Csapat& uj){
    csapatok.add(&uj);
}

int Nyilvantartas::keresEskiir(const char* nev){
    int talalat=0;
    for(Lista<Csapat>::Iterator it=csapatok.begin(); it!=csapatok.end(); it++){
        if(strcmp(it->getNev(), nev)==0){
            std::cout << talalat++ << ". ";
            it->kiir();
        }
    }
    return talalat;
}

void Nyilvantartas::torolElem(const char* nev, int hanyadik=1){
    int talalat=0;
    for(Lista<Csapat>::Iterator it=csapatok.begin(); it!=csapatok.end(); it++){
        if(strcmp(it->getNev(), nev)==0 && ++talalat==hanyadik){
            csapatok.torolElem(it);
            return;
            }
    }
}