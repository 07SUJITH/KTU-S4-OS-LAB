#include<stdio.h>
#include<stdlib.h>

int main(){

    int n , disk_queue[20],head,head_mov =0;
    printf("ENTER THE SIZE OF DISK QUEUE : ");
    scanf("%d",&n);
    printf("ENTER THE HEAD POINTER POSITION : ");
    scanf("%d",&head);
    printf("ENTER THE DISK QUEUE : ");
    for(int i =0;i< n;i++)
        scanf("%d",&disk_queue[i]);

    int prev = head;
    printf("\nSEEK SEQUENCE IN FCFS : ");
    for(int i =0;i< n; i++){
        head_mov += abs(disk_queue[i]-prev);
        prev = disk_queue[i];
        if(i<n-1)
            printf("%d -> ",prev);
        else    
            printf("%d \n",disk_queue[i]);
    }
    printf("TOTAL HEAD MOVEMENT : %d",head_mov);
}
