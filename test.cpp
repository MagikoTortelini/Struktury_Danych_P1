#include <iostream>
#include "linklist.hpp"
#include <fstream>
#include <vector>
#include <chrono>
#include <numeric>
#include "double_linked_list.hpp"
#include "tablica_dynamiczna.hpp"
#include <random>
#include <limits>

void testy(int decyzja_){
    Double_list lista_dwu;
    Linked_list<int> lista_jedno;
    Tablica_dynamiczna tab(1);
    int index;
    int decyzja;
    std::string buff;
    bool temp=true;
    int liczba;
    while(temp){
    system("clear");    
    std::cout<<"TESTOWANIE STRUKTURY:"<<std::endl<<"Wybierz opcje testu:"<<std::endl;
    std::cout<<"1. Test dodawania elementu na poczatku"<<std::endl<<
               "2. Test dodawania elementu na koncu"<<std::endl<<
               "3. Test dodawania elementu na indeksie"<<std::endl<<
               "4. Test usuwania elementu na poczatku"<<std::endl<<
               "5. Test usuwanie elementu na koncu"<<std::endl<<
               "6. Test usuwanie elementu na indeksie"<<std::endl<<
               "7. Test wyszukiwania elementu"<<std::endl<<
               "8. Wroc"<<std::endl;

    
    std::cin>>decyzja;
    switch (decyzja)
    {
    case 1:{
        if(decyzja_==1){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            lista_jedno.add_at_front(liczba);
        }
        else if(decyzja_==2){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            lista_dwu.add_beg(liczba);
        }
        else if(decyzja_==3){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            tab.add_beg(liczba);
        }
    }
        break;
    case 2:{
        system("clear"); 
        if(decyzja_==1){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            lista_jedno.add_at_back(liczba);
        }
        if(decyzja_==2){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            lista_dwu.add_end(liczba);
        }
        else if(decyzja_==3){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            tab.add_end(liczba);
        }
    }
        break;
    case 3:{
        if(decyzja_==1){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            std::cout<<"Podaj indeks"<<std::endl;
            cin>>index;
            lista_jedno.insert(liczba,index);
        }
        if(decyzja_==2){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            std::cout<<"Podaj indeks"<<std::endl;
            cin>>index;
            lista_dwu.add(liczba,index);
        }
        else if(decyzja_==3){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
            cin>>liczba;
            std::cout<<"Podaj indeks"<<std::endl;
            cin>>index;
            tab.add(liczba,index);
        }
    }
        break;
    case 4:
        if(decyzja_==1){
            system("clear");
            lista_jedno.delete_front();
        }
        if(decyzja_==2){
            system("clear");
            lista_dwu.del_beg();
        }
        else if(decyzja_==3){
            system("clear");
            tab.del_beg();
        }
        break;
    case 5:
        if(decyzja_==1){
            system("clear");
            lista_jedno.delete_end();
        }
        if(decyzja_==2){
            system("clear");
            lista_dwu.del_end();
        }
        else if(decyzja_==3){
            system("clear");
            tab.del_end();
        }
        break;
    case 6:
        if(decyzja_==1){
            system("clear");
            std::cout<<"Podaj indeks"<<std::endl;
            cin>>index;
            lista_jedno.delete_index(index);
        }
        if(decyzja_==2){
            system("clear");
            std::cout<<"Podaj indeks"<<std::endl;
            cin>>index;
            lista_dwu.del(index);
        }
        if(decyzja_==3){
            system("clear");
            std::cout<<"Podaj indeks"<<std::endl;
            cin>>index;
            tab.del(index);
        }
        
        break;
    case 7:{
            if(decyzja_==1){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
             cin>>liczba;
            std::cout<<lista_jedno.find(liczba);
        }
        if(decyzja_==2){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
             cin>>liczba;
            std::cout<<lista_dwu.find(liczba);
        }
        if(decyzja_==3){
            system("clear");
            std::cout<<"Podaj liczbe"<<std::endl;
             cin>>liczba;
            std::cout<<tab.find(liczba);
        }
        
    }
        break;
    case 8:
        temp=false;
        break;
    default:
        temp=false;
        break;
    }
    std::cout<<std::endl;
    if(decyzja_==1){
        lista_jedno.display();
    }
    else if(decyzja_==2){
        lista_dwu.display();
    }else if(decyzja_==3){
        tab.display();
    }
    
    std::cout<<std::endl<<"wpisz co kolwiek"<<std::endl;
    std::cin>>buff;
    }

    
}



void wybor_struktury(){
    system("clear"); 
    int decyzja;
    std::cout<<"TESTOWANIE STRUKTUR:"<<std::endl<<"Wybierz struktury do testu:"<<std::endl;
    std::cout<<"1. Lista jednokierunkowa"<<std::endl<<
               "2. Lista dwukierunkowa"<<std::endl<<
               "3. Tablica dynamiczna"<<std::endl;
    std::cin>>decyzja;
    testy(decyzja);

}


int main(){
    while (true)
    {
    wybor_struktury();
    }
    return 0;
}