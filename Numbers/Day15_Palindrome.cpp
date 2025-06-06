/* 
Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.
Example 1:
Input: x = 121 Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:
Input: x = -121 Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:
Input: x = 10 Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome. */

#include <bits/stdc++.h>
using namespace std;

/* Approach 1 :- Convert the integer to string and then check whether it is palindrome or not by comparing first and last char
Time Complexity = O(N) Space Complexity = O(N) */
    bool isPalindrome(int x) {
        string ans = to_string(x);
        int n = ans.size();
        for(int i =0;i<n/2;i++){
            if(ans[i] != ans[n-1-i]) return false;
        }

        return true;
    }

/* Approach 2 :- Reverse the integer and then check whether it is equal to original integer or not.
Time Complexity = O(N) Space Complexity = O(1) */
bool isPalindrome(int x){
    int reverse = 0;
    int temp = x;
    if (x < 0 || x > 0 && x%10 == 0){
        return 0;
    }
    else{
        while(temp!= 0){
            if (reverse<= INT_MAX/10){
                reverse = reverse*10 + temp%10;
                temp /= 10;
            }
            else break;
        }
    }
    return x == reverse;
}
