//
//  main.cpp
//  資料結構
//  homework
//
//  Created by Xin on 2016/10/30.
//  Copyright © 2016年 hongxin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX 40

struct LongInt {
    //value
    int length;
    int number[MAX]; // 假設number[0]為個位 number[1]為十位 以此類推
    
    //init
    LongInt(){
        length = 0;
    }
    LongInt(LongInt const &p){
        length = p.length;
        for(int i=0; i<MAX; i++){
            number[i] = p.number[i];
        }
    }
    
    //func
    void show(){
        for(int i=MAX-1; i>=length; i--){
            printf(" ");
        }
        for(int i=length-1; i>=0; i--){
            number[i]>=0 ? printf("%d",number[i]) : printf("-");
        }
        printf("\n");
    }
    
    void random(){
        length = rand() % 19 + 1; // 最多只會產生19位數
        for(int i=0; i<length; i++){
            // 最大項不為0
            i==length-1 ? number[i]=rand()%9+1 : number[i]=rand()%10;
        }
        for(int i=length; i<MAX; i++){
            number[i] = 0;
        }
    }
    
    void clear(){
        length = 1;
        for (int i=0;i<MAX;i++){
            number[i] = 0;
        }
    }
    
    LongInt add(LongInt p){
        LongInt temp(*this);
        length > p.length ? temp.length = length : temp.length = p.length;
        for(int i=0; i<temp.length; i++){
            temp.number[i] += p.number[i];
            if(i==temp.length-1 && temp.number[i]>9){
                temp.length++;
            }
            temp.number[i+1] += (int)(temp.number[i] / 10);
            temp.number[i] = temp.number[i] % 10;
        }
        return temp;
    }
    
    LongInt sub(LongInt p){
        LongInt  a,b;
        LongInt self(*this);
        bool negative = false;
        
        if(self.biggerThen(p)){
            a=self;
            b=p;
        }else{
            a=p;
            b=self;
            negative=true;
        }
        for(int i=0; i<a.length; i++){
            a.number[i] -= b.number[i];
            if(a.number[i]<0){
                a.number[i+1]--;
                a.number[i]+=10;
            }
        }
        a.checkLength();
        if(negative){
            a.number[a.length] = -1;
            a.length++;
        }
        return a;
    }
    
    LongInt multi(LongInt p){
        LongInt temp,zero;
        zero.clear();
        temp.length = length + p.length;
        for(int i=0; i<p.length; i++){
            for(int j=0;  j<length; j++){
                temp.number[j+i] += number[j] * p.number[i];
            }
        }
        
        temp = temp.add(zero);
        temp.checkLength();
        return temp;
    }
    
    bool biggerThen(LongInt p){
        if(length>p.length){
            return true;
        }
        if(length<p.length){
            return false;
        }
        if(length==p.length){
            for(int i=length-1;i>=0;i--){
                if(number[i]>p.number[i]){
                    return true;
                }else if (number[i]<p.number[i]){
                    return false;
                }
            }
        }
        return true;
    }
    
    void checkLength(){
        for(int i=MAX-1; i>=0; i--){
            if(number[i]!=0 ){
                length = i+1;
                break;
            }
        }
    }
};

int main() {
    LongInt a,b;
    // 亂數種子
    srand((unsigned)time(NULL));
    
    a.random();
    b.random();
    printf("a = \n");
    a.show();
    printf("b = \n");
    b.show();
    printf("a + b = \n");
    a.add(b).show();
    printf("a - b = \n");
    a.sub(b).show();
    printf("a + b = \n");
    a.multi(b).show();
    return 0;
}
