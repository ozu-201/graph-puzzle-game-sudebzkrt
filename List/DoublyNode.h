//
// Created by Olcay Taner YILDIZ on 13.03.2023.
//

#ifndef GRAPH_PUZZLE_GAME_SUDEBZKRT_DOUBLYNODE_H
#define GRAPH_PUZZLE_GAME_SUDEBZKRT_DOUBLYNODE_H


#include "Node.h"

class DoublyNode : public Node{
private:
    DoublyNode* previous;
public:
    explicit DoublyNode(int data);
    void setPrevious(DoublyNode* _previous);
    DoublyNode* getPrevious();
};


#endif //GRAPH_PUZZLE_GAME_SUDEBZKRT_DOUBLYNODE_H
