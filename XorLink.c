#include <stdio.h> 
#include <stdlib.h> 
#include <inttypes.h>  
struct Node 
{ 
    int data; 
    struct Node* npx; 
}; 
struct Node* XOR (struct Node *a, struct Node *b) 
{ 
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b)); 
} 
void insert(struct Node **head_ref, int data) 
{ 
 
    struct Node *new_node = (struct Node *) malloc (sizeof (struct Node) ); 
    new_node->data = data; 
    new_node->npx = *head_ref;
    if (*head_ref != NULL) 
    {  
        (*head_ref)->npx = XOR(new_node, (*head_ref)->npx); 
    } 
    *head_ref = new_node; 
}  
void ins_end(struct Node **head, int val){
    if(*head == NULL){
        *head = (struct Node *) malloc (sizeof (struct Node) );
        (*head)->data = val;
        return;
    }

    struct Node *newn = (struct Node *) malloc (sizeof (struct Node) );
    newn->data = val;

    struct Node* curr = *head;
    struct Node* prev = NULL;
    struct Node* nex = XOR(prev, curr->npx);
    while (nex != NULL)
    { 
        prev = curr;
        curr = nex;
        nex = XOR(prev, curr->npx);
    }
    newn->npx = curr;
    curr->npx = XOR(prev, newn);
}
void printList (struct Node *head) 
{ 
    struct Node *curr = head; 
    struct Node *prev = NULL; 
    struct Node *next;  
    while (curr != NULL) 
    { 
        printf ("%d ", curr->data); 
        next = XOR (prev, curr->npx);  
        prev = curr; 
        curr = next; 
    } 
} 
int main () 
{ 
    struct Node *head = NULL; 
    insert(&head, 5); 
    insert(&head, 6); 
    insert(&head, 7); 
    insert(&head, 8);
    ins_end(&head, 1);
    ins_end(&head, 2);
    ins_end(&head, 3);  
    printList (head); 
    return (0); 
} 
