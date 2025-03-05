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

        const string& longer_str = a.length() > b.length() ? a : b;
        const string& shorter_str = a.length() > b.length() ? b : a;
        auto longer_it = longer_str.rbegin();
        auto shorter_it = shorter_str.rbegin();
        size_t carry = 0;

        for (;;) {
            if (longer_it != longer_str.rend() && shorter_it != shorter_str.rend()) {
                BitSum sum = sum_char_byte(*longer_it, *shorter_it, carry);
                result.push_back(sum.val);
                carry = sum.carry;
                ++longer_it;
                ++shorter_it;
            } else if (longer_it != longer_str.rend()) { 
                if (carry > 0) {
                    --carry;
                    BitSum sum = sum_char_byte(*longer_it, '1', carry);
                    result.push_back(sum.val);
                    carry = sum.carry;
                } else {
                    result.push_back(*longer_it);
                }
                ++longer_it;
            } else {
                break;
            }
        }

        if (carry > 0) {
            result += string(carry - 1, '0') + string(1, '1');
        }

        // Reverse
        return string(result.rbegin(), result.rend());
    }

    struct BitSum {
        char val;
        size_t carry;
    };

    BitSum sum_char_byte(char lhs, char rhs, size_t carry) {
        BitSum result;

        result.carry = carry;
        bool is_carry_added = false;

        if ((lhs & rhs) == '1') {
            result.val = '0';
            ++result.carry;
            is_carry_added = true;
        } else if (lhs != rhs) {
            result.val = '1';
        } else {
            result.val = '0';
        }

        return result;
    }
    
};


void test() {
    auto solution = Solution();

    {
        auto result = solution.sum_char_byte('0', '1');
        assert('1' == result.val);
        assert(0 == result.carry);
    }

    {
        auto result = solution.sum_char_byte('1', '0');
        assert('1' == result.val);
        assert(0 == result.carry);
    }

    {
        auto result = solution.sum_char_byte('1', '1');
        assert('0' == result.val);
        assert(1 == result.carry);
    }

    {
        auto result = solution.sum_char_byte('0', '0');
        assert('0' == result.val);
        assert(0 == result.carry);
    }

    {
        string expected = "10"s;
        string fact = solution.addBinary("1"s, "1"s);
        assert(fact == expected);
    }

    {
        string expected = "10101"s;
        string fact = solution.addBinary("1010"s, "1011"s);
        assert(fact == expected);
    }
}

int main() {
    test();

    return 0;
}