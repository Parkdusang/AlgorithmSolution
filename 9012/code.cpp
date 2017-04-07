#include <iostream>
#include <string.h>
using namespace std;

string check(string sc){
    int sk =0;
    for(int i = 0 ; i < sc.size() ; i++){
        if(sc[i] == '('){
            sk++;
        }
        else{
            sk--;
        }
        if(sk  < 0)
            return "NO";

    }

    if(sk == 0 ){
        return "YES";
    }
    else{
        return "NO";
    }
}

int main(int argc, const char * argv[]) {
    int N;
    string sentence;
    cin>>N;
    for(int i = 0; i < N ;i++){
        cin >> sentence;
        cout <<check(sentence)<<endl;
    }
    return 0;
}
