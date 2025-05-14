#include <vector>

namespace problem23
{
    struct ListNode
    {
        int val;
        ListNode *next;
    };

    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        int hops = 1;
        int iter = 0;
        while (hops < lists.size())
        {
            size_t firstIter = iter;
            size_t secondIter = iter + hops;

            if (firstIter >= lists.size() || secondIter >= lists.size())
            {
                iter = 0;
                hops *= 2;
                continue;
            }

            ListNode *list1 = lists[firstIter];
            ListNode *list2 = lists[secondIter];

            ListNode *head = nullptr;
            if (!list1 || !list2)
            {
                lists[firstIter] = (ListNode *)((size_t)list1 | (size_t)list2);
            }
            else
            {
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

                ListNode *iterator = head;
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

                lists[firstIter] = head;
                lists[secondIter] = nullptr;
            }

            iter += 2 * hops;
        }

        return lists[0];
    }
}