#include <iostream>
#include <fstream>
#include "tablica_dynamiczna.hpp"

using namespace std;

Tablica_dynamiczna::Tablica_dynamiczna(int s) {actual = 0; size = s; tab = new int[size];}
Tablica_dynamiczna::~Tablica_dynamiczna() {delete[] tab;}

int Tablica_dynamiczna::resize() {
    int n_size = 2*size;
    int* n_tab = new int[n_size];

    for (int i=0; i<size; i++) {
        n_tab[i]=tab[i];
    }
    delete[] tab;
    tab = n_tab;
    size = n_size;
    return size;
}

void Tablica_dynamiczna::add_beg(int element) {
    if(actual==size){resize();}
    for(int i = actual - 1;i>=0;i--){ 
        tab[i+1]=tab[i];
    }
    tab[0]=element;
    actual++;
}

void Tablica_dynamiczna::add_end(int element) {
    if(actual==size){resize();}
    tab[actual]=element;
    actual++;
}


void Tablica_dynamiczna::add(int element, int position){
    position--;
    if (position < 0 || position > actual) return;

    if(actual==size){resize();}
    for(int i=actual; i>position; i--){
        tab[i]=tab[i-1];
    }
    tab[position]=element;
    actual++;
}

void Tablica_dynamiczna::del_beg(){
    for(int i = 0; i < actual-1;i++){
        tab[i]=tab[i+1];
    }
    actual--;
}

void Tablica_dynamiczna::del_end(){
    if (actual > 0) {
        actual--;
    }    
}

void Tablica_dynamiczna::del(int position) {
    position--;
    if (position < 0 || position >= actual) return;
    for(int i = position; i < actual - 1; i++) {
        tab[i]=tab[i+1];
    }
    actual--;
}
bool Tablica_dynamiczna::find(int x) const{
    for(int i = 0; i<actual; i++) {
        if(tab[i]==x){
            return true;
        }
    }
    return false;
}
void Tablica_dynamiczna::display(){
    for(int i = 0; i<actual; i++) {

        std::cout<<tab[i]<<", ";
    }
}




