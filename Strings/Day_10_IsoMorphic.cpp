#include <bits/stdc++.h>
using namespace std;
/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation: The strings s and t can be made identical by: Mapping 'e' to 'a'. Mapping 'g' to 'd'.

Example 2:
Input: s = "foo", t = "bar"
Output: false
Explanation: The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:
Input: s = "paper", t = "title"
Output: true
*/

/* Approach 1 :- Using one ordered Map where we will complicate in one loop over other loop so first loop is to find 
whether s string is present in keys. If not check in other whether t string is present in values of Map if yes then false
If not insert the key and value in map and then proceed with logic whether if key is found then is it matching with t's char
Time complexity = O(N^2) Space Complexity = O(elements of s) ~ O(1) */

bool isIsomorphic(string s, string t) {
unordered_map<char, char> um;
for (int i = 0; i < s.length(); ++i) {
    if (um.find(s[i]) != um.end()) {
        if (um[s[i]] != t[i]) return false;
    } else {
        for (const auto& pair : um) {
            if (pair.second == t[i]) return false; 
        }
        um[s[i]] = t[i];
    }
}
return true;
}

/* Approach 2 :- Using two unordered maps where we will note char and Index of particular char. For first map we will have 
s string's char and it's index. Other map we will have t string's char and index. If s[i] is not found we need add s[i] and index.
similar way t[i] we will do and compare both indexes. If indexes are not same then they are not isomorphic as if s is found 
and t is not found we will insert t so index will be differ to s one. vice versa 
Time Complexity = O(N) Space Complexity = O(chars of s + chars of t) ~ O(1)*/
bool isIsomorphic(string s, string t) {
    unordered_map<char,int> um1;
    unordered_map<char,int> um2;
    int n = s.length();

    for(int i=0;i<n;i++){
        if(um1.find(s[i]) == um1.end()){
            um1.insert({s[i],i});
        }
        if(um2.find(t[i]) == um2.end()){
            um2.insert({t[i],i});
        }
        if(um1[s[i]] != um2[t[i]]) return false;
    }
    return true;
}