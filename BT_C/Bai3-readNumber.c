/*
 * File: Bai3-readNumber.c
 * Author: Nguyen Xuan Cuong
 * Date:20/05/2023
 * Description: Type a number has less than 7 digit and read that number
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * Function: Mang
 * Description: Fuction of Mang is separate digits of number and save in a array with size is 7. 
 * first element of array is units place, last element of array is millions place
 * Input:
 *    x: number that user type into
 *    mangso[]: array to save digit of number x
 * Output:
 *    None
*/
void Mang(int x, int mangso[])
{
    int buf = x;
    for (int i = 0;i<7;i++)
    {
        mangso[i]=buf%10;
        buf=buf/10;
    }
}
int main()
{
    int x;
    int mangSo[7];
    int flag = 0;
    char *docso[7] = {"trieu", "tram", "muoi", "nghin", "tram", "muoi"," "};
    char *chu[10] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
    printf("Nhap vao so co nhieu nhat 7 chu so: ");
    scanf("%d", &x);
    Mang(x, mangSo);
    for (int i = 6; i >= 0; i--)
    {
        /*bo qua khong doc nhung thanh phan cua so it hon 7 chu so
        * Neu vi tri hang trieu bang 0, se bo qua va khong in ra phan trieu
        * Tuong tu voi nhung thanh phan hang nghin, hang tram tiep theo
        */
        if (mangSo[i] == 0 && flag == 0)
        {
            continue;
        }
        flag = 1;
        // Truong hop hang chuc nghin va hang chuc bang 0
        if ((mangSo[4] == 1 && i == 4) | (mangSo[1] == 1 && i == 1))
        {
            printf("muoi ");
            continue;
        }
        // Truong hop hang nghin bang 0
        if (mangSo[3] == 0 && i == 3)
        {
            printf("%s ", docso[6 - i]);
            continue;
        }
        //truong hop hang don vi bang 0
        if (mangSo[0] == 0 && i == 0)
        {
            continue;
        }
        //truong hop hang chuc nghin va hang chuc bang 0
        if ((mangSo[1] == 0 && i == 1) | (mangSo[4] == 0 && i == 4))
        {
            printf("linh ");
            continue;
        }
        //in ra cach doc so nhap vao
        printf("%s %s ", *(chu+mangSo[i]), *(docso +6 - i));  
    }
    return 0;
}