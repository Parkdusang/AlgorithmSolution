//9177

#include <string>
#include <iostream>
#include <cstring>
using namespace std;
int dp[201][201];
string A,B,C;
bool ch(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(i == A.length() && j == B.length()) return 1;
    dp[i][j] = 0;
    if(i != A.length() && A[i] == C[i+j] && ch(i+1,j))
        dp[i][j] = 1;
    if(j != B.length() && B[j] == C[i+j] && ch(i,j+1))
        dp[i][j] = 1;
    return dp[i][j];
}

int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i < N ;i++){
        cin >> A >> B >> C;
        memset(dp, -1, sizeof(dp));
        cout << "Data set " << i+1 << ": " << (ch(0, 0) ? "yes\n" : "no\n");
    }
    return 0;
}