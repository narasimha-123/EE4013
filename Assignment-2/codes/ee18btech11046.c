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

struct Node *createMat(struct Node *head, int n, int m)
{
    // This function creates a matrix of size (nxm) using linked lists with scanf inputs
    int data;
    struct Node *temp, *newNode;
    head = (struct Node *)malloc(sizeof(struct Node)); // creating head node
    scanf("%d", &data);
    head->data = data; // adding value to head node
    head->next = NULL;

    temp = head;
    for (int i = 2; i <= n * m; i++)
    {
        // creating n*m-length linked list
        newNode = (struct Node *)malloc(sizeof(struct Node)); 
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    struct Node *temp2, *temp3;
    temp2 = temp;
    for (int i = 0; i < n; i++)
    {
        // creates nxm matrix from n*m length linked list
        for (int j = 0; j < m; j++)
        {
            temp2 = temp2->next;
        }
        temp->down = temp2;
        temp = temp2;
    }

    temp = head;
    temp2 = head;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp2 = temp->down;
        temp = temp2;
    }
    return head; // return first element of linked list matrix  
}

void checkCollinear(struct Node *head, int n, int m)
{
    /*
    Checks the collinearity of n points of m dimensions
    Input head is the first element of the nxm lnked list matrix
    */
    struct Node *temp, *temp2, *temp3;
    float slope1, slope2;
    temp = head;
    while (temp->down != NULL && temp->down->down != NULL)
    {
        /*
        Taking temp to always point to first element of each row for every iteration
        */
        temp2 = temp->down;
        temp3 = temp2->down;
        slope1 = temp->data - temp2->data;
        temp2 = temp2->next;
        temp = temp->next;
        int count = 0;
        while (count < m && slope1 == 0)
        {
            // calculating difference for first two vectors
            slope1 = temp->data - temp2->data;
            temp = temp->next;
            temp2 = temp2->next;
            count = count + 1;
        }
        temp = head;
        temp2 = temp->down;
        count = 0;
        slope2 = temp->data - temp3->data;
        temp3 = temp3->next;
        temp = temp->next;
        while (count < m && slope2 == 0)
        {
            // calculating difference for first and third vectors
            slope2 = temp->data - temp3->data;
            temp = temp->next;
            temp3 = temp3->next;
            count = count + 1;
        }
        temp = head;
        temp2 = temp->down;
        temp3 = temp->down->down;
        if (slope1 != 0 && slope2 != 0)
        {
            float lambda = slope2 / slope1;
            for (int i = 0; i < m; i++)
            {
                // checking the difference of points at everyy direction 
                slope1 = temp->data - temp2->data;
                slope2 = temp->data - temp3->data;
                if (slope2 != lambda * slope1)
                {
                    // If the difference of vectors is not equal
                    printf("Points are not collinear \n");
                    return;
                }
                temp = temp->next;
                temp2 = temp2->next;
                temp3 = temp3->next;
            }
        }
        temp = temp->down;
    }
    printf("Points are Collinear \n");
    return;
}

int main()
{
    struct Node *newNode, *temp, *head, *temp2, *temp3;
    int data, n, m;
    // n is the number of points to check
    // m is the dimension of each point
    scanf("%d", &n);
    scanf("%d", &m);
    head = createMat(head, n, m);
    checkCollinear(head, n, m);

    return 0;
}