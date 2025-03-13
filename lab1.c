#include <stdio.h>

void sort(int proc_id[], int at[], int bt[], int n) {
    int min, temp;
    for (int i = 0; i < n; i++) {
        min = at[i];
        for (int j = i; j < n; j++) {
            if (at[j] < min) {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                
                temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;
                
                temp = proc_id[i];
                proc_id[i] = proc_id[j];
                proc_id[j] = temp;
            }
        }
    }
}

int main() {
    int n, c = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int proc_id[n], at[n], bt[n], ct[n], tat[n], wt[n];
    
    
    for (int i = 0; i < n; i++) {
        proc_id[i] = i + 1;  
    }

    printf("Enter arrival times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    sort(proc_id, at, bt, n);

    for (int i = 0; i < n; i++) {
        if (c >= at[i])
            c += bt[i];
        else
            c += at[i]  + bt[i];
        ct[i] = c;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
    }

   
    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
    }

    printf("FCFS scheduling:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", proc_id[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // for (int i = 0; i < n; i++) {
    //     ttat += tat[i];
    //     twt += wt[i];
    // }

    // avg_tat = ttat / (double)n;
    // avg_wt = twt / (double)n;

    // printf("\nAverage turnaround time: %.2lf ms\n", avg_tat);
    // printf("Average waiting time: %.2lf ms\n", avg_wt);

    return 0;
}
