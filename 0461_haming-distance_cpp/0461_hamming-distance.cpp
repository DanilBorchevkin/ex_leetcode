// https://leetcode.com/problems/hamming-distance/

#include <cassert>
#include <cstddef>

class Solution {
public:
    int hammingDistance(int x, int y) {
        if (x == y) {
            return 0;
        }

        int great = x >= y ? x : y;
        int less = x < y ? x : y;

        int distance = 0;
        
        while (great > 0) {
            if ((great & 0x01) != (less & 0x01)) {
                ++distance;
            }

            great = great >> 1;
            less = less >> 1;
        }

        return distance;
    }
};

void test() {
    auto solution = Solution();

    assert(2 == solution.hammingDistance(1, 4));
    assert(1 == solution.hammingDistance(3, 1));
    assert(2 == solution.hammingDistance(93, 73));
}

int main() {
    test();
}

