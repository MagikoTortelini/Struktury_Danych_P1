#ifndef double_linked_list_hpp
#define double_linked_list_hpp

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

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
        Double_list(){
            size=0;
            head=nullptr;
            tail=nullptr;
        }
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
            if (position == 0) {
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
                    while (pos < position - 2) {
                        temp = temp->next;
                        pos++;
                    }
                } else {
                    temp = tail;
                    pos = size - 1;
                    while (pos >= position - 1) {
                        temp = temp->prev;
                        pos--;
                    }
                }
        
                Node* node = new Node(data);
                node->next = temp->next;
                node->prev = temp;
        
                if (temp->next != nullptr){
                    temp->next->prev = node;
                }
                temp->next = node;
                size++;
            }
        }
        
        void add_beg(int data){
            Node* node= new Node(data);
            if(size==0){
                tail=node;
                head=node;
                size++;
            }
            else {
                node->next = head;
                head->prev = node;
                head=node;
                size++;
            }
        }

        void add_end(int data){
            Node* node = new Node (data);
            if(head == nullptr){
                head = node;
                tail = node;
                size++;
            } else {
                tail->next = node;
                node->prev = tail;
                tail = node;
                size++;
            }
    }

        void del_beg(){
            if(size==1){
                delete head;
                head=nullptr;
                tail=nullptr;
            }else{
                Node* temp=head->next;
                delete head;
                head=temp;
                head->prev = nullptr;
            }
            size--;
        }

        void del_end(){
            if(size==1){
                delete head;
                head=nullptr;
                tail=nullptr;
            }else{
                Node* temp=tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
            size--;
        }

        void del(int position) {
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
                    while (pos < position - 1) {
                        temp = temp->next;
                        pos++;
                    }
                } else {
                    temp = tail;
                    pos = size - 1;
                    while (pos > position - 1) {
                        temp = temp->prev;
                        pos--;
                    }
                }
                // temp to teraz element do usunięcia
                temp->prev->next = temp->next;
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
    };
#endif

