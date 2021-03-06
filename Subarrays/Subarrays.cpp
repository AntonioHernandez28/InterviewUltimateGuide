#include <iostream>
#include <vector> 
using namespace std;
// OJO NO CONFUNDIR ESTE APPROACH CON UN DP
// SUBSTRING SIEMPRE SON SEGUIDOS, SI NO SON SEGUIDOS PERO SI LOS MISMOS ELEMENTOS EN UNA SUBSECUENCIA
vector<vector<int>> Subarrays; 
//Sacar todos los subarrays con Recursion
void GenerateAllSubarrays(vector<int> nums, int Start, int End){
    if(Start == nums.size()) return; 
    else if(Start > End) GenerateAllSubarrays(nums, 0, End + 1); 
    else {
        vector<int> currentArray; 
        for(int i = Start; i <=  End; i++){
            currentArray.push_back(nums[i]); 
        }
        Subarrays.push_back(currentArray); 
        GenerateAllSubarrays(nums, Start + 1, End); 
    }
    return; 
}

/* Solution Problem 1 */
vector<vector<int>> GlobalSolution; 
void Helper(vector<int> nums, int Start, int End, int K){
    if(Start == nums.size())return; 
    else if(Start > End) Helper(nums, 0, End + 1, K); 
    else{
        vector<int> currentSubarray; 
        for(int i = Start; i <= End; i++){
            currentSubarray.push_back(nums[i]); 
        }
        if(currentSubarray.size() < K) GlobalSolution.push_back(currentSubarray); 
        Helper(nums, Start + 1, End, K);
    }

    return; 
}
int MaximumSubarray(vector<int> nums, int K){
    Helper(nums, 0, 0, K); 
    return GlobalSolution.size(); 
}
/* Hacer subarrays */ 
int main(){
    /* Teniendo [1,2,3,4] sacar todos los posibles subarreglos */ 
    /* Es bastante frecuente en subarreglos y aunque se puede hacer de manera iterativa gasta mucha memoria ya que es O(N^2), asi que se hace recursivo SIIIUUH 
    Input : [1, 2, 3]
    Output : [1], [1, 2], [2], [1, 2, 3], [2, 3], [3]
    */

    vector<int> A {1, 0, 1, 0, 1}; 
    //GenerateAllSubarrays(A, 0, 0); 
    for(auto x:Subarrays){
        for(auto y:x){ cout << y << " "; }
        //cout << endl; 
    }

    /* Problems Subarrays*/ 
    /* 1 Given an integer array and an integer K, find the number of sub arrays in which all elements are less than K. */ 
    cout << MaximumSubarray(A, 4) << endl; 

    /* More Problems: https://leetcode.com/problems/subarray-sums-divisible-by-k/ */


}

