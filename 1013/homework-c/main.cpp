#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define POLY_MAX 30
#define ACT_LEN 8

struct variable{
	float coe;
	int exp;
};

struct mypoly{
	variable var[POLY_MAX];
	int length;

	void ReadData(char *filename);
	void ShowPoly();
	mypoly Add(mypoly);
	void SingelMult(int);
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
		length = 0;
		while(!feof(fptr)){
			fscanf(fptr,"%f %d",&var[length].coe,&var[length].exp);
			length++;
		}
		fclose(fptr);
	};
};

int main(){
  int opt,p,mult,add_e,re_e;
  float add_c;
  bool over = false;
  mypoly A,B;
	char *action[ACT_LEN];
	action[0]="讀入多項式\n";
	action[1]="印出多項式內容\n";
	action[2]="多項式相加\n";
	action[3]="多項式乘上一數值\n";
	action[4]="印出多項式中最大指數的係數\n";
	action[5]="新增項式\n";
	action[6]="刪除多項式中的項式\n";
	action[7]="多項式相乘\n";

	A.ReadData("a.txt");
  B.ReadData("b.txt");

  while(!over){
    for(int i=0;i<ACT_LEN;i++){
      printf("%d. %s",i+1,action[i]);
    }
    printf("其他. 離開此程序\n\n");
    printf("請選擇 : ");
    scanf("%d",&opt);
    printf("\n");
    switch(opt){
      case 1:
        A.ReadData("a.txt");
        B.ReadData("b.txt");
        break;
      case 2:
        printf("多項式1:");
        A.ShowPoly();
        printf("多項式2:");
        B.ShowPoly();
        break;
      case 3:
        printf("多項式相加結果:");
        A.Add(B).ShowPoly();
        break;
      case 4:
        printf("請輸入要操作哪個多項式:");
        scanf("%d",&p);
        if(p!=1 && p!=2){
          printf("輸入錯誤,請重新嘗試\n");
          break;
        }
        printf("請輸入要乘上哪個正整數:");
        scanf("%d",&mult);
        if(p==1){
          A.SingelMult(mult);
        }
        if(p==2){
          B.SingelMult(mult);
        }
        break;
      case 5:
        printf("請輸入要印出哪個多項式的領導係數:");
        scanf("%d",&p);
        if(p!=1 && p!=2){
          printf("輸入錯誤,請重新嘗試\n");
          break;
        }
        printf("\n多項式%d的領導係數為",p);
        if(p==1){
          printf("%d\n",A.Lead_Exp());
        }
        if(p==2){
         printf("%d\n",B.Lead_Exp());
        }
        break;
      case 6:
        printf("請輸入要操作哪個多項式:");
        scanf("%d",&p);
        if(p!=1 && p!=2){
          printf("輸入錯誤,請重新嘗試\n");
          break;
        }
        printf("請輸入要加上的項次係數:");
        scanf("%f",&add_c);
        printf("請輸入要加上的項次指數:");
        scanf("%d",&add_e);
        if(p==1){
          A.Attach(add_c,add_e);
        }
        if(p==2){
          B.Attach(add_c,add_e);
        }
        break;
      case 7:
        printf("請輸入要操作哪個多項式:");
        scanf("%d",&p);
        if(p!=1 && p!=2){
          printf("輸入錯誤,請重新嘗試\n");
          break;
        }
        printf("請輸入要移除的項次的指數:");
        scanf("%d",&re_e);
        if(p==1){
          A.Remove(re_e);
        }
        if(p==2){
          B.Remove(re_e);
        }
        break;
      case 8:
        printf("多項式相乘結果:");
        A.Mult(B).ShowPoly();
        break;
      default:
        over = true;
        printf("離開程序中...");
    }
    printf("------------------\n\n");
  }
	return 0;
}

void mypoly::ReadData(char *filename){
  FILE *fptr;
  fptr = fopen(filename,"r");
  length = 0;
  while(!feof(fptr)){
    fscanf(fptr,"%f %d",&var[length].coe,&var[length].exp);
    length++;
  }
  fclose(fptr);
}

void mypoly::ShowPoly(){
  variable temp;
	for(int i=0;i<length;i++){
    for(int j=i;j<length;j++){
      if(var[i].exp<var[j].exp){
        temp = var[i];
        var[i] = var[j];
        var[j] = temp;
      }
    }

		if(i==length-1){
			printf("%.0fX^%d\n",var[i].coe,var[i].exp);
		}else{
      printf("%.0fX^%d + ",var[i].coe,var[i].exp);
		}
	}
}

mypoly mypoly::Add(mypoly p2){
  mypoly temp1;
  temp1.length = length;
  mypoly temp2=p2;

  for(int i=0;i<temp1.length;i++){
    temp1.var[i] = var[i];
    for(int j=temp2.length-1;j>=0;j--){
      variable temp_v;
      if(temp1.var[i].exp==temp2.var[j].exp){
        temp_v = temp2.var[j];
        temp2.var[j] = temp2.var[temp2.length-1];
        temp2.var[temp2.length-1] = temp_v;
        temp1.var[i].coe += temp2.var[temp2.length-1].coe;
        temp2.length--;
        break;
      }
    }
  }
  for(int k=0;k<temp2.length;k++){
    temp1.var[length+k]=temp2.var[k];
    temp1.length++;
  }
  return temp1;

}

void mypoly::SingelMult(int c){
	for(int i=0;i<length;i++){
		var[i].coe = var[i].coe * c;
	}
}

int mypoly::Lead_Exp(){
  variable temp;
  temp.exp=0;
  for(int i=0;i<length;i++){
    if(temp.exp < var[i].exp){
      temp.exp = var[i].exp;
      temp.coe = var[i].coe;
    }
  }
  return temp.coe;
}

void mypoly::Attach(float c,int e){
  bool same_exp = false;
  for(int i=0;i<length;i++){
    if(var[i].exp==e){
      var[i].coe += c;
      same_exp = true;
      break;
    }
  }
  if(!same_exp){
    var[length].coe = c;
    var[length].exp = e;
    length++;
  }
}

void mypoly::Remove(int e){
 float c=0.0;
  for(int i=0;i<length;i++){
    if(var[i].exp == e){
      c = var[i].coe;
      var[i] = var[length-1];
      var[length-1].coe=0;
      var[length-1].exp=0;
      length--;
      printf("%.0fx^%d已Remove\n",c,e);
      break;
    }
  }
  if(c==0){
    printf("沒有找到這個次方的項次\n");
  }
}

mypoly mypoly::Mult(mypoly p2){
  mypoly total;
  for(int i=0;i<length;i++){
    mypoly temp;
    for(int j=0;j<p2.length;j++){
      temp.var[j].coe = var[i].coe * p2.var[j].coe;
      temp.var[j].exp = var[i].exp + p2.var[j].exp;
      temp.length++;
    }
    total = total.Add(temp);
  }
  return total;
}
