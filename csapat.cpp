#include "csapat.h"
#include "meccs.h"

std::ostream& operator<<(std::ostream& os, const Csapat& cs) {
    return os << cs.getNev() << " Letszam: " << cs.getLetszam() << " Edzo: " << cs.getEdzo() << "Meccsek száma: " << cs.getMeccsek().getLen();
}

void Csapat::kiir(std::ostream& os){
    os << (*this) << std::endl;
}

Csapat& Csapat::operator=(const Csapat& rhs){
    if(&rhs!=this){
        delete[] csapatnev;
        delete[] edzo;
        csapatnev=new char[strlen(rhs.getNev())+1];
        edzo=new char[strlen(rhs.getEdzo())+1];
        strcpy(edzo, rhs.getEdzo());
        strcpy(csapatnev, rhs.getNev());
        alapletszam=rhs.getLetszam();
        meccsek=rhs.getMeccsek();
//		meccsek.torol();
//		for (Lista<Meccs>::Iterator it = rhs.getMeccsek().begin(); it != NULL; ++it) {
//			meccsek.add(&(*it));
		//}
    }
    return *this;
}

Csapat::~Csapat(){
        delete[] csapatnev;
        delete[] edzo;
        if(meccsek.getLen()!=0) meccsek.torol();
        std::cout << "csapatwtf" <<std::endl;
}


void Csapat::addMeccs(Meccs* uj){
    meccsek.add(uj);
}

void Csapat::torolMeccs(int torlendo){
    if((unsigned)torlendo > meccsek.getLen()) throw "hibas torles";
    Lista<Meccs>::Iterator it=meccsek.begin();
    for(int i=0; i<torlendo; i++){
        it++;
    }
    meccsek.torolElem(it);
}

void Csapat::kiirMeccsek(std::ostream& os){
    for (Lista<Meccs>::Iterator it = meccsek.begin(); it != meccsek.end(); ++it) {
        it->kiir(os);
    }
}


