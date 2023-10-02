#include<stdio.h>
#include<stdbool.h>
struct process{
    int process_id ;
    int burst_time ;
    int turn_around_time;
    int waiting_time;
    bool isCompleted;
    int required_time;
};

void roundrobin(struct process *p,int n,int qt);
void displayDetails(struct process *p,int no_of_process);

int main(){
    int no_of_process;
    int quantum_time;
    struct process p[10];

    printf("Enter the number of processes : ");
    scanf("%d",&no_of_process);
    printf("Enter the quantum time : ");
    scanf("%d",&quantum_time);
    printf("Enter the process_id and burst_time of each process :\n");
    for(int i=0;i<no_of_process;i++)
        scanf("%d%d",&p[i].process_id,&p[i].burst_time);

    roundrobin(p,no_of_process,quantum_time);
    displayDetails(p,no_of_process);
    return 0;
}
void roundrobin(struct process *p,int n,int qt){
    for (int i = 0; i < n; i++){
        p[i].isCompleted = false;
        p[i].required_time = p[i].burst_time;
    }
    int tat_prev = 0;
    int one_more = n;
    for(int i = 0; one_more > 0 ; i = (i+1)%n){
        if(p[i].isCompleted)
            continue;
        if(p[i].required_time > qt){
            p[i].turn_around_time = tat_prev + qt;
            p[i].required_time -=qt; 
        }
        else{
            p[i].turn_around_time = tat_prev + p[i].required_time;
            p[i].isCompleted = true;
            one_more--;
        }
        tat_prev = p[i].turn_around_time;
        p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
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
