#include <bits/stdc++.h>
using namespace std;
/* Reverse Words in a String :-
Given an input string s, reverse the order of the words. A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space. Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1: Input: s = "the sky is blue" Output: "blue is sky the"
Example 2:
Input: s = "  hello world  " Output: "world hello" Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:
Input: s = "a good   example" Output: "example good a" Explanation: You need to reduce multiple spaces between two words to a single
space in the reversed string. 
*/

/* Approach :- First Reverse the String and remove unwanted spaces or leading spaces by continuing it if temp has no data. 
If temp has data and it triggered spacing means it has got a word so we are reverseing Temp and adding it to ans with space to ans. 
In this way we will avoid extra spaces at last and make temp empty. if it did not trigger space then we have to add char's to temp.
After Iterating check temp is empty if it is then return ans or add temp and return it.  */
string reverseWords(string s) {
    reverse(s.begin(), s.end());
    string ans = "", temp = "";
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i] == ' '){
            if(temp == "") continue;
            reverse(temp.begin(),temp.end());
            if(ans != "") ans += " ";
            ans += temp;
            temp = "";
        }
        else {
            temp += s[i];
        }
        
    }
    if(temp!= ""){
        reverse(temp.begin(),temp.end());
        if(ans != "") ans += " ";
        ans += temp;
    }
    
    return ans;
}