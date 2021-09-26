#include<stdio.h>
#include<conio.h>
int main(){
    for(int i=0;i<10;i++){
    char str[50];
    printf("Enter your order: ");
    scanf("%s",&str);
    FILE*f=fopen("data.txt","w");
    fprintf(f,"Order: ");
    FILE*s=fopen("data.txt","a");
    fprintf(s,"\n%s ",str);}
    
    return 0;}
    
    
    
    
    
    
    
