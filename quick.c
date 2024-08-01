#include <stdio.h>
#include <time.h>
void Exch(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}
void Quicksort(int a[],int low,int high){
    int i,j,key,k;
    if(low>=high){
        return;
    }
    key=low;
    i=low+1;
    j=high;
    while (i<=j){
        while(a[i]<=a[key]){
            i=i+1;
        }
        while(a[j]>a[key])
        j=j-1;
    if(i<j)
    Exch(&a[i],&a[j]);
    }
    Exch(&a[j],&a[key]);
    Quicksort(a,low,j-1);
    Quicksort(a,j+1,high);
      

}
void main(){
    int n, a[1000],k;
    clock_t st,et;double ts;
    printf("\n Enter how many Numbers:");
    scanf("%d",&n);
    printf("\n The Random Number are:\n");
    for(k=1;k<=n;k++){
        //a[k]= rand();
        printf("%d\t",a[k]);
    }
    st=clock();
    Quicksort(a,1,n);
    et=clock();
    ts=(double)(et-st)/CLOCKS_PER_SEC;
    printf("\nSorted Number are:\n");
    for(k=1;k<=n;k++)
    printf("%d\t",a[k]);
    printf("\n The time taken is %e",ts);


}

