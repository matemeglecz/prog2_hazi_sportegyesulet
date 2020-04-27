#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

enum Allapotok{fomenu, csapatlistaz, meccslistaz, meccsadd, meccstorol, csapatadd, csapattorol, csapatkeres, kilep};

class Interface{
    Allapotok allapot;
public:
    void control();
    void mainMenu();
    void listCsapat();
    void listMeccs();
    void addMeccs();
    void deleteMeccs();
    void addCsapat();
    void deleteCsapat();
    void searchCsapat();
    void quit();
};

#endif // INTERFACE_H_INCLUDED
