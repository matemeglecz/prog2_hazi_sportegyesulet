#include "kezilabda.h"

void Kezilabda::kiir(){
    std::cout << "Kezilabda: " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Kezilabda& k) {
    return os << (Csapat&)k << " tamogatas: " << k.getTamogatas();
}

Kezilabda& Kezilabda::operator=(const Kezilabda& rhs){
    if(&rhs!=this){
        (Csapat&)*this=(Csapat&)rhs;
        tamogatas=rhs.getTamogatas();
    }
    return *this;
}
