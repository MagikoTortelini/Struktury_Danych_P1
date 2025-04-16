#ifndef tablica_dynamiczna_hpp
#define tablica_dynamiczna_hpp

class Tablica_dynamiczna{
    private:
        int* tab;
        int size;
        // aktualna ilosc elementow
        int actual;
    public: 
        // konstruktor i desktruktor
        Tablica_dynamiczna(int size);
        ~Tablica_dynamiczna();

        int resize();
    
        void add_beg(int element);
        void add_end(int element);
        void add(int element, int position);

        void del_beg();
        void del_end();
        void del(int position);

        bool find(int x) const;
        void display();
};
#endif
