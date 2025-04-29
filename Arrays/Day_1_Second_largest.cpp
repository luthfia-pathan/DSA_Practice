/* 
Second Largest element

Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't 
exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:
Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
*/

/* First way :- Sort the array and return Second Largest element. Space complexity = O(1), Time complexity = O(Nlogn)*/
#include <bits/stdc++.h>
using namespace std;
int getSecondLargest(vector<int> &arr) {
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int max = arr[n-1];
    int secmax= -1;
    for(int i=n-1;i>=0;i--){
        if(arr[i]<max){
            return arr[i];
        }
        }
    return secmax;
}

/* Second way:- Run two Iterations. In first Iteration => find max, In Second Iteration => find secmax. 
Space complexity = O(1), Time complexity = O(2N) ~ O(N) */

/* Third Way :- Find max and second max in one iteration keep track of both in one Iteration. 
Space complexity = O(1), Time complexity = O(N)*/

int getSecondLargest(vector<int> &arr) {
    int max= -1,secmax = -1;
    
    for(int i=0;i<arr.size();i++){
        if(max<arr[i]) {
            secmax = max;
            max = arr[i];
        }
        else if(secmax<arr[i] && max>arr[i]) {
            secmax = arr[i];
        }
        
    }
    return secmax;
}
