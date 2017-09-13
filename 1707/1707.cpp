#include <string>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int arr[20001];
vector<pair< pair<int, int>, bool>> ve;
int V_size;

bool DFS(vector<vector<int>> &ve,int k){

    int len = ve[k].size();
    
    for(int i = 0; i< len ; i++){
        if(arr[ve[k][i]] == 0){ // 물들지 않았을때
            if(arr[k] == 1){
                arr[ve[k][i]] = 2;
                
            }
            else{
                arr[ve[k][i]] = 1;
            }
            if(!DFS(ve,ve[k][i])) return false;
        }
        else
            if(arr[ve[k][i]] == arr[k] ) return false;
    }
    
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int loop;
    cin>> loop;
    int N,NUM_N;
    
    while(loop--){
        cin >>N >>NUM_N;

        vector< vector<int> > ve(N+1);
        memset(arr, 0, sizeof(arr));
        int AA,BB;
        for(int i = 0 ; i < NUM_N ; i++){
            cin >> AA >> BB;
            ve[AA].push_back(BB);
            ve[BB].push_back(AA);
        }
        int isTrue = true;
        
        for(int i = 1 ; i <= N ; i++){
            if(arr[i] == 0){
                arr[i] = 1;
                if(!DFS(ve,i)){
                    isTrue = false;
                    break;
                }
            }
        }
        
        if(isTrue) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}