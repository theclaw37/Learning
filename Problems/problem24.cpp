namespace problem24
{
    struct ListNode
    {
        int val;
        ListNode *next;
    };

    ListNode * swapPairs(ListNode *head)
    {
        auto dummy = ListNode();
        ListNode * prevPair = &dummy;
        prevPair->next = head;
        auto newHead = prevPair;

        while (prevPair->next && prevPair->next->next)
        {
            auto temp = prevPair->next;
            auto tempLink = temp->next->next;
            prevPair->next = prevPair->next->next;
            temp->next = tempLink;
            prevPair->next->next = temp;

            prevPair = prevPair->next->next;
        }

        return newHead->next;
    }
}