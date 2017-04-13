#include<stdio.h>
#include<stdlib.h>
int **A;
int width,height;

void throwRoot(int,int);
int checkRoot(int, int );
void throwRoot(int i ,int j){
    A[i][j] = 0;
    
    
    if(i-1 >= 0){
        if(A[i-1][j] == 1)
            throwRoot(i-1,j);
        
    }
    if(i+1 < width){
        if(A[i+1][j] == 1)
            throwRoot(i+1,j);
    }
    if(j-1 >= 0){
        if(A[i][j-1] == 1)
            throwRoot(i,j-1);
    }
    if(j+1 < height){
        if(A[i][j+1] == 1)
            throwRoot(i,j+1);
    }
    
}
int checkRoot(int width, int height){
    int count = 0,i ,j;
    
    for(i = 0 ; i < width ; i++){
        for(j = 0 ; j < height ; j++){
            if(A[i][j] == 1){
                throwRoot(i,j);
                count++;
            }
        }
    }
    
    
    return count;
}


int main(){
    int N,i,j,k,count ,wd,hei, result;
    
    scanf("%d",&N);
    
    
    for(k = 0 ;k < N ; k++){
        scanf("%d %d %d",&width, &height, &count);
        
        
        A = (int**) malloc ( sizeof(int*) * width );
        for(i=0; i<width; i++){
            A[i] = (int*) malloc ( sizeof(int) * height );
        }
        
        for(i = 0 ; i < width ; i++){
            for(j = 0 ; j < height ; j++){
                A[i][j] = 0;
            }
        }
        
        for(i = 0 ; i < count ; i++){
            scanf("%d %d",&wd,&hei);
            A[wd][hei] = 1;
        }
        
        
        result = checkRoot(width,height);
        
        printf("%d\n",result);
        
    }
    for(i = 0 ; i < height ; i++){
        free(A[i]);
    }
    free(A);
    return 0;
}