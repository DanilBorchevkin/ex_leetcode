// Link to the problem - https://leetcode.com/problems/valid-anagram/description/

#include <cassert>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;


class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> hash_map_s;
    unordered_map<char, int> hash_map_t;

    this->fillMap(s, hash_map_s);
    this->fillMap(t, hash_map_t);

    return hash_map_s == hash_map_t;
  }

  void fillMap(const string &str, unordered_map<char, int> &map) {
    for (const char &ch : str) {
      if (map.count(ch)) {
        map[ch] += 1;
      } else {
        map[ch] = 0;
      }
    }
  }
};

void test() {
    Solution solution = Solution();

    assert(true == solution.isAnagram("an", "na"));
    assert(false == solution.isAnagram("cat", "rat"));
}

int main() {
    test();

    return 0;
}