/* 
Reverse Integer
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside 
the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
Example 1:
Input: x = 123 Output: 321
Example 2:
Input: x = -123 Output: -321
Example 3:
Input: x = 120 Output: 21
*/

#include <bits/stdc++.h>
using namespace std;

/* Approach :- Reverse the Integer in normal method, if normal integer it's fine if it is INT_MAX or INT_MIN then reverse it 
would create a problem for that reason we are using it if(temp > INT_MAX/10 || temp < INT_MIN/10) return 0;
Time complexity = O(N) Space Complexity = O(1) */
int reverse(int x) {
        long int temp = 0;
        while(x != 0){
            if(temp > INT_MAX/10 || temp < INT_MIN/10) return 0;
            temp = temp*10 + x%10;
            x = x/10;
        }

    return temp;
}