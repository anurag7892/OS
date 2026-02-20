#include <stdio.h>
int main()
{
    int n = 5;
    int at[5] = {0, 1, 2, 3, 4};
    int bt[5] = {5, 7, 6, 2, 4};
    int d=2;
    int ct[n], tat[n], wt[n];

    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    for (int i = 1; i < n; i++)
    {
        ct[i] = 2 + (ct[i - 1] + bt[i]);
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    printf("\nProcess\tAT\tBT\tD\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], d,ct[i], tat[i], wt[i]);
    }
    return 0;
}