#ifndef KEZILABDA_H_INCLUDED
#define KEZILABDA_H_INCLUDED

#include "csapat.h"
#include <string>

using namespace std;

class Kezilabda :public Csapat{
    int tamogatas;
public:
    Kezilabda(string nev = "", int alapletszam = 0, string edzonev = "", int tamogatas = 0) :Csapat(nev, alapletszam, edzonev), tamogatas(tamogatas) {}
    void kiir(std::ostream& os = std::cout);
    int getTamogatas() const{return tamogatas;}
    Kezilabda& operator=(const Kezilabda& rhs);
    friend std::istream& operator>>(std::istream& is, Kezilabda& k);
    ~Kezilabda() {}
};

std::ostream& operator<<(std::ostream& os, const Kezilabda& k);
std::istream& operator>>(std::istream& is, Kezilabda& k);

#endif // KEZILABDA_H_INCLUDED
