#include <iostream>

using namespace std;

#define MAX_STACK 10

struct tStack {
    int top;
    int elements[MAX_STACK];
};

void create(struct tStack *stack);

void put(struct tStack *stack, int elem);

void pop(struct tStack *stack, int *elem);

int fill(struct tStack *stack);

int clear(struct tStack *stack);

int main() {
    struct tStack stack;
    int elem, n;

    create(&stack);

    printf("\nHow many elements do you want to put in the stack?: ");
    scanf("%d", &n);

    for (int cont = 1; cont <= n; cont++) {
        if (fill(&stack))
            printf("\nFilled the stack.");
        else {
            printf("\nEnter the element: ");
            cin >> elem;
            put(&stack, elem);
        }
    }

    printf("\nHow many elements do you want to pop?: ");
    scanf("%d", &n);

    for (int cont = 1; cont <= n; cont++)
        if (clear(&stack))
            printf("\nCleared stack.");
        else {
            pop(&stack, &elem);
            printf("\nElement #%d", elem);
        }

    cout << "\n\n";
    system("PAUSE");

    return 0;
}

void create(struct tStack *stack) {
    stack->top = -1;
}

void put(struct tStack *stack, int elem) {
    stack->top++;
    stack->elements[stack->top] = elem;
    return;
}

void pop(struct tStack *stack, int *elem) {
    *elem = stack->elements[stack->top--];
}

int fill(struct tStack *stack) {
    return (stack->top == MAX_STACK);
}

int clear(struct tStack *stack) {
    return (stack->top == -1);
}
