namespace problem21
{
    struct ListNode
    {
        int val;
        ListNode *next;
    };

    ListNode * mergeTwoLists(ListNode * list1, ListNode * list2) {
        ListNode * head = nullptr;
        if (!list1 || !list2)
        {
            return (ListNode*)((size_t)list1 | (size_t)list2);
        }
        if (list1->val < list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }

        ListNode * iterator = head;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                iterator->next = list1;
                iterator = iterator->next;
                list1 = list1->next;
            }
            else
            {
                iterator->next = list2;
                iterator = iterator->next;
                list2 = list2->next;
            }
        }
        iterator->next = list1 ? list1 : list2;

        return head;
    }
}