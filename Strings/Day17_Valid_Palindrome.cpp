/* 
Valid Palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome. */

#include <bits/stdc++.h>
using namespace std;

/* Approch 1 :- Take a new string and place all characters one by one without placing special charaters we can place alphabets and numbers.
and take two pointers and compare them if not matching retirn false otherwise return true. 
Time Complexity :- O(N) Space Complexity :- O(N) */
bool isPalindrome(string s) {
    string str;
    for (char ch : s) {
        if (ch >= 'A' && ch <= 'Z') {
            str.push_back(tolower(ch));
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            str.push_back(ch);
        }
    }

    int i = 0, j = str.size() - 1;
    while (i <= j) {
        if (str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

/* Approch 2 :- Use two pointers and check whether it is alphanumeric or not. If it is then check whether it is equal or not.
Time Complexity :- O(N) Space Complexity :- O(1) */
bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if(!isalnum(s[i])) { i++; continue; }
        if(!isalnum(s[j])) {j--; continue;}
        if (tolower(s[i]) != tolower(s[j])) return false;
        i++;
        j--;
    }
    return true;
}