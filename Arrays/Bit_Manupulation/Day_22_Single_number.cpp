/*
Single Number
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

/* Approach: Bit Manipulation using XOR
1. Initialize a variable `result` to 0. 
2. Iterate through each number in the array `nums`.
3. For each number, perform XOR operation with `result`.
4. The XOR operation will cancel out the numbers that appear twice, leaving only the single number.
5. Return `result` as the single number.
Time Complexity: O(n), where n is the length of the array nums.
Space Complexity: O(1) since we are using only a constant amount of extra space.
*/
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i=0;i<n;i++){
            ans = ans^nums[i];
        }
        return ans;
    }


/* Alternative Approach: Using Hash Map
1. Create an unordered map to store the frequency of each number.
2. Iterate through each number in the array `nums` and update its frequency in the map.
3. After processing all numbers, iterate through the map to find the number with frequency 1.   
4. Return that number as the single number.
Time Complexity: O(n), where n is the length of the array nums.
Space Complexity: O(n) for the hash map.
*/
    int singleNumberUsingMap(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        for (const auto& pair : freqMap) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        return -1; // This line should never be reached if input is guaranteed to have a single number.
    }

/* Alternative Approach: Using Sorting
1. Sort the array `nums`.
2. Iterate through the sorted array and check adjacent elements.
3. If two adjacent elements are the same, skip to the next pair.
4. If an element is not equal to the next one, return that element as the single number.
Time Complexity: O(n log n) due to sorting, where n is the length of the array nums. */