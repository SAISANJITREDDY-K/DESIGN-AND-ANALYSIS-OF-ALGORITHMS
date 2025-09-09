#include <stdio.h>
#include <stdlib.h>

#define T_S 10

typedef struct Node {
    int key;
    struct Node* next;
} Node;

int hash(int key) {
    return key % T_S;
}

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

void insert(Node* ht[], int key) {
    int index = hash(key);
    Node* newNode = createNode(key);

    if (ht[index] == NULL) {
        ht[index] = newNode;
    } else {
        newNode->next = ht[index];
        ht[index] = newNode;
    }
    printf("Key %d inserted successfully.\n", key);
}

Node* search(Node* ht[], int key, int* pos) {
    int index = hash(key);
    Node* curr = ht[index];
    *pos = 0;
    while (curr != NULL) {
        if (curr->key == key) return curr;
        curr = curr->next;
        (*pos)++;
    }
    return NULL;
}

void delete(Node* ht[], int key) {
    int index = hash(key);
    Node* curr = ht[index];
    Node* prev = NULL;

    while (curr != NULL) {
        if (curr->key == key) {
            if (prev == NULL) ht[index] = curr->next;
            else prev->next = curr->next;
            free(curr);
            printf("Key %d deleted successfully.\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Key %d not found for deletion.\n", key);
}

void display(Node* ht[]) {
    int i;
    printf("\nHash Table with Chaining:\n");
    for (i=0; i<T_S; i++) {
        printf("[%d]: ", i);
        Node* curr = ht[i];
        if (curr == NULL) printf("X");
        else {
            while (curr != NULL) {
                printf("%d -> ", curr->key);
                curr = curr->next;
            }
            printf("NULL");
        }
        printf("\n");
    }
}

int main() {
    Node* ht[T_S] = {NULL};
    int choice, key, pos;
    Node* result;

    while (1) {
        printf("\nMenu:\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(ht, key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = search(ht, key, &pos);
                if (result != NULL)
                    printf("Key %d found in chain at index %d, position %d in the chain.\n", key, hash(key), pos);
                else
                    printf("Key %d not found.\n", key);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(ht, key);
                break;
            case 4:
                display(ht);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
