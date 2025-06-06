/* 136. Single Number

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1] Output: 1

Example 2:
Input: nums = [4,1,2,1,2] Output: 4

Example 3:
Input: nums = [1] Output: 1 */

#include <bits/stdc++.h>
using namespace std;

/* Approch 1 :- sort numbers and check next number is not equal to previous number, if this condn id good then that is single number.
Time Complexity :- O(nLog(N)) Space Complexity :- O(1) */
int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
}

/* Approch 2 :- Using Unordered map counting the number where the number is 1 that would be the answer 
Time Complexity :- O(n) Space Complexity :- O(n) */
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        unordered_map<int, int> count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }

        for(auto x:count){
            if(x.second == 1) return x.first;
        }
        return -1;
    }

/* Approch 3 :- Using XOR operation, if we do XOR of all numbers then the number which is not repeated will be the answer.
Time Complexity :- O(n) Space Complexity :- O(1) */
int singleNumber(vector<int>& nums) {
        int l = nums.size();
        int result =0;
        for(int i=0;i<l;i++){
            result = result^nums[i];
        }
        return result;
}