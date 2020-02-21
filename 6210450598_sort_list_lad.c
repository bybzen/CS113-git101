// 6210450598 Thanakorn Rattrakulthip
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} Node;

void append(Node **head, int num)
{
    Node *size = (Node *)malloc(sizeof(Node));
    size->num = num;
    size->next = NULL;
    if (*head!=NULL)
    {
        Node *ptr = *head;
        if (ptr->num > num)
        {
            size->next = ptr;
            *head = size;
        }
        else
        {
            while (ptr->next!=NULL)
            {
                if (ptr->next->num > num)
                {
                    size->next = ptr->next;
                    break;
                }
                ptr = ptr->next;
            }
            ptr->next = size;
        }
    }
    else
        *head = size;
}

int main()
{
    int num;
    Node *head = NULL;
    while (1)
    {
        // printf("add ---> ");
        scanf("%d", &num);
        // Node *size = ((Node *)malloc(sizeof(Node)));
        if (num == -1)
        {
            break;
        }
        else
        {
            append(&head, num);
        }
    }
    while (head!=NULL) //headมีค่า
    {
        printf("%d\n", head->num);
        head = head->next;
    }
}