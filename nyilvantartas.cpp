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
        fout << it->getMeccsek().getLen() <<std::endl;
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
        if(tipus=="Foci:"){
            Foci* fp=new Foci;
            fin >> (*fp);
            add(fp);
        }
        else if(tipus=="Kosarlabda:"){
            Kosarlabda* kp=new Kosarlabda;
            fin >> (*kp);
            add(kp);
        }
        else if(tipus=="Kezilabda:"){
            Kezilabda* kp=new Kezilabda;
            fin >> (*kp);
            add(kp);
        }
        fin >> meccsekszama;
        for(int i=0; i<meccsekszama; i++){
            Meccs* mp=new Meccs;
            fin >> (*mp);
            addMeccs(csapatok.getLen(), mp);
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

void Nyilvantartas::kiirMeccs(int hanyadik){
    if(hanyadik > csapatok.getLen()) throw "hibas meccs sorszam";
    Lista<Csapat>::Iterator it=csapatok.begin();
    for(int i=0; i<hanyadik-1; i++){
        it++;
    }
    it->kiirMeccsek();
}

void Nyilvantartas::torolMeccs(int csapat, int meccs){
    if(csapat > csapatok.getLen()) throw "hibas meccs sorszam";
    Lista<Csapat>::Iterator it=csapatok.begin();
    for(int i=0; i<csapat-1; i++){
        it++;
    }
    try {it->torolMeccs(meccs);}
    catch (const char *p){throw;}
}
