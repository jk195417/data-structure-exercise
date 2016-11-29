//
//  main.cpp
//  homework-c
//
//  Created by Xin on 2016/11/26.
//  Copyright © 2016年 hongxin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int weights(const char c){
    int n;
    switch (c) {
        case '(':
            n = 0;
            break;
        case '+':
        case '-':
            n = 1;
            break;
        case '*':
        case '/':
            n = 2;
            break;
        default:
            n = -1;
            break;
    }
    return n;
}
typedef enum {op, val, unknown} mytype;
struct data{
    mytype type = unknown;
    int value;
    char oper;
};

struct stack{
    data a[MAX] ;
    int top=-1 ;
    
    bool IsEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
    
    bool IsFull(){
        if(top == MAX - 1){
            return true;
        }else{
            return false;
        }
    }
    
    void Push(data d){
        if(IsFull()){
            printf("The STACK is full");
        }else{
            top++;
            a[top] = d;
        }
    }

    data Pop(){
        data d;
        data n;
        if(IsEmpty()){
            printf("The STACK is empty");
        }else{
            d = a[top];
            a[top] = n;
            top--;
        }
        return d;
    }
    
    data Top(){
        data d;
        if(IsEmpty()){
            printf("The STACK is empty");
        }else{
            d = a[top];
        }
        return d;
    }
    
    void Show(){
        for(int i=0;i<MAX;i++){
            if(a[i].type==op){
                printf("%c\n",a[i].oper);
            }else if (a[i].type==val){
                printf("%d\n",a[i].value);
            }
            else{
                break;
            }
        }
        
    }
};


int main(){
    FILE *file;
    char buf[5];
    data temp;
    stack answer,compute;
    const char *path = "/Users/Xin/Code/Data-Structure-Exercise/1117/homework.txt";
    file = fopen(path, "r");
    if(!file){
        printf("open file failed\npath : %s\n",path);
        exit(1);
    }
    
    printf("file : %s\nopen success!\n",path);
    while (!feof(file)) {
        fscanf(file, "%s",&buf);
        printf("%s\n",&buf);
        switch (buf[0]) {
            case '+':
            case '-':
            case '*':
            case '/':
                temp.type = op;
                temp.oper = buf[0];
                if (weights(compute.Top().oper) < weights(temp.oper)) {
                    compute.Push(temp);
                }else if (weights(compute.Top().oper) >= weights(temp.oper)){
                    while (weights(compute.Top().oper) >= weights(temp.oper)) {
                        answer.Push(compute.Pop());
                    }
                    compute.Push(temp);
                }
                break;
            case '(':
                temp.type = op;
                temp.oper = buf[0];
                compute.Push(temp);
                break;
            case ')':
                while (answer.Top().oper!='(') {
                    answer.Push(compute.Pop());
                }
                answer.Pop();
                break;
            default:
                temp.type = val;
                temp.value = atoi(buf);
                answer.Push(temp);
                break;
        }
    }
    while (!compute.IsEmpty()) {
        answer.Push(compute.Pop());
    }
    
    
    printf("answer :\n");
    answer.Show();
    
    for(int i=0;i<MAX;i++){
        if(answer.a[i].type==op){
            double num1,num2;
            num2 = compute.Pop().value;
            num1 = compute.Pop().value;
            switch (answer.a[i].oper) {
                case '+':
                    temp.type=val;
                    temp.value = num1+num2;
                    compute.Push(temp);
                    break;
                case '-':
                    temp.type=val;
                    temp.value = num1-num2;
                    compute.Push(temp);
                    break;
                case '*':
                    temp.type=val;
                    temp.value = num1*num2;
                    compute.Push(temp);
                    break;
                case '/':
                    temp.type=val;
                    temp.value = num1/num2;
                    compute.Push(temp);
                    break;
            }
        }else if (answer.a[i].type==val){
            compute.Push(answer.a[i]);
        }
        else{
            break;
        }
    }
    
    printf("final answer :\n");
    compute.Show();
}
