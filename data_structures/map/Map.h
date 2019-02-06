//
// Created by Nathan Wayne on 2019-02-05.
//

#ifndef UNTITLED_MAP_H
#define UNTITLED_MAP_H
#include "Node.h"
#include<list>
using namespace std;
template<typename Key, typename Value>
class Map{
private:
    Node<Key,Value> **myList;

    Map(){
        myList = new list<Node<Key,Value>>;
    }

    void put(Key key, Value value){
        int index = (key%1000); // change this to actual hash later
        if(myList[index]==NULL){
            myList[index] = new Node<Key,Value>(key,value); // if nothing at index insert a new node
        }
        else {
            Node<Key,Value> *entry = myList[index];
            while(entry->getNext() != NULL){ // if there is already elements here traverse till end
                entry = entry->getNext();
            }
            if (entry->getKey() == key) {//if element has the same key set value as this value
                entry->setValue(value);
            }
            else
                entry->setNext()(new Node(key,value)) // if key doesnt already exist throw it at end

        }
    }

    int get(Key key){
        int index= key%1000; //change later to actual hash
        if(myList[index] == NULL)// if key doesnt exist send back error
            return -1;
        else {
            Node<Key, Value> *entry = myList[index];
            while(entry != NULL && entry->getKey()) {// while you are not at end of list and the key at index istn the key you are looking for
                entry = entry->getNext(); // traverse list
            }
            if(entry == NULL) {
                return -1; // if you reach end of list return error
            }
            else return entry->getValue;// if this runs then you found the key you were looking for and you return itst value


        }
    }

    void remove(Key key){
        int index = key%1000;// change later to actual hash
        if(myList[index] != NULL){// there exists at least one Node at given hashed key
            Node<Key,Value> *prev = NULL;
            Node<Key,Value> *entry = myList[index];
            while(entry->getNext() != NULL && entry->getKey() != key){
                prev = entry;
                entry = entry->getNext();// traverse list until you either reach end or you reach your key
            }
            if(entry->getKey() == key){ // key matches your key
                Node<Key,Value> *next = entry->getNext(); //keep reference point to next node
                delete entry;// delete your node
                prev->setNext(next);// reconnect nodes with your node deleted
            }

        }
    }

};


#endif //UNTITLED_MAP_H
