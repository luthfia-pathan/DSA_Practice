#include <bits/stdc++.h>
#include <string>
using namespace std;
/*
Anagram
Given two strings s1 and s2 consisting of lowercase characters. The task is to check 
whether two given strings are an anagram of each other or not. An anagram of a string is 
another string that contains the same characters, only the order of characters can be 
different. For example, "act" and "tac" are an anagram of each other. Strings s1 and s2 
can only contain lowercase alphabets.
Note: You can assume both the strings s1 & s2 are non-empty.

Examples :
Input: s1 = "geeks", s2 = "kseeg"
Output: true
Explanation: Both the string have same characters with same frequency. So, they are anagrams.

Input: s1 = "allergy", s2 = "allergic"
Output: false
Explanation: Characters in both the strings are not same, so they are not anagrams.
*/

/* Approach 1 :- Sort the String and then check whether both the strings are equal or not. 
Time Complexity = O(Mlogn) + O(Nlogn), Space = O(1)*/
bool areAnagrams(string& s1, string& s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

/* Approach 2:- Use Maps or Disctionaries where we can store each string count and then compare the count. 
1rst string add the count and 2nd string decrease the count. If all count is 0 then true otherwise false.
Time Complexity = O(M) + O(N), Space = O(1) */
bool areAnagrams(string& s1, string& s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    unordered_map<char, int> charCount;
    int n = s1.length();

    for(int i=0;i<n;i++){
        charCount[s1[i]]++;
        charCount[s2[i]]--;
    }

    for(auto& pair: charCount) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true;
}

/* Approach 3 :- Use Frequency Array, Take array length upto 26 and add count of s1 and decrease count of
s2. After that check the whole array if all elements inside array is 0 then true otherwise false.
Time Complexity = O(M) + O(N), Space = O(1) */
bool areAnagrams(string& s1, string& s2) {
    if(s1.length() != s2.length()){
        return false;
    }

    int n = s1.length();
    int arr[26] = {0};

    for(int i=0;i<n;i++){
        int temp = s1[i] - 'a';
        arr[temp]++;
        temp = s2[i] -'a';
        arr[temp]--;
    }

    for(int i=0;i<26;i++){
        if(arr[i] != 0){
            return false;
        }
    }
    return true;
}