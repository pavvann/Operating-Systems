#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fcfs(int blocks[], int length, int start)
{
    int head = abs(start - blocks[0]);
    printf("Sequence of Blocks: %d", start);
    for (int i = 0; i < length - 1; i++)
    {
        printf(" -> %d", blocks[i]);
        head += abs(blocks[i+1] - blocks[i]);
    }
    printf(" -> %d", blocks[length-1]);
    printf("\nTotal Head Movements = %d Cylinders", head);
}

void sstf(int blocks[], int length, int start)
{
    int location,x, y, head = 0;
    printf("Sequence of Blocks: %d", start);
    for (int i = 0; i < length; i++)
    {
        int pointer = abs(start - blocks[0]);
        for (int j = 0; j < length; j++)
        {   
            x = abs(start - blocks[j]);
            if (x <= pointer)
            {
                y = blocks[j];
                pointer = x;
                location = j;
            }
        }
        printf(" -> %d", y);
        start = y;
        head += pointer;
        blocks[location] = 100000;
    }
    printf("\nTotal Head Movements = %d Cylinders", head);
}

void scan(int blocks[], int length, int start, int size, int direction)
{
    int end, head;
    for (int i = 0; i < length; i++)
    {
        int temp;
        for (int j = i+1; j < length; j++)
        {
            if (blocks[i] > blocks[j])
            {
                temp = blocks[i];
                blocks[i] = blocks[j];
                blocks[j] = temp;
            }
        }
    }
    
    printf("Sequence of Blocks: %d", start);
    if (direction == 1)
    {
        int loca;
        end = size - 1;
        for (int i = 0; i < length; i++)
        {
            if (blocks[i]<start)
            {
                loca = i;
                continue;
            }
        }    
        loca++;
        for (int j = loca; j < length; j++)
        {
            printf(" -> %d", blocks[j]);
        }
        printf(" -> %d", end);
        for (int j = loca - 1; j >= 0; j--)
        {
            printf(" -> %d", blocks[j]);
        }   
        head = abs(end-start) + abs(end - blocks[0]);
    }

    else
    {    
        int loca;
        end = 0;
        for (int i = 0; i < length; i++)
        {
            if (blocks[i]>start)
            {
                loca = i;
                break;
            }
        }
        loca--;
        for (int j = loca; j >= 0; j--)
        {
            printf(" -> %d", blocks[j]);
        }
        printf(" -> %d", end);
        for (int j = loca+1; j < length; j++)
        {
            printf(" -> %d", blocks[j]);
        }
        head = abs(end-start) + abs(end - blocks[length - 1]);
    }
    printf("\nTotal Head Movements = %d Cylinders", head);
}
int main()
{
    int start, length, size;
    printf("Enter the Size of Memory: ");
    scanf("%d", &size);

    printf("Enter the Block you are presently at: ");
    scanf("%d", &start);

    printf("Enter the number of blocks to travel to: ");
    scanf("%d", &length);
    
    int blocks[length];
    printf("Enter the sequence of blocks: ");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &blocks[i]);
        if (blocks[i]>=size || blocks[i]<0)
        {
            printf("Block location out of bounds!");
            i--;
        }  
    }
    while (1)
    {
        int choice, direction, tempblocks[length];
        printf("\n\nEnter your choice:\n1.FCFS\n2.SSTF\n3.SCAN\nAny other to exit\n-> ");
        scanf("%d", &choice);
        for (int i = 0; i < length; i++)
        {
            tempblocks[i] = blocks[i];
        }
        
        switch (choice)
        {
        case 1:
            fcfs(tempblocks, length, start);
            break;
        
        case 2:
            sstf(tempblocks, length, start);
            break;
        
        case 3:
            printf("Enter the direction for pointer (0 for direction towards 0 and 1 for direction towards %d: ", size-1);
            scanf("%d", &direction);
            scan(tempblocks, length, start, size, direction);
            break;

        default:
            exit(1);
            break;
        }     
    }
    return 0;
}



