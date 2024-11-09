// https://leetcode.com/problems/assign-cookies/description/

#include <vector>
#include <cassert>
#include <numeric>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int contented = 0;

        // TODO: finish this

        return contented;
    }
};

void test() {
    auto solution = Solution();

    {
        vector<int> greed{1, 2, 3};
        vector<int> cookies{1, 1};
        assert(1 == solution.findContentChildren(greed, cookies));
    }
}

int main() {
    test();
}