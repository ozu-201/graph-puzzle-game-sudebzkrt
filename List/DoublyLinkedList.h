//
// Created by Olcay Taner YILDIZ on 14.03.2023.
//

#ifndef GRAPH_PUZZLE_GAME_SUDEBZKRT_DOUBLYLINKEDLIST_H
#define GRAPH_PUZZLE_GAME_SUDEBZKRT_DOUBLYLINKEDLIST_H


#include "LinkedList.h"
#include "DoublyNode.h"

class DoublyLinkedList : public LinkedList{
public:
    void insertFirst(DoublyNode* newNode);
    void insertMiddle(DoublyNode* newNode, DoublyNode* previous);
    void insertLast(DoublyNode* newNode);
    void deleteFirst() override;
    void deleteMiddle(DoublyNode* node);
    void deleteLast() override;
};


#endif //GRAPH_PUZZLE_GAME_SUDEBZKRT_DOUBLYLINKEDLIST_H
