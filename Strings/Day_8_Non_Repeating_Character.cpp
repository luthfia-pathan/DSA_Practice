#include <bits/stdc++.h>
using namespace std;
/*
Non Repeating Character

Given a string s consisting of lowercase English Letters. Return the first non-repeating character in s.
If there is no non-repeating character, return '$'.
Note: When you return '$' driver code will output -1.

Example:
Input: s = "geeksforgeeks"
Output: 'f'
Explanation: In the given string, 'f' is the first character in the string which does not repeat.
*/ 

/* Approach 1 :- By doing two timws iteration in string we can get result. First Time Take a character 
and check that char is Repeating in the Given string or not. If it is repeating char in string use Break 
to come out of Loop. If it is not found return the String Character which is Not Repeating 
Time Complexity = O(N^2) Space Cpmplexity = O(N)*/
char nonRep(string &s) {
    int n = s.size();

    for(int i=0;i<n;i++){
        char ch = s[i];
        bool found = false;
        for(int j=0;j<n;j++){
            if(i!=j && s[j] == ch){
                found = true;
                break;
            }
        }
        if(!found){
            return ch;
        }
    }
    return '$';
}

/* Approach 2 :- By using HashMap we can do this in O(n) time complexity. First we will store the 
count of char in string and then we traverse over the string to find first char of Count 1 string 
and return that. Time Complexity is O(2N) ~ O(N) Space Complexity = O(1) */
char nonRepeatingChar(string &s) {
    unordered_map<char,int> um;
    int n = s.size();
    char ans;
    for(int i=0;i<n;i++){
        if(um.find(s[i]) == um.end()) um.insert({s[i],1});
        else um[s[i]]++;
    }
    
    for(int i=0;i<n;i++){
        if(um[s[i]] == 1){
            ans = s[i];
            return ans;
        }
    }
    return '$';
}

/* Approach 3 :- By using Array we can do this in O(n) time complexity. First we will store the
count of char in string and then we traverse over the string to find first char of Count 1 string
and return that. Time Complexity is O(2N) ~ O(N) Space Complexity = O(26) = O(1) */
char nonRepeatingChar(string &s) { 
    int n = s.size();
    int count[26] = {0};
    char ans;
    for(int i=0;i<n;i++){
        count[s[i]-'a']++;
    }
    for(int i=0;i<n;i++){
        if(count[s[i]-'a'] == 1){
            ans = s[i];
            return ans;
        }
    }
    return '$';
}