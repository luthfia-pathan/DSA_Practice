/*
Rotate String

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.

Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:
Input: s = "abcde", goal = "abced"
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

/* Approach: KMP Algorithm
1. Check if the lengths of `s` and `goal` are equal. If not, return false.
2. Concatenate `s` with itself to create a new string `s2`.
3. Check if `goal` is a substring of `s2`. If it is, return true; otherwise, return false. 
Time Complexity: O(n), where n is the length of the string s.
Space Complexity: O(n) for the concatenated string s2.
*/

bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) {
        return false;
    }
    
    string s2 = s + s; // Concatenate s with itself
    return s2.find(goal) != string::npos; // Check if goal is a substring of s2
}

/* Alternative Approach:
1. Check if the lengths of `s` and `goal` are equal. If not, return false.
2. Create a temporary string by concatenating `goal` with itself.
3. Use a loop to check if `s` can be found in the temporary string by simulating shifts.
4. If a match is found, return true; otherwise, return false after all shifts.
5. Reset the index `k` when a mismatch occurs and continue checking.
Time Complexity: O(n^2) in the worst case, where n is the length of the string s.
Space Complexity: O(n) for the temporary string.
*/
 bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string temp = (goal + goal);
        int n = s.size(), k=0;

        for(int i =0;i<temp.size();i++){
            if(s[k] == temp[i]){
                k++;
                if(k == n) return true;
            }
            else { 
                i = i - k;
                k = 0;}
        }

        return false;

    }