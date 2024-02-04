#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* next;
};
int count1 = 1;
int count2 = 1;

struct node* list1 = NULL;
struct node* list2 = NULL;

void insertInFirst(int x)
{
    struct node* p;
    struct node* q;

    if (list1 == NULL)
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->info = x;
        p->next = NULL;
        list1 = p;
    }
    else
    {
        p = list1;
        while (p->next != NULL)
        {
            p = p->next;
            count1++;
        }
        q = (struct node*)malloc(sizeof(struct node));
        q->info = x;
        p->next = q;
        q->next = NULL;
    }
}

void insertInSecond(int x)
{
    struct node* p;
    struct node* q;

    if (list2 == NULL)
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->info = x;
        p->next = NULL;
        list2 = p;
    }
    else
    {
        p = list2;
        while (p->next != NULL)
        {
            p = p->next;
            count1++;

        }
        q = (struct node*)malloc(sizeof(struct node));
        q->info = x;
        p->next = q;
        q->next = NULL;
    }
}

void display()
{
    struct node* p;
    struct node* q;
    p = list1;
    if (list1 == NULL || list2 == NULL)
    {
        printf("No nodes to show\n");
    }
    else
    {
        printf("Displaying Linked List 1\n");
        while (p != NULL)
        {
            printf("%d\n", p->info);
            p = p->next;
        }
        q = list2;
        printf("Displaying Linked List 2\n");
        while (q != NULL)
        {
            printf("%d\n", q->info);
            q = q->next;
        }
    }
}

void merge()
{
    struct node* p = list1;
    struct node* q = list2;

    while (p != NULL && q != NULL)
    {
        struct node* temp1 = p->next;
        struct node* temp2 = q->next;

        p->next = q;
        q->next = temp1;

        p = temp1;
        q = temp2;
    }

    p = list1;
    printf("Merged List 1:\n");
    while (p != NULL)
    {
        printf("%d\n", p->info);
        p = p->next;
    }

    list2 = NULL;
}

int main()
{
    int opt, x;
    do
    {
        printf("Press\n1 to Insert in Linked List 1\n2 to Insert in Linked List 2\n3 to display both Linked Lists\n4 to merge at alternate positions\n-1 to terminate\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter value to insert in Linked List 1\n");
            scanf("%d", &x);
            insertInFirst(x);
            break;
        case 2:
            printf("Enter value to insert in Linked List 2\n");
            scanf("%d", &x);
            insertInSecond(x);
            break;
        case 3:
            display();
            break;
        case 4:
            merge();
            break;
        case -1:
            printf("Program Terminated\n");
            exit(1);
            break;
        default:
            printf("Invalid Key!\n");
            break;
        }
    } while (opt != -1);

    return 0;
}
