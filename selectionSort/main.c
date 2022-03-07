#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*                                 cost    times
    for(i equal 0 to n-2)              c1      n-1
        for(j equals to i+1 to n-1)    c2      E(tj) j is from1 to n
            if(a[j]<a[i])              c3      E(tj - 1) j is from1 to n
                 index = j;            c4      E(tj - 1) j is from1 to n
        t = a[i];                      c5      n-2
        a[i] = a[index];               c6      n-2
        a[index] = t;                  c7      n-2
    *.......................................................*
    best case : c1(n-1)+c2*n+c5*(n-2)+c6*(n-2)+c7*(n-2)
         O(n)
    worst case : c1(n-1)+c2*n**+c3*n**2+c4*n**2+c5(n-2)+c6*(n-2)+c7*(n-2)
         O(n^2)
    cannot find the loop invariant
    * ........... *
    Our mistake : it's always n^2, because in each iteration we must take the inner for loob , insertion was different
    because it depended on a condition in while which is as long as the element selected is bigger than the main element, then compare.
    But now we are iterating always the inner for loop

    */
    return 0;
}
