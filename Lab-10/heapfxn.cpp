#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val, degree;
    Node *parent, *child, *sibling;
};
typedef Node* NODE;

NODE root = NULL;

void binomialLink(NODE h1,NODE h2)
{
    h1->parent = h2;
    h1->sibling = h2->child;
    h2->child = h1;
    h2->degree = h2->degree + 1;
}

NODE createNode(int n)
{
    NODE new_node = new Node;
    new_node->val = n;
    new_node->parent = NULL;
    new_node->sibling = NULL;
    new_node->child = NULL;
    new_node->degree = 0;
    return new_node;
}

NODE mergeBHeaps(NODE h1,NODE h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;

    NODE res = NULL;

    if (h1->degree <= h2->degree)
        res = h1;

    else if (h1->degree > h2->degree)
        res = h2;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->degree < h2->degree)
            h1 = h1->sibling;

        else if (h1->degree == h2->degree)
        {
           NODE sib = h1->sibling;
            h1->sibling = h2;
            h1 = sib;
        }

        else
        {
            NODE sib = h2->sibling;
            h2->sibling = h1;
            h2 = sib;
        }
    }
    return res;
}

NODE unionBHeaps(NODE h1,NODE h2)
{
    if (h1 == NULL && h2 == NULL)
       return NULL;

    NODE res = mergeBHeaps(h1, h2);

    NODE prev = NULL, curr = res,next = curr->sibling;
    while (next != NULL)
    {
        if ((curr->degree != next->degree) ||((next->sibling != NULL) &&(next->sibling)->degree ==curr->degree))
        {
            prev = curr;
            curr = next;
        }

        else
        {
            if (curr->val <= next->val)
            {
                curr->sibling = next->sibling;
                binomialLink(next, curr);
            }
            else
            {
                if (prev == NULL)
                    res = next;
                else
                    prev->sibling = next;
                binomialLink(curr, next);
                curr = next;
            }
        }
        next = curr->sibling;
    }
    return res;
}

void binomialHeapInsert(int x)
{
    root = unionBHeaps(root, createNode(x));
}

void display(NODE h)
{
    while (h)
    {
        cout << h->val << " ";
        display(h->child);
        h = h->sibling;
    }
}

void revertList(NODE h)
{
    if (h->sibling != NULL)
    {
        revertList(h->sibling);
        (h->sibling)->sibling = h;
    }
    else
        root = h;
}

NODE extractMinBHeap(NODE h)
{
    if (h == NULL)
       return NULL;

    NODE min_node_prev = NULL;
    NODE min_node = h;

    int min = h->val;
    NODE curr = h;
    while (curr->sibling != NULL)
    {
        if ((curr->sibling)->val < min)
        {
            min = (curr->sibling)->val;
            min_node_prev = curr;
            min_node = curr->sibling;
        }
        curr = curr->sibling;
    }

    if (min_node_prev == NULL && min_node->sibling == NULL)
        h = NULL;

    else if (min_node_prev == NULL)
        h = min_node->sibling;

    else
        min_node_prev->sibling = min_node->sibling;
    if (min_node->child != NULL)
    {
        revertList(min_node->child);
        (min_node->child)->sibling = NULL;
    }
    return unionBHeaps(h, root);
}

NODE findNode(NODE h, int val)
{
    if (h == NULL)
      return NULL;
    if (h->val == val)
        return h;
    NODE res = findNode(h->child, val);
    if (res != NULL)
       return res;
    return findNode(h->sibling, val);
}
void decreaseKeyBHeap(NODE H, int old_val,int new_val)
{
    NODE node = findNode(H, old_val);
    if (node == NULL)
        return;
    node->val = new_val;
    NODE parent = node->parent;
    while (parent != NULL && node->val < parent->val)
    {
        swap(node->val, parent->val);
        node = parent;
        parent = parent->parent;
    }
}
NODE binomialHeapDelete(NODE h, int val)
{
    if (h == NULL)
        return NULL;
    decreaseKeyBHeap(h, val, INT_MIN);
    return extractMinBHeap(h);
}


int main()
{
    int n,element,choice;

    cout<<"Operations on Binomial heap"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1)Insert Element in the heap"<<endl;
    cout<<"2)Delete Element in the heap"<<endl;
    cout<<"3)Decrease key value "<<endl;
    cout<<"4)Display Heap"<<endl;
    cout<<"5)Exit"<<endl;
    cout<<"Enter Your Choice: ";
    cin>>choice;
    while (1)
    {

        switch(choice)
        {
        case 1: cout<<"Enter no of elements to be inserted"<<endl;
                cin>>n;
                for(int i=0;i<n;i++)
                {
                   cout<<"Enter element "<<(i+1)<<endl;
                   cin>>element;
                   binomialHeapInsert(element);
                }
                break;

        case 2: cout<<"Enter the element to be deleted"<<endl;
                cin>>element;
                root = binomialHeapDelete(root, element);
                cout<<"After deleting, heap is : " <<endl;
                display(root);
                cout<<endl;
                break;

        case 3: cout<<"Enter the key value to be decreased"<<endl;
                cin>>n;
                cout<<"Enter the new value to be placed "<<endl;
                cin>>element;
                decreaseKeyBHeap(root,n,element);
                cout<<"After decreasing the key, heap is "<<endl;
                display(root);
                cout<<endl;
                break;

        case 4: cout<<"The Heap is: "<<endl;
                display(root);
                cout<<endl;
                break;

        case 5: exit(1);

	  }
	  cout<<"Enter Your Choice: ";
      cin>>choice;
    }
    return 0;
}
