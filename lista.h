#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>

template <typename T>
class Lista{
    struct ListaElem{
        ListaElem* kov;
        T adat;
        ListaElem(ListaElem *p=NULL) :kov(p) {}
    };
    ListaElem* eleje;
public:
    Lista(ListaElem* eleje = NULL) :eleje(eleje) {}
    class Iterator{
        ListaElem* elem;
    public:
        Iterator(ListaElem* elem=NULL) :elem(elem) {};

        Iterator operator++(){
            if(elem!=NULL)
                elem=elem->kov;
            return *this;
        }

        Iterator operator++(int){
            Iterator temp=*this;
            ++(*this);
            return temp;
        }

        bool operator==(Iterator rhs) const{
            return elem==rhs.elem;
        }

        bool operator==(T& rhs) const{
            return elem.adat==rhs;
        }

        bool operator!=(Iterator rhs) const{
            return elem!=rhs.elem;
        }

        bool operator!=(ListaElem& rhs) const{
            return elem!=rhs;
        }

        T* operator->() const {
            if(elem != NULL) return &(elem->adat);
            else throw "hibas";
        }

        T& operator*() const {
            if(elem != NULL) return (elem->adat);
            else throw "hibas";
        }


    };

    void torolElem(ListaElem* torlendo);

    Iterator begin(){
        return Iterator(eleje);
    }
    Iterator end(){
        return Iterator(NULL);
    }

    void torol(){
        Iterator akt=eleje;
        while(akt!=NULL){
            Iterator temp=akt++;
            delete &akt;
            akt=temp;
        }
        eleje = NULL;
    }

    ~Lista() {torol();}

    void add(T ujadat){
        ListaElem *uj=new ListaElem;
        uj->adat=ujadat;
        uj->kov=NULL;
        if(eleje==NULL){
            eleje=uj;
        }
        else{
            Iterator vege;
            for(Iterator it = eleje; it!=NULL; it++){
                vege=it;
            }
            ++vege=uj;
        }
    }


};

#endif // LISTA_H_INCLUDED
