#include "interface.h"
#include <iostream>
using namespace std;

void Interface::control(Nyilvantartas& nyilv){
    int valasztas;
    int valasztottcsapat;
    while(1){
    switch(allapot){
        case fomenu:
            mainMenu();
            cin >> valasztas;
            while(allapot==fomenu){
                switch(valasztas){
                    case 1:
                        allapot=csapatlistaz; break;
                    case 2:
                        allapot=csapatadd; break;
                    case 3:
                        allapot=csapattorol; break;
                    case 4:
                        kilep; break;
                    default:
                        cout << "Ilyen lehetõség nincs, próbálja újra" << endl; break;
                }
            }break;
        case csapatlistaz:
            listCsapat(nyilv);
            while(allapot==csapatlistaz){
                cin >> valasztas;
                if(valasztas==0){
                    allapot=fomenu;
                }
                else if(valasztas <=nyilv.getLen()){
                    valasztottcsapat=valasztas;
                    allapot=meccslistaz;
                } else allapot=csapatlistaz;
            } break;
        case meccslistaz:
            try{
                listMeccs(valasztas, nyilv);
            } catch (const char *p){
                allapot=csapatlistaz;
                break;
            }
            while(valasztas==meccslistaz){
                cin >> valasztas;
                switch(valasztas){
                    case(0):
                        allapot=fomenu; break;
                    case(1):
                        allapot=meccsadd; break;
                    case(2):
                        allapot=meccstorol; break;
                    default:
                        cout << "Ilyen lehetõség nincs, próbálja újra" << endl; break;
                }
            } break;
        case meccsadd:
            addMeccs(valasztottcsapat, nyilv);
            allapot=meccslistaz;
            break;
        case meccstorol:
            cout << "Adja be a törölni kívánt meccs sorszámát!" << endl;
            int valasztottm;
            while(allapot==meccstorol){
                cin >>  valasztas;
                if(valasztas==0){
                    allapot=fomenu;
                }
                else{
                    valasztas=valasztottm;
                    allapot=meccslistaz;
                    try{
                        deleteMeccs(valasztottcsapat, valasztottm, nyilv);
                    } catch (const char* p){
                        cout << "Ilyen lehetõség nincs, próbálja újra" << endl;
                        allapot=meccstorol;
                    }
                }
            } break;
        case csapatadd:
            addCsapat(nyilv);
            allapot=fomenu;
            break;
        case csapattorol:
            deleteCsapat(nyilv);
            allapot=fomenu;
            break;
        case csapatkeres:



    }
    }
}

void Interface::mainMenu(){
    allapot=fomenu;
    cout << "Menupont kivalasztasahoz a menüpontnak megfelelõ számot kell beadni!" << endl;
    cout << "1. Csapatok listazasa" << endl << "2. Uj csapat hozzaadasa" << endl << "3. Csapat torlese" << endl <<
    "4. Csapat keresese" << endl << "5. Kilep" << endl;
}

void Interface::listCsapat(Nyilvantartas& nyilv){
    nyilv.listaz();
    cout << "A fomenube valo visszalepeshez adjon be 0-at!" << endl;
    cout << "Adja be annak a csapaatnak a sorszamat, aminek a meccseit megkívánja tekinteni!" << endl;
}

void Interface::listMeccs(int hanyadik, Nyilvantartas& nyilv){
    try{
    nyilv.kiirMeccs(hanyadik);
    } catch (const char *p){
        throw;
    }
    cout << "0. Vissza a fomenube" << endl << "1. Meccs hozzadasa" << endl << "2. Meccs torlese" << endl;
}

void Interface::addMeccs(int valasztottcsapat, Nyilvantartas& nyilv){
    string ellen;
    string hely;
    int ev,honap, nap, ora, perc;
    cout << "Ellenfel neve: ";
    cin >> ellen;
    cout << "Helyszin: ";
    cin >> hely;
    cout << "Datum: (ev.honap.nap. ora:perc)";
    cin >> ev;
    cin.ignore(1,'.');
    cin >> honap;
    cin.ignore(1,'.');
    cin >> nap;
    cin.ignore(2,' ');
    cin >> ora;
    cin.ignore(1,':');
    cin >> perc;
    Meccs* uj=new Meccs(hely, ellen, ev, honap , nap, ora, perc);
    nyilv.addMeccs(valasztottcsapat, uj);
}

void Interface::deleteMeccs(int valasztottcsapat, int valasztottmeccs, Nyilvantartas& nyilv){
    try{
        nyilv.torolMeccs(valasztottcsapat, valasztottmeccs);
    } catch (const char *p){ throw;}
}

void Interface::addCsapat(Nyilvantartas& nyilv){
    cout << "Valassza ki a csapat fajtáját!" << endl;
    cout << "1. Foci" << endl << "2. Kosar" << endl << "3. Kezilabda" << endl;
    int valasztas = 0;
    while(valasztas>3 || valasztas < 1)
        cin >> valasztas;
    string nev, edzo;
    int letszam;
    cout << "Csapat neve: ";
    cin >> nev;
    cout << "Alapletszama: ";
    cin >> letszam;
    cout << "Edzo neve: ";
    cin >> edzo;
    switch(valasztas){
        case 1:
            string medzo;
            cout << "Masodedzo neve: ";
            cin >> medzo;
            nyilv.add(new Foci(nev, letszam, edzo, medzo));
            break;
        case 2:
            int pompom;
            cout << "Pom-pomcsapat letszama: ";
            cin >> pompom;
            nyilv.add(new Kosarlabda(nev, letszam, edzo, pompom));
            break;
        case 3:
            int tamogatas;
            cout << "Tamogatas: ";
            cin >> tamogatas;
            nyilv.add(new Kezilabda(nev, letszam, edzo, tamogatas));
            break;
    }
}

void Interface::deleteCsapat(Nyilvantartas& nyilv){
    cout << "Torolni kivant csapat pontos neve: ";
    string torolnev;
    cin >> torolnev;
    int talalat=nyilv.keresEskiir(torolnev);
    if(talalat==0)
        cout << "Nincs ilyen csapat" << endl;
    else if(talalat==1)
        nyilv.torolElem(torolnev);
    else{
        int valasztas;
        while(valasztas>talalat){
            cout << "Valassza a torolni kivant csapatot!" << endl;
            cin >> valasztas;
            if(valasztas>talalat) cout << "Ilyen lehetõség nincs, próbálja újra" << endl;
        }
        nyilv.torolElem(torolnev, valasztas);
    }
}
