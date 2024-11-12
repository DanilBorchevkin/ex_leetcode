// https://leetcode.com/problems/search-insert-position/

#include <vector>
#include <cstddef>
#include <cassert>

using namespace std;

class Solution {
public:
    // Solution based on binary search
    int searchInsert(vector<int>& nums, int target) {
        size_t max_idx = nums.size() - 1;
        size_t min_idx = 0;
        size_t mid_idx = 0;
        size_t result_idx = 0;

        for (;;) {
            mid_idx = (max_idx + min_idx) / 2;

            if (nums[mid_idx] == target) {
                // NOTE: Target was found and it's a insert position
                result_idx = mid_idx;
                break;
            } 

            if (min_idx == mid_idx) {
                // NOTE: Target not found. Let's find insert position
                if ((max_idx == nums.size() - 1) && (target > nums[max_idx])) {
                    // NOTE: In this case we can return index > max_idx
                    result_idx = nums[max_idx] > target ? max_idx : max_idx + 1;
                } else {
                    result_idx = nums[min_idx] > target ? min_idx : min_idx + 1;
                }
                break;
            }
            
            if (nums[mid_idx] < target) {
                min_idx = mid_idx;
            } else {
                max_idx = mid_idx;
            }
        }

        return (int) result_idx;
    }
};

void test() {
    auto solution = Solution();

    {
        vector<int> test_vector{1,2,3};
        assert(1 == solution.searchInsert(test_vector, 2));
    }

    {
        vector<int> test_vector{1,3,5,6};
        assert(2 == solution.searchInsert(test_vector, 5));
    }

    {
        vector<int> test_vector{1,3,5,6};
        assert(1 == solution.searchInsert(test_vector, 2));
    }

    {
        vector<int> test_vector{1,3,5,6};
        assert(4 == solution.searchInsert(test_vector, 7));
    }

    {
        vector<int> test_vector{1,3,5,6};
        assert(0 == solution.searchInsert(test_vector, 0));
    }

    {
        vector<int> test_vector{1,3};
        assert(0 == solution.searchInsert(test_vector, 0));
    }

    {
        vector<int> test_vector{1,3};
        assert(1 == solution.searchInsert(test_vector, 3));
    }
}

int main() {
    test();

    return 0;
}