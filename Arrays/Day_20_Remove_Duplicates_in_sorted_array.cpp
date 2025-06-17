/*
Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. 
The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:
The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores)
 */

#include <bits/stdc++.h>
using namespace std;

/* Approch 1 :- Take a variable K where we are counting non duplicates of array and inserting it into array. Check next array Index is 
not equal to current one, use the count as index and add the non matched current index value to k index and increase k. Check the last case
and then return k.
Time Complexity = O(N), Space Complexity = O(1) */
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k =0;
        for(int i=0;i <n-1;i++){
            if(nums[i] != nums[i+1]){
                nums[k] = nums[i];
                k++;
            }
        }
        nums[k] = nums[n-1];
        k++;
        return k;
    }

/* Approch 2 :- Use set to store unique elements and then copy the set to vector and return the size of vector.
Time Complexity = O(NlogN), Space Complexity = O(N) */
    int removeDuplicates(vector<int>& nums) {
        set<int> uniqueElements(nums.begin(), nums.end());
        nums.assign(uniqueElements.begin(), uniqueElements.end());
        return nums.size();
    }

/* Approch 3 :- Use two pointers, one for current index and another for next index. If current index is not equal to next index then
we can add the current index value to next index and increase the next index. After that return next index.
Time Complexity = O(N), Space Complexity = O(1) */
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int nextIndex = 1; // Start from the second element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[nextIndex] = nums[i];
                nextIndex++;
            }
        }
        return nextIndex;
    }

    