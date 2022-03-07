#include <stdio.h>
#include <stdlib.h>
#define max 100
int binarySortIndexFinder(int a[],int start,int end,int number) // sending the loop invariant with the key to find its place
{
    int x, mid=(start+end)/2; // calculating the mean
   // if(end > start) // means we still searching, it's the condition that permits us to keep on searching in the subarray
    if(mid != 0 && a[end] < 100)
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
        else if(a[mid] == number){
            x = mid + 1;
        }
        else if(a[mid] < number && a[mid+1]> number){
            x = mid + 1;    // why? because the bigger is to be pushed
        }
        else if(a[mid] > number && a[mid-1] < number){
            x = mid;    // why? because the bigger is to be pushed
        }
    }
      else if(mid == 0)
      {
          if(number<=a[mid])
            x = 0;
          if(number>a[mid])
            x=1;
      }
      else
        x = end;
       // else if(start === end)
    //}
    // in case of start == end pr start > end means that we have found the place, it's the Qonquer step


    return x;
}

void insRec(int a[],int n)
{
    int key, begii;
    if(n == 0)      // the base case, reaching a sorted subarray of one element
        return;
    else
    {
           key = a[n];     // the element we want to find its place in the subarray
           insRec(a,n-1);  // the subproblem, calling a smaller version of the problem
           begii = binarySortIndexFinder(a,0,n,key); // takes to the binary sort function that allow us to find the index
           for(int i = n; i > begii; i--) //
           {
               a[i]=a[i-1];
           }
           a[begii] = key;
           for(int i = 0; i <= n; i++)
            {
                printf("%i ",a[i]);
            }
            printf("\n");
        return;
    }
}


int main()
{
    int a[max],n,co,te = 0;
    scanf("%i",&co);
    while(te < co){
    scanf("%i",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%i",&a[i]);
    }
    insRec(a,n-1); //Takes us to the insertion sort function
    for(int i = 0; i < n; i++)
    {
        printf("%i ",a[i]);
    }
    te++;
    }
    return 0;
}
