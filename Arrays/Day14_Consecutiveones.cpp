/*  
Max Consecutive Ones
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:
Input: nums = [1,1,0,1,1,1] Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1] Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

/* Approach: Iterate through the array and count consecutive 1's, reset count when a = 0 is encountered.
using a temporary variable to keep track of the current count of consecutive 1's.
Time Complexity: O(n) and Space Complexity: O(1) */
int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 1,temp = 1;
    int n = nums.size();
    for(int i=0;i<=n-2;i++){
        if(nums[i] == 0) {temp = 1; continue;}
        if((nums[i] == nums[i+1])&&nums[i] == 1) temp++;
        if(temp>count) count = temp;
    }
    return count;
}

// OR

int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0,temp=0;
        int n = nums.size();
        for(int i=0;i<=n-1;i++){
            if(nums[i] == 0) {temp = 0; continue;}
            if(nums[i] == 1) temp++;
            if(temp>count) count = temp;
        }
        return count;
}

int main(){
    vector<int> nums = {1,1,0,1,1,1};
    cout << findMaxConsecutiveOnes(nums) ; // Output: 3
    return 0;
}