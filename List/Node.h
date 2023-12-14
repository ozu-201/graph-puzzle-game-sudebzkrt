//
// Created by Olcay Taner YILDIZ on 6.03.2023.
//

#ifndef GRAPH_PUZZLE_GAME_SUDEBZKRT_NODE_H
#define GRAPH_PUZZLE_GAME_SUDEBZKRT_NODE_H
#include <string>

using namespace  std;

class Node {
private:
    int data;
    Node* next;
public:
    explicit Node(int data);
    void setNext(Node* _next);
    Node* getNext();
    int getData();
    string to_string();
};


#endif //GRAPH_PUZZLE_GAME_SUDEBZKRT_NODE_H
