// https://leetcode.com/problems/adding-spaces-to-a-string/description/

#include <vector>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string new_s;
        size_t final_len = s.length() + spaces.size();
        new_s.reserve(final_len);

        auto spaces_it = spaces.begin();
        size_t char_shift = 0;

        for (size_t idx = 0; idx < s.length(); ++idx) {
            if ((spaces_it != spaces.end()) && (*spaces_it == idx)) {
                new_s.push_back(' ');
                ++spaces_it;
            }

            new_s.push_back(s[idx]);
        }

        return new_s;
    }

    string addSpaces_naive(string s, vector<int>& spaces) {
        size_t shift = 0;
        for (const auto& space : spaces) {
            s = s.insert(space + shift, " ");
            ++shift;
        }

        return s;
    }
};

void test() {
    auto solution = Solution();

    {
        string test{"LeetcodeHelpsMeLearn"};
        vector<int> test_pos{8, 13, 15};
        string expected{"Leetcode Helps Me Learn"};

        auto fact = solution.addSpaces(test, test_pos);
        assert(expected == fact);
    }
}

int main() {
    test();

    return 0;
}