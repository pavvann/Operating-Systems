#include <stdio.h>

int main()
{
    printf("Name: Pawan Bajaj\tSAP ID: 500096625\tBatch: B-39\n\n");
    int n;
    printf("enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");
    float bt[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter the burst time of process %d: ", i);
        scanf("%f", &bt[i]);
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
    
    printf("\nAverage waiting time = %.2f ms\nAverage turnaround time = %.2f ms\n", wtsum/n, ttsum/n); 
    return 0;  
}













///////////////////////////////////////////////////////////////////////////////////////////////////////







/*
struct process
{
        int PID;
        int burst_time;
};

int individual_process(struct process p[], int i)
{  
    int loop_var, process_time=0;
    for(loop_var=i; loop_var>=0; loop_var--)
    {
        process_time+= p[loop_var].burst_time;
    }
    return process_time;
}

int sum(struct process p[], int n)
{
    int wait_time = 0;
    for(int i = 0; i < n-1; i++)
    {
        wait_time +=  individual_process(p, i);
    }
    return wait_time;
}

int main()
{
    int waitTime, numberOfProcesses, loop;
    float avgWaitTime;
    printf("Enter total number of processes: ");
    scanf("%d", &numberOfProcesses);
    struct process p[numberOfProcesses];
    for (loop=1; loop<=numberOfProcesses; loop++)
    {
        struct process p[loop];
    }
    for (loop=0; loop<numberOfProcesses; loop++)
    {
        p[loop].PID = loop;
        printf("Enter the burst time of PID %d: ", loop);
        scanf("%d", &p[loop].burst_time);
    }
    waitTime = sum(p, numberOfProcesses);
    avgWaitTime = (float)waitTime / (numberOfProcesses);

    printf("Average wait time: %f\n", avgWaitTime);
    return 0;
}*/