#include <stdio.h>
int main() {
    int n, i;
    int bt[20], at[20], ct[20], wt[20], tat[20];
    float awt = 0, atat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time of each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }
    printf("Enter the burst time of each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
    ct[0] = at[0] + bt[0];
    for(i = 1; i < n; i++) {
        if(at[i] > ct[i-1]) {
            
            ct[i] = at[i] + bt[i];
        } 
        else {
            ct[i] = ct[i-1] + bt[i];
        }
    }
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
        atat += tat[i];
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", awt/n);
    printf("Average Turnaround Time: %.2f\n", atat/n);
    return 0;
}

