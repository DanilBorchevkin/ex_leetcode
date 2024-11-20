// https://leetcode.com/problems/contains-duplicate/

#include <vector>
#include <cstddef>
#include <cassert>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }

        sort(nums.begin(), nums.end());

        bool result = false;

        for (auto it = (nums.begin() + 1); it != nums.end(); ++it) {
            if ((*it) == (*(it - 1))) {
                result = true;
                break;
            }
        }

        return result;
    }

    bool containsDuplicate_map(vector<int>& nums) {
        unordered_map<int, int> nums_map;
        bool result = false;

        for (const int num: nums) {
            if (nums_map.count(num) == 0) {
                nums_map[num] = 1;
            } else {
                result = true;
                break;
            }
        }

        return result;
    }
};


void test() {
    auto solution = Solution();

    {
        vector<int> test_vector{1,2,3,1};
        auto expected = true;

        auto actual = solution.containsDuplicate(test_vector);
        assert(expected == actual);
    }

    {
        vector<int> test_vector{1,2,3,4};
        auto expected = false;

        auto actual = solution.containsDuplicate(test_vector);
        assert(expected == actual);
    }
}

int main() {
    test();

    return 0;
}