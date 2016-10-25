//
//  main.cpp
//  homework
//
//  Created by Xin on 2016/10/24.
//  Copyright © 2016年 hongxin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 20


struct MyStr {
    // 結構資料
    char arr[MAX];
    // 建構子
    MyStr(){}
    
    MyStr(const char *str){
        for (int i=0; i<MAX; i++) {
            arr[i]=str[i];
            if (str[i]=='\0') {
                break;
            }
        }
    }
    // 結構函數
    void Show(){
        for (int i=0; i<MAX; i++) {
            if (arr[i]=='\0') {
                printf("\n");
                break;
            }
            printf("%c",arr[i]);
        }
    }
    
    int Length(){
        int length=0;
        for (int i=0; i<MAX; i++) {
            if (arr[i]=='\0') {
                break;
            }
            length++;
        }
        return length;
    }
    
    int IndexOf(const char *str){
        int strLength=0;
        
        for (int i=0; i<MAX; i++) {
            if (str[i]=='\0') {
                break;
            }
            strLength++;
        }
        
        for (int i=0; i<MAX; i++) {
            int check=0;
            for(int j=0;j<strLength;j++){
                if(arr[i+j]==str[j]){
                    check++;
                }
            }
            if(check==strLength){
                return i;
            }
        }
        return -1;
    }
    
    MyStr SubStr(int idx,int len){
        MyStr newStr;
        int j=0;
        for(int i=0; i<len; i++){
            newStr.arr[j]=arr[i+idx];
            j++;
        }
        return newStr;
    }
    
    MyStr Assign(const char *str){
        MyStr newStr;
        for (int i=0; i<MAX; i++) {
            newStr.arr[i]=str[i];
            if (str[i]=='\0') {
                break;
            }
        }
        return newStr;
    }
    
    MyStr InsertOf(const char *str,int idx){
        MyStr newStr;
        for (int i=0; i<idx; i++) {
            newStr.arr[i]=arr[i];
        }
        int strLen=0;
        for(int i=idx; i<MAX; i++){
            newStr.arr[i]=str[i-idx];
            if (str[i-idx]=='\0') {
                break;
            }
            strLen++;
        }
        for(int i=idx+strLen; i<MAX ;i++){
            newStr.arr[i]=arr[i-strLen];
            if (arr[i-strLen]=='\0') {
                break;
            }
        }
        return newStr;
    }
    
    
    
};

int main(){
    
    MyStr str1("hello");
    str1.Show();
    printf("%d\n",str1.Length());
    printf("%d\n",str1.IndexOf("hello"));
    str1.SubStr(0, 5).Show();
    str1.Assign("ABCDEFGHIJK").Show();
    str1.InsertOf("123",5).Show();
    
    
    
    return 0;
}
