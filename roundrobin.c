#include <stdio.h>

int main()
{
    int t;
    float tq, tt = 0, wt = 0;
    printf("Enter the number of processes: ");

    scanf("%d", &t);

    float bt[t], at[t], btr[t], pid[t];

    for (int i = 0; i < t; i++)
    {
        printf("\nEnter the Burst Time of Process %d: ", i+1);
        scanf("%f", &bt[i]);
        btr[i] = bt [i];
        printf("Enter the Arrival Time of Process %d: ", i+1);
        scanf("%f", &at[i]);
        pid[i] = i+1;
    }
    int tempat, tempbt, tempbtr, temppid;

    for (int i = 0; i < t; i++)
    {
        for (int j = i+1; j < t; j++)
        {
            if (at[i]>at[j])
            {
                tempat = at[i];
                at[i] = at[j];
                at[j] = tempat;

                tempbt = bt[i];
                bt[i] = bt[j];
                bt[j] = tempbt;

                tempbtr = btr[i];
                btr[i] = btr[j];
                btr[j] = tempbtr;

                temppid = pid[i];
                pid[i] = pid[j];
                pid[j] = temppid;
            }
        }
    }

    printf("\nEnter the time quantum: ");
    scanf("%f", &tq);
    float gct = at[0], totbt = 0, tta[t];
    for (int i = 0; i < t; i++)
    {
        totbt+=bt[i];
    }

    printf("\nSequence of processes: \n");
    for (int i = 0; i < totbt/tq ; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (gct >= at[j])   
            {
                if (btr[j]>=tq)
                {
                    btr[j] -= tq;
                    gct += tq;
                    printf("-> P%d ", j+1);
                    if (btr[j]==0)
                    {
                        tta[j] = gct-at[j];
                    }    
                }
                else if (btr[j]<tq && btr[j]> 0)
                {
                    gct += btr[j];
                    btr[j] -= btr[j];
                    printf("-> P%d ", j+1);
                    if (btr[j]==0)
                    {
                        tta[j] = gct-at[j];
                    }
                }
                else
                    continue;
            }
        }
        if (gct - at[0]==totbt)
        {
            break;
        }
    }

    printf("\n");
    for (int i = 0; i < t; i++)
    {
        wt += tta[i] - bt[i];
    }
    
    for (int i = 0; i < t; i++)
    {
        tt += tta[i];
    }
    printf("\nAverage turnaround time = %.2f\n", tt/t);
    printf("\nAverage waiting time = %.2f\n\n", wt/t);
}






