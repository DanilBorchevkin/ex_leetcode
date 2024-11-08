#include <string>
#include <cassert>
#include <cstddef>
#include <algorithm>

using std::string;
using std::literals::string_literals::operator""s;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = ""s;

        const string& longest_str = a.length() > b.length() ? a : b;
        const string& shortest_str = a.length() > b.length() ? b : a;

        size_t carry = 0;

        // TODO finish this

        std::reverse(result.begin(), result.end());

        return result;
    }
};


void test() {
    auto solution = Solution();
    
    assert("10"s == solution.addBinary("1", "1"));
}

int main() {
    test();

    return 0;
}