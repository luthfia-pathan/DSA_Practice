#include <bits/stdc++.h>
using namespace std;

/*
Remove Outermost Parentheses
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, 
and + represents string concatenation.
For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, 
with A and B nonempty valid parentheses strings.
Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive 
valid parentheses strings.
Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

Example 1:
Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:
Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
*/

/* Approach:
1. Initialize a counter `k` to keep track of the balance of parentheses.
2. Iterate through each character in the string `s`.
3. If the character is '(', increment `k`. If `k` is greater than 1, append the character to the result string.
4. If the character is ')', if `k` is greater than 1, append the character to the result string, then decrement `k`.
5. Return the result string after processing all characters.
Time Complexity: O(n), where n is the length of the string s.
Space Complexity: O(n) for the result string.
*/

 string removeOuterParentheses(string s) {
        int k =0;
        int n = s.length();
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                k++;
                if(k!=1){
                    ans += s[i];
                }
            }
            else{
                if(k!=1){
                    ans += s[i];
                }
                k--;
            }
        }

        return ans;
        
    }

int main() {
    string s = "(()())(())";
    cout << removeOuterParentheses(s) << endl; // Output: "()()()"
    
    s = "(()())(())(()(()))";
    cout << removeOuterParentheses(s) << endl; // Output: "()()()()(())"
    
    s = "()()";
    cout << removeOuterParentheses(s) << endl; // Output: ""
    
    return 0;
}