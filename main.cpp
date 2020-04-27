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

    f1.getMeccsek().add(Meccs("BP", "Masik", 2010,12,12,12,12));
    f1.getMeccsek().torol();

    return 0;
}
