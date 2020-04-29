#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>

template <typename T>
class Lista{
    struct ListaElem{
        ListaElem* kov;
        T* adat;
        ListaElem(ListaElem *p=NULL) :kov(p) {}
    };
    ListaElem* eleje;
    size_t len;
public:
    Lista(ListaElem* eleje = NULL) :eleje(eleje), len(0) {}
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

        T* operator*() const {
            if(elem != NULL) return (elem->adat);
            else throw "hibas";
        }


    };

    void torolElem(ListaElem* torlendo){
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
    }

    Iterator begin(){
        return Iterator(eleje);
    }
    Iterator end(){
        return Iterator(NULL);
    }

    void torol(){
        ListaElem* akt=eleje;
        while(akt!=NULL){
            ListaElem* temp=akt->kov;
            delete akt->adat;
            delete akt;
            akt=temp;
        }
        eleje = NULL;
        len=0;
    }

    ~Lista() {torol();}

    void add(T* ujadat){
        ListaElem *uj=new ListaElem;
        uj->adat=ujadat;
        uj->kov=NULL;
        if(eleje==NULL){
            eleje=uj;
        }
        else{
            ListaElem* vege=eleje;
            while(vege->kov!=NULL)
                vege=vege->kov;
        vege->kov=uj;
        }
        len++;
    }

    ListaElem* operator[](size_t hanyadik){
        if(hanyadik>=len) throw "hibas indexeles";
        ListaElem* akt=eleje;
        for(size_t i; i<hanyadik; i++)
            akt=akt->kov;
        return akt;
    }


};

#endif // LISTA_H_INCLUDED
