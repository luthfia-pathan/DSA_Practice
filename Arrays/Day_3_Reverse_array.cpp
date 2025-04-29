#include <bits/stdc++.h>
using namespace std;
/*
Reverse an Array

You are given an array of integers arr[]. Your task is to reverse the given array.
Note: Modify the array in place.

Examples:
Input: arr = [1, 4, 3, 2, 6, 5]
Output: [5, 6, 2, 3, 4, 1]
Explanation: The elements of the array are 1 4 3 2 6 5. After reversing the array, the first element goes to the last position, the second element goes to the second last position and so on. Hence, the answer is 5 6 2 3 4 1.
Input: arr = [4, 5, 2]
Output: [2, 5, 4]
Explanation: The elements of the array are 4 5 2. The reversed array will be 2 5 4.
*/

/* Approach 1 :- Take temp arr and Iterate from 0 to n where Logic consists of temp[i] = arr[n-1-i] and arr = temp so arr will be reversed. 
Space complexity = O(N), Time complexity = O(N) */
void reverseArray(int arr[], int n) {
    // Code here
    int temp[n];
    for(int i=0;i<n;i++){
        temp[i] = arr[n-1-i];
    }
    for(int i=0;i<n;i++){
        arr[i] = temp[i];
    }
}

/* Approach 2 :- Take two pointers(i,j) one from 0 to n and second from n to 0, swap two elements increase i decrease j 
when j<i then stop the loop. Space complexity = O(1), Time complexity = O(N) */
void reverseArray(vector<int> &arr) {
    int n = arr.size(), j=n-1, temp;
    for(int i=0;i<(n/2);i++){
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j--;
    }
}