#include<iostream>
#include <stack>
int **a;
int M,N;

using namespace std;


int rootSearch(int i,int j){
    int count = 0;
    if(i == M-1 && j == N-1){
        return 1;
    }
    if(i-1 >= 0){
        if(a[i-1][j] < a[i][j]){
            count +=rootSearch(i-1 ,j);
        }
            
    }
    if(i+1 < M){
        if(a[i+1][j] < a[i][j])
            count +=rootSearch(i+1 ,j);
            
    }
    if(j-1 >= 0){
        if(a[i][j-1] < a[i][j])
            count +=rootSearch(i ,j-1);
            
    }
    if(j+1 < N){
        if(a[i][j+1] < a[i][j])
            count +=rootSearch(i ,j+1);
    }
    
    
    return count;
}

int main(){
    int result;
    
    cin>>M>>N;
    
    a = new int*[M];
    for(int i = 0 ; i < M ;i++){
        a[i] = new int[N];
    }
    
    
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>a[i][j];
        }
    }
    
    
//    for(int i = 0 ; i < M ; i++){
//        for(int j = 0 ; j < N ; j++){
//            cout<<a[i][j]<<" ";
//        }
//        cout <<endl;
//    }

    
    result = rootSearch(0,0);
    cout<<result<<endl;
    return 0;
}
