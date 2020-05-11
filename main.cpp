#include <iostream>
#include "foci.h"
#include "kosarlabda.h"
#include "kezilabda.h"
#include "gtest_lite.h"
#include "lista.h"
#include "memtrace.h"
#include "meccs.h"
#include "nyilvantartas.h"
#include "interface.h"


using namespace std;

int main()
{
//   Foci f1("Focika", 21, "Jani", "Pisti");
//    f1.kiir();
//    TEST(foci, nev){
//        EXPECT_STREQ("Focika", f1.getNev())<<"nem jo a nev";
//    }ENDM
//
//    TEST(foci, letszam){
//        EXPECT_EQ(21, f1.getLetszam())<<"nem jo a letszam";
//    }ENDM
//
//    TEST(foci, edzo){
//        EXPECT_STREQ("Jani", f1.getEdzo())<<"nem jo az edzo";
//    }ENDM
//
//    TEST(foci, masodedzo){
//        EXPECT_STREQ("Pisti", f1.getMasodedzo())<<"nem jo a masodedzo";
//    }ENDM
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
//
//    //f1.addMeccs(m2);
//    //f1.getMeccsek().torol();
//    //m2->kiir();
//
//    if(f1.getMeccsek().getLen()!=0) std::cout<<"mitortenik"<<endl;
//
//    m1.kiir();
//    std::cout << f1.getMeccsek().getLen() <<std::endl;
//    m1.kiir();
//
//    if(f1.getMeccsek().getLen()!=0) std::cout<<"mitortenik"<<endl;

    Nyilvantartas nyilv;
    //for(int i=0; i< 10; i++)
    //Nyilvantartas ny1;
    nyilv.beolvas("test.txt");

    string nev="ehhh";
    string edzo="uhhh";
    int letszam=2;
    string medzo="kkkk";
//    nyilv.add(new Foci(nev, letszam, edzo, medzo));
//    std::cout<<"faszom";
//    nyilv.addMeccs(1, new Meccs("BP", "Masik", 2010,12,12,12,12));
//    nyilv.addMeccs(2, new Meccs("BP", "Masik", 2010,12,12,12,13));
//    nyilv.addMeccs(1, new Meccs("BP", "Masik", 2010,12,12,12,14));
//    nyilv.addMeccs(1, new Meccs("BP", "Masik", 2010,12,12,12,15));
//
    Interface i;
    i.control(nyilv);
    nyilv.mentes("test.txt");
//    nyilv.listaz();
//
//
//
//
//
//
//
//    TEST(meccs, hely){
//        EXPECT_STREQ("BP", m1.getHelyszin())<<"nem jo a hely";
//    }ENDM
//
//    f1.kiirMeccsek();
//
//    TEST(meccs, ellenfel){
//        EXPECT_STREQ("Masik", m1.getEllenfel())<<"nem jo az ellenfel";
//    }ENDM

//    TEST(meccs, date){
//        EXPECT_EQ(Datum(2010,12,12,12,12), m1.getDatum())<<"nem jo a datum";
//    }ENDM


    return 0;
}
