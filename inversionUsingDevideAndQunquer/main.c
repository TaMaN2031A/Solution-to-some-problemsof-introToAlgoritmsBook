#include <stdio.h>
#include <stdlib.h>
#define max 100
int qunquer(int arr[], int start, int mid, int end)
{
   int cR = mid + 1, cL = start,Rl = mid-start+1, Rr = end-mid, range = Rl*Rr, left[max], right[max], inv = 0, cr = 0, cl = 0; // all this values are calculated on the logic that mid in included in the left[], You can watch the picture in the AlgoApproaches/inversion_as_divide&conquer
   for(int i = 0; i < Rr; i++)
   {
       right[i] = arr[cR];
       cR++;
   }
   for(int i = 0; i < Rl; i++)
   {
       left[i] = arr[cL];
       cL++;
   }
   for(int i = 0; i < range; i++)
   {
       if(cr < Rr)
       {
         if(left[cl] > right[cr])
          inv++;
         cr++;
       }
       else // reseting the loop left[], this step kept the process linear instead of using double for loop
        {
         cl++;
         cr = 0;
         i--; // the most beautiful step, we have found a bug. First there were only range comparisons, but we then found out that when we reset cr this...
        } // demands a step, so we minused i because we really care ab out the steps where there is a comparison left[cl] > right[cr] is held
   }
   return inv;
}




int breakTheList(int arr[], int start, int end)
{
    int mid, inversions = 0;
    if(start < end)
    {
        mid = (start + end)/2;
        inversions += breakTheList(arr, start, mid);    // the standard divide used in merge sorting "nothing new except for that we know want the value ...
        inversions += breakTheList(arr, mid+1, end);    // ... returned from the current qunquer and the previous ones so we made this integer"
        inversions += qunquer(arr,start,mid,end);
    }
    return inversions;
}


int main()
{
    int arr[max],n;
    scanf("%i",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%i",&arr[i]);
    }
    printf("There is %i inversions in the list, Amigo!",breakTheList(arr, 0, n-1));
    return 0;
}
