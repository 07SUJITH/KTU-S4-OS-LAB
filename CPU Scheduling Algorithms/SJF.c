#include<stdio.h>
#include<stdbool.h>
struct process{
    int process_id ;
    int burst_time ;
    int turn_around_time;
    int waiting_time;
};
void sjf(struct process *p,int no_of_process);
void displayDetails(struct process *p,int no_of_process);
int main(){
    int no_of_process;
    struct process p[10];

    printf("Enter the number of processes : ");
    scanf("%d",&no_of_process);
    printf("\nEnter the process_id and burst_time of each process\n");
    for(int i=0;i<no_of_process;i++)
        scanf("%d%d",&p[i].process_id,&p[i].burst_time);
    sjf(p,no_of_process);
    displayDetails(p,no_of_process);
    return 0;
}
void processSort(struct process *p,int n){
    int min_idx;
    struct process temp;
    for(int i = 0;i < n-1 ; i++){
        min_idx = i;
        for(int j =i +1 ; j < n ;j++ )       
                if(p[j].burst_time < p[min_idx].burst_time)
                    min_idx = j;          
        if(min_idx != i){
            temp = p[i];
            p[i] = p[min_idx];
            p[min_idx] = temp;
        }
    }
}
void sjf(struct process *p,int no_of_process){ 
    processSort(p,no_of_process);
    int turnaround_time_prev = 0;
    for(int i = 0; i< no_of_process;i++){
        p[i].turn_around_time = turnaround_time_prev + p[i].burst_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
        turnaround_time_prev = p[i].turn_around_time;
    }
}
void displayDetails(struct process *p,int no_of_process){
    int total_TAT = 0;
    int total_WT = 0;
    printf("Process_id  Burst_time  Turn_around_time  Waiting_time \n");
    for(int i=0;i<no_of_process;i++){
        printf("  %d\t\t%d",p[i].process_id,p[i].burst_time);
        printf("\t\t%d \t\t %d\n",p[i].turn_around_time,p[i].waiting_time);
        total_TAT +=p[i].turn_around_time;
        total_WT +=p[i].waiting_time;
    }
    printf("Total turn around time : %d\n",total_TAT);
    printf("Average turn around time = %.2f\n",(float)total_TAT/no_of_process);
    printf("Total waiting time : %d\n",total_WT);
    printf("Average waiting time = %.2f\n",(float)total_WT/no_of_process);
}
