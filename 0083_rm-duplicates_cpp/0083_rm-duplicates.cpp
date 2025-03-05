// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        ListNode * prev_node = head;
        ListNode * curr_node = head;
        curr_node = curr_node->next;

        while (curr_node != nullptr) {
            if (prev_node->val != curr_node->val) {
                prev_node->next = curr_node;
                prev_node = curr_node;
            }

            curr_node = curr_node->next;
        }
        
        prev_node->next = nullptr;

        return head;
    }
};

void test() {
    auto solution = Solution();

    {
        auto head = ListNode(1);
        auto n_2 = ListNode(1);
        auto n_3 = ListNode(2);

        head.next = &n_2;
        n_2.next = &n_3;

        auto return_head = solution.deleteDuplicates(&head);
        assert(&head == return_head);
        assert(1 == head.val);
        assert(2 == head.next->val);
        assert(nullptr == head.next->next);
    }

    {
        auto head = ListNode(1);
        auto n_2 = ListNode(1);
        auto n_3 = ListNode(2);
        auto n_4 = ListNode(3);
        auto n_5 = ListNode(3);

        head.next = &n_2;
        n_2.next = &n_3;
        n_3.next = &n_4;
        n_4.next = &n_5;

        auto return_head = solution.deleteDuplicates(&head);
        assert(&head == return_head);
        assert(1 == head.val);
        assert(2 == head.next->val);
        assert(3 == head.next->next->val);
        assert(nullptr == head.next->next->next);
    }
}

int main() {
    test();

    return 0;
}