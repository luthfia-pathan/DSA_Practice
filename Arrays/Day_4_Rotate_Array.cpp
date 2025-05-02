#include <bits/stdc++.h>
using namespace std;
/*
Rotate Array

Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. 
Do the mentioned change in the array in place.
Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.
Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.
*/

/* Approach 1 :- Use Two Loops where first loop will be from 0 to d-1 and second loop will be from 0 to n-1. Where 1rst loop 
will note first element that is arr[0] and then in second loop we will place arr[i] = arr[i+1] and then finally arr[n-1] = first element.
Space complexity = O(1), Time complexity = O(N^d) */
void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
    for (int i = 0; i < d; i++) {
        int first = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = first;
    }
}

/* Approach 2 :- Use temp array insert values from d to n-1 in first of temp array and 0 to d-1 in last of array 
and Finally copy temp to arr. Space complexity = O(N), Time complexity = O(N) */
 void rotateArr(vector<int>& arr, int k) {
    int n = arr.size();
    k = k%n;
    vector<int> temp(begin(arr),end(arr));
    int j=0;
    
    for(int i =k;i<n;i++){
        arr[j++] = temp[i];
    }
    
    for(int i=0;i<k;i++){
        arr[j++] = temp[i];
    }
}

/* Approach 3 :- Use Reverse method where first reverse the 0 to d-1 elements and then Reverse the d to n-1 elements 
and then reverse the 0 to n-1 elements that is whole array. 
Space complexity = O(1), Time complexity = O(N) */
void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
    
    d = d%n;
    
    reverse(arr.begin(), arr.begin() + d);
    
    reverse(arr.begin() + d, arr.end());
    
    reverse(arr.begin(), arr.end());
}