#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;            
    struct Node* link1;  
    struct Node* link2;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->link1 = NULL;
    newNode->link2 = NULL;
    return newNode;
}

void printList(Node* head, const char* listName) {
    printf("Список %s: ", listName);
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link2;
    }
    printf("NULL\n");
}

int main() {
    Node* list1 = NULL; 
    Node* list2 = NULL;  
    Node* tail1 = NULL; 
    Node* tail2 = NULL;

    int count = 0; 
    int input;
    
    printf("Введите последовательность целых чисел (0 для завершения):\n");
    while (1) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }

        Node* newNode = createNode(input);

        if (count % 2 == 0) { 
            if (list1 == NULL) {  
                list1 = newNode;
                tail1 = newNode;
            } else {
                tail1->link2 = newNode;
                tail1 = newNode;
            }
        } else {
            if (list2 == NULL) { 
                list2 = newNode;
                tail2 = newNode;
            } else {
                tail2->link2 = newNode;
                tail2 = newNode;
            }
        }
        
        count++;
    }

    Node* temp1 = list1;
    Node* temp2 = list2;
    while (temp1 != NULL && temp2 != NULL) {
        temp1->link1 = temp2;
        temp1 = temp1->link2;
        temp2 = temp2->link2;
    }

    printList(list1, "1");
    printList(list2, "2");

    while (list1 != NULL) {
        Node* temp = list1;
        list1 = list1->link2;
        free(temp);
    }
    while (list2 != NULL) {
        Node* temp = list2;
        list2 = list2->link2;
        free(temp);
    }

    return 0;
}