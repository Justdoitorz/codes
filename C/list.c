#include <stdio.h>
#include <stdlib.h>
//单向循环链表
typedef struct list_head {
    struct list_head *next;
    int data;
}list_head;

void list_init(list_head *h)
{
    h->next = h;
}

list_head *new_node(int data, list_head *next)
{
    list_head *new_n = (list_head *)malloc(sizeof(list_head));
    new_n->next = next;
    new_n->data = data;
    return new_n;
}

void list_add(list_head *h, int data)
{
    h->next = new_node(data, h->next);
}

void list_del(list_head *h, int data)
{
    list_head **indirect = &h->next;
    list_head *del;
    while (*indirect != h && (*indirect)->data != data) {
        indirect = &(*indirect)->next;
    }

    if (*indirect != h) {
        del = *indirect;
        *indirect = del->next;
        free(del);
    }
}

void print_list(list_head *h)
{
    list_head **indirect = &h->next;

    printf("List: ");
    while (*indirect != h) {
        printf("%4d", (*indirect)->data);
        indirect = &(*indirect)->next;
    }
    printf("..\n");
}

int main()
{
    list_head head = {&head};
    //list_init(&head);

    list_add(&head, 1);
    list_add(&head, 2);
    list_add(&head, 3);
    list_add(&head, 4);
    list_add(&head, 5);

    print_list(&head);

    list_del(&head, 3);
    list_del(&head, 5);
    list_del(&head, 6);
    list_del(&head, 1);

    print_list(&head);

    return 0;
}
