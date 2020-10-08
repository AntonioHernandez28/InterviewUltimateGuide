#include<iostream> 
#include<vector>
using namespace std; 

vector<vector<int>> MergeLists(vector<vector<int>> A, vector<vector<int>> B){
    int s = INT_MIN, e = INT_MIN, i = 0, j = 0; 
    vector<vector<int>> res; 
    while(i < A.size() || j < B.size()){
        vector<int> curr(2,-1); 
        if(i >= A.size()) curr = B[j++]; 
        else if(j >= B.size()) curr = A[i++]; 
        else curr = A[i][0] < B[j][0] ? A[i++] : B[j++]; 
        if(curr[0] > e){
            if(e > INT_MIN) res.push_back({s,e}); 
            s = curr[0]; 
            e = curr[1]; 
        }
        else e = max(curr[1], e); 
    }

    if(e > INT_MIN) res.push_back({s,e}); 

    return res; 
}


int main(){
    vector<vector<int>> A {{1,3}, {4,5}, {7,10}, {16,17}}; 
    vector<vector<int>> B {{2,3}, {4,8}, {11,15}}; 
    //Output {[1,3], [4, 10], [11, 15], [16, 17]}
    vector<vector<int>> v = MergeLists(A,B);
    for(auto x:v){
        for(auto y:x) cout << y << " "; 
        cout << endl; 
    }
}