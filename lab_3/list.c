#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#define max_size 5


void init(Node** head){

    for(int i = 0;i < max_size;i++){
        insert(head,i,i*i);
    }
}


int empty(const Node *head){
     return (head->next != NULL);
}

int size(const Node *head)
{
    if(head == NULL) return -1;
    int count = 0;
    while(empty(head)){
        count++;
        head = head->next;
    }
    return count;
}

int show(const Node *head){
    if(head == NULL || (empty(head) == 0)) return -1;
    Node* cur = head;
    int i = 0;
    printf("List:\n");
    while(empty(cur))
    {
        printf("%d) %d \n",i, cur->val);
        cur=cur->next;
        i++;
    }
}

int at(const Node* head, int k, T* val){

    if(range(head,k) != 0) return -1;
    int d = size(head) - 1;

    Node* cur = head;
    for (int i = 0; i < k; ++i) cur = cur->next;
    *val = cur->val;

    return 0;
}

int insert(Node** head, int k, T val){

    Node *ptr = (Node*) malloc(sizeof(Node));

    if(*head == NULL){
        *head = (Node *) malloc(sizeof(Node));
        (*head)->val = val;
        (*head)->next = (Node *) malloc(sizeof(Node));
        ptr = (*head)->next;
        ptr->next = NULL;
        return 0;
    }

    ptr->val = val;

    if(k == 0){
        ptr->next = *head;
        (*head) = ptr;
        return 0;
    }

    if(k == size(*head)){
        Node* cur = *head;
        for (int i = 0 ; i < k-1; ++i) cur = cur->next;
        cur->next = ptr;
        cur = cur->next;
        cur->next = (Node *) malloc(sizeof(Node));
        cur = cur->next;
        cur->next = NULL;
        return 0;
    }

    int d = size(*head) -1 ;


    Node* cur = *head;
    for (int i = 0; i < k-1; ++i) cur = cur->next;
    ptr->next = cur->next;
    cur->next = ptr;

    return 0;
}

int range(const Node* head,int k){
    int d = size(head) - 1;
    if(k > d || k < 0) return -1;
    return 0;
}

int erase(Node** head, int k){

    if(range(*head,k) != 0) return -1;
    int d = size(*head) - 1;

    Node *ptr = *head;
    if(k == 0){
        (*head) = (*head)->next;
        free(ptr);
        return 0;
    }

    Node* cur = *head;
    for (int i = 0; i < k-1; ++i) cur = cur->next;

    if(empty(cur) == 0) return -1;

    ptr = cur->next;
    ptr = ptr->next;
    free(cur->next);
    cur->next = (Node *) malloc(sizeof(Node*));
    cur->next = ptr;

    return 0;
}

void eraseAll(Node** head)
{
    Node *cur;
    while( (*head) ){
        cur=(*head);
        (*head)=(*head)->next;
        free(cur);
    }
    *head = NULL;
}
