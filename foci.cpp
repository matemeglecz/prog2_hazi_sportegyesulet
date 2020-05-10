#include "foci.h"

void Foci::kiir(std::ostream& os){
   os << "Foci: " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Foci& k) {
    return os << (Csapat&)k << " Masodedzo: " << k.getMasodedzo();
}

Foci& Foci::operator=(const Foci& rhs){
    if(&rhs!=this){
        (Csapat&)*this=(Csapat&)rhs;
//        delete[] masodedzo;
//        masodedzo=new char[strlen(rhs.getMasodedzo())+1];
//        strcpy(masodedzo, rhs.getMasodedzo());
        masodedzo=rhs.getMasodedzo();
    }
    return *this;
}
