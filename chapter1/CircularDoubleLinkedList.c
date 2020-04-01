//
// Created by minkyu on 2020-04-01.
//

#include "headers/CircularDoubleLinkedList.h"

Node* CDLL_CreateNode(ElementType NewData) {
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;
    return NewNode;
}

void CDLL_DestroyNode(Node* Node) {
    free(Node);
}
void CDLL_AppendNode(Node** Head, Node* NewNode) {
    if ( (*Head) == NULL ) {
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    } else {
        Node* Tail = (*Head)->PrevNode;

        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;

        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Tail;
    }
}
Node* CDLL_GetNodeAt(Node* Head, int Location) {
    Node* Current = Head;
    while( Current != NULL && (--Location) >= 0 ) {
        Current = Current->NextNode;
    }

    return Current;
}
void CDLL_RemoveNode(Node** Head, Node* Remove) {
    if ( *Head == Remove ) {
        (*Head)->PrevNode->NextNode = Remove->NextNode;
        (*Head)->NextNode->PrevNode = Remove->PrevNode;

        *Head = Remove->NextNode;

        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    } else {
        Node* Temp = Remove;

        Remove->PrevNode->NextNode = Temp->NextNode;
        Remove->NextNode->PrevNode = Temp->PrevNode;

        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    }
}
void CDLL_InsertAfter(Node* Current, Node* NewNode) {
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;
}
int CDLL_GetNodeCount(Node* Head) {
    unsigned int Count = 0;
    Node *Current = Head;

    while (Current != NULL) {
        Current = Current->NextNode;
        Count++;

        if (Current == Head)
            break;
    }

    return Count;
}
