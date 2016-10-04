#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *fp;
    int money_now,bonus,money_estimate;
    double rate,year;
    fp = fopen("2.txt","r");
    if(!fp){
        printf("no such file");
        exit(0);
    }
    printf("open file success\n\n");
    fscanf(fp,"%d %d %d",&money_now,&bonus,&money_estimate);
    fclose(fp);

    printf("money now : %d,\n",money_now);
    printf("bonus : %d,\n",bonus);
    printf("money estimate : %d\n",money_estimate);


    // compute
    rate = 1 + (double)bonus/100;
    year = (log((double)money_estimate)-log((double)money_now))/(log((double)rate));
    printf("you need %f years to let your money from %d grow up to %d\n",year,money_now,money_estimate);


    return 0;
}
