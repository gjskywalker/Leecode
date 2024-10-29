#include<string>
#include<iostream>
#include<map>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int max_length = 0;
        for(int i=0; i<s.length(); i++) {
            std::string tmp = "";
            std::map<char, int> records;
            for(int j=i; j<s.length(); j++) {
                records[s[j]] += 1;
                if(records[s[j]] >= 2) {
                    if(tmp.length() > max_length) {
                        max_length = tmp.length();
                    }
                    break;
                }
                tmp += s[j];
            }
            if(tmp.length() > max_length) {
                max_length = tmp.length();
            }
        }
        return max_length;
    }
};


int main() {
    Solution S;
    S.lengthOfLongestSubstring("abc");
}