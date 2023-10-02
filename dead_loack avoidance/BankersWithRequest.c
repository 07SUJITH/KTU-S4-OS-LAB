#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int nr,np, work[10]; 
int avail[10],alloc[10][10],need[10][10];
bool finish[10];
int max[10][10];

bool safetyAlgorithm(){
    int safeSequence[10],s=0;
    for(int i =0;i< nr ; i++){
        work[i]= avail[i];
    }
    for(int i =0 ; i < np ;i++)  
        for(int j =0 ; j < nr ; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    for(int i =0 ; i < np ; i++)
        finish[i] = false;
    bool possible = true;
    for(int i =0 ; i< 5 ; i++ )
        for(int  i =0; i< np ; i++){
            possible = true;
            if(!finish[i]){
                for(int j = 0 ;j < nr; j++)
                    if(need[i][j] > work[j] ){
                        possible=false;
                        break;
                    }             
                if(possible){
                    for(int k = 0 ;k < nr; k++)
                        work[k]+= alloc[i][k];
                    finish[i] = true;
                    safeSequence[s++] = i;
                }
            }
        }
    possible = true;
    for(int i =0;i< np ;i++)
        if(!finish[i]){
            possible = false;
            printf("THE SYSTEM IS NOT IN SAFE STATE");
            return false;
            break;
        }
    if(possible){
        printf("THE SYSTEM IS IN SAFE STATE");
        printf("\nSAFE SEQUENCE : ");
        for(int i = 0 ; i < np-1 ; i++)
            printf("P%d -> ",safeSequence[i]);
        printf("P%d\n",safeSequence[np-1]);  
        return true;      
    }
}
void resourceRequestAlgorithm(){
    int pNumber,req[10];
    printf("\nENTER THE NEW REQUEST \n");
    printf("ENTER THE PROCESS NUMBER: ");
    scanf("%d",&pNumber);
    printf("ENTER THE AMOUNT OF REQUESTED RESOURCE :");
    for(int i = 0;i< nr;i++)
        scanf("%d",&req[i]);

    for(int i =0;i< nr ; i++)
        if(req[i] > need[pNumber][i]){
            printf("RESOURCE NOT GRANTED!! \nREQUESTED RESOURCE GREATER THAN NEEDED");
            exit(0);
        }
    for(int i =0;i< nr ; i++){
        avail[i] -=req[i];
        alloc[pNumber][i] += req[i];
        need[pNumber][i] -= req[i];
    }
    if(safetyAlgorithm())
        printf("REQUEST CAN BE GRANTED IMMEDIATELY.");
    else
        printf("REQUEST NOT ALLOCATED -- DEADLOCK OCCURED\n");
}
int main(){
    printf("ENTER THE NUMBER OF RESOURCES: ");
    scanf("%d",&nr);
    printf("ENTER THE AVAILABLE RESOURCES: ");
    for(int i =0;i< nr ; i++){
        scanf("%d",&avail[i]);
        work[i]= avail[i];
    }
    printf("ENTER THE NUMBER OF PROCESSES : ");
    scanf("%d",&np);
    printf("ENTER THE ALLOCATION MATRIX\n");
    for(int i = 0;i< np; i++)
        for(int j =0; j< nr;j++)
            scanf("%d",&alloc[i][j]);
    printf("ENTER THE MAX MATRIX \n");
    for(int i = 0;i< np; i++)
        for(int j =0; j< nr;j++)
            scanf("%d",&max[i][j]);
    bool safe = safetyAlgorithm();
    if(safe)
        resourceRequestAlgorithm();
}
