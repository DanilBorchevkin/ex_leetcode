// https://leetcode.com/problems/shuffle-string/

#include <vector>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string new_s{s};

        for (size_t idx = 0; idx < s.length(); ++idx) {
            new_s[(size_t) indices[idx]] = s[idx];
        }

        return new_s;
    }
};

void test() {
    auto solution = Solution();

    {
        string test{"codeleet"};
        vector<int> test_pos{4,5,6,7,0,2,1,3};
        string expected{"leetcode"};

        auto fact = solution.restoreString(test, test_pos);
        assert(expected == fact);
    }
}

int main() {
    test();

    return 0;
}