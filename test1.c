#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

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

    int slopex1 = 0, slopey1 = 0, slopez1 = 0, slope1 = 0;
    int slopex2 = 0, slopey2 = 0, slopez2 = 0, slope2 = 0;

    while (temp->down != NULL && temp->down->down != NULL)
    {
        temp2 = temp;
        // printf("Yes I came here \n");
        slopex1 = (temp2->data - temp2->down->data);
        slopex2 = (temp2->down->data - temp2->down->down->data);
        int min = 1000, max = -1000;
        min = MIN(slopex1, slopex2);
        max = MAX(slopex1, slopex2);
        float lambda = slopex2 / slopex1;
        temp2 = temp2->next;
        while (temp != temp2)
        {
            slope1 = (temp2->data - temp2->down->data);
            slope2 = (temp2->down->data - temp2->down->down->data);
            min = 1000, max = -1000;
            min = MIN(slope1, slope2);
            max = MAX(slope1, slope2);
            float refLambda = slope2 / slope1;
            if (refLambda != lambda)
            {
                printf("points are not collinear \n");
                return 0;
            }
            temp2 = temp2->next;
        }
        temp = temp->down;
    }
    printf("Points are collinear \n");
    return 0;
}