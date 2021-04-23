
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *ret, **last = &ret;
  
    while (head) {

    }
	
    while (n--) {
        bak = &head->next;

		g = k;
        while (g--) {
            tmp = head->next;
            head->next = last;
            last = head;
            head = tmp;
        }

		*addr = last;
		addr = bak;
    }
	*addr = head;
    return ret;
}