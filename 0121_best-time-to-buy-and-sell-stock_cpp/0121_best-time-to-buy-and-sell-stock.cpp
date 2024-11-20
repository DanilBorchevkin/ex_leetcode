// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <vector>
#include <cstddef>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        vector<int> max_profits;
        max_profits.reserve(prices.size());

        // Iterate over all prices
        for (auto it = prices.begin(); it != prices.end(); ++it) {
            // Find maximum profits for each price
            int profit = maxProfitByBuyPrice((it + 1), prices.end(), *it);
            max_profits.push_back(profit);
        }

        // Find maximum profit over all prices
        int max_profit = 0;
        auto it = std::max_element(max_profits.begin(), max_profits.end());
        if (it != max_profits.end()) {
            max_profit = *it;
        }

        return max_profit;
    }
private:
    template <class Iterator>
    int maxProfitByBuyPrice(Iterator first, Iterator last, int buy_price) {
        int max_profit = 0;

        while (first != last) {
            int profit = *first - buy_price;
            if (profit > max_profit) {
                max_profit = profit;
            }
            ++first;
        }

        return max_profit;
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