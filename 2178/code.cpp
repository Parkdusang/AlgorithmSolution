#include<cstdio>
#include<queue>
#include<utility>
#include<string.h>
using namespace std;
int main(){
    int N,M;
    queue<pair<pair<int,int> ,int>> que;
    scanf("%d %d",&N,&M);
    pair<pair<int,int> ,int> Pair_in_Que;
    pair<int,int> pointer;
    
    int **arr = new int*[N];
    bool **isVisit =  new bool*[N];
    for(int i = 0; i < N; ++i) {
        arr[i] = new int[M];
        isVisit[i] = new bool[M];
        memset(isVisit[i], true, sizeof(bool)*M);
    }
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j <M; j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    
    pointer = make_pair(0, 0);
    Pair_in_Que = make_pair(pointer, 1);
    isVisit[0][0] = false;
    
    
    que.push(Pair_in_Que);
    int  x,y,value;
    while(!que.empty()){
        y = que.front().first.first;
        x = que.front().first.second;
        value = que.front().second;
        
        isVisit[y][x] = false;
        if(y == N-1 && x == M-1) break;
        que.pop();
        
        if(x+1 < M && isVisit[y][x+1] && arr[y][x+1] != 0){
            pointer = make_pair(y,x+1);
            Pair_in_Que = make_pair(pointer, value+1);
            que.push(Pair_in_Que);

        }
        if(x-1 >= 0 && isVisit[y][x-1] && arr[y][x-1] != 0){
            pointer = make_pair(y,x-1);
            Pair_in_Que = make_pair(pointer, value+1);
            que.push(Pair_in_Que);
        }
        if(y+1 < N && isVisit[y+1][x] && arr[y+1][x] != 0){
            pointer = make_pair(y+1,x);
            Pair_in_Que = make_pair(pointer, value+1);
            que.push(Pair_in_Que);
        }
        if(y-1 >= 0 && isVisit[y-1][x] && arr[y-1][x] != 0){
            pointer = make_pair(y-1,x);
            Pair_in_Que = make_pair(pointer, value+1);
            que.push(Pair_in_Que);
        }
    }
    
    
    printf("%d", value);

    
    
    
    
    /* 메모리 해제 */
    for(int i = 0; i < N; ++i) {
        delete [] arr[i];
        delete [] isVisit[i];
    }
    
    return 0;
}