#include <ranges>

namespace problem25
{
    struct ListNode
    {
        int val;
        ListNode *next;
    };

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (k == 1)
        {
            return head;
        }
        auto dummy = ListNode();
        ListNode * prevSet = &dummy;
        prevSet->next = head;
        auto newHead = prevSet;

        while (true)
        {
            auto sentinel = prevSet;

            for (int i : std::ranges::iota_view {0, k})
            {
                sentinel = sentinel->next;

                if (!sentinel)
                {
                    return newHead->next;
                }
            }

            auto cursor = prevSet->next->next;
            auto prev = prevSet->next;

            while (cursor != sentinel)
            {
                auto temp = cursor->next;
                cursor->next = prev;
                prev = cursor;
                cursor = temp;
            }

            auto nextSet = sentinel->next;
            cursor->next = prev;

            prevSet->next->next = nextSet;
            auto lastItemFromPrevSet = prevSet->next;
            prevSet->next = cursor;

            prevSet = lastItemFromPrevSet;
        }

        return newHead->next;
    }
}