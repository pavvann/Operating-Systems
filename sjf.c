#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    float pid[n], bt[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the burst time of process %d (in ms): ", i);
        scanf("%f", &bt[i]);
        pid[i]=i;
    }
    int temp, temppid;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (bt[i]>bt[j])
            {
                temp = bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temppid = pid[i];
                pid[i]=pid[j];
                pid[j]=temppid;
            }   
        }   
    }
    float wt[n];
    wt[0]=0;
    float wtsum=0;
    for (int i = 1; i < n; i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        wtsum += wt[i];
    }
    float tt[n];
    float ttsum = 0;
    for (int i = 0; i < n; i++)
    {
        tt[i]=wt[i]+bt[i];
        ttsum += tt[i];
    }
    printf("\n\nSequence of processes: P%.0f", pid[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" -> P%.0f", pid[i]);
    }
    
    printf("\n\nAverage waiting time = %.2f ms\nAverage turnaround time = %.2f ms\n\n", (wtsum)/n, ttsum/n); 
    return 0;
}










