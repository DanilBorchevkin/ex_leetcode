// https://leetcode.com/problems/counting-bits/

#include <vector>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include <string>
#include <cstring>
#include <array>

using namespace std;

#include <cstdint>
#include <array>

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;
        ret.reserve(n + 1);

        for (int num = 0; num <= n; ++num) {
            ret.push_back(__builtin_popcount(num));
        }

        return ret;
    }
};

class SolutionNaive {
public:

    array<int, 16> lut_;

    SolutionNaive() {
        populateLut();
    }

    vector<int> countBits(int n) {
        uint32_t unsigned_n = static_cast<uint32_t>(n);
        
        vector<int> ret;
        ret.reserve(unsigned_n);

        for (uint32_t val = 0; val <= unsigned_n; ++val) {
            uint8_t bitCount = 0;

            for (uint8_t byteNum = 0; byteNum < 8; ++byteNum) {
                uint8_t halfByte = extractHalfByte(val, byteNum);
                bitCount += lut_.at(halfByte);
            }

            ret.push_back(bitCount);
        }

        return ret;
    }

    uint8_t extractHalfByte(uint32_t val, uint8_t halfByteNum) {
        return ((uint8_t) ((val >> (halfByteNum * 4)) & 0x0F));
    }

    void populateLut() {
        for (uint8_t idx = 0; idx < 16; ++idx) {
            lut_[idx] = calcSetBitCount(idx);
        }
    }

    uint8_t calcSetBitCount(uint8_t val) {
        uint8_t ret = 0;
        for (uint8_t idx = 0; idx < 8; ++idx) {
            uint8_t extractedBit = (val >> idx) & 0x01;
            if (extractedBit == 0x01) {
                ++ret;
            }
        }
        return ret;
    }
};

void test() {
    auto solution = Solution();

    {
        int test_val = 2;
        vector<int> expected{0, 1, 1};


        auto fact = solution.countBits(test_val);
        assert(expected == fact);
    }

    {
        int test_val = 16;
        vector<int> expected{0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1};

        auto fact = solution.countBits(test_val);
        assert(expected == fact);
    }
}

int main() {
    test();

    return 0;
}