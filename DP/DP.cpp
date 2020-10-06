#include<iostream> 
#include<vector>
using namespace std; 

// Problema 1: Mejorar el algoritmo recursivo de Fibonacci
// Algoritmo Fib SIN DP
int Fib(int n){
    if(n < 2) return 1; 
    return Fib(n - 1) + Fib(n - 2);
}
// Algoritmo con DP
vector<int> DP(1000, -1); 
int FibWithDP(int n){
    DP[0] = DP[1] = 1; 
    if(DP[n] == -1) DP[n] = FibWithDP(n - 1) + FibWithDP(n - 2); 
    return DP[n]; 
}

vector<vector<int>> grid; 
int MinPath(){
    if(grid.size()==0)
            return 0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,grid[0][0]));

        
        for(int i=1;i<n;i++)
        {
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int j=1;j<m;j++)
        {
            dp[j][0]=dp[j-1][0]+grid[j][0];
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
}

//Problem Coin change

int main(){
    //cout << "DP: " << FibWithDP(45) << endl; 
    //cout << "NP: " << Fib(45) << endl;

    grid.push_back({1,3,1}); 
    grid.push_back({1,5,1}); 
    grid.push_back({4,2,1}); 

    cout << MinPath() << endl; 

}