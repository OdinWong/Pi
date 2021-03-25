#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    FILE *pifp = fopen("./pi1000000.txt","r");

    if (!pifp)
    {
        exit(1);
    }
    
    long freq[10];
    int d;
    memset(freq, 0, 10*__SIZEOF_LONG__);
    while ((d = getc(pifp)) != EOF)
    {
        if (isdigit(d))
        {
            freq[d - '0']++;
            printf("%d", d - '0');
        }
        
    }
    
    for (size_t i = 0; i <= 9; i++)
    {
        printf("\n%ld - %8ld", i ,freq[i]);
    }
    printf("\n");

    return 0;
}
