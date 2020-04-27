#ifndef KEZILABDA_H_INCLUDED
#define KEZILABDA_H_INCLUDED

#include "csapat.h"

class Kezilabda :public Csapat{
    int tamogatas;
public:
    Kezilabda(const char* nev, int alapletszam, const char* edzonev, int tamogatas) :Csapat(nev, alapletszam, edzonev), tamogatas(tamogatas) {}
    void kiir();
    int getTamogatas() const{return tamogatas;}
    Kezilabda& operator=(const Kezilabda& rhs);
    ~Kezilabda() {}
};

std::ostream& operator<<(std::ostream& os, const Kezilabda& k);

#endif // KEZILABDA_H_INCLUDED
