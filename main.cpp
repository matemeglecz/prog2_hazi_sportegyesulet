#include <iostream>
#include "foci.h"
#include "kosarlabda.h"
#include "kezilabda.h"
#include "gtest_lite.h"
#include "lista.hpp"
#include "memtrace.h"
#include "meccs.h"
#include "nyilvantartas.h"
#include "interface.h"
#include "test.h"

using namespace std;

int main()
{
    test();

//
////   Foci f3=f1;
////   std::cout<<"kesz";
////   f3.kiir();
//
//    Meccs m1("BP", "Masik", 2010,12,12,12,12);
//    /*Meccs* m2=new Meccs;
//    *m2=m1;
//    std::cout << m2->getEllenfel();
//    m2->kiir();*/
//    f1.addMeccs(new Meccs("BP", "Masik", 2010,12,12,12,12));
//    f1.addMeccs(new Meccs("BP", "Masik", 2010,12,12,12,12));
//    f1.addMeccs(new Meccs("BP", "Masik", 2010,12,12,12,12));
//    f1.addMeccs(new Meccs("BP", "Masik", 2010,12,12,12,12));
//    f1.addMeccs(new Meccs("BP", "Masik", 2010,12,12,12,12));


    Nyilvantartas nyilv;
    try{
        nyilv.beolvas();
    }catch(const char*){
        cout << "Nem sikerult megnyitni a fajlt." << endl;
        return 0;
    }

    Interface interface;
    interface.control(nyilv);

    try{
        nyilv.mentes();
    }catch(const char*){
        cout << "Nem sikerult megnyitni a fajlt." << endl;
        return 0;
    }


//    nyilv.add(new Foci(nev, letszam, edzo, medzo));
//    nyilv.addMeccs(1, new Meccs("BP", "Masik", 2010,12,12,12,12));
//    nyilv.addMeccs(2, new Meccs("BP", "Masik", 2010,12,12,12,13));
//    nyilv.addMeccs(1, new Meccs("BP", "Masik", 2010,12,12,12,14));
//    nyilv.addMeccs(1, new Meccs("BP", "Masik", 2010,12,12,12,15));


    return 0;
}
