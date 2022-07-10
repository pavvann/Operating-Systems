#include <stdio.h>
#include <stdlib.h>

void first_fit(int no_of_processes, int size_of_processes[], int block[], int location[], int count[], int mem, int j)
{
    for (int i = 0; i < no_of_processes; i++)
    {
        int flag = 0, loca;
        for (int l = 0; l < j ; l++)
        {
            if (count[l]>=size_of_processes[i])
            {
                for (int k = 0; k < size_of_processes[i]; k++)
                {
                    block[location[l]+k] = 1;
                }
                count[l] -= size_of_processes[i];
                loca = location[l];
                location[l] += size_of_processes[i];
                flag = 1;
            }
            if (flag == 1)
            {
                printf("Memory for process %d successfully alloted at location %d\n", i + 1, loca);
                break;
            }
            
        }
        if (flag == 0)
        {
            printf("Memory for process %d could not be allocated\n", i+1);
        }
        
    }
    printf("\n\nUpdated memory status: ");
    for (int i = 0; i < mem; i++)
    {
        printf("%d ",block[i]);
    }
    printf("\n\n");
}

void best_fit(int no_of_processes, int size_of_processes[], int block[], int location[], int count[], int mem, int j)
{
    int temp, templ;
    for (int i = 0; i < j; i++)
    {
        for (int k = i+1; k < j; k++)
        {
            if (count[i] > count[k])
            {
                temp = count[i];
                count[i] = count[k];
                count[k] = temp;

                templ = location[i];
                location[i] = location[k];
                location[k] = templ;
            }   
        }
    }
    for (int i = 0; i < no_of_processes; i++)
    {
        int flag = 0, loca;
        for (int l = 0; l < j ; l++)
        {
            if (count[l]>=size_of_processes[i])
            {
                for (int k = 0; k < size_of_processes[i]; k++)
                {
                    block[location[l]+k] = 1;
                }
                count[l] -= size_of_processes[i];
                loca = location[l];
                location[l] += size_of_processes[i];
                flag = 1;
            }
            if (flag == 1)
            {
                printf("Memory for process %d successfully alloted at location %d\n", i + 1, loca);
                break;
            }
            
        }
        if (flag == 0 )
        {
            printf("Memory for process %d could not be allocated\n", i+1);
        }
        
    }
    printf("\n\nUpdated memory status: ");
    for (int i = 0; i < mem; i++)
    {
        printf("%d ",block[i]);
    }
    printf("\n\n");
}

void worst_fit(int no_of_processes, int size_of_processes[], int block[], int location[], int count[], int mem, int j)
{
    int temp, templ;
    for (int i = 0; i < j; i++)
    {
        for (int k = i+1; k < j; k++)
        {
            if (count[i] < count[k])
            {
                temp = count[i];
                count[i] = count[k];
                count[k] = temp;

                templ = location[i];
                location[i] = location[k];
                location[k] = templ;
            }   
        }
    }
    for (int i = 0; i < no_of_processes; i++)
    {
        int flag = 0, loca;
        for (int l = 0; l < j ; l++)
        {
            if (count[l]>=size_of_processes[i])
            {
                for (int k = 0; k < size_of_processes[i]; k++)
                {
                    block[location[l]+k] = 1;
                }
                count[l] -= size_of_processes[i];
                loca = location[l];
                location[l] += size_of_processes[i];
                flag = 1;
            }
            if (flag == 1)
            {
                printf("Memory for process %d successfully alloted at location %d\n", i + 1, loca);
                break;
            }
            
        }
        if (flag == 0 )
        {
            printf("Memory for process %d could not be allocated\n", i+1);
        }
        
    }
    printf("\n\nUpdated memory status: ");
    for (int i = 0; i < mem; i++)
    {
        printf("%d ",block[i]);
    }
    printf("\n\n");
}

int main()
{
    printf("Enter the memory available: ");
    int mem, n;
    scanf("%d", &mem);
    int block[mem];
    printf("\nEnter 0 for unoccupied block and 1 for occupied block: \n-> ");
    for (int i = 0; i < mem; i++)
    {
        scanf("%d", &block[i]);
    }
    
    printf("\nUnoccupied Blocks: \n-> ");
    for (int i = 0; i < mem; i++)
    {
        if (block[i]==0)
        {
            printf("%d ", i + 1);
        }    
    }
    printf("\n\nOccupied Blocks: \n-> ");
    for (int i = 0; i < mem; i++)
    {
        if (block[i]==1)
        {
            printf("%d ", i + 1);
        }
    }
    
    printf("\n\nUsed space\tSize\n");
    for (int i = 0; i < mem; i++)
    {
        
        int filled_location = i, count = 0, flag = 1;
        while (block[i] == 1)
        {
            count++;
            ++i;
            flag = 0;
        }
        if (flag == 0)
        {
            printf("%d\t\t%d\n", filled_location, count);  
        }
        
    }
    int location[mem], count[mem], j = 0;
    printf("\n\nFree space\tSize\n");
    for (int i = 0; i < mem; i++)
    {
        location[j] = i, count[j] = 0;
        int flag = 1;
        while (block[i] == 0 && i < mem)
        {
            count[j]++;
            ++i;
            flag = 0;
        }
        if (flag == 0)
        {
            printf("%d\t\t%d\n", location[j], count[j]);    
            j++;
        }
        
    }
    
    
    int choice;
    while (1)
    {   
        printf("\nDo you want to add more processes?\n1. Yes\n2. No\n-> ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int no_of_processes;
            printf("\nEnter the number of processes you want to add: ");
            scanf("%d", &no_of_processes);
            printf("Enter the size of each processes: \n-> ");
            int size_of_processes[no_of_processes];
            for (int i = 0; i < no_of_processes; i++)
            {
                scanf("%d", &size_of_processes[i]);
            }
            printf("\n\nEnter your choice\n1. First Fit\n2. Best Fit\n3. Worst Fit\nAny other key to exit\n-> ");
            scanf("%d", &choice);
            
            printf("\n");
            switch (choice)
            {
            case 1:
                first_fit(no_of_processes, size_of_processes, block, location, count, mem, j);
                break;

            case 2:
                best_fit(no_of_processes, size_of_processes, block, location, count, mem, j);
                break;
            
            case 3:
                worst_fit(no_of_processes, size_of_processes, block, location, count, mem, j);
                break;
            
            default:
                exit(1);
                break;
            }
        }
        else
        {
            exit(1);
        }
    }
    return 0;
}










