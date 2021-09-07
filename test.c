#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *down;
};

int main()
{
    struct Node *newNode, *temp, *head;
    int data, n;
    head = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL)
        exit(0);
    scanf("%d", &n);
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;
    for (int i = 2; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    struct Node *temp2, *temp3;
    temp2 = temp->next->next->next;
    while (temp2 != NULL)
    {
        temp->down = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp = head;
    for (int i = 0; i < 3; i++)
    {
        temp2 = temp->next->next;
        temp3 = temp2->next;
        temp2->next = temp;
        temp = temp3;
    }
    temp = head;
    int det = 0;
    for (int i = 0; i < 3; i++)
    {
        int a, b, c, d, e;
        a = temp->data;
        b = temp->next->down->data;
        c = temp->next->next->down->down->data;
        d = temp->next->next->down->data;
        e = temp->next->down->down->data;
        det += (a) * ((b * c) - (d * e));
        // printf("%d %d %d %d %d \n", a, b, c, d, e);
        temp = temp->next;
    }
    printf("%d \n", det);
    // temp = head->down->next;
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ", temp->data);
    //     temp = temp->next;
    // }
    // printf("\n");
    return 0;
}