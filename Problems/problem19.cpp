#include <array>

namespace problem19
{
    struct ListNode
    {
        int val;
        ListNode *next;
    };

    ListNode * removeNthFromEnd(ListNode * head, int n)
    {
        ListNode * preservedHead = head;

        while(n)
        {            
            --n;
            head = head->next;
        }

        ListNode * itemToRemovePrev = nullptr;
        ListNode * itemToRemove = preservedHead;

        while (head)
        {
            itemToRemovePrev = itemToRemove;
            itemToRemove = itemToRemove->next;
            head = head->next;
        }

        if (!itemToRemovePrev)
        {
            preservedHead = itemToRemove->next;
        }
        else
        {
            itemToRemovePrev->next = itemToRemove->next;
        }

        return preservedHead;
    }
}