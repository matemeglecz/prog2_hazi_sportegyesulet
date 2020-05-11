#include "interface.h"
#include <iostream>
#include "nyilvantartas.h"
#include "foci.h"
#include "kosarlabda.h"
#include "kezilabda.h"
#include "csapat.h"
#include <cctype>
#include <stdlib.h>
#include "string.h"
using namespace std;

void Interface::vonalhuz(int hossz, char c) const{
 for(int i=0; i<70; i++)
        cout << "-";
    cout << endl;
}

bool Interface::isNumber(const char* szam) const{
    for(size_t i=0; i<strlen(szam); i++){
        if(!isdigit(szam[i]))
            return false;
    }
    return true;
}

void Interface::control(Nyilvantartas& nyilv){
    int valasztottcsapat;
    while(1){
    switch(allapot){
        case Allapotok::fomenu:
            mainMenu();
            break;
        case Allapotok::csapatlistaz:
            valasztottcsapat=listCsapat(nyilv);
            break;
        case Allapotok::meccslistaz:
            listMeccs(valasztottcsapat, nyilv);
            break;
        case Allapotok::meccsadd:
            addMeccs(valasztottcsapat, nyilv);
            allapot=Allapotok::meccslistaz;
            break;
        case Allapotok::meccstorol:
            deleteMeccs(valasztottcsapat, nyilv);
            break;
        case Allapotok::csapatadd:
            addCsapat(nyilv);
            allapot=Allapotok::fomenu;
            break;
        case Allapotok::csapattorol:
            deleteCsapat(nyilv);
            allapot=Allapotok::fomenu;
            break;
        case Allapotok::csapatkeres:
            searchCsapat(nyilv);
            allapot=Allapotok::fomenu;
            break;
        case Allapotok::kilep:
            return;
    }
    }
}


void Interface::mainMenu(){
    allapot=Allapotok::fomenu;
    cout << "Menupont kivalasztasahoz a menupontnak megfelelo szamot kell beadni!" << endl;
    cout << "1. Csapatok listazasa" << endl << "2. Uj csapat hozzaadasa" << endl << "3. Csapat torlese" << endl <<
    "4. Csapat keresese" << endl << "5. Kilep" << endl;
    int valasztas;
    while(allapot==Allapotok::fomenu){
        cin >> valasztas;
        switch(valasztas){
            case 1:
                allapot=Allapotok::csapatlistaz; break;
            case 2:
                allapot=Allapotok::csapatadd; break;
            case 3:
                allapot=Allapotok::csapattorol; break;
            case 5:
                allapot=Allapotok::kilep; break;
            case 4:
                allapot=Allapotok::csapatkeres; break;
            default:
                cout << "Ilyen lehetoseg nincs, probalja ujra" << endl; break;
        }
    }
}

int Interface::listCsapat(Nyilvantartas& nyilv){
    vonalhuz();
    nyilv.listaz();
    vonalhuz();
    cout << "A fomenube valo visszalepeshez adjon be 0-at!" << endl;
    cout << "Adja be annak a csapaatnak a sorszamat, aminek a meccseit megkivanja tekinteni!" << endl;
    int valasztas;
    while(allapot==Allapotok::csapatlistaz){
        cin >> valasztas;
        if(valasztas==0){
            allapot=Allapotok::fomenu;
        }
        else if((unsigned)valasztas <=nyilv.getLen()){
            allapot=Allapotok::meccslistaz;
        } else allapot=Allapotok::csapatlistaz;
    }
    return valasztas;
}

void Interface::listMeccs(int hanyadik, Nyilvantartas& nyilv){
    vonalhuz();
    try{
    nyilv.kiirMeccs(hanyadik);
    } catch (const char *p){
        allapot=Allapotok::csapatlistaz;
        return;
    }
    vonalhuz();
    int valasztas;
    cout << "0. Vissza a fomenube" << endl << "1. Meccs hozzadasa" << endl << "2. Meccs torlese" << endl;
    cin >> valasztas;
        switch(valasztas){
            case(0):
                allapot=Allapotok::fomenu; break;
            case(1):
                allapot=Allapotok::meccsadd; break;
            case(2):
                allapot=Allapotok::meccstorol; break;
            default:
                cout << "Ilyen lehetoseg nincs, probalja ujra" << endl; break;
        }
}

void Interface::addMeccs(int valasztottcsapat, Nyilvantartas& nyilv){
    string ellen;
    string hely;
    char szam[50];
    int ev, honap, nap, ora, perc;
    cout << "Ellenfel neve: ";
    cin.ignore(256,'\n');
    getline(cin, ellen);
    cout << "Helyszin: ";
    getline(cin, hely);
    cout << "Datum: "  << endl;
    bool sikeres=false;
    while(!sikeres){
        cout << "Ev: ";
        cin >> szam;
        if(!isNumber(szam)){
            cout << "Hibas ev, probalja ujra!" << endl;
            cin.ignore(256, '\n');
            continue;
        }
        ev=atoi(szam);

        cout << "Honap: ";
        cin >> szam;
        honap=atoi(szam);
        if(!isNumber(szam) || honap>12 || honap<1){
            cout << "Hibas honap, probalja ujra!" << endl;
            cin.ignore(256, '\n');
            continue;
        }

        cout << "Nap: ";
        cin >> szam;
        nap=atoi(szam);
        if(!isNumber(szam) || nap<1 || nap>31){
            cout << "Hibas nap, probalja ujra!" << endl;
            cin.ignore(256, '\n');
            continue;
        }

        cout << "Ora: ";
        cin >> szam;
        ora=atoi(szam);
        if(!isNumber(szam) || ora<0 || ora>24){
            cout << "Hibas ora, probalja ujra!" << endl;
            cin.ignore(256, '\n');
            continue;
        }

        cout << "Perc: ";
        cin >> szam;
        perc=atoi(szam);
        if(!isNumber(szam) || perc<0 || perc>59){
            cout << "Hibas perc, probalja ujra!" << endl;
            cin.ignore(256, '\n');
            continue;
        }
        sikeres=true;
    }
    Meccs* uj=new Meccs(hely, ellen, ev, honap , nap, ora, perc);
    nyilv.addMeccs(valasztottcsapat, uj);
}

void Interface::deleteMeccs(int valasztottcsapat, Nyilvantartas& nyilv){
    cout << "Adja be a torolni kivant meccs sorszamat!" << endl;
    int valasztottm;
    while(allapot==Allapotok::meccstorol){
        cin >>  valasztottm;
        if(valasztottm==0){
            allapot=Allapotok::fomenu;
        }
        else{
            allapot=Allapotok::meccslistaz;
            try{
                nyilv.torolMeccs(valasztottcsapat, valasztottm);
            } catch (const char* p){
                cout << "Ilyen lehetoseg nincs, probalja ujra" << endl;
                allapot=Allapotok::meccstorol;
            }
        }
    }
}

void Interface::addCsapat(Nyilvantartas& nyilv){
    cout << "Valassza ki a csapat fajtajat!" << endl;
    cout << "1. Foci" << endl << "2. Kosar" << endl << "3. Kezilabda" << endl;
    int valasztas = 0;
    while(valasztas>3 || valasztas < 1)
        cin >> valasztas;
    bool sikeres=false;
    while(!sikeres){
        string nev, edzo;
        char letszam[20];
        cout << "Csapat neve: ";
        cin.ignore(256,'\n');
        getline(cin, nev);
        cout << "Alapletszama: ";
        cin >> letszam;
        if(!isNumber(letszam)){
            cout << "Hibas bemenet, probalja ujra!" << endl;
            continue;
        }
        cout << "Edzo neve: ";
        cin.ignore(256,'\n');
        getline(cin, edzo);
        switch(valasztas){
            case 1:{
                string medzo;
                cout << "Masodedzo neve: ";
                getline(cin, medzo);
                nyilv.add(new Foci(nev, atoi(letszam), edzo, medzo));
                break;}
            case 2:{
                char pompom[20];
                cout << "Pom-pomcsapat letszama: ";
                cin >> pompom;
                if(!isNumber(pompom)){
                    cout << "Hibas bemenet, probalja ujra!" << endl;
                    continue;
                }
                nyilv.add(new Kosarlabda(nev, atoi(letszam), edzo, atoi(pompom)));
                break;}
            case 3:{
                char tamogatas[20];
                cout << "Tamogatas: ";
                cin >> tamogatas;
                if(!isNumber(tamogatas)){
                    cout << "Hibas bemenet, probalja ujra!" << endl;
                    continue;
                }
                nyilv.add(new Kezilabda(nev, atoi(letszam), edzo, atoi(tamogatas)));
                break;}
        }
        sikeres=true;
    }
}

void Interface::deleteCsapat(Nyilvantartas& nyilv){
    cout << "Torolni kivant csapat pontos neve: ";
    string torolnev;
    cin.ignore(256, '\n');
    getline(cin, torolnev);
    vonalhuz();
    int talalat=nyilv.keresEskiir(torolnev);
    vonalhuz();
    if(talalat==0)
        cout << "Nincs ilyen csapat" << endl;
    else if(talalat==1)
        nyilv.torolElem(torolnev);
    else{
        int valasztas;
        while(valasztas>talalat){
            cout << "Valassza a torolni kivant csapatot!" << endl;
            cin >> valasztas;
            if(valasztas>talalat) cout << "Ilyen lehetoseg nincs, probalja ujra" << endl;
        }
        nyilv.torolElem(torolnev, valasztas);
    }
}

void Interface::searchCsapat(Nyilvantartas& nyilv){
    string keresett;
    cout << "A keresett csapat pontos neve: ";
    cin.ignore(256, '\n');
    getline(cin, keresett);
    vonalhuz();
    if(nyilv.keresEskiir(keresett)==0)
        cout << "Nincs talalat" << endl;
    vonalhuz();
}
