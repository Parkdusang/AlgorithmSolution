#include <vector>
#include <memory.h>
#include <cstdio>
using namespace std;
int arr[2001];

int dp[2001][2001];
bool isPal(int i , int j){
    
    if(i == j){
        dp[i][j] = 1;
        return true;
        
    }
    else if(i+1 == j){
        if(arr[i] == arr[j]){
            dp[i][j] = 1;
            return true;
        }
        else{
            dp[i][j] = 0;
            return false;
        }
    }
    else{
        if(dp[i][j] != -1) return dp[i][j];
        else{
            if(arr[i] != arr[j]) return dp[i][j] =0;
            else return dp[i][j] = isPal(i+1, j-1);
        }
    }
}



int main(){
    memset(arr , -1 , sizeof(arr));
    memset(dp , -1 , sizeof(dp));
    int N;
    scanf("%d",&N);
    
    for(int i = 1 ; i <= N ; i++){
        scanf("%d",&arr[i]);
    }
    
    
    int caseN;
    scanf("%d",&caseN);
    
    int a,b;
    for(int i = 0 ; i < caseN ; i++){
        scanf("%d %d",&a , &b);
        if(isPal(a, b)) printf("1\n");
        else printf("0\n");
    }
    
    return 0;
}