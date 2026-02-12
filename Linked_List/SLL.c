#include<stdio.h>
#include<stdlib.h>
//call by address

struct node {
    int data;
    struct node* next;
};

struct node* create_node () {
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    struct node* temp = (struct node*) malloc (sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
}

struct node* insert_at_end(struct node* head) {
    struct node* temp = create_node();
    if (head == NULL) {
        head = temp;
        return head;
    }
    else {
        struct node* traverse = head;
        while (traverse->next!=NULL) traverse = traverse->next;
        traverse -> next = temp;
        return head;
    }
}


struct node* new_node() {
    struct node* temp = (struct node*) malloc (sizeof(struct node));
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    temp->data = val;
    temp->next = NULL;
    return temp;
}


void insert_end(struct node** phead) {
    struct node* temp = new_node();
    if (*phead == NULL) {
        *phead = temp;
        return;
    }
    else {
        struct node* traverse = *phead;
        while(traverse->next != NULL) traverse = traverse->next;
        traverse->next = temp;
        return;
    }
}

void print_list (struct node* head) {
    //if (head == NULL) { printf("No values to print"); return; }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main () {
    struct node* head = NULL;
    struct node** phead = &head;

    for (int i=0; i<5; i++) {
        // head = insert_at_end(head);
        insert_end(phead);
    }
    print_list(head);
    return 0;
}