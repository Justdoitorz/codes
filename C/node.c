#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *next;
    int val;
}Node_t;

void insert(Node_t **phead, int val)
{
    Node_t *node = malloc(sizeof(Node_t));
    node->val = val;
    node->next = *phead;
    *phead = node;
}

void show(Node_t *head)
{
    while (head) {
        printf("->val = %d\n", head->val);
        head = head->next;
    }
}

void delete_node(Node_t **phead, Node_t *entry)
{

}

void delete_val(Node_t **phead, int val)
{
    while (*phead) {
        if ((*phead)->val == val) {
            Node_t *tmp = *phead;
            *phead = tmp->next;
            free(tmp);
        } else {
            phead = &(*phead)->next;
        }
    }
}

int main()
{
    Node_t *head = NULL;

    int val;
    int n = 10;

    while (n--) {
        scanf("%d", &val);
        insert(&head, val);
    }
    show(head);

    delete_val(&head, 9);
    printf("...\n");
    show(head);

    return 0;
}
