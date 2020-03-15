#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include <locale>

namespace strings_easy{

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
void reverseString(std::vector<char>& s) {
    for (int i = 0; i < s.size()/2; i++){
        int t = s.size()-i-1;
        std::swap(s[i], s[t]);
    }
}

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/
int reverse(int x) {
    if (x > INT32_MAX  - 1 || x < INT32_MIN + 1) {
        return 0;
    }
    int sign = 1;
    if (x < 0){
        sign = -1;
        x = sign*x;
    }
    int q = x, result = 0;

    for (; q > 9; q /= 10 ){
        if (result > INT32_MAX / 10){
            return 0;
        }else if (result*10 > INT32_MAX - (q%10)){
            return 0;
        }
        result = (result*10) + (q%10);
    }
    if (result > INT32_MAX/10){
        return 0;
    }else if (result*10 > INT32_MAX - q){
        return 0;
    }
    return sign*(result*10+q);
}

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
int firstUniqChar(std::string s) {
    std::unordered_map<char, std::array<int, 2>> store;
    for (int i = 0; i < s.size(); i++){
        auto got = store.find(s[i]);
        if (got == store.end()){
            store[s[i]] = {i, 1};
        }else{
            store[s[i]] = {i, 2};
        }
    }
    int min_index = s.size();
    for (auto j = store.begin(); j != store.end(); j++){
        if (j->second[1] != 1){
            continue;
        }else if (j->second[0] < min_index){
            min_index =  j->second[0];
        }
    }
    if (min_index != s.size()){
        return min_index;
    }else{
        return -1;
    }
}


bool isAnagram(std::string s, std::string t){
    if (s.size() != t.size()){
        return false;
    }
    std::array<int, 26> store;
    store.fill(0);
    int sum = 0;
    for (int i=0; i< s.size(); i++){
        store[ (int)s[i] - 'a' ]++;
        store[ (int)t[i] - 'a' ]--;
    }
    for (int i = 0; i< 26; i++){
        if (store[i] != 0){
            return false;
        }
    }
    return true;
}

bool isPalindrome(std::string s) {
    int start = 0, end = s.size();
    std::locale loc;
    while (start != end && start < end){
        if (!std::isalnum(s[start])){
            start++;
            continue;
        }
        if (!std::isalnum(s[end])){
            end--;
            continue;
        }
        char st = std::tolower(s[start], loc);
        char en = std::tolower(s[end], loc);
        if (st!=en){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int myAtoi(std::string str){
    int result = 0;
    bool init = false;
    int sign = 1;
    for (int i = 0; i < str.size(); i++){
        if (str[i] == ' '){
            if (init){
                break;
            }else{
                continue;
            }
        }
        int ci = (int)str[i] - '0';
        if ( ci == -3){
            if (init){
                break;
            }else{
                init = true;
                sign = -1;
            }
        }else if (ci == -5){
            if (init){
                break;
            }else{
                init = true;
                sign = 1;
            }
        }else if (ci < 0 || ci > 9){
            break;
        }else{
            if (result > INT32_MAX/10 || result*10 > INT32_MAX - ci){
                if (sign == -1){
                    std::cout<<"got -1 "<<INT32_MIN<<" | "; 
                    return INT32_MIN;
                }else{
                    std::cout<<"got +1 "<<INT32_MAX<< " | "; 
                    return INT32_MAX;
                }
            }
            init = true;
            result = result*10 + ci;
        }
    }
    return result*sign;

}

} //namespace strings_easy

// int main(int argc, char** argv){
//     std::string str = "loveleetcode";
//     // std::cout<<"\nFirst unique char in "<< str << " = "<<strings_easy::firstUniqChar(str)<<"\n";

//     std::string str2 = "car";
//     str = "rat";
//     std::cout<<"\nAre "<<str<<" and "<<str2<<" anagrams?  "<< strings_easy::isAnagram(str, str2)<<"\n";
// }