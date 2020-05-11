#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include "nyilvantartas.h"

enum Allapotok{fomenu = 1, csapatlistaz  = 2, meccslistaz = 3, meccsadd = 4, meccstorol = 5, csapatadd = 6, csapattorol = 7, csapatkeres = 8, kilep = 0};

class Interface{
    Allapotok allapot;
public:
    Interface() :allapot(fomenu) {}
    void control(Nyilvantartas& nyilv);
    void mainMenu();
    void listCsapat(Nyilvantartas& nyilv);
    void listMeccs(int hanyadik, Nyilvantartas& nyilv);
    void addMeccs(int valasztottcsapat, Nyilvantartas& nyilv);
    void deleteMeccs(int valasztottcsapat, int valasztottmeccs, Nyilvantartas& nyilv);
    void addCsapat(Nyilvantartas& nyilv);
    void deleteCsapat(Nyilvantartas& nyilv);
    void searchCsapat(Nyilvantartas& nyilv);
    void quit();
};

#endif // INTERFACE_H_INCLUDED
