#include <stdio.h>

#define MAX_PROCESSES 10


typedef struct {
    int pid;        
    int arrival;
    int burst;      

    int queue;
} Process;


void fcfs(Process queue[], int n) {
    int time = 0;
    printf("\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    int completion, turnaround, waiting;
    
    for (int i = 0; i < n; i++) {
        if (time < queue[i].arrival)
            time = queue[i].arrival;
        
        completion = time + queue[i].burst;
        turnaround = completion - queue[i].arrival;
        waiting = turnaround - queue[i].burst;
        
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", queue[i].pid, queue[i].arrival, queue[i].burst, completion, turnaround, waiting);
        time = completion;
    }
}

int main() {
    Process processes[MAX_PROCESSES], systemQueue[MAX_PROCESSES], userQueue[MAX_PROCESSES];
    int n, sysCount = 0, userCount = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter Process ID, Arrival Time, Burst Time, and Queue Type (0 for System, 1 for User)\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d %d", &processes[i].pid, &processes[i].arrival, &processes[i].burst, &processes[i].queue);
        
        if (processes[i].queue == 0)
            systemQueue[sysCount++] = processes[i];
        else
            userQueue[userCount++] = processes[i];
    }
    
    
    for (int i = 0; i < sysCount - 1; i++) {
        for (int j = i + 1; j < sysCount; j++) {
            if (systemQueue[i].arrival > systemQueue[j].arrival) {
                Process temp = systemQueue[i];
                systemQueue[i] = systemQueue[j];
                systemQueue[j] = temp;
            }
        }
    }
    
    for (int i = 0; i < userCount - 1; i++) {
        for (int j = i + 1; j < userCount; j++) {
            if (userQueue[i].arrival > userQueue[j].arrival) {
                Process temp = userQueue[i];
                userQueue[i] = userQueue[j];
                userQueue[j] = temp;
            }
        }
    }
    
   
    printf("\nExecuting System Queue (Higher Priority)\n");
    fcfs(systemQueue, sysCount);
    
   
    printf("\nExecuting User Queue (Lower Priority)\n");
    fcfs(userQueue, userCount);
    
    return 0;
}
