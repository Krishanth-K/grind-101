#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int val;
    struct Node * link;
} Node;


bool addNode(struct Node **top, int val)
{
    if (*top == NULL)
    {
        *top = (struct Node *)malloc(sizeof(Node));

        **(top)->val = 0;
        **(top)->link = NULL;
    }
}



int main()
{
    struct Node *top = NULL;

    addNode(&top, 5);
}