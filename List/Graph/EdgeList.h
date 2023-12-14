//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef GRAPH_PUZZLE_GAME_SUDEBZKRT_EDGELIST_H
#define GRAPH_PUZZLE_GAME_SUDEBZKRT_EDGELIST_H


#include "Edge.h"

class EdgeList {
private:
    Edge* head;
    Edge* tail;
public:
    EdgeList();
    ~EdgeList();
    bool isEmpty() const;
    Edge* search(int to) const;
    void insert(Edge* newEdge);
    Edge* getHead();
};


#endif //GRAPH_PUZZLE_GAME_SUDEBZKRT_EDGELIST_H
