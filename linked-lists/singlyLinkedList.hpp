#include <iostream>

using namespace std;

// Singly Linked List Structure 
struct ListNode {
    int data;
    struct ListNode *next;
};

// Takes a linked list as input and counts the number of nodes in the list
int ListLength(struct ListNode *head) {
    struct ListNode *current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current -> next;
    }
    return count;
}

void insertInLinkedList(struct ListNode **head, int data, int position) {
    int k = 1;
    struct ListNode *p, *q, *newNode;
    // Allocate memory to newNode
    newNode = (ListNode *)malloc(sizeof(struct ListNode));
    if (!newNode)
    {
        cout << "Memory allocation error";
        return;
    }
    newNode -> data = data;
    p = *head;
    // Inserting at the beginning
    if (position == 1)
    {
        newNode -> next = p;
        *head = newNode;
    } else {
        // Traverse the list until the position where we want to insert
        while ((p != NULL) && (k < position) )
        {
            k++;
            q = p;
            p = p -> next;
        }
        q -> next = newNode;
        newNode -> next = p;
    }
}

void deleteNodeFromLinkedList(struct ListNode **head, int position) {
    int k = 1;
    struct ListNode *p, *q;
    if (*head == NULL)
    {
        cout << "List is empty";
        return;
    }
    p = *head;
    // Remove from the beginning
    if (position == 1)
    {
        *head = (*head) -> next;
        free(p);
        return;
    } else {
        // Traverse the list from where we want to remove the node
        while ((p != NULL) && (k < position))
        {
            k++;
            q = p;
            p = p -> next;
        }
        q -> next = p -> next;
        free(p);
    }
}

void deleteLinkedList(struct ListNode **head) {
    struct ListNode *auxilaryNode, *iterator;
    iterator = *head;
    while (iterator)
    {
        auxilaryNode = iterator -> next;
        free(iterator);
        iterator = auxilaryNode;
    }
    *head = NULL;
}