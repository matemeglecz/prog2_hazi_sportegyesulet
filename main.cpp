#include <iostream>
#include "csapat.h"
#include "foci.h"
#include "kosarlabda.h"
#include "kezilabda.h"
#include "gtest_lite.h"
#include "lista.h"
#include "memtrace.h"


using namespace std;

int main()
{
   Foci f1("Focika", 21, "Jani", "Pisti");
    f1.kiir();
    TEST(foci, nev){
        EXPECT_STREQ("Focika", f1.getNev())<<"nem jo a nev";
    }ENDM

    TEST(foci, letszam){
        EXPECT_EQ(21, f1.getLetszam())<<"nem jo a letszam";
    }ENDM

    TEST(foci, edzo){
        EXPECT_STREQ("Jani", f1.getEdzo())<<"nem jo az edzo";
    }ENDM

    TEST(foci, masodedzo){
        EXPECT_STREQ("Pisti", f1.getMasodedzo())<<"nem jo a masodedzo";
    }ENDM

    f1.getMeccsek().add(new Meccs("BP", "Masik", 2010,12,12,12,12));
    f1.getMeccsek().add(new Meccs("BP", "Masik", 2010,12,12,12,12));
    f1.getMeccsek().add(new Meccs("BP", "Masik", 2010,12,12,12,12));
    f1.getMeccsek().add(new Meccs("BP", "Masik", 2010,12,12,12,12));
    f1.getMeccsek().add(new Meccs("BP", "Masik", 2010,12,12,12,12)); //még nem mûködik a lista
    //f1.getMeccsek().torol();

    Meccs m1("BP", "Masik", 2010,12,12,12,12);

    TEST(meccs, hely){
        EXPECT_STREQ("BP", m1.getHelyszin())<<"nem jo a hely";
    }ENDM

    TEST(meccs, ellenfel){
        EXPECT_STREQ("Masik", m1.getEllenfel())<<"nem jo az ellenfel";
    }ENDM

    TEST(meccs, date){
        EXPECT_EQ(Datum(2010,12,12,12,12), m1.getDatum())<<"nem jo a datum";
    }ENDM




    return 0;
}
