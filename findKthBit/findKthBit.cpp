#include<string>
#include<algorithm>
#include<iostream>

class Solution {
public:
    char findKthBit(int n, int k) {
        std::string s;
        s = Solution::build_string(n);
        std::cout << s[k-1] << std::endl;
        return s[k-1];
    }
    std::string build_string(int n) {
        if (n == 1) {
            return "0";
        }
        else {
            std::string s;
            s = Solution::build_string(n-1) + "1" + Solution::reverse_string(Solution::invert(Solution::build_string(n-1)));
            return s;
        }
    }
    std::string invert(std::string s) {
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                s[i] = '1';
            }
            else {
                s[i] = '0';
            }
        }
        return s;
    }
    std::string reverse_string(std::string s) {
        std::reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    Solution S;
    S.findKthBit(2, 0);
    return 0;
}