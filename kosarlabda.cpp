#include "kosarlabda.h"

void Kosarlabda::kiir(){
    std::cout << "Kosarlabda: " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Kosarlabda& k) {
    return os << (Csapat&)k << " Pompom csapat letszama: " << k.getPomletszam();
}

Kosarlabda& Kosarlabda::operator=(const Kosarlabda& rhs){
    if(&rhs!=this){
        (Csapat&)*this=(Csapat&)rhs;
        pompomletszam=rhs.getPomletszam();
    }
    return *this;
}
