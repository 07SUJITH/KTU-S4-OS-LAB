#include<stdio.h>
#include<limits.h>

int main(){
    
    int block_size[10],process_size[10],allocated_block[10];
    int no_of_blocks,no_of_processes,fragment;
    int least=INT_MAX;
    for(int i =0;i< 10; i++)
        allocated_block[i] = -1;

 
    printf("ENTER THE NUMBER OF BLOCKS: ");
    scanf("%d",&no_of_blocks);
    printf("ENTER THE SIZE OF EACH BLOCK: ");
    for(int i = 0; i < no_of_blocks;i++)
        scanf("%d",&block_size[i]);
    printf("ENTER THE NUMBER OF PROCESSES: ");
    scanf("%d",&no_of_processes);
    printf("ENTER THE SIZE OF EACH PROCESSES: ");
    for(int i = 0; i < no_of_processes;i++)
        scanf("%d",&process_size[i]);
    
    
    for(int i = 0; i < no_of_processes;i++){
        for(int j = 0;j< no_of_blocks;j++){
            if(process_size[i]<=block_size[j]){
                fragment = block_size[j] - process_size[i];
                if(fragment < least ){
                    least = fragment;
                    allocated_block[i] = j;
                }
            }
        }
        if(allocated_block[i] !=-1)
            block_size[allocated_block[i]] -= process_size[i];
        least=INT_MAX;
    }
   
    printf("\nPROCESS NO.\tPROCESS SIZE\tBLOCK NO\n");
    for(int i = 0; i < no_of_processes ;i++ ){
        printf("  %d\t\t  %d\t\t",i+1,process_size[i]);
        if(allocated_block[i] !=-1)
            printf("  %d\n",allocated_block[i]+1);
        else
            printf("NOT ALLOCATED\n");
    }


}

