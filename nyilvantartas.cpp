#include "nyilvantartas.h"
#include "lista.h"
#include <fstream>
#include <string>
#include "csapat.h"
#include "foci.h"
#include "kosarlabda.h"
#include "kezilabda.h"

void Nyilvantartas::mentes(const char* file){
    std::ofstream fout;
    fout.open(file);
    fout << csapatok.getLen() << std::endl;
    for(Lista<Csapat>::Iterator it=csapatok.begin(); it!=csapatok.end(); it++){
        it->kiir(fout);
        it->kiirMeccsek(fout);
    }
    fout.close();
}

void Nyilvantartas::beolvas(const char* file){
    std::ifstream fin;
    fin.open(file);
    std::string tipus, nev, edzo;
    int letszam, meccsekszama, csapatokszama;
    fin >> csapatokszama;
    for(int j=0; j<csapatokszama; j++){
        fin >> tipus;
        fin >> nev;
        fin.ignore(100, ':');
        fin >> letszam;
        fin.ignore(6, ':');
        fin >> edzo;
        fin.ignore(15, ':');
        fin >> meccsekszama;
        if(tipus=="Foci:"){
            std::string masodedzo;
            fin.ignore(12, ':');
            fin >> masodedzo;
            add(new Foci(nev, letszam, edzo, masodedzo));
        }
        else if(tipus=="Kosarlabda:"){
             int pompom;
            fin.ignore(23, ':');
            fin >> pompom;
            add(new Kosarlabda(nev, letszam, edzo, pompom));
        }
        else if(tipus=="Kezilabda:"){
            int tamogatas;
            fin.ignore(10, ':');
            fin >> tamogatas;
            add(new Kezilabda(nev, letszam, edzo, tamogatas));
        }
        for(int i=0; i<meccsekszama; i++){
            std::string hely, ellen;
            int ev, ora, perc, honap, nap;
            fin.ignore(10, ':');
            fin >> ellen;
            fin.ignore(10, ':');
            fin >> hely;
            fin.ignore(6, ':');
            fin >> ev;
            fin.ignore(1, '.');
            fin >> honap;
            fin.ignore(1, '.');
            fin >> nap;
            fin.ignore(2, ' ');
            fin >> ora;
            fin.ignore(1, ':');
            fin >> perc;
            addMeccs(csapatok.getLen(), new Meccs(hely, ellen, ev, honap, nap, ora, perc));
        }
    }
    listaz();

    fin.close();
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

int Nyilvantartas::keresEskiir(const std::string nev){
    int talalat=0;
    for(Lista<Csapat>::Iterator it=csapatok.begin(); it!=csapatok.end(); it++){
        if(it->getNev()==nev){
            std::cout << talalat++ << ". ";
            it->kiir();
        }
    }
    return talalat;
}

void Nyilvantartas::torolElem(const std::string nev, int hanyadik=1){
    int talalat=0;
    for(Lista<Csapat>::Iterator it=csapatok.begin(); it!=csapatok.end(); it++){
        if(it->getNev()==nev && ++talalat==hanyadik){
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
