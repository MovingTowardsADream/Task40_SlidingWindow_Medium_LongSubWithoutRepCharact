#include <iostream>
#include <unordered_map>

class Solution {
public:
    static int lengthOfLongestSubstring(std::string s) {
        int max = 0, super_max = 0, index = 0;
        char tmp;
        std::unordered_map<char, int> umap;
        for (int i = 0;i < s.size();i++) {
            if (umap[s[i]] == 0) {
                umap[s[i]]++;
                max++;
            }
            else {
                if (super_max < max)
                    super_max = max;
                tmp = s[i];
                int a = 0;
                while (s[index] != tmp) {
                    a++;
                    umap[s[index]]--;
                    index++;
                }
                index++;
                max -= a;
            }
        }
        if (max > super_max)
            return max;
        return super_max;
    }
};

int main()
{
    std::cout << Solution::lengthOfLongestSubstring("ggububgvfk");
}
