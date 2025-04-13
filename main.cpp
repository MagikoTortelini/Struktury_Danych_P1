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

using namespace std::chrono;
void test_dodawania_na_poczatku(int ilosc,int typ,int liczba_){

    std::vector<long long> duration_tablica;
    switch (typ)
    {
    case 1:{
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Linked_list<int> list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_at_front(liczba);
                }
                auto start=high_resolution_clock::now();
                list.add_at_front(liczba_);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    }
    case 2:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Double_list list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                list.add_beg(liczba_);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    case 3:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Tablica_dynamiczna tab(ilosc);
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    tab.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                tab.add_beg(liczba_);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;    
    default:
        break;
    }
    std::cout<<"Czas trwania dodawania na poczatek: "<<std::accumulate(duration_tablica.begin(),duration_tablica.end(),0LL)/100<<"ns"<<std::endl;
    std::cout<<std::endl;
}
void test_dodawania_na_koncu(int ilosc,int typ, int liczba_){
std::vector<long long> duration_tablica;
    switch (typ)
    {
    case 1:{
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Linked_list<int> list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_at_front(liczba);
    }
                auto start=high_resolution_clock::now();
                list.add_at_back(liczba_);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    }
    case 2:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Double_list list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                list.add_end(liczba_);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    case 3:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Tablica_dynamiczna tab(ilosc);
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    tab.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                tab.add_end(liczba_);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    default:
        break;
    }
    std::cout<<"Czas trwania dodawania na koncu: "<<std::accumulate(duration_tablica.begin(),duration_tablica.end(),0LL)/100<<"ns"<<std::endl;
    std::cout<<std::endl;
}
void test_usuwania_na_poczatku(int ilosc,int typ){
 std::vector<long long> duration_tablica;
    switch (typ)
    {
    case 1:{
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Linked_list<int> list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_at_front(liczba);
                }
                auto start=high_resolution_clock::now();
                list.delete_front();
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    }
    case 2:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Double_list list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                list.del_beg();
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    case 3:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Tablica_dynamiczna tab(ilosc);
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    tab.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                tab.del_beg();
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    default:
        break;
    }
    std::cout<<"Czas trwania usuwania na poczatku: "<<std::accumulate(duration_tablica.begin(),duration_tablica.end(),0LL)/100<<"ns"<<std::endl;
    std::cout<<std::endl;
}
void test_usuwania_na_koncu(int ilosc,int typ){
std::vector<long long> duration_tablica;
    switch (typ)
    {
    case 1:{
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Linked_list<int> list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_at_front(liczba);
                }
                auto start=high_resolution_clock::now();
                list.delete_end();
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
            
        }
        break;
    }
    case 2:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Double_list list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                list.del_end();
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    case 3:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Tablica_dynamiczna tab(ilosc);
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    tab.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                tab.del_end();
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    default:
        break;
    }
    std::cout<<"Czas trwania usuwania na koncu: "<<std::accumulate(duration_tablica.begin(),duration_tablica.end(),0LL)/100<<"ns"<<std::endl;
    std::cout<<std::endl;
}
void test_wyszukiwania(int ilosc,int typ,int liczba_){
    std::vector<long long> duration_tablica;
    switch (typ)
    {
    case 1:{
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Linked_list<int> list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_at_front(liczba);
                }
                auto start=high_resolution_clock::now();
                list.find(liczba_);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    }
    case 2:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Double_list list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                list.find(liczba_);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    case 3:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Tablica_dynamiczna tab(ilosc);
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    tab.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                tab.find(liczba_);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    default:
        break;
    }
    std::cout<<"Czas trwania wyszukiwania elementu "<<std::accumulate(duration_tablica.begin(),duration_tablica.end(),0LL)/100<<"ns"<<std::endl;
    std::cout<<std::endl;
}
void test_dodawania_na_indexie(int ilosc,int typ,int liczba_,int index){
    std::vector<long long> duration_tablica;
    switch (typ)
    {
    case 1:{
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Linked_list<int> list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_at_front(liczba);
                }
                auto start=high_resolution_clock::now();
                list.insert(liczba_,index);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
            
        }
        break;
    }
    case 2:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Double_list list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                list.add(liczba_,index);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    case 3:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Tablica_dynamiczna tab(ilosc);
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    tab.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                tab.add(liczba_,index);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    default:
        break;
    }
    std::cout<<"Czas trwania dodawania na indeksie: "<<std::accumulate(duration_tablica.begin(),duration_tablica.end(),0LL)/100<<"ns"<<std::endl;
    std::cout<<std::endl;
}
void test_usuwania_na_indeksie(int ilosc,int typ, int index){
    std::vector<long long> duration_tablica;
    switch (typ)
    {
    case 1:{
        std::vector<Linked_list<int>> tablice;
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Linked_list<int> list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_at_front(liczba);
                }
                auto start=high_resolution_clock::now();
                list.delete_index(index);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }

        }
        break;
    }
    case 2:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Double_list list;
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    list.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                list.del(index);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    case 3:
        for(int z=0;z<10;z++){
            for(int i=0;i<10;i++){
                Tablica_dynamiczna tab(ilosc);
                std::string nazwa_pliku = "dane/dane_" + std::to_string(ilosc)+"_"+std::to_string(i) + ".txt";
                std::fstream plik(nazwa_pliku,std::ios_base::in);
                int liczba;
                while (plik >> liczba) {
                    tab.add_beg(liczba);
                }
                auto start=high_resolution_clock::now();
                tab.del(index);
                auto end=high_resolution_clock::now();
                duration_tablica.push_back(duration_cast<nanoseconds>(end-start).count());
            }
        }
        break;
    default:
        break;
    }
   
    std::cout<<"Czas trwania usuwania na indeksie: "<<std::accumulate(duration_tablica.begin(),duration_tablica.end(),0LL)/100<<"ns"<<std::endl;
    std::cout<<std::endl;
}
void testy(int decyzja_){
    std::vector<int> zakres={5000,8000,10000,16000,20000,40000,60000,100000};
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    
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
    case 1:
        system("clear"); 
        std::cout<<"Podaj liczbe: ";
        std::cin>>liczba;
        system("clear"); 
        for(int i=0;i<zakres.size();i++){
            std::cout<<"Test dla zakresu: "<<zakres[i]<<std::endl;
            test_dodawania_na_poczatku(zakres[i],decyzja_,liczba);
        }
        break;
    case 2:
        system("clear"); 
        std::cout<<"Podaj liczbe: ";
        std::cin>>liczba;
        system("clear"); 
        for(int i=0;i<zakres.size();i++){
            std::cout<<"Test dla zakresu: "<<zakres[i]<<std::endl;
            test_dodawania_na_koncu(zakres[i],decyzja_,liczba);
        }
        break;
    case 3:
        system("clear"); 
        std::cout<<"Podaj liczbe: ";
        std::cin>>liczba;
        system("clear"); 
        for(int i=0;i<zakres.size();i++){
            std::uniform_int_distribution<int> dist(0,zakres[i]);
            std::cout<<"Test dla zakresu: "<<zakres[i]<<std::endl;
            test_dodawania_na_indexie(zakres[i],decyzja_,liczba,dist(gen));
        }
        break;
    case 4:
        system("clear"); 
        for(int i=0;i<zakres.size();i++){
            std::cout<<"Test dla zakresu: "<<zakres[i]<<std::endl;
            test_usuwania_na_poczatku(zakres[i],decyzja_);
        }
        break;
    case 5:
        system("clear"); 
        for(int i=0;i<zakres.size();i++){
            std::cout<<"Test dla zakresu: "<<zakres[i]<<std::endl;
            test_usuwania_na_koncu(zakres[i],decyzja_);
        }
        break;
    case 6:
        system("clear"); 
        for(int i=0;i<zakres.size();i++){
            std::uniform_int_distribution<int> dist(0,zakres[i]);
            std::cout<<"Test dla zakresu: "<<zakres[i]<<std::endl;
            test_usuwania_na_indeksie(zakres[i],decyzja_,dist(gen));
        }
        break;
    case 7:
        system("clear"); 
        std::cout<<"Podaj liczbe: ";
        std::cin>>liczba;
        system("clear"); 
        for(int i=0;i<zakres.size();i++){
            std::cout<<"Test dla zakresu: "<<zakres[i]<<std::endl;
            test_wyszukiwania(zakres[i],decyzja_,liczba);
        }
        break;
    case 8:
        temp=false;
        break;
    default:
        temp=false;
        break;
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