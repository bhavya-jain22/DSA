#include<stdio.h>
#include<stdlib.h>

//call by value

struct node {
    int data;
    struct node* next;
};

struct node* create_node() {
    int val;
    printf("Enter the value: ");
    scanf("%d", &val);
    struct node *temp = (struct node*) malloc (sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}

struct node* insert_end(struct node* head) {
    struct node* temp = create_node();
    struct node* buffer = head;
    if (head==NULL) {
        printf("head updated\n");
        head = temp;
        return head;
    }
    else {
        while (buffer->next!=NULL) {
            buffer = buffer->next;
        }
        buffer->next = temp;
        return head;
    }
}

struct node* insert_begin (struct node* head) {
    struct node* temp = create_node();
    temp->next = head;
    head = temp;
    return head;
}

struct node* insert_at_k(struct node* head) {
    int k;
    printf("At which index(0-based) you want to insert: ");
    scanf("%d", &k);
    if(k==0) return insert_begin(head);
    struct node* temp = create_node();
    struct node* traverse = head;
    if (head == NULL) {
        head = temp;
        return head;
    }
    while (--k && traverse->next != NULL) {
        traverse = traverse->next;
    }
    temp->next = traverse->next;
    traverse->next = temp;
    return head;
}

struct node* del_end(struct node* head) {
    if(head==NULL) return NULL;
    if(head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node* traverse = head;
    while (traverse->next->next!=NULL) traverse = traverse->next;
    free(traverse->next);
    traverse->next = NULL;
    return head;
}

struct node* del_begin(struct node* head) {
    if(head == NULL) return NULL;
    struct node* temp = head->next;
    free(head);
    return temp;
}

void print_list(struct node*head) {
    struct node* temp = head;
    if (temp==NULL) {
        printf("No values to print\n");
        return;
    }
    while (temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main () {
    struct node *head = NULL;
    int choice;
    do {
        printf("\n\n0. Exit\n1. Insert at End\n2. Insert at Begin\n3. Insert at K\n4.Delete from End\n5.Delete from Begin\n6. Print the list\n\n");
        scanf("%d", &choice);
        switch (choice) {
            case 0 : break;
            case 1 : head = insert_end(head); break;
            case 2 : head = insert_begin(head); break;
            case 3 : head = insert_at_k(head); break;
            case 4 : head = del_end(head); break;
            case 5 : head = del_begin(head); break;
            case 6 : print_list(head); break;
            default : printf("\nEnter valid choice: "); break;
        }
    }while (choice);
return 0;
}