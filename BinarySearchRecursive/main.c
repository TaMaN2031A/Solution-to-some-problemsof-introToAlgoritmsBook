#include <stdio.h>
#include <stdlib.h>
#define max 100
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
    int n,a[max], number,noit,counter = 0;
    scanf("%i",&noit);
    while(counter < noit)
    {
    scanf("%i\n",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%i",&a[i]);
    }
    scanf("%i",&number);
    printf("%i\n",index(a,0,n,number));
    counter++;
    }
    return 0;
}
