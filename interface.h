#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include "nyilvantartas.h"
#include <string>

struct Allapotok{
    typedef enum {fomenu = 1, csapatlistaz  = 2, meccslistaz = 3, meccsadd = 4, meccstorol = 5, csapatadd = 6, csapattorol = 7, csapatkeres = 8, kilep = 0} allapot;
};

class Interface{
    Allapotok::allapot allapot;
public:
    Interface(Allapotok::allapot all=Allapotok::fomenu) :allapot(all) {}
    void control(Nyilvantartas& nyilv);
    void mainMenu();
    int listCsapat(Nyilvantartas& nyilv);
    void listMeccs(int hanyadik, Nyilvantartas& nyilv);
    void addMeccs(int valasztottcsapat, Nyilvantartas& nyilv);
    void deleteMeccs(int valasztottcsapat, Nyilvantartas& nyilv);
    void addCsapat(Nyilvantartas& nyilv);
    void deleteCsapat(Nyilvantartas& nyilv);
    void searchCsapat(Nyilvantartas& nyilv);

    void vonalhuz(int hossz = 100, char c = '-') const;
    bool isNumber(const char* szam) const;
};

#endif // INTERFACE_H_INCLUDED
