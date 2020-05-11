#include "kezilabda.h"

void Kezilabda::kiir(std::ostream& os){
    os << "Kezilabda: " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Kezilabda& k) {
    return os << (Csapat&)k << ", tamogatas: " << k.getTamogatas();
}

Kezilabda& Kezilabda::operator=(const Kezilabda& rhs){
    if(&rhs!=this){
        (Csapat&)*this=(Csapat&)rhs;
        tamogatas=rhs.getTamogatas();
    }
    return *this;
}

std::istream& operator>>(std::istream& is, Kezilabda& k){
    is >> (Csapat&)k;
    is.ignore(11, ':');
    is >> k.tamogatas;
    return is;
}
