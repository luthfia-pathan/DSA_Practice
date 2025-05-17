#include <bits/stdc++.h>
using namespace std;

/* Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. 
Refer the below steps to know about atoi() function.

Cases for atoi() conversion:
    Skip any leading whitespaces.
    Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
    Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. 
    If no digits are present, return 0.
    If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.

Examples:
Input: s = "-123"
Output: -123
Explanation: It is possible to convert -123 into an integer so we returned in the form of an integer
Input: s = "  -"
Output: 0
Explanation: No digits are present, therefore the returned answer is 0. */

/* Approach :- By using Conditions 1 by 1 as given in Question we can do this.
Time Complexity = O(N) Space Complexity = O(1)
Take Variables sign (To note Sign of Integer), num (To note the Integer), i (To iterate over the string), n (Size of String)
1. First we will skip the leading spaces in the string. 
2. Then we will check for sign of Integer. If it is +ve then we will set sign = 1 and if it is -ve then we will set sign = -1
3. Then we will iterate over the string and check if the character is digit or not. 
If it is digit then we will convert it into integer by subtracting '0' from it and then we will multiply num with 10 
and add the digit to num.
4. If the character is not digit then we will break the loop.
5. Then we will check if the num is greater than 2^31 - 1 then we will return 2^31 - 1 and if it is less than -2^31 
then we will return -2^31.
6. Finally we will return num * sign.
*/

int myAtoi(char *s) {
    int i =0, sln = 0, sign = 1;
    
    while (s[i] == ' ')
    i++;
    
    if(s[i] == '-' || s[i] == '+'){
        if(s[i] == '-')
            sign = -1;
        i++;
    }
    
    while(s[i]>= '0' && s[i]<= '9'){
        
        if((sln > INT_MAX/10) || (sln == INT_MAX / 10 && s[i] > '7'))    
            return sign == 1? INT_MAX : INT_MIN;
        
        sln = sln*10 + (s[i]-'0');
        i++;
    }
    
    return sign*sln;
}