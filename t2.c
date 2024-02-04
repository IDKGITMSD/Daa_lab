#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* dud) {
    while (dud != NULL) {
        printf("%d", dud->data);
        dud = dud->next;
    }
    printf("\n");
}

void deflist(struct Node** list, int inp) {
    while (inp != 0) {
        int dig = inp % 10;

        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = dig;

        if (*list == NULL) {
            temp->next = NULL;
        } else {
            temp->next = *list;
        }

        *list = temp;
        inp = inp / 10;
    }
}

void sumLists(struct Node* lista, struct Node* listb, struct Node** result, int carry) {
    while (lista != NULL || listb != NULL || carry != 0) {
        int x = (lista ? lista->data : 0) + (listb ? listb->data : 0) + carry;

        carry = x / 10;

        // Add the new node to the result linked list
        struct Node* resultNode = (struct Node*)malloc(sizeof(struct Node));
        resultNode->data = x % 10;
        resultNode->next = NULL;

        // Move to the next nodes in the input linked lists
        if (lista) lista = lista->next;
        if (listb) listb = listb->next;

        // Connect the new node to the result linked list
        resultNode->next = *result;
        *result = resultNode;
    }
}

int main() {
    int num1;
    int num2;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    printf("Enter first number to be stored in linked list: ");
    scanf("%d", &num1);
    printf("Enter second number to be stored in linked list: ");
    scanf("%d", &num2);

    deflist(&list1, num1);
    deflist(&list2, num2);

    printf("Linked List 1: ");
    display(list1);

    printf("Linked List 2: ");
    display(list2);

    struct Node* result = NULL;
    int carry = 0;

    sumLists(list1, list2, &result, carry);

    printf("Resultant Linked List: ");
    display(result);

    return 0;
}
