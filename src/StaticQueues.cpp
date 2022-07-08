#include <iostream>
using namespace std;

#define MAX_QUEUE 10

struct Queue
{
    int input, output, elem, elements[MAX_QUEUE];
};

void create(struct Queue *queue);
void enqueue(struct Queue *queue, int elem);
void dequeue(struct Queue *queue, int *elem);
int fill(struct Queue *queue);
int clear(struct Queue *queue);

int main()
{
    struct Queue queue;
    int elem, n;

    create(&queue);

    printf("\nHow many elements do you want to enqueue: ");
    scanf("%d", &n);

    for(int cont=0; cont<n; cont++)
    {
        if(fill(&queue))
            printf("\nFill Queue");
        else
        {
            printf("\nIntroduce element #%d: ", cont+1);
            cin >> elem;
            enqueue(&queue, elem);
        }
    }

    printf("\nHow many elements do you want to dequeue: ");
    scanf("%d", &n);

    for(int cont=0; cont<n; cont++)
    {
        if (clear(&queue))
            printf("\nEmpty Queue");
        else
        {
            dequeue(&queue, &elem);
            printf("\nElement %d", elem);
        }
    }
    cout <<"\n\n";
    system("PAUSE");

    return 0;
}

void create(struct Queue *queue)
{
    queue->output = queue->input = queue->elem = 0;
    return;
}

void enqueue(struct Queue *queue, int elem)
{
    queue->input++;
    queue->elements[queue->input] = elem;

    if(queue->output > queue->input)
    {
        queue->output = 0;
        queue->input = MAX_QUEUE - 1;
    }
    return;
}

void dequeue(struct Queue *queue, int *elem)
{
    queue->output++;
    *elem = queue->elements[queue->output];

    if(queue->output == queue->input)
    {
        queue->output = 0;
        queue->input = 0;
    }
    return;
}

int fill(struct Queue *queue)
{
    return (queue->input == MAX_QUEUE);
}

int clear(struct Queue *queue)
{
    return (queue->output >= queue->input);
}