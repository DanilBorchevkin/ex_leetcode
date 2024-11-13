// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <vector>
#include <cstddef>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        size_t buy_idx = 0;
        size_t sell_idx = 0;
        int max_profit = 0
        
        for (size_t idx = 1; idx < prices.size(); ++idx) {
            // Define buy / min price index
            if ((prices[idx] < prices[buy_idx]) && (idx < (prices.size() - 1))) {
                buy_idx = idx;

                // Assing low value for selling
                sell_idx = idx;
                continue;
            }

            // Define max / sell price index
            if (prices[idx] > prices[sell_idx]) {
                sell_idx = idx;
            }
        }

        // TODO: finish this

        int result = 0;

        if (buy_idx >= sell_idx) {
            result = 0;
        } else {
            result = prices.at(sell_idx) - prices.at(buy_idx);
        }

        return result;
    }
};

void test() {
    auto solution = Solution();

    {
        vector<int> test_vector{7,1,5,3,6,4};
        int expected = 5;

        int actual = solution.maxProfit(test_vector);
        assert(expected == actual);
    }

    {
        vector<int> test_vector{7,6,4,3,1};
        int expected = 0;

        int actual = solution.maxProfit(test_vector);
        assert(expected == actual);
    }

    {
        vector<int> test_vector{2, 4, 1};
        int expected = 2;

        int actual = solution.maxProfit(test_vector);
        assert(expected == actual);
    }

    {
        vector<int> test_vector{3,2,6,5,0,3};
        int expected = 4;

        int actual = solution.maxProfit(test_vector);
        assert(expected == actual);
    }
}

int main() {
    test();

    return 0;
}