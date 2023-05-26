/*
 * File: Bai3-readNumber.c
 * Author: Nguyen Xuan Cuong
 * Date:20/05/2023
 * Description: Type a number has less than 7 digit and read that number
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int freq=1;
/*
 * Function: random
 * Description: make a random elements between min value and max value
 * Input:
 *    min: min value
 *    max: max value
 * Output:
 *    random value
*/
int random (int min, int max)
{  
    int ran = min + rand()%(max+1-min);
    return ran;
}
/*
 * Function: sortArray
 * Description: sort elements in array follow ascending value
 * Input:
 *    arr: array
 *    num: number elements of array
 * Output:
 *    None
*/
void sortArray(int arr[], int num)
{
    int min;
    printf("\nMang sau khi sap xep tang dan la:\n");
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
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
}
/*
 * Function: freqOfElement
 * Description: determite frequency of number in the array
 * Input:
 *    arr: array
 *    num: number elements of array
 * Output:
 *    None
*/
void freqOfElement(int arr[],int num)
{
        for(int i=0;i<num;i++)
    {
        if(freq>1)
        {
            freq=freq-1;
            continue;
        }
        for(int j=i+1;j<num;j++)
        {
            
            if(arr[i]==arr[j])
            {
                freq=freq+1;
                if(j==num-1)
                {
                    printf("\nSo %d xuat hien %d lan",arr[num-1],freq);
                }
            }
            else
            {
                printf("\nSo %d xuat hien %d lan",arr[i],freq);
                break;
            }
        } 
        if((i==(num-1))&&(arr[num-1]!=arr[num-2]))
        {
           printf("\nSo %d xuat hien 1 lan",arr[num-1]); 
        }  
    }
}
/*
 * Function: typeValue
 * Description: requite user type value of number, max value, min value to make a array
 * Input:
 *    num: number of array
 *    max: the maximum value of element in array
 *    min: the minimum value of element in array
 * Output:
 *    None
*/
void typeValue (int *num, int *max, int *min)
{
    printf("Nhap so phan tu co trong mang:");
    scanf("%d",num);
    while 
    (*num<=0)
    {
        printf("Nhap lai so phan tu co trong mang:");
        scanf("%d",num);
    }
    printf("Nhap gia tri phan tu random lon nhat:");
    scanf("%d",max);
    printf("Nhap gia tri phan tu random nho nhat:");
    scanf("%d",min);
    while(*max<*min)
    {
       printf("Nhap lai gia tri phan tu random lon nhat:");
       scanf("%d",max);
       printf("Nhap lai gia tri phan tu random nho nhat:");
       scanf("%d",min); 
    }
}
int main(int argc, char const *argv[])
{
    int num, max, min;
    typeValue(&num,&max,&min);
    // make a dynamic array by malloc
    int *arr = (int*)malloc(num *sizeof(int));
    srand((int)time(NULL));
    printf("Mang random la:\n");
    for (int i=0;i<num;i++)
    {
        arr[i]=random(min,max);
        printf("%d ",arr[i]);
    }
    sortArray(arr,num);
    freqOfElement(arr, num);
    free(arr);
    return 0;
}