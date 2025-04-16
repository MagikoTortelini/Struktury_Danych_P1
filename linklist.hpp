#ifndef LINKLIST_H
#define LINKLIST_H

template <typename T>
struct NodeS // Struktura bloku
{
    T data;
    NodeS<T>* next;

    NodeS(T _data,NodeS* _next){
        data=_data;
        next=_next;
    }
};




template <typename T>
class Linked_list
{
private:
    int size;
    NodeS<T>* head;
    NodeS<T>* tail;
public:
    Linked_list(){ //konstruktor
        size=0;
        head=nullptr;
        tail=nullptr;
    }
    ~Linked_list(){ //destruktor
        NodeS<T>* temp;
        while (head!=nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    int get_size(){ //zwrocenie wielkosci listy
        return size;
    }
    void insert(T data,int pozycja){//wsadzenie elementu na indeksie
        if(size==0||pozycja==0){ //jezeli lista jest pusta lub indeks wynosi 0 dodajemy na poczatku
            add_at_front(data);
        }
        else if(pozycja<size&&pozycja>0){//jezeli indeks jest wiekszy od 0 i mniejszy od wielkosci listy przechodzimy przez liste az nie dotrzemy do miejsca w ktorym ma znajdowac sie element
            int pos=1;
            NodeS<T>* temp=head;
            while(temp->next!=nullptr){
                if(pos==pozycja){
                   NodeS<T>* Node= new NodeS<T>(data,temp->next);//stworzenie bloku
                   temp->next=Node; //umieszczenie bloku na wyznaczonym miejscu
                   size+=1; 
                   return;
                }
                temp=temp->next;
                pos+=1;

            }
        }else if(pozycja==size){//jezeli indeks wynosi rozmiar listy dodajemy element na koncu
            add_at_back(data);
        }
        else{// jezeli indeks jest poza zakresem nic nie robimy
            std::cout<<"Indeks poza lista"<<std::endl;
        }
    }
    void add_at_front(T data){
        if(size==0){//jezlei lista jest pusta stworzony blok bedzie head i tailem
            NodeS<T>* Node= new NodeS<T>(data,tail); //utworzenie bloku
            tail=Node;//przypisanie bloku jak tail
            head=Node;//przypisanie bloku jak head
            size+=1;

        }
        else if(size>0){
            NodeS<T>* temp=head;//tymczasowe wskazanie head
            NodeS<T>* Node= new NodeS<T>(data,temp);//utworzenie bloku z wskaznikiem na aktualny head
            head=Node;//przypisanie heada jako nowy blok
            size+=1;

        }
    }
    void delete_front(){
        if(size==0){//jezli lista jest pusta nic nie robimy
            std::cout<<"Lista jest pusta"<<std::endl;
        }
        else if(size==1){//jezeli jest 1 element po prostu go usuwamy i zmieniamy head i tail na null
            delete head; //usuniecie pierwszego bloku
            head=nullptr;//przypisanie head jako null
            tail=nullptr;//przypisanie tail jako null
            size-=1;
        }
        else{// w przeciwnym razie przechowujemy na jaki element wskazuje aktualny head i usuwamy head, po czym przypisujemy head jako przechowywany element
            NodeS<T>* temp=head->next;//przechowanie nastepnego elementu heada
            delete head;//usuniecie head
            head=temp;//przypisanie nowego heada
            size-=1;

        }
    }
    void delete_end(){
        if(size==0){//jezeli lista jest pusta nic nie robimy
            std::cout<<"Lista jest pusta"<<std::endl;
        }
        else if(size==1){//jezeli list jest pusta po prostu usuwamy head i ustawiamy head i tail na null
            delete head;//usuniecie heada
            head=nullptr;//przypisanie heada jako null
            tail=nullptr;//przypisnie taila jako null
            size-=1;
        }
        else{// w przeciwnym razie przechodzimy przez cala liste az nie dojdziemy do przedostatniego elementu po czym usuwamy nastepny element i ustawiamy przedostatni jako nowy tail
            NodeS<T>* temp=head;
            while(temp->next!=nullptr){
                if(temp->next==tail){
                    delete tail;//usuniecie taila
                    tail=temp;//przypisanie taila jako przedostaniego elementu
                    tail->next=nullptr;//zmiana na co wskazuje ostatni element
                    size-=1;
                    break;

                }else{
                temp=temp->next;// przejscie dalej w petli
                }
                
        }
        }
    }
    void delete_index(int pozycja){
        if(size==0){//jezeli lista jest pusta nic nie robimy
            std::cout<<"Lista jest pusta"<<std::endl;
        }
        else if(pozycja==0){//jezeli indeks wynosi 0 to uzywamy funkcji usuniecia poczatku
            delete_front();
        }
        else if(pozycja<size&&pozycja>0){// jezeli indesk jest wieksz od 0 i mniejszy od wielkosci listy przechodzimy przez liste az nie dotrzemy o miejsca ktore mamy usunac, po czym przechowujemy nastepny element jaki wskazuje element do usuniecia, usuwamy go i przypisujemy nastepny element do poprzedniego
            int pos=1;
            NodeS<T>* temp=head;
            while(temp->next!=nullptr){
                if(pos==pozycja-1){
                   NodeS<T>* temp2=temp->next;// przechowanie na co wskazuje element ktory usuniemy
                   temp->next=temp2->next; // przypisanie na co wskazuje usuwany element do poprzedniego
                   delete temp2;//usunie elmentu
                   size-=1; 
                   return;
                }
                temp=temp->next;// przejscie dalej w petli
                pos+=1;

            }
        }else if(pozycja==size){//jezlie indeks wynosi wielkosc listy uzywamy funkcji usuniecia na koncu
            delete_end();
        }
        else{// jezeli indeks jest poza zakresem to nic nie robimy
            std::cout<<"Indeks poza lista"<<std::endl;

    }
    }
    void add_at_back(T data){
            if(size == 0){//jezeli jest pierwszym elementem tworzymy nowy blok i przypisujemy go jako head i tail
                NodeS<T>* Node = new NodeS<T>(data, nullptr);// stworzenie nowego bloku wskazujacego na null
                head = Node;//przypisanie bloku jako head
                tail = Node;//przypisanie bloku jako head
                size+=1;
            } 
            else {//jezli nie jest pierwszym elementem tworzymy nowy blok wskazujcy null i przypisujemy aktualnemy tailowy jako nastepny element nowy blok po czym zastepujemy taila nowym blokiem
                NodeS<T>* Node = new NodeS<T>(data, nullptr);// stworzenie nowego bloku wskazujacego na null
                if (tail) //sprawdzenie czy istnieje tail
                    tail->next = Node;//przypisanie aktualnemu tailowmi nowego elementi
                tail = Node;//ustawienie nowego taila
                size+=1;
            }
            


    }
    void display(){
        NodeS<T>* temp=head;
        if(temp==nullptr){
            std::cout<<"Lista jest pusta"<<std::endl;
        }
        while(temp!=nullptr){
            std::cout<<temp->data<<", ";
            temp=temp->next;
        }

    }
    void display_last(){
        if(tail!=nullptr){
            std::cout<<tail->data<<std::endl;
        }
        else{
        std::cout << "Lista jest pusta" << std::endl;
        }
        
    }
    bool find(T data){
        NodeS<T>* temp=head;
        while(temp!=nullptr){//przejscie przez cala liste jezeli znajdziemy element zwracamy true w przeciwnym razie false
            if(temp->data==data){

                return true;
            }
            temp=temp->next;// przejscie dalej w petli
        }
        return false;

    }

};



#endif