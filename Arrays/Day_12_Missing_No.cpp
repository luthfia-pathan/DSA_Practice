#include <bits/stdc++.h>
using namespace std;

/*
Missing Number
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1: Input: nums = [3,0,1] Output: 2
Explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2: Input: nums = [0,1] Output: 2
Explanation:
n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
*/

/* Approach 1 :- Sort the array and find the missing number by comparing it with index
Time Complexity :- O(N logN) Space Complexity :- O(1) */
int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    for(int i = 0; i < n; i++) {
        if(nums[i] != i) {
            return i;
        }
    }
    
    return n; // If all numbers are present, the missing number is n
}

/* Approach 2 :- Use XOR operation to find the missing number.
XOR all the numbers from 0 to n and also XOR all the numbers in the array. The result will be the missing number.
 */
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int xor_all = 0;
    
    // XOR all numbers from 0 to n
    for(int i = 0; i <= n; i++) {
        xor_all ^= i;
    }
    
    // XOR all numbers in the array
    for(int num : nums) {
        xor_all ^= num;
    }
    
    return xor_all; // The result is the missing number
}

/* Approach 3 :- Use the formula for the sum of the first n natural numbers n * (n + 1) / 2. 
Calculate the expected sum and subtract the actual sum of the array. 
Time Complexity :- O(N) Space Complexity :- O(1)
*/
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;

    for(int i=0;i<n;i++){
        sum += nums[i];
    }

    int avg = (n*(n+1))/2;
    return avg - sum;
}