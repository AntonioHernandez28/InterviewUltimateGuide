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

//Problem Coin change

int main(){
    cout << "DP: " << FibWithDP(45) << endl; 
    cout << "NP: " << Fib(45) << endl;
}