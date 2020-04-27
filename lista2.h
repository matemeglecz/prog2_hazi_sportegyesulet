#ifndef LISTA2_H_INCLUDED
#define LISTA2_H_INCLUDED
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

        ListaElem* operator&(){
            return elem;
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
    Iterator akt(eleje);
    while(akt!=NULL){
        Iterator temp=akt++;
        delete &akt;
        akt=temp;
    }
	eleje = NULL;
    }

    ~Lista() {this->torol();}

    void add(T& ujadat);


};

#endif // LISTA2_H_INCLUDED
