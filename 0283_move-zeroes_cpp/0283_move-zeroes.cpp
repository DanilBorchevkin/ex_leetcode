// https://leetcode.com/problems/move-zeroes/description/

#include <vector>
#include <cstddef>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
        void moveZeroes(vector<int> &nums) {
            size_t offset = 0;
            for (size_t idx = 0; idx < nums.size(); ++idx) {
                if (idx > 0) {
                    // Move all values by offset
                    nums[idx - offset] = nums[idx];
                }

                if (nums[idx] == 0) {
                    // It's zero and we increase offset
                    ++offset;
                }

                if (offset > 0 && idx > 0) {
                    // If ve have offset - set current value to zero. It virtually "moves" zero to end.
                    nums[idx] = 0;
                }
            }
        }

        void moveZeroes_speed_N_mem_N(vector<int> &nums) {
        size_t zero_count = 0;

        vector<int> new_nums;
        new_nums.reserve(nums.size());

        for (const auto num : nums) {
            if (num != 0) {
                new_nums.push_back(num);
            } else {
                ++zero_count;
            }
        }

        for (; zero_count > 0; --zero_count) {
            new_nums.push_back(0);
        }

        nums = new_nums;
      }
};

void test() {
    auto solution = Solution();

    {
        vector<int> test_vector{0,1,0,3,12};
        vector<int> expected_vector{1,3,12,0,0};

        solution.moveZeroes(test_vector);
        assert(expected_vector == test_vector);
    }
}

int main() {
    test();

    return 0;
}