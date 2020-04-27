#include "lista2.h"
#include "meccs.h"

template <typename T>
void Lista<T>::add(T& ujadat){
    ListaElem *uj=new ListaElem;
    uj->adat=ujadat;
    uj->kov=NULL;
    if(eleje=NULL){
        eleje=uj;
    }
    else{
        Iterator vege;
        for(Iterator it = eleje; it!=NULL; it++){
            vege=it;
        }
        vege.elem->kov=uj;
    }
}

template <typename T>
void Lista<T>::torolElem(ListaElem* torlendo){
    if(torlendo==NULL)
        throw "hibas torles";
    if(eleje==torlendo){
        ListaElem* temp=eleje->kov;
        delete eleje;
        eleje=temp;
    }
    else{
        Iterator torlendoelott;
        for(Iterator it = eleje; it.elem.kov!=NULL || it.elem.kov!=torlendo; it++){
            torlendoelott=it;
        }
        if(torlendoelott.elem.kov==torlendo)
            torlendoelott.elem.kov=torlendo->kov;
            delete torlendo;
    }
}

/*template <typename T>
void Lista<T>::torol(){
    Iterator akt(eleje);
    while(akt!=NULL){
        Iterator temp=akt++;
        delete akt.elem;
        akt=temp;
    }
	eleje = NULL;
}
*/

/*template <typename T>
Lista<T>::~Lista(){
    torol();
}
*/
