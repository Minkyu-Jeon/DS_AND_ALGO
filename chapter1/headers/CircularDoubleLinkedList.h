//
// Created by minkyu on 2020-04-01.
//

#ifndef DS_AND_ALGO_CIRCULARDOUBLELINKEDLIST_H
#define DS_AND_ALGO_CIRCULARDOUBLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    int Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

Node* CDLL_CreateNode(ElementType NewData);
void CDLL_DestroyNode(Node* Node);
void CDLL_AppendNode(Node** Head, Node* NewNode);
Node* CDLL_GetNodeAt(Node* Head, int Location);
void CDLL_RemoveNode(Node** Head, Node* Remove);
void CDLL_InsertAfter(Node* Current, Node* NewNode);
int CDLL_GetNodeCount(Node* Head);

#endif //DS_AND_ALGO_CIRCULARDOUBLELINKEDLIST_H
