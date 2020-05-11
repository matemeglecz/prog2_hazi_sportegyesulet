#include "meccs.h"

void Meccs::kiir(std::ostream& os){
    os << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Meccs& m) {
    return os << "Ellenfel: " << m.getEllenfel() << ", Helyszin: " << m.getHelyszin() << ", Datum: " << m.getDatum();
}

Meccs& Meccs::operator=(const Meccs& rhs){
    if(&rhs!=this){
        helyszin=rhs.getHelyszin();
        ellenfel=rhs.getEllenfel();
        datum=rhs.getDatum();
    }
    return *this;
}

std::istream& operator>>(std::istream& is, Meccs& m){
    is.ignore(50, ':');
    is.ignore(1, ' ');
    getline(is, m.ellenfel, ',');
    is.ignore(12, ':');
    is.ignore(1, ' ');
    getline(is, m.helyszin, ',');
    is.ignore(8, ':');
    int ev, ora, perc, honap, nap;
    is >> ev;
    is.ignore(1, '.');
    is >> honap;
    is.ignore(1, '.');
    is >> nap;
    is.ignore(2, ' ');
    is >> ora;
    is.ignore(1, ':');
    is >> perc;
    m.datum=Datum(ev,honap, nap, ora, perc);
    return is;
}
