//
//  main.c
//  swapPairs
//
//  Created by friday on 2019/11/18.
//  Copyright © 2019 friday. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


typedef struct ListNode ListNode;

struct ListNode* swapPairs(struct ListNode* head)
{
	struct ListNode *ret, **last = &ret, *tmp;
	while (head && head->next) {
		//*last = head->next;
		//last = &head->next;

		//tmp = head->next->next;
		//head->next->next = head;
		//head = tmp;

		*last = *((struct ListNode **)head+1);
		last = (struct ListNode **)head+1;

        tmp = *((struct ListNode **)head->next+1);
        *((struct ListNode **)head->next+1) = head;
        head = tmp;
	}
	*last = head;

	return ret;
}
void print_list(struct ListNode *h)
{
    struct ListNode *indirect = h;
    printf("List: \n");
    while (indirect) {
        printf("%p: %4d\n", indirect, indirect->val);
        indirect = indirect->next;
    }
    printf("..\n");
}



int leftbek(struct ListNode* head, int k)
{
    while (k--) {
		//printf("k = %d\n", k);
        if (!head) return 0;
        head = head->next;
    }
    return 1;
}


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *ret, **addr = &ret, *tmp, *bak, *l = NULL;
    int g;

    while (leftbek(head, k)) {
        g = k;

        bak = head;
        while (g--) {
            tmp = head->next;
            head->next = l;
            l = head;
            head = tmp;
        }

		*addr = l;
		addr = &bak->next;
    }
	*addr = head;
    return ret;
}


struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode*ret = NULL, *be = NULL, **pl = &ret, **pbe = &be;

    while(head) {
        printf("head = %p\n", head);
        if (head->val < x) {
            *pl = head;
            pl = &head->next;
        } else {
            *pbe = head;
            pbe = &head->next;
        }
        head = head->next;
    }
    *pl = be;
    printf("ret = %p\n", ret);
    return ret;
}
int main() {

    ListNode l21;
    l21.val = 1;
    l21.next = NULL;

    ListNode l22;
    l22.val = 4;
    l22.next = NULL;
    ListNode l23;
    l23.val = 3;
    l23.next = NULL;
    ListNode l24;
    l24.val = 2;
    l24.next = NULL;

    ListNode l25;
    l25.val = 5;
    l25.next = NULL;

    l21.next = &l22;
    l22.next = &l23;
    l23.next = &l24;
    l24.next = &l25;

    print_list(&l21);

    ListNode *bbq = partition(&l21, 3);
    printf("%p:\n", bbq);

    print_list(bbq);
    // insert code here...

    return 0;
}
