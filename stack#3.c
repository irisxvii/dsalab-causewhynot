#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int top = -1, arr[SIZE];
void push();
void pop();
void show();

int main()
{
    int ch;
    printf("Perform operations on the stack:");
    printf("\n1.Push the element\n2.Pop the element\n3.Display\n4.Exit\n");
    do
    {
        printf("Enter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            printf("exiting..");
            break;
        default:
            printf("\nInvalid choice!!");
        }
    }
    while(ch!=4);
}

void push()
{
    int x;
    if (top== SIZE - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("Enter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        arr[top] = x;
    }
}

void pop()
{
    if (top== -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("Popped element: %d\n", arr[top]);
        top = top - 1;
    }
}

void show()
{
    if (top== -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", arr[i]);
    }
}
