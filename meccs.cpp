#include "meccs.h"

void Meccs::kiir(){
    std::cout << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Meccs& m) {
    return os << "Ellenfel: " << m.getEllenfel() << " Helyszin: " << m.getHelyszin() << " Datum: " << m.getDatum();
}

Meccs& Meccs::operator=(const Meccs& rhs){
    if(&rhs!=this){
        delete[] ellenfel;
        delete[] helyszin;
        ellenfel=new char[strlen(rhs.getEllenfel())+1];
        helyszin=new char[strlen(rhs.getHelyszin())+1];
        strcpy(ellenfel, rhs.getEllenfel());
        strcpy(helyszin, rhs.getHelyszin());
        datum=rhs.getDatum();
    }
    return *this;
}
