#ifndef LINKLIST_H
#define LINKLIST_H

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(T _data,Node* _next){
        data=_data;
        next=_next;
    }
};




template <typename T>
class Linked_list
{
private:
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    Linked_list(){
        size=0;
        head=nullptr;
        tail=nullptr;
    }
    ~Linked_list(){
        Node<T>* temp;
        while (head!=nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    int get_size(){
        return size;
    }
    void insert(T data,int pozycja){
        if(size==0||pozycja==0){
            add_at_front(data);
        }
        else if(pozycja<size&&pozycja>0){
            int pos=1;
            Node<T>* temp=head;
            while(temp->next!=nullptr){
                if(pos==pozycja){
                   Node<T>* node= new Node<T>(data,temp->next);
                   temp->next=node;
                   size+=1; 
                   return;
                }
                temp=temp->next;
                pos+=1;

            }
        }else if(pozycja==size){
            add_at_back(data);
        }
        else{
            std::cout<<"Indeks poza lista"<<std::endl;
        }
    }
    void add_at_front(T data){
        if(size==0){
            Node<T>* node= new Node<T>(data,tail);
            tail=node;
            head=node;
            size+=1;

        }
        else if(size>0){
            Node<T>* temp=head;
            Node<T>* node= new Node<T>(data,temp);
            head=node;
            size+=1;

        }
    }
    void delete_front(){
        if(size==0){
            std::cout<<"Lista jest pusta"<<std::endl;
        }
        else if(size==1){
             delete head;
            head=nullptr;
            tail=nullptr;
            size-=1;
        }
        else{
            Node<T>* temp=head->next;
            delete head;
            head=temp;
            size-=1;

        }
    }
    void delete_end(){
        if(size==0){
            std::cout<<"Lista jest pusta"<<std::endl;
        }
        else if(size==1){
            delete head;
            head=nullptr;
            tail=nullptr;
            size-=1;
        }
        else{
            Node<T>* temp=head;
            while(temp->next!=nullptr){
                if(temp->next==tail){
                    delete tail;
                    tail=temp;
                    tail->next=nullptr;
                    size-=1;
                    break;

                }else{
                temp=temp->next;
                }
                
        }
        }
    }
    void delete_index(int pozycja){
        if(size==0){
            std::cout<<"Lista jest pusta"<<std::endl;
        }
        else if(pozycja==0){
            delete_front();
        }
        else if(pozycja<size&&pozycja>0){
            int pos=1;
            Node<T>* temp=head;
            while(temp->next!=nullptr){
                if(pos==pozycja-1){
                   Node<T>* temp2=temp->next;
                   temp->next=temp2->next; 
                   delete temp2;
                   size-=1; 
                   return;
                }
                temp=temp->next;
                pos+=1;

            }
        }else if(pozycja==size){
            delete_end();
        }
        else{
            std::cout<<"Indeks poza lista"<<std::endl;

    }
    }
    void add_at_back(T data){
            if(size == 0){
                Node<T>* node = new Node<T>(data, nullptr);
                head = node;
                tail = node;
                size+=1;
            } 
            else {
                Node<T>* node = new Node<T>(data, nullptr);
                if (tail)
                    tail->next = node;
                tail = node;
                size+=1;
            }
            


    }
    void display(){
        Node<T>* temp=head;
        if(temp==nullptr){
            std::cout<<"Lista jest pusta"<<std::endl;
        }
        while(temp!=nullptr){
            std::cout<<temp->data<<std::endl;
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
    void find(T data){
        Node<T>* temp=head;
        while(temp!=nullptr){
            if(temp->data==data){
                std::cout<<"Liczba znajduje sie w liscie"<<std::endl;
                return;
            }
            temp=temp->next;
        }
        std::cout<<"Liczby nie ma w liscie"<<std::endl;

    }

};



#endif