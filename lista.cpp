#include "lista.h"

/*template <typename T>
void Lista<T>::torolElem(ListaElem* torlendo){
    if(torlendo==NULL)
        throw "hibas torles";
    if(eleje==torlendo){
        ListaElem* temp=eleje->kov;
        delete eleje;
        eleje=temp;
    }
    else{
        ListaElem* mozgo=eleje;
        while(mozgo->kov!=torlendo && mozgo!=NULL){
            mozgo=mozgo->kov;
        }
        if(mozgo==NULL) throw "nincs ilyen elem";
        mozgo->kov=torlendo->kov;
        delete torlendo->adat;
        delete torlendo;
    }
    --len;
}*/


