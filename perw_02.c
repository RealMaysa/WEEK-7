#include<stdio.h>
#include<conio.h>
int main(){

int arr[10];
double sum;
double avgCM;
for(int i=0;i<10;++i){
     printf("Enter your height: ");
     scanf("%d",&arr[i]);
     sum+=arr[i];
    
printf("Height: %d\n",arr[i]);

}
avgCM=sum/10.0;
printf("Average height: %.2f", avgCM);
    FILE*f=fopen("data.txt","w");
    fprintf(f,"Average height: %.2f",avgCM);
    return 0;

}