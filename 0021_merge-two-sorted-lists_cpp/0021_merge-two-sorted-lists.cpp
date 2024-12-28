// https://leetcode.com/problems/merge-two-sorted-lists/description/

#include <cassert>
#include <iostream>
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) {
            return list2;
        }

        if (list2 == nullptr) {
            return list1;
        }

        auto curr_node_list_1 = list1;
        auto curr_node_list_2 = list2;
        ListNode *head_result = nullptr;
        ListNode *prev_result = nullptr;

        while (true) {
            ListNode *smaller_node = nullptr;

            if (curr_node_list_1 != nullptr && curr_node_list_2 != nullptr) {
                if (curr_node_list_1->val <= curr_node_list_2->val) {
                    smaller_node = curr_node_list_1;
                    curr_node_list_1 = curr_node_list_1->next;
                } else {
                    smaller_node = curr_node_list_2;
                    curr_node_list_2 = curr_node_list_2->next;
                }
            } else if (curr_node_list_1 != nullptr) {
                smaller_node = curr_node_list_1;
                curr_node_list_1 = curr_node_list_1->next;
            } else if (curr_node_list_2 != nullptr) {
                smaller_node = curr_node_list_2;
                curr_node_list_2 = curr_node_list_2->next;
            } else {
                break;
            }

            if (prev_result == nullptr) {
                prev_result = smaller_node;
                head_result = smaller_node;
            } else {
                prev_result->next = smaller_node;
                prev_result = prev_result->next;
            }
        }

        return head_result;
    }
};

void test() {
    auto solution = Solution();

    {
        ListNode node_1_3(4);
        ListNode node_1_2(3, &node_1_3);
        ListNode node_1_1(1, &node_1_2);

        ListNode node_2_3(10);
        ListNode node_2_2(8, &node_2_3);
        ListNode node_2_1(1, &node_2_2);

        auto head_1 = &node_1_1;
        auto head_2 = &node_2_1;

        auto fact = solution.mergeTwoLists(head_1, head_2);
        assert(nullptr != fact);

        while (fact != nullptr) {
            cout << fact->val << "\n";
            fact = fact->next;
        }
    }
}

int main() {
    test();

    return 0;
}