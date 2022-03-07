#include <stdio.h>
#include <stdlib.h>
#define max 100
int binarySortIndexFinder(int a[],int start,int end,int number) // sending the loop invariant with the key to find its place
{
    int x, mid=(start+end)/2; // calculating the mean
    if(end > start) // means we still searching, it's the condition that permits us to keep on searching in the subarray
    {
        if(a[mid] < number){
            start = mid + 1; // the O(lg(n)) step which breaks the problem into smaller ones
            x = binarySortIndexFinder(a, start, end, number); //smaller subproblems
        }
        else if(a[mid] > number)
            {
            end = mid - 1; // the O(lg(n)) step which breaks the problem into smaller ones
            x = binarySortIndexFinder(a, start, end, number);//smaller subproblem
            }
    }
    else
        x = mid; // in case of start == end pr start > end means that we have found the place, it's the Qonquer step


    return x;
}

void insRec(int a[],int n)
{
    int key, begii;
    if(n == 0)      // the base case, reaching a sorted subarray of one element
        return;
    else
    {
           insRec(a,n-1);  // the subproblem, calling a smaller version of the problem
           key = a[n];     // the element we want to find its place in the subarray
           begii = binarySortIndexFinder(a,0,n,key); // takes to the binary sort function that allow us to find the index
           for(int i = n; i > begii; i--) //
           {
               a[i]=a[i-1];
           }
           a[begii] = key;
           return;
    }
}
int index(int a[],int start,int end,int number)
{
    int x, mid=(start+end)/2;
    if(end >= start)
    {
        if(a[mid] < number){
            start = mid + 1;
            x = index(a, start, end, number);
        }
        else if(a[mid] > number){
            end = mid - 1;
            x = index(a, start, end, number);
        }
        else
            x = mid;
    }
    else
        x = -1;

    return x;
}

int main()
{
    int n,a[max], number,noit,counter = 0,x;
    scanf("%i",&noit);
    while(counter < noit)
    {
    scanf("%i\n",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%i",&a[i]);
    }
    scanf("%i",&number);
    insRec(a,n);
    for(int i = 0; i < n; i++)
    {
        printf("%i ",a[i]);
    }
    /*for(int i = 0; i < n; i++)
    {
        x = index(a,0,n,number-a[i]);
        if(x != -1 && x != i)
        {
            printf("Numbers %i and %i can help us\n",a[i],a[x]);
        }

    }*/
    counter++;
    }
    return 0;
}
