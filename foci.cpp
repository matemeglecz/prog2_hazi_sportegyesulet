#include "foci.h"

void Foci::kiir(std::ostream& os){
   os << "Foci: " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Foci& k) {
    return os << (Csapat&)k << ", Masodedzo: " << k.getMasodedzo();
}

Foci& Foci::operator=(const Foci& rhs){
    if(&rhs!=this){
        (Csapat&)*this=(Csapat&)rhs;
        masodedzo=rhs.getMasodedzo();
    }
    return *this;
}

std::istream& operator>>(std::istream& is, Foci& f){
    is >> (Csapat&)f;
    is.ignore(12, ':');
    is.ignore(1, ' ');
    getline(is, f.masodedzo);
    return is;
}
