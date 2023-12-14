//
// Created by Olcay Taner YILDIZ on 18.04.2023.
//

#ifndef GRAPH_PUZZLE_GAME_SUDEBZKRT_HASH_H
#define GRAPH_PUZZLE_GAME_SUDEBZKRT_HASH_H


#include "LinkedList.h"

namespace list {

    class Hash {
    private:
        LinkedList *table;
        int N;
        int hashFunction(int value);
    public:
        Hash(int N);
        Node* search(int value);
        void insert(int value);
        void insert(Node* node);
        void deleteValue(int value);
    };

}
#endif //GRAPH_PUZZLE_GAME_SUDEBZKRT_HASH_H
