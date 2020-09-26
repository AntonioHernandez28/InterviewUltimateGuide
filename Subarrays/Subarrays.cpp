#include <iostream>
#include <vector> 
using namespace std;

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
/* Hacer subarrays */ 
int main(){
    /* Teniendo [1,2,3,4] sacar todos los posibles subarreglos */ 
    /* Es bastante frecuente en subarreglos y aunque se puede hacer de manera iterativa gasta mucha memoria ya que es O(N^2), asi que se hace recursivo SIIIUUH 
    Input : [1, 2, 3]
    Output : [1], [1, 2], [2], [1, 2, 3], [2, 3], [3]
    */

    vector<int> A {1, 2, 3, 4, 5, 6}; 
    GenerateAllSubarrays(A, 0, 0); 
    for(auto x:Subarrays){
        for(auto y:x){ cout << y << " "; }
        cout << endl; 
    }

}

