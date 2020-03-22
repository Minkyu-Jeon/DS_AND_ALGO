#include <stdio.h>
#include "chapter1/headers/LinkedList.h"

void chapterOne();

int main() {
    printf("Hello, World!\n");
    printf("============Chapter 1 Start\n");
    chapterOne();
    printf("============Chapter 1 End\n");
    return 0;
}


void chapterOne()
{
    int i = 0;
    int Count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

    // 노드 5개 추가
    for ( i = 0; i < 5; i ++ ) {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }
    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    // 리스트 출력
    Count = SLL_GetNodeCount(List);
    for ( i = 0; i < Count; i++ ) {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d]: %d\n", i, Current->Data);
    }

    printf("\nInserting 3000 After [2] ...\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);
    SLL_InsertAfter(Current, NewNode);

    // 리스트 출력
    Count = SLL_GetNodeCount(List);
    for ( i = 0; i < Count; i++ ) {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d]: %d\n", i, Current->Data);
    }

    printf("\nDestroying List...\n");

    for ( i = 0; i < Count; i ++ ) {
        Current = SLL_GetNodeAt(List, 0);

        if ( Current != NULL ) {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }
}