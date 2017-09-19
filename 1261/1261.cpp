#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
#include <queue>
using namespace std;

bool isCheck[101][101];
int arr[101][101];
int main(){
    
    int N,M;
    int num;
    scanf("%d %d",&N,&M);
    
    for(int i = 1 ; i <= M; i++){
        for(int j =1 ; j <= N ;j++){
            scanf("%1d",&arr[j][i]);
        }
    }
    pair<int, int> pir;
    pair<int, int> pointer;
    
    queue<pair<int, int>> que;
    queue<pair<int, int>> next_que;
    
    pir = make_pair(1, 1);
    que.push(pir);
    
    if(que.empty()) cout <<"tlqkf\n";
    int i , j;
//    int*dir[]= {{0,1},{1,0},{0,-1},{-1,0}};
    int cost = 0;
    
    while(!que.empty() || !next_que.empty()){
        i = que.front().first;
        j = que.front().second;
        
        if(i == N && j == M)
            break;
            
        que.pop();
//        for(int k=0;k<4;k++){
//            int nr = i+dir[k][0];
//            int nc = j+dir[k][1];
//        }
        isCheck[i][j] = true;
        if(i-1 >= 1 && !isCheck[i-1][j]){
            pointer = make_pair(i-1, j);
            isCheck[i-1][j] = true;
            if(arr[i-1][j] == 0) que.push(pointer);
            else next_que.push(pointer);
        }
        if(i+1 <= N && !isCheck[i+1][j]){
            pointer = make_pair(i+1, j);
            isCheck[i+1][j] = true;
            if(arr[i+1][j] == 0) que.push(pointer);
            else next_que.push(pointer);
        }
        if(j-1 >= 1 && !isCheck[i][j-1]){
            pointer = make_pair(i, j-1);
            isCheck[i][j-1] = true;
            if(arr[i][j-1] == 0) que.push(pointer);
            else next_que.push(pointer);
        }
        if(j+1 <= M && !isCheck[i][j+1]){
            pointer = make_pair(i, j+1);
            isCheck[i][j+1] = true;
            if(arr[i][j+1] == 0) que.push(pointer);
            else next_que.push(pointer);
        }
        
        
        if(que.empty()){
            que = next_que;
            next_que = queue<pair<int, int>> ();
            cost++;
        }
    }
    printf("%d",cost);
}