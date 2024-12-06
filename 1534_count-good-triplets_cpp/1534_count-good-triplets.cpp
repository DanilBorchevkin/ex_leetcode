// https://leetcode.com/problems/count-good-triplets/description/

#include <vector>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:

    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int result = 0;

        for (size_t idx_1 = 0; idx_1 <= arr.size() - 3; ++idx_1) {
            for (size_t idx_2 = idx_1 + 1; idx_2 <= arr.size() - 2; ++idx_2) {
                if (!isValGood(arr[idx_1], arr[idx_2], a)) {
                    continue;
                }
                for (size_t idx_3 = idx_2 + 1; idx_3 <= arr.size() - 1; ++idx_3) {
                    if (isTripletGood(arr[idx_1], arr[idx_2], arr[idx_3], a, b, c)) {
                        ++result;
                    }
                }
            }
        }

        return result;
    }

    int countGoodTriplets_naive(vector<int>& arr, int a, int b, int c) {
        /* Naive solution */
        int result = 0;

        for (size_t idx_1 = 0; idx_1 <= arr.size() - 3; ++idx_1) {
            for (size_t idx_2 = idx_1 + 1; idx_2 <= arr.size() - 2; ++idx_2) {
                for (size_t idx_3 = idx_2 + 1; idx_3 <= arr.size() - 1; ++idx_3) {
                    if (isTripletGood(arr[idx_1], arr[idx_2], arr[idx_3], a, b, c)) {
                        ++result;
                    }
                }
            }
        }

        return result;
    }

    bool isTripletGood(int val_i, int val_j, int val_k, int a, int b, int c) {
        bool result = isValGood(val_i, val_j, a) && isValGood(val_j, val_k, b) && isValGood(val_i, val_k, c);

        return result;
    }

    bool isValGood(int val_lhs, int val_rhs, int x) {
        return (abs(val_lhs - val_rhs) <= x);
    }
};

void test() {
    auto solution = Solution();

    {
        vector<int> test{3,0,1,1,9,7};
        int a = 7;
        int b = 2;
        int c = 3;
        int expected{4};

        auto fact = solution.countGoodTriplets(test, a, b, c);
        assert(expected == fact);
    }
}

int main() {
    test();

    return 0;
}