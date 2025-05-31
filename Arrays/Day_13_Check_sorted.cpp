#include <bits/stdc++.h>
using namespace std;
/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, 
then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] 
for every valid index i.

Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
*/
class Solution {
    public:
    /* Approach 1 :- Find a break point where next number is lesser thatn current number. 
    Use that point and Reverse Array so that array gets sorted. Once array gets sorted check whether it is increasing array that is sorted array
    If not retuen false
    Time complexity :- O(N) Space Complexity :- O(1) */
        bool check(vector<int>& nums) {
            int n = nums.size();
            int point = 0;
            for(int i=0;i<n-1;i++){
                if(nums[i] > nums[i+1]){
                    point = i+1;
                    break;
                }
            }
            reverse(nums.begin(), nums.begin()+ point);
            reverse(nums.begin() + point, nums.end());
            reverse(nums.begin(), nums.end());
    
            for(int i=0;i<n-1;i++){
                if(nums[i] > nums[i+1])
                return false;
            }
    
            return true;
        }

        /* Approach 2 :- using sliding window Take an array 3 4 5 1 2 when we concatenate array we get 3 4 5 1 2 3 4 5 1 2 so here we can 
        find sorted and non decreasing array. To concatenate we can simply iterate over array agin by using %n over iterater and add count 
        numbers. Once count == n that is size of array then we can return it true otherwise false.
        Time complexity :- O(N) Space Complexity :- O(1) */
        bool checkA(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        for(int i=0;i<2*n;i++){
            if(nums[i%n] > nums[(i+1)%n])
            {
                count = 1;
            }else{
                count++;
                if(count == n) return true;
            }
        }

        return n==1;
    }
    };

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};
    if (sol.check(nums)) {
        cout << "The array can be sorted by reversing a subarray." << endl;
    } else {
        cout << "The array cannot be sorted by reversing a subarray." << endl;
    }
    return 0;
}