#include <iostream>
#include <vector>

namespace strings_easy{

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
void reverseString(std::vector<char>& s) {
    for (int i = 0; i < s.size()/2; i++){
        int t = s.size()-i-1;
        std::swap(s[i], s[t]);
    }
}

} //namespace strings_easy