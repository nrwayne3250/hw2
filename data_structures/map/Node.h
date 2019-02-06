//
// Created by Nathan Wayne on 2019-02-05.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H
using namespace std;
template <typename Key, typename Value>// instance of a Node that holds a key and value pair
class Node{
private:
    Key key;
    Value value;
    Node* next;
public:
    Node(const Key &key, const Value &value){
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }

    Key getKey() const {
        return key;
    }

    Value getValue() const {
        return value;
    }
    void setValue(){
        this->value = value;
    }
    Node *getNext(){
        return next;
    }
    void setNext(Node *next){
        this->next = next;
    }


};
#endif //UNTITLED_NODE_H
