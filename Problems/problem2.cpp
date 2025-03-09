namespace problem2 
{
    struct ListNode 
    {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int remainder = 0;
        auto top = l1;
        auto last = l1;

        while (l1 && l2) 
        {
            last = l1;

            int sum = l1->val + l2->val + remainder;
            l1->val = sum % 10;
            remainder = sum >= 10;

            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) 
        {
            last = l1;

            int sum = l1->val + remainder;
            l1->val = sum % 10;
            remainder = sum >= 10;

            l1 = l1->next;
        }
        while(l2) 
        {
            last->next = l2;

            int sum = l2->val + remainder;
            l2->val = sum % 10;
            remainder = sum >= 10;

            last = l2;
            l2 = l2->next;
        }
        if (remainder) 
        {
            last->next = new ListNode(1);
        }

        return top;
    }
}