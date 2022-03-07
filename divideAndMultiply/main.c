#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i, j, t;
    scanf("%i %i", &i, &j);
    if(i>j)
    {
      t=i;
      i=j;
      j=t;
    }
    int outcounter = i, incounter = i, x = i, printedcounter = 0, counter = 0;
    while(outcounter <= j)
    {
        while(incounter!=1)
        {
            counter++;
            if(incounter % 2 == 0)
                incounter/=2;
            else
                incounter = incounter*3 + 1;
        }
        if( counter > printedcounter )
        {
            printedcounter = counter;
        }
        outcounter++;
        x++;
        incounter = x;
        counter = 0;
    }
    printf("%i %i %i",i,j,printedcounter+1);

    return 0;
}
