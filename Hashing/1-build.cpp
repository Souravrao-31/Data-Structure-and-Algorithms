//Implement a hashing
//Seperate Chaining Technique

#include<iostream>
#include<cstring>
#include "hashtable.h"
using namespace std;

template<typename T>
class Node{
    public:
    string key;
    T value;
    Node<T>*next;

    Node(string key, T val){
      this->key = key;
      value = val;
      next = NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

template<typename T>
class Hashtable
{
  
  Node<T>** table; //pointer to an array of pointers
  int current_size;
  int table_size;


  int hashFn(string key){
      int idx=0;
      int p=1; //power is one
      for(int j=0;j<key.length();j++){
          idx = idx + (key[j] * p )% table_size;
          idx = idx%table_size;
          p = (p*27)%table_size;
      }
      return idx;

  }
   void rehash(){

       Node<T>** oldtable = table;
       int oldtable_size = table_size;
       table_size = 2*table_size;
       table = new Node<T>*[table_size];

       for(int i=0; i<table_size;i++){
           table[i] = NULL;
       }
       current_size = 0;

       //Shift the element from old table to new table
       for(int i=0;i<oldtable_size;i++){

          Node<T>*temp = oldtable[i];
          while(temp != NULL){
            insert(temp->key,temp->value);
            temp = temp->next;
          }
          if(oldtable[i] != NULL){
              delete oldtable[i];  //it will deleted recursively
          }
       }
       delete [] oldtable;
   }

  public:
    Hashtable(int ts=7){
        table_size = ts;
        table = new Node<T>*[table_size]; 

        current_size =0;
        for(int i=0;i<table_size;i++){
            table[i]=NULL;
        }

    }

    void insert(string key, T value)
    {
        int idx = hashFn(key);
        Node<T> *n = new Node<T>(key, value);
        //Insert at head of the linked list with id=idx
        n->next = table[idx];
        table[idx] = n;
        current_size++;

        //rehashing

        float Load_factor = current_size/(1.0*table_size);
        if(Load_factor > 0.7){
            rehash();
        }
    }

    void print()
    {
        for (int i = 0; i < table_size; i++)
        {
            cout<<"Bucket "<<i<<"->";
            Node<T> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
    T* Search(string key){
        int idx = hashFn(key);
        Node<T>*temp = table[idx];
        while(temp != NULL){
           if(temp->key==key){
               return &temp->value;
           }

        }
        return NULL;
    }
    T& operator[](string key){
        T*f =Search(key);
        if(f==NULL){
           //Insert key, value(garbage) in the hashmap
           T garbage;
           insert(key,garbage);
           f = Search(key);
        }
        return *f;
    }
    void erase(){

    }
};

/*
what is rehashing
Increae the table size as no of elements increment.
*/



int main(){
    Hashtable<int> price_menu;

    price_menu.insert("Burger",150);
    price_menu.insert("Maggi", 50);
    price_menu.insert("Cold coffee", 180);
    price_menu.insert("Paneer chilly", 250);
   
    price_menu.insert("Oreo shake", 120);
    
    

    price_menu.print();

    //search  function
    int *price = price_menu.Search("Burger");
    if(price==NULL){
       cout<<"Not Found! ";
    }
    else{
        cout<<"Price is "<<*price<<endl;
    }

    //insert
    price_menu["fries"] = 100;
    //update
    price_menu["fries"] += 20;
    //Search
    cout<<"Price of fries ";
    cout<< price_menu["fries"]<<endl;
    return 0;
}
