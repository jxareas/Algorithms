/* Algorithms & Data Structures - Linked List

   Write a program that reads from the keyboard a list of integers & insert them
   using a linked list, print the linked list, and request a sequence of data that will be
   deleted from the list
*/

#include <cstdio>
#include <cstdlib>

typedef struct input {
    int elem;
    struct input *next;
} node;

node *newNode(int info);              //Pointer to a function
void add(node **first, int data);

void clear(node **first, int data);

void print(node *first);

int main() {
    int x;
    node *first;
    first = nullptr;                      // Initializing empty list

    printf("\n\t\t\tLinked List\n");

    do {
        printf("\nEnter the data to add (-1 = End): ");
        scanf("%d", &x);

        if (x != -1)
            add(&first, x);
    } while (x != -1);

    print(first);

    do {
        printf("\n\nEnter the data to delete(-1 = End): ");
        scanf("%d", &x);

        if (x != -1)
            clear(&first, x);

        print(first);

    } while (x != -1);

    printf("\n\n");
    system("PAUSE");
    return 0;
}

node *newNode(int info) {
    node *n;
    n = (node *) malloc(sizeof(node));//malloc returns a generic pointer (void *)
    n->next = nullptr;                    // and then converts it
    n->elem = info;
    return n;
}

void add(node **first, int data) {
    node *new_node;
    new_node = newNode(data);      //Local variable disappears when exiting the function due to it's scope
    if (*first == nullptr)          //Empty List
        *first = new_node;           // The`first` variable points to the new Node
    else {
        new_node->next = *first;
        *first = new_node;
    }
    return;
}

void clear(node **first, int data) {
    node *last, *current;
    int found = 0;                         //Flag Variable

    last = nullptr;
    current = *first;

    while ((current != nullptr) && (!found))  // Search Bucle, non-empty list
    {
        found = (current->elem == data);

        if (!found)
        {
            last = current;
            current = current->next;
        }
    }

    if (current != nullptr)
        if (current == *first)
            *first = current->next;
        else last->next = current->next;

    free(current);
    return;
}

void print(node *first) {
    printf("\n\t\tElements of the list\n\n");

    while (first != nullptr) {
        printf("%d\t", first->elem);
        first = first->next;             // Advance pointer
    }
    return;
}
