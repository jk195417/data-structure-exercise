#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void p(int num,int bits){
  int q,r;
  if(bits==1){
    r =  num % 2;
    printf("%d\n",r);
  }else{
    q = (num / (int)pow(2,bits-1));
    r = (num % (int)pow(2,bits-1));
    printf("%d ",q);
    p(r,bits-1);
  }
}

int main(){

  int num;
  printf("Input a number:");
  scanf("%d",&num);

  for(int i=0;i<=pow(2,num)-1;i++){
    p(i,num);
  }
  return 0 ;
}
