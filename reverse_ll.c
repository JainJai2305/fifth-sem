#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};

struct Node *rev(struct Node *head,int k){
	
	struct Node* current = head;  
    struct Node* next = NULL;  
    struct Node* prev = NULL;  
    int count = 0;  
  
    while (current != NULL && count < k)  
    {  
        next = current->next;  
        current->next = prev;  
        prev = current;  
        current = next;  
        count++;  
    }  
      

    if (next != NULL)  
        head->next = rev(next, k);  
    return prev;  
}

void insert(struct Node **head,int v){
	struct Node *n = (struct Node *) malloc (sizeof (struct Node) );
	n->data=v;
	n->next=*head;
	*head=n;
}

void printList(struct Node *node)  
{  
    while (node != NULL)  
    {  
        printf("%d ",node->data) ; 
        node = node->next;  
    }  
}  

int main(){
	struct Node *head=NULL;
	int val;
	printf("Enter values and enter '-99' to end:\n");
	for(;;){
		scanf("%d",val);
		if(val==-99)
		    break;
		else
		    insert(&head,val);    
	}
	printf("\nEnter k :");
	int k;
	scanf("%d",k);
	printf("My current list is: ");
	printList(head);
	
	head=rev(head,k);
	printf("\nReversed Linked list: ");  
    printList(head);
	return 0;
}


/* OUTPUT ...
Enter values and enter '-99' to end:
5
3
4
1
7
8
2
-99
Enter k :3
My current list is: 2 8 7 1 4 3 5
Reversed Linked list: 7 8 2 3 4 1 5
*/
