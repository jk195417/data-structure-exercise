#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10
typedef struct {
	float coe;
	int exp;
} variable;

struct mypoly
{
	variable var[MAX];
	int length;

	void ShowPoly();
	mypoly Add(mypoly);
	mypoly SingelMult(int);
	int Lead_Exp();
	void Attach(float,int);
	void Remove(int);
	mypoly Mult(mypoly);

	mypoly(){
		length = 0;
	};
	mypoly(char *filename){
		FILE *fptr;
		fptr = fopen(filename,"r");
		total=0;
		while(!feof(fptr))
		{
			fscanf(fptr,"%f %d",&terms[total].coef,&terms[total].expon);
			total++;

		}
		fclose(fptr);
	};
};

int main()
{

	mypoly A("a.txt");
	mypoly B("b.txt");
	int i;

	A.ShowPoly();
	B.ShowPoly();

	A = A.SingelMult(3);
	A.ShowPoly();


	system("pause");
	return 0;
}

void mypoly::ShowPoly()
{

	int i;
	for(i=0;i<total;i++)
	{
		if(i<total-1)
		{
			printf("%.0fX^%d+",terms[i].coef,terms[i].expon);
		}
		else
			printf("%.0fX^%d",terms[i].coef,terms[i].expon);
	}
	printf("€n");

}

mypoly mypoly::SingelMult(int c)
{
	mypoly D;
	int i;

	for(i=0;i<total;i++)
	{
		D.terms[i].coef = terms[i].coef * c ;
		D.terms[i].expon = terms[i].expon ;
		D.total++;
	}
	return D;
}
