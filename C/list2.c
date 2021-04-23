#include <stdio.h>
#include <stdlib.h>

typedef struct list_head {
    struct list_head *next;
    int data;
}list_head;


list_head *new_node(int data, list_head *next)
{
    list_head *new_n = (list_head *)malloc(sizeof(list_head));
    new_n->next = next;
    new_n->data = data;
    return new_n;
}

void list_add(list_head **h, int data)
{
    *h = new_node(data, *h);
}

void list_del(list_head **h, int data)
{
    list_head **indirect = h;
    list_head *del;
    while (*indirect && (*indirect)->data != data) {
        indirect = &(*indirect)->next;
    }

    if (*indirect) {
        del = *indirect;
        *indirect = del->next;
        free(del);
    }
}

void list_all_del(list_head **h)
{
    list_head **indirect = h;
    list_head *del;
    while (*indirect) {
        del = *indirect;
        *indirect = del->next;
        free(del);
    }
}

void print_list(list_head *h)
{
    list_head *indirect = h;
    printf("List: ");
    while (indirect) {
        printf("%4d", indirect->data);
        indirect = indirect->next;
    }
    printf("..\n");
}

int main()
{
    list_head *head = NULL;

    list_add(&head, 1);
    list_add(&head, 2);
    list_add(&head, 3);
    list_add(&head, 4);
    list_add(&head, 5);

    print_list(head);

    list_del(&head, 1);
    list_del(&head, 5);
    list_del(&head, 7);
    print_list(head);

    list_all_del(&head);
    printf("head = %p\n", head);
    print_list(head);

    list_all_del(&head);list_all_del(&head);list_all_del(&head);print_list(head);
    return 0;
}
