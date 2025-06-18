/* Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 
if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
*/

#include <bits/stdc++.h>
using namespace std;

/* Approach: (My Approach)
1. Initialize two pointers, i for haystack and j for needle.
2. Traverse through the haystack using the pointer i.
3. If the character at haystack[i] matches needle[j], increment both i and j.
4. If j reaches the length of needle, it means we found a match, so return i - j.
5. If there is a mismatch, reset i to the next position after the last matched character and reset j to 0.
6. If we reach the end of haystack without finding a match, return -1.
This approach has a time complexity of O(m*n) in the worst case, where m is the length of haystack and n is the length of needle.
Space complexity is O(1) since we are using only a few variables for indexing.
*/

int strStr(string haystack, string needle) {
    int m = haystack.size(), n = needle.size();
    int i = 0, j = 0;
    while(i<=m){
        if(j == n) return i - n;
            if(haystack[i] == needle[j]){
                j++;
                i++;
            }
            else{
                i = i-j +1;
                j =0;
            }
        }
    return -1;
 }

/* Alternative Approach:
1. Use the find() method of the string class to search for the first occurrence of needle in haystack.
2. If found, return the index; otherwise, return -1.
This approach has a time complexity of O(m*n) in the worst case, where m is the length of haystack and n is the length of needle.
Space complexity is O(1) since we are using only a few variables for indexing.
*/

    int strStr2(string haystack, string needle) {
        size_t pos = haystack.find(needle);
        return (pos != string::npos) ? pos : -1;
    }

/* Another Alternative Approach:
1. Use the KMP (Knuth-Morris-Pratt) algorithm to find the first occurrence of needle in haystack.
2. Preprocess the needle to create a longest prefix-suffix (LPS) array.
3. Use the LPS array to skip unnecessary comparisons while searching in haystack.
This approach has a time complexity of O(m+n) where m is the length of haystack and n is the length of needle.
Space complexity is O(n) for the LPS array.
*/

    vector<int> computeLPSArray(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        int len = 0, i = 1;
        while (i < n) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int strStr3(string haystack, string needle) {
        if (needle.empty()) return 0;
        vector<int> lps = computeLPSArray(needle);
        int m = haystack.size(), n = needle.size();
        int i = 0, j = 0;
        while (i < m) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == n) return i - j; // Found match
            else if (i < m && haystack[i] != needle[j]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return -1; // Not found
    }