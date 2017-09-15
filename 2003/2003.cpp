
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    
    vector<int> ve;
    int num, N,M;
    cin >> N >> M;
    for(int i  = 0 ; i <N ; i++){
        cin >>num;
        ve.push_back(num);
    }
    
    
    int start = 0;
    int end = 0;
    int len = ve.size();
    int sum = ve[0];
    int count1 = 0;
    
    while(start <= end && start < len){
        if(sum < M){
            if(end +1 < len){
                end = end+1;
                sum += ve[end];
            }
            else break;
            
        }
        else if(sum > M){
                sum -= ve[start];
                start++;
            
            
        }
        else{
            count1++;
            if(end +1 < len){
                end = end+1;
                sum += ve[end];
            }
            else
                break;
        }
    }
    cout << count1;
}