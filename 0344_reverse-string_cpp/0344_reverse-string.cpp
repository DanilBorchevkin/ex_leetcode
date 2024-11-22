// https://leetcode.com/problems/reverse-string/

#include <vector>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        s = vector<char>(s.rbegin(), s.rend());
    }

    void reverseString_alg(vector<char>& s) {
        reverse(s.begin(), s.end());
    }

    void reverseString_c_way(vector<char>& s) {
        size_t half_len = s.size() / 2;
        size_t max_idx = s.size() - 1;

        for (size_t idx = 0; idx < half_len; ++idx) {
            char buffer = s[idx];
            s[idx] = s[max_idx - idx];
            s[max_idx - idx] = buffer;
        }
    }
};

void test() {
    auto solution = Solution();

    {
        vector<char> test{'h','e','l','l','o'};
        vector<char> expected{'o','l','l','e','h'};

        solution.reverseString(test);
        assert(expected == test);
    }
}

int main() {
    test();

    return 0;
}