#include "test.h"
#include <iostream>
#include "foci.h"
#include "kosarlabda.h"
#include "kezilabda.h"
#include "gtest_lite.h"

void test(){
    //foci test
    Foci f1("Focika", 21, "Jani", "Pisti");

    TEST(foci, nev){
        EXPECT_EQ("Focika", f1.getNev())<<"nem jo a nev";
    }ENDM

    TEST(foci, letszam){
        EXPECT_EQ(21, f1.getLetszam())<<"nem jo a letszam";
    }ENDM

    TEST(foci, edzo){
        EXPECT_EQ("Jani", f1.getEdzo())<<"nem jo az edzo";
    }ENDM

    TEST(foci, masodedzo){
        EXPECT_EQ("Pisti", f1.getMasodedzo())<<"nem jo a masodedzo";
    }ENDM

    f1.addMeccs(new Meccs("BP", "Masik", 2010,12,12,12,12));


    //operator=
    Foci f2=f1;

    TEST(focim, nev){
        EXPECT_EQ("Focika", f2.getNev())<<"nem jo a moasolas";
    }ENDM

    TEST(focim, letszam){
        EXPECT_EQ(21, f2.getLetszam())<<"nem jo a moasolas";
    }ENDM

    TEST(focim, edzo){
        EXPECT_EQ("Jani", f2.getEdzo())<<"nem jo a moasolas";
    }ENDM

    TEST(focim, masodedzo){
        EXPECT_EQ("Pisti", f2.getMasodedzo())<<"nem jo a moasolas";
    }ENDM


    //Kosar test
    Kosarlabda k1("Kosaracska tobb szoval", 10, "Edzo ba", 10);

    TEST(kosar, nev){
        EXPECT_EQ("Kosaracska tobb szoval", k1.getNev())<<"nem jo a nev";
    }ENDM

    TEST(kosar, letszam){
        EXPECT_EQ(10, k1.getLetszam())<<"nem jo a letszam";
    }ENDM

    TEST(kosar, edzo){
        EXPECT_EQ("Edzo ba", k1.getEdzo())<<"nem jo az edzo";
    }ENDM

    TEST(kosar, pompom){
        EXPECT_EQ(10, k1.getPomletszam())<<"nem jo a pompomletszam";
    }ENDM

   Kosarlabda k2;
   k2=k1;

    TEST(kosarm, nev){
        EXPECT_EQ("Kosaracska tobb szoval", k2.getNev())<<"nem jo a moasolas";
    }ENDM

    TEST(kosarm, letszam){
        EXPECT_EQ(10, k2.getLetszam())<<"nem jo a moasolas";
    }ENDM

    TEST(kosarm, edzo){
        EXPECT_EQ("Edzo ba", k2.getEdzo())<<"nem jo a moasolas";
    }ENDM

    TEST(kosarm, pompom){
        EXPECT_EQ(10, k1.getPomletszam())<<"nem jo a moasolas";
   }ENDM


    //kezi teszt
    Kezilabda kezi("Kezi tobb szoval es szammal", 40, "Edzo neni", 500000000);

    TEST(kezi, nev){
        EXPECT_EQ("Kezi tobb szoval es szammal", kezi.getNev())<<"nem jo a nev";
    }ENDM

    TEST(kezi, letszam){
        EXPECT_EQ(40, kezi.getLetszam())<<"nem jo a letszam";
    }ENDM

    TEST(kezi, edzo){
        EXPECT_EQ("Edzo neni", kezi.getEdzo())<<"nem jo az edzo";
    }ENDM

    TEST(kezi, tamogatas){
        EXPECT_EQ(500000000, kezi.getTamogatas())<<"nem jo a tamogatas";
    }ENDM

    Kezilabda kezi2=kezi;

    TEST(kezim, nev){
        EXPECT_EQ("Kezi tobb szoval es szammal", kezi2.getNev())<<"nem jo a moasolas";
    }ENDM

    TEST(kezim, letszam){
        EXPECT_EQ(40, kezi2.getLetszam())<<"nem jo a moasolas";
    }ENDM

    TEST(kezim, edzo){
        EXPECT_EQ("Edzo neni", kezi2.getEdzo())<<"nem jo a moasolas";
    }ENDM

    TEST(kezim, tamog){
        EXPECT_EQ(500000000, kezi2.getTamogatas())<<"nem jo a moasolas";
    }ENDM

    //meccs teszt
    Meccs m1("BP", "Masik", 2010,12,12,12,12);

    TEST(meccs, hely){
        EXPECT_EQ("BP", m1.getHelyszin())<<"nem jo a hely";
    }ENDM

    TEST(meccs, ellen){
        EXPECT_EQ("Masik", m1.getEllenfel())<<"nem jo az ellenfel";
    }ENDM

    TEST(meccs, date){
        EXPECT_EQ(Datum(2010,12,12,12,12), m1.getDatum())<<"nem jo a datum";
    }ENDM

    Meccs m2=m1;

    TEST(meccsm, hely){
        EXPECT_EQ("BP", m2.getHelyszin())<<"nem jo a masolas";
    }ENDM

    TEST(meccsm, ellen){
        EXPECT_EQ("Masik", m2.getEllenfel())<<"nem jo a masolas";
    }ENDM

    TEST(meccsm, date){
        EXPECT_EQ(Datum(2010,12,12,12,12), m2.getDatum())<<"nem jo a masolas";
    }ENDM







}
