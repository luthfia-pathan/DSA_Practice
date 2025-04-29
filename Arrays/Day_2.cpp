#include <bits/stdc++.h>
using namespace std;
/* 
Move All Zeroes to End
Difficulty: EasyAccuracy: 45.51%Submissions: 316K+Points: 2Average Time: 15m
You are given an array arr[] of non-negative integers. Your task is to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements. The operation must be performed in place, meaning you should not use extra space for another array.

Examples:

Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.
Input: arr[] = [10, 20, 30]
Output: [10, 20, 30]
Explanation: No change in array as there are no 0s.
*/

/* Approach 1 :- Take a temp array Iterate over given array place all Non zero values and then remaing length fill with zeros
Space complexity = O(N), Time complexity = O(N) */
void pushZerosToEnd(int nums[], int n) {
        int count0 = 0;
        vector<int> temp;
        for(int i =0; i<n;i++){
            if(nums[i]==0){
                count0++;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }

        for(int i=0;i<count0;i++){
            temp.push_back(0);
        }
        for(int i=0;i<n;i++){
            nums[i] = temp[i];
        }
	}

/* Approach 2 :- Iterate over Array and take a variable for suppose count where it should be arr[count] = arr[i] increase count when arr 
triggers non zero element, If arr[i] triggers zero don't do anything. Then as count will be having some number, Using that number till length place
place zeros in arr. Space complexity = O(N), Time complexity = O(N) // as 2 iterations we can optimize it.  */
void pushZerosToEnd(vector<int>& arr) {
    int n = arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            arr[count] = arr[i];
            count++;
        } 
    }
    for(int i=count;i<n;i++){
        arr[i] = 0;
    }
}

/* Approach 3 :- Iterate over Array and take a variable for suppose count where we should be swap(count, i) & increase count when arr 
triggers non zero element, If arr[i] triggers zero don't do anything. The solution will be sorted. Zeros at last.
 Space complexity = O(N), Time complexity = O(N)  */
 void pushZerosToEnd(vector<int>& arr) {
    int n = arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            swap(arr[count], arr[i]);
            count++;
        } 
    }
}