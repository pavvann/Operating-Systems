#include <stdio.h>

int main()
{
    int n;
    printf("enter the number of processes: ");
    scanf("%d", &n);

    float bt[n], prt[n], seq[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nenter the burst time of process %d: ", i);
        scanf("%f", &bt[i]);
        printf("enter the priority of process %d: ", i);
        scanf("%f", &prt[i]);
        seq[i]=i;
    }
    int tempp = 0, tempbt = 0, temps =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (prt[i]>prt[j])
            {
                tempp = prt[i];
                prt[i] = prt[j];
                prt[j] = tempp;

                tempbt = bt[i];
                bt[i] = bt[j];
                bt[j] = tempbt;

                temps = seq[i];
                seq[i] = seq[j];
                seq[j] =temps;
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
    printf("\nSequence of Processes: P%.0f", seq[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" -> P%.0f", seq[i]);
    }
    printf("\n\nAverage waiting time = %.2f ms\nAverage turnaround time = %.2f ms\n\n", wtsum/n, ttsum/n); 
    return 0;
}




