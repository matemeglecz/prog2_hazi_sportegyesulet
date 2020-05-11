#include "csapat.h"
#include "meccs.h"

std::ostream& operator<<(std::ostream& os, const Csapat& cs) {
    return os << cs.getNev() << ", Letszam: " << cs.getLetszam() << ", Edzo: " << cs.getEdzo();
}

void Csapat::kiir(std::ostream& os){
    os << (*this) << std::endl;
}

Csapat& Csapat::operator=(const Csapat& rhs){
    if(&rhs!=this){
        csapatnev=rhs.getNev();
        edzo=rhs.getEdzo();
        alapletszam=rhs.getLetszam();
        meccsek=rhs.getMeccsek();
    }
    return *this;
}

Csapat::~Csapat(){if(meccsek.getLen()!=0) meccsek.torol();}


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
    int hanyadik = 0;
    for (Lista<Meccs>::Iterator it = meccsek.begin(); it != meccsek.end(); ++it) {
        os << ++hanyadik << ". ";
        it->kiir(os);
    }
}

std::istream& operator>>(std::istream& is, Csapat& cs){
    is.ignore(1, ' ');
    getline(is, cs.csapatnev, ',');
    is.ignore(100, ':');
    is >> cs.alapletszam;
    is.ignore(7, ':');
    is.ignore(1, ' ');
    getline(is, cs.edzo, ',');
    return is;
}


