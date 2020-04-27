#include "csapat.h"


std::ostream& operator<<(std::ostream& os, const Csapat& cs) {
    return os << cs.getNev() << " Letszam: " << cs.getLetszam() << " Edzo: " << cs.getEdzo();
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

		/*meccsek.torol();
		for (Lista<Meccs>::Iterator it = rhs.getMeccsek().begin(); it != NULL; ++it) {
			meccsek.add(*it);
		}*/
    }
    return *this;
}

