#include "nyilvantartas.h"
#include "lista.h"
#include <fstream>
#include <string>

void Nyilvantartas::mentes(char* file){
    std::ofstream fout;
    fout.open(file);
    for(Lista<Csapat>::Iterator it=csapatok.begin(); it!=csapatok.end(); it++){
        it->kiir(fout);
        it->kiirMeccsek(fout);
    }
}

void Nyilvantartas::beolvas(char* file){
    std::ifstream fin;
    fin.open(file);
    std::string tipus;
    fin >> tipus;
    std::cout << tipus << std::endl;
    string nev;
    string edzo;
    int letszam;
    if(tipus=="Foci:")
        fin >> nev >> ignore()

}

void Nyilvantartas::listaz(){
    int hanyadik=1;
    for(Lista<Csapat>::Iterator it=csapatok.begin(); it!=csapatok.end(); it++){
        std::cout << hanyadik++ << ". ";
        it->kiir();
    }
}

void Nyilvantartas::add(Csapat* uj){
    csapatok.add(uj);
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

void Nyilvantartas::addMeccs(int hanyadik, Meccs* uj){
    if(hanyadik > csapatok.getLen()) throw "hibas meccs hozzaadas";
    Lista<Csapat>::Iterator it=csapatok.begin();
    for(int i=0; i<hanyadik-1; i++){
        it++;
    }
    it->addMeccs(uj);
}
