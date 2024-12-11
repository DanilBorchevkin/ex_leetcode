// https://leetcode.com/problems/reverse-bits/

#include <vector>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdint>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        
        for (size_t idx = 0; idx < 32; ++idx) {
            // Extract byte
            uint32_t extracted_bit = (n >> idx) & 0x01;

            // Add byte to reserved 
            reversed |= extracted_bit << (31 - idx);
        }

        return reversed;
    }
};

void test() {
    auto solution = Solution();
}

int main() {
    test();

    return 0;
}