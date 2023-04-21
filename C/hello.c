#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random (int min, int max)
{  
    int ran = min + rand()%(max+1-min);
    return ran;
}
int main(int argc, char const *argv[])
{
    int num, max, min;
    int n=1;
    printf("Nhap so phan tu co trong mang:");
    scanf("%d",&num);
    while 
    (num<=0)
    {
        printf("Nhap lai so phan tu co trong mang:");
        scanf("%d",&num);
    }
    printf("Nhap gia tri phan tu random lon nhat:");
    scanf("%d",&max);
    printf("Nhap gia tri phan tu random nho nhat:");
    scanf("%d",&min);
    while(max<min)
    {
       printf("Nhap lai gia tri phan tu random lon nhat:");
       scanf("%d",&max);
       printf("Nhap lai gia tri phan tu random nho nhat:");
       scanf("%d",&min); 
    }
    int *arr = (int*)malloc(num *sizeof(int));
    srand((int)time(NULL));
    printf("Mang random la:\n");
    for (int i=0;i<num;i++)
    {
        arr[i]=random(min,max);
        printf("%d ",arr[i]);
    }
    printf("\nMang sau khi sap xep tang dan la:\n");
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
        int min;
        if(arr[i]>arr[j])
        {
            min =arr[j];
            arr[j]=arr[i];
            arr[i]=min;
        }
        }
    }
    for(int i=0;i<num;i++)
    {
        printf("%d ",arr[i]);
    }
    for(int i=0;i<num;i++)
    {
        if(n>1)
        {
            n=n-1;
            continue;
        }
        for(int j=i+1;j<num;j++)
        {
            
            if(arr[i]==arr[j])
            {
                n=n+1;
                if(j==num-1)
                {
                    printf("\nSo %d xuat hien %d lan",arr[num-1],n);
                }
            }
            else
            {
                printf("\nSo %d xuat hien %d lan",arr[i],n);
                break;
            }
        } 
        if(i==(num-1)&&arr[num-1]!=arr[num-2])
        {
           printf("\nSo %d xuat hien 1 lan",arr[num-1]); 
        }  
    }
    return 0;
}