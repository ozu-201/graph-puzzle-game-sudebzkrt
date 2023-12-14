//
// Created by Olcay Taner YILDIZ on 20.03.2023.
//

#ifndef GRAPH_PUZZLE_GAME_SUDEBZKRTSTACK_H
#define GRAPH_PUZZLE_GAME_SUDEBZKRT_STACK_H


#include "Node.h"

namespace list{

class Stack {
private:
    Node* top;
public:
    Stack();
    bool isEmpty();
    Node* peek();
    void push(Node* node);
    Node* pop();
};

}

#endif //GRAPH_PUZZLE_GAME_SUDEBZKRT_STACK_H
