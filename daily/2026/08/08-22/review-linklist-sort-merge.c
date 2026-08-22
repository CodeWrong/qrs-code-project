/*
    归并排序算法
*/

#include <stdio.h>

typedef struct Node {
    int data;
    struct Node * next;

}Node;

Node * merge_two_list(Node * list1, Node * list2){
    if(list1 == NULL || list2 == NULL){
        return NULL;
    }
    Node dummy ;
    Node * p = &dummy;
    p->next = NULL;
    while (list1 != NULL && list2 != NULL)
    {
        if(list1->data > list2->data){
            p->next = list2;
            list2 = list2->next;
        }else{
            p->next = list1;
            list1 = list1->next;
        }
        p=p->next;
    }

    if(list1 != NULL){ p->next = list1;}
    if(list2 != NULL){ p->next = list2;}

    return dummy.next;
}

Node * sub_merge_linklist(Node * node){
    if(node == NULL || node->next == NULL){
        return node;
    }
    Node * slow = node;
    Node * fast = node->next;

    while(fast !=NULL && slow != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node * mid = slow->next;
    Node * left = sub_merge_linklist(slow);
    Node * right = sub_merge_linklist(mid);

    return merge_two_list(left, right);
}

Node * sort_merge_linklist(Node * head){
    if(head == NULL){
        return NULL;
    }

    head->next = sub_merge_linklist(head->next);
}