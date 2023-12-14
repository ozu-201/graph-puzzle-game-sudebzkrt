//
// Created by Olcay Taner YILDIZ on 27.03.2023.
//

#ifndef GRAPH_PUZZLE_GAME_SUDEBZKRT_QUEUE_H
#define GRAPH_PUZZLE_GAME_SUDEBZKRT_QUEUE_H

#include "Node.h"

namespace list {

    class Queue {
    private:
        Node* first;
        Node* last;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        Node* dequeue();
        void enqueue(Node* newNode);
    };

}
#endif //GRAPH_PUZZLE_GAME_SUDEBZKRT_QUEUE_H
