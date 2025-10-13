#include <stdio.h>
#include <stdlib.h>
int N;
int que[];
int front=-1, rear=-1;
void enqueue(int x)
{
    if(rear==N-1)
    {
        printf("\nQueue Overflow\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        que[rear]=x;
    }
    else
        rear++;
        que[rear]=x;
}
void deque()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        printf("\n Deleted element: %d\n", que[front]);
        front++;
    }
}
void peek()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nFront element: %d\n", que[front]);
    }
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("Queue: ");
        for(int i=front; i<=rear; i++)
        {
            printf("%d ", que[i]);
            printf("");
        }
    }
}
int main()
{
    int choice, val;
    printf("Enter size of queue: ");
    scanf("%d", &N);
    while(1)
    {
        printf("\nEnter your choice: \n1. Insert \n2. Delete \n3. Peek \n4. Display \n5. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to be inserted: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                deque();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid");
        }
    }
}
