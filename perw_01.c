#include<stdio.h>
 void reverse(char * input){
     int i,c=0;
     for(i=0;*(input+i)!='\0';i++){
         
         c++;
     } 
     printf("\nREVERSEDWORLD = ");
     for(i=c-1;i>=0;i--){
         printf("%c",*(input+i));
     }
    
 }
int main(){
    
     char world[30];
     char *input= world;
     int count=0;
      printf("ENTER YOUR WORLD : ");
      scanf("%s",&world);
      reverse(world);



    return 0;
}