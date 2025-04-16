#ifndef double_linked_list_hpp
#define double_linked_list_hpp

#include <iostream>
using namespace std;

// struktura pojedynczego wezla
struct Node {
    int data;
    Node* next;
    Node* prev;

    // konstruktor wezla
    Node(int _data){
        data=_data;
        next=nullptr;
        prev=nullptr;
    }
};

class Double_list{
    private:
        int size;
        Node* head;
        Node* tail;
    public:
        Double_list(){size=0; head=nullptr; tail=nullptr;}
        ~Double_list(){
            Node* temp;
            while (head!=nullptr) {
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        int get_size() const{
            return size;
        }
        void add(int data, int position) {
            if (position < 0 || position > size) return;

            if (position == 1) {
                add_beg(data);
            } else if (position == size) {
                add_end(data);
            } else {
                Node* temp;
                int pos;
        
                // wybor od ktorej strony
               if (position < size / 2) {
                    temp = head;
                    pos = 0;
                    while (pos < position - 1) {
                        temp = temp->next;
                    }
                } else {
                    temp = tail;
                    pos = size - 1;
                    while (pos >= position - 1) {
                        temp = temp->prev;
                    }
                }
                // nowy wezel
                Node* node = new Node(data);
                // wskazniki nowego wezla na sasiadow
                node->next = temp->next;
                node->prev = temp;
        
                // jezeli nastepny istnieje to jego wskaznik prev wskazuje na nowy
                if (temp->next != nullptr){
                    temp->next->prev = node;
                }
                // poprzedni wskazuje na nowy
                temp->next = node;
                size++;
            }
        }
        
        void add_beg(int data){
            Node* node= new Node(data);

            // jesli nie ma elementow
            if(size==0){
                // nowy jest headem i tailem
                tail=node;
                head=node;
                size++;
            }else {
                // nowy wskazuje na pierwszy
                node->next = head;
                // pierwszy wskazuje na nowy
                head->prev = node;
                // node jest teraz headem
                head=node;
                size++;
            }
        }

        void add_end(int data){
            Node* node = new Node (data);

            // jesli lista pusta
            if(head == nullptr){
                head = node;
                tail = node;
                size++;
            } else {
                // tail wskazuje na nowy wezel
                tail->next = node;
                // nowy wezel wskazuje na poprzedni czyli teraz tail
                node->prev = tail;
                // nowy wezel jest teraz tailem
                tail = node;
                size++;
            }
        }

        void del_beg(){
            if (size == 0) return;

            // jezeli rozmiar to 1
            if(size==1){
                delete head;
                head=nullptr;
                tail=nullptr;
            }else{
                // przesuniecie head i usuniecie starego
                Node* temp=head->next;
                delete head;
                head=temp;
                head->prev = nullptr;
            }
            size--;
        }

        void del_end(){
            if (size == 0) return;

            // jezeli rozmiar to 1
            if(size==1){
                delete head;
                head=nullptr;
                tail=nullptr;
            }else{
                // przesuniecie tail i usuniecie starego
                Node* temp=tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
            size--;
        }

        void del(int position) {
            if (position < 0 || position >= size) return;

            if (position == 0) {
                del_beg();
            } else if (position == size - 1) {
                del_end();
            } else {
                Node* temp;
                int pos;
        
                // wybor od ktorej strony
                if (position < size / 2) {
                    temp = head;
                    pos = 0;

                    // przechodzimy do wezla poprzedzajacego
                    while (pos < position - 1) {
                        temp = temp->next;
                        pos++;
                    }
                } else {
                    temp = tail;
                    pos = size - 1;

                    // cofamy sie do wezla przed miejscem usuwania
                    while (pos > position - 1) {
                        temp = temp->prev;
                        pos--;
                    }
                }
                // wskaznik next poprzedniego wezla wskazuje na nastepny element po temp
                temp->prev->next = temp->next;

                // wskaznik prev nastepego wezla wskazuje na element przed temp
                temp->next->prev = temp->prev;
        
                delete temp;
                size--;
            }
        }
        
        bool find(int data) const{
            Node* temp=head;
            while(temp!=nullptr){
                if(temp->data==data){
                    return true;
                }
                temp=temp->next;
            }
            return false;
        }
        void display(){
        Node* temp=head;
        if(temp==nullptr){
            std::cout<<"Lista jest pusta"<<std::endl;
        }
        while(temp!=nullptr){
            std::cout<<temp->data<<", ";
            temp=temp->next;
        }

    }
    };
#endif