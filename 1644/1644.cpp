#include <cstdio>
#include <vector>

using namespace std;

int main(){
    
    vector<int> ve;
    bool bArr[4000000];

    for (int i = 2; i <= 4000000; i++) {
        if (bArr[i]) continue;
        ve.push_back(i);
        for (int j = i + i; j <= 4000000; j += i) { // i를 제외한 i의 배수들은 0으로 체크
            bArr[j] = true;
        }
    }

    int N;
    scanf("%d",&N);
    int len = ve.size();
    int sum = 0;
    int ans = 0;
    int leftGo=0;
    int rightGo=0;
    while (1) {
        if(sum == N){
            ans++;
            sum += ve[rightGo++];
        }
        else if(sum < N){
            if(ve[rightGo] > N) break;
            sum += ve[rightGo++];
        }
        else if(sum >= N) sum -= ve[leftGo++];
        
        if(rightGo >= len) break;
    }
    printf("%d\n",ans);
}