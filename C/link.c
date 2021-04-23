#include <stdio.h>
#include <stdlib.h>

typedef struct LINK{

    struct LINK *next;
    int laji;
    char data;

}link_t;

link_t *head;


void remove_(link_t *addr)
{
    link_t *prev = NULL;
    link_t *walk = head;
    while (walk != addr) {
        prev = walk;
        walk = walk->next;
    }

    if (!prev) {
        head = head->next;
    } else {
        prev->next = addr->next;
    }

    //free(addr);
}

void remove_g(link_t *addr)
{
    link_t **indirect = &head;
    while ((*indirect) != addr) {
        printf("*indirect = %p\n", *indirect);
        printf("&(*indirect)->next = %p\n", &(*indirect)->next);
        indirect = (*indirect);//->next;
    }
    *indirect = addr->next;
    free(addr);
}

void init_link(link_t **phead)
{
    int i;
    link_t **indirect = phead;
    for (i = 0; i < 10; i++) {
        *indirect = malloc(sizeof(link_t));
        (*indirect)->data = i+'0';
        indirect = &(*indirect)->next;
    }
    *indirect = NULL;
}

void lookup_link(link_t **phead)
{
    link_t **indirect = phead;
    while (*indirect) {
        printf("%c\n", (*indirect)->data);
        indirect = &(*indirect)->next;
    }
}

link_t * get_addr_(char data, link_t **phead)
{
    link_t **indirect = phead;
    while (*indirect && (*indirect)->data!=data) {
        //printf("%c\n", (*indirect)->data);
        indirect = &(*indirect)->next;
    }
    return *indirect;
}

int main()
{
    lookup_link(&head);
    init_link(&head);
    lookup_link(&head);
    printf("%c..555555555555555.;;;\n", get_addr_('5', &head)->data);
    remove_(get_addr_('0', &head));
    lookup_link(&head);
    printf("%c..666666666666.;;;\n", get_addr_('6', &head)->data);
    remove_g(get_addr_('6', &head));
    lookup_link(&head);

    return 0;
}
