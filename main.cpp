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

    return 0;
}
