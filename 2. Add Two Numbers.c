struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* p = NULL;
    int carry = 0;
    while(l1 != NULL || l2 != NULL || carry != 0){
        struct ListNode* temp = (struct ListNode* )malloc(sizeof(struct ListNode));
        temp->next = NULL;
        int sum = carry;
        if(l1 != NULL){
            sum+= l1-> val;
            l1 = l1->next;
        }
        if(l2 != NULL){
            sum+= l2-> val;
            l2 = l2->next;
        }

        temp->val = sum%10;
        carry = sum/10;

        if(head == NULL){
            head = temp;
            p = head;
        }
        else{
            p->next = temp;
            p = p->next; 
        } 
    }
    return head;
}
