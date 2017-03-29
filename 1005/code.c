#include<stdio.h>
#include<stdlib.h>


short int **arr1;
short int *pathCost;
short int pathCount;

int searchCost(short int goal){
    int  i, j ,count;
    short *index,*cost;
    int max= 0;
    count =0;
    
    for(i = 0 ; i <pathCount ; i++){
        if(arr1[goal][i] != -1){
            count++;
        }
    }
    if(count == 0){
        return pathCost[goal];
    }
    
    else{
        index = (short int *)malloc(sizeof(short int) * count);
        cost = (short int *)malloc(sizeof(short int) * count);
        j = 0;
        for(i = 0 ; i < pathCount ; i++){
            if(arr1[goal][i] != -1 ){
                index[j] = i;
                j++;
            }
        }
        if(count == 1){
            return pathCost[goal] + searchCost(index[0]);
        }
        else{
            for(i = 0 ; i < count ;i++){
                cost[i] = pathCost[goal] + searchCost(index[i]);
            }
            
            for(i = 0 ; i < count ; i++){
                if(i == 0 ){
                    max = cost[i];
                }
                else{
                    if(max < cost[i]){
                        max = cost[i];
                    }
                }
                
            }
            free(index);
            free(cost);
            return max;
        }
    }
}

int main(){
    int N,ruleCount;
    int i,j,k,startPath,result;
    short int endPath;
    
    
    scanf("%d",&N);
    
    for(k = 0 ; k < N ; k++){
        scanf("%hd %d",&pathCount,&ruleCount);
        // root 가 누군지 찾을것
        
        // 각 path cost입력
        pathCost = (short int *) malloc (sizeof(short int) * pathCount);
        for(i = 0 ;i < pathCount ; i++){
            scanf("%hd",&pathCost[i]);
        }
        
        // table생성
        arr1 = (short int**) malloc ( sizeof(short int*) * pathCount );
        for(int i=0; i<pathCount; i++){
            arr1[i] = (short int*) malloc (sizeof(short int) * pathCount );
        }
        
        //initialization
        for(i = 0 ; i < pathCount ; i++){
            for(j = 0 ; j < pathCount ; j++){
                arr1[i][j] = -1;
                //printf("%d ",arr1[i][j]);
            }
            //printf("\n");
        }
        
        // 상대적 경로입력
        for(i = 0 ; i < ruleCount ; i++){
            scanf("%d %hd",&startPath,&endPath);
            arr1[endPath-1][startPath-1] = pathCost[startPath-1];
        }
        //        for(i = 0 ; i < pathCount ; i++){
        //            for(j = 0 ; j < pathCount ; j++){
        //                printf("%d ",arr1[i][j]);
        //            }
        //            printf("\n");
        //        }
        scanf("%hd",&endPath);
        result = searchCost(endPath-1);
        printf("%d",result);
        
        free(arr1);
        free(pathCost);
    }
    return 0;
}
