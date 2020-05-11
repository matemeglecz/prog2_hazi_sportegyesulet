#ifndef KOSARLABDA_H_INCLUDED
#define KOSARLABDA_H_INCLUDED

#include "csapat.h"
#include <string>
using namespace std;

class Kosarlabda :public Csapat{
    int pompomletszam;
public:
    Kosarlabda(string nev = "", int alapletszam = 0, string edzonev = "", int pomletszam = 0) :Csapat(nev, alapletszam, edzonev), pompomletszam(pomletszam) {}
    void kiir(std::ostream& os = std::cout);
    int getPomletszam() const{return pompomletszam;}
    Kosarlabda& operator=(const Kosarlabda& rhs);
    friend std::istream& operator>>(std::istream& is, Kosarlabda& k);
    ~Kosarlabda() {}
};

std::ostream& operator<<(std::ostream& os, const Kosarlabda& k);
std::istream& operator>>(std::istream& is, Kosarlabda& k);

#endif // KOSARLABDA_H_INCLUDED
