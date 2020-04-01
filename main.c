#include <stdio.h>
//#include "chapter1/headers/LinkedList.h"
//#include "chapter1/headers/DoubleLinkedList.h"
#include "chapter1/headers/CircularDoubleLinkedList.h"

void chapterOne();
void chapterOneDouble();
void chapterOneCircular();

int main() {
    printf("Hello, World!\n");
    printf("============Chapter 1 Start\n");
//    chapterOne();
    printf("============Chapter 1 End\n");
    printf("============Chapter 1 Double Start\n");
//    chapterOneDouble();
    printf("============Chapter 1 Double End\n");
    printf("============Chapter 1 Circular Start\n");
    chapterOneCircular();
    printf("============Chapter 1 Circular End\n");
    return 0;
}


//void chapterOne()
//{
//    int i = 0;
//    int Count = 0;
//    Node* List = NULL;
//    Node* Current = NULL;
//    Node* NewNode = NULL;
//
//    // 노드 5개 추가
//    for ( i = 0; i < 5; i ++ ) {
//        NewNode = SLL_CreateNode(i);
//        SLL_AppendNode(&List, NewNode);
//    }
//    NewNode = SLL_CreateNode(-1);
//    SLL_InsertNewHead(&List, NewNode);
//
//    NewNode = SLL_CreateNode(-2);
//    SLL_InsertNewHead(&List, NewNode);
//
//    // 리스트 출력
//    Count = SLL_GetNodeCount(List);
//    for ( i = 0; i < Count; i++ ) {
//        Current = SLL_GetNodeAt(List, i);
//        printf("List[%d]: %d\n", i, Current->Data);
//    }
//
//    printf("\nInserting 3000 After [2] ...\n");
//
//    Current = SLL_GetNodeAt(List, 2);
//    NewNode = SLL_CreateNode(3000);
//    SLL_InsertAfter(Current, NewNode);
//
//    // 리스트 출력
//    Count = SLL_GetNodeCount(List);
//    for ( i = 0; i < Count; i++ ) {
//        Current = SLL_GetNodeAt(List, i);
//        printf("List[%d]: %d\n", i, Current->Data);
//    }
//
//    printf("\nDestroying List...\n");
//
//    for ( i = 0; i < Count; i ++ ) {
//        Current = SLL_GetNodeAt(List, 0);
//
//        if ( Current != NULL ) {
//            SLL_RemoveNode(&List, Current);
//            SLL_DestroyNode(Current);
//        }
//    }
//}

void chapterOneDouble()
{
    int i = 0;
    int Count = 0;
    Node *List = NULL;
    Node *NewNode = NULL;
    Node *Current = NULL;

    for ( i = 0; i < 5; i ++ ) {
        NewNode = DLL_CreateNode(i);
        DLL_AppendNode(&List, NewNode);
    }

    Count = DLL_GetNodeCount(List);
    for ( i = 0; i < Count; i ++ ) {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d]: %d\n", i, Current->Data);
    }

    printf("\nInserting 3000 After [2]...\n\n");

    Current = DLL_GetNodeAt(List, 2);
    NewNode = DLL_CreateNode(3000);
    DLL_InsertAfter(Current, NewNode);

    Count = DLL_GetNodeCount(List);
    for ( i = 0; i < Count; i ++ ) {
        Current = DLL_GetNodeAt(List, i);
        printf("List[%d]: %d\n", i, Current->Data);
    }

    printf("\nDestroying List...\n");

    Count = DLL_GetNodeCount(List);
    for ( i = 0; i < Count; i ++ ) {
        Current = DLL_GetNodeAt(List, i);

        if ( Current != NULL ) {
            DLL_RemoveNode(&List, Current);
            DLL_DestroyNode(Current);
        }
    }
}

void chapterOneCircular() {
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* NewNode = NULL;
    Node* Current = NULL;

    for (i=0; i < 5; i++) {
        Node* NewNode = CDLL_CreateNode(i);
        CDLL_AppendNode(&List, NewNode);
    }

    Count = CDLL_GetNodeCount(List);
    for ( i = 0; i < Count; i ++ ) {
        Current = CDLL_GetNodeAt(List, i);
        printf("List[%d]: %d\n", i, Current->Data);
    }

    printf("\nInserting 3000 After [2]...\n\n");
    Current = CDLL_GetNodeAt(List, 2);
    NewNode = CDLL_CreateNode(3000);
    CDLL_InsertAfter(Current, NewNode);

    Count = CDLL_GetNodeCount(List) * 2;
    for ( i = 0; i < Count; i ++ ) {
        if ( i == 0 ) {
            Current = List;
        } else {
            Current = Current->NextNode;
        }
        printf("List[%d]: %d\n", i, Current->Data);
    }

    printf("\nDestroying list...\n");

    Count = CDLL_GetNodeCount(List);

    for ( i = 0 ; i < Count; i ++ ) {
        Current = CDLL_GetNodeAt(List, i);
        if ( Current != NULL ) {
            CDLL_RemoveNode(&List, Current);
            CDLL_DestroyNode(Current);
        }
    }
}
