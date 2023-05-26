/*
 * File: Bai3-readNumber.c
 * Author: Nguyen Xuan Cuong
 * Date:20/05/2023
 * Description: Type a number has less than 7 digit and read that number
 */
#include <stdio.h>
/*
 * Function: namnhuan
 * Description: function identify a year is leap year or not
 * Input:
 *    nam: year
 * Output:
 *    return 1 or 0 - 1 is leap year, 0 is not
*/
int namnhuan(int nam)
{
    if((nam%100!=0&&nam%4==0)| nam%400==0)
    {
        return(1);
    }
    else
    {
        return 0;
    }
}
/*
 * Function: tinhSoNamNhuan
 * Description: function identify quantity leap year from year 1 to current
 * Input:
 *    nam: year
 *    thang: month
 *    ngay: day
 *    sonamNhuan: quantity of leap year
 * Output:
 *    none
*/
void tinhSoNamNhuan(int ngay, int thang, int nam, int *sonamNhuan)
{
    if(nam>=4)
{
    if( (namnhuan(nam)&&thang>2) | (namnhuan(nam)&&thang==2&&ngay==29))
    {
        *sonamNhuan= (nam-4)/4+1;
    }
    else 
    {
        *sonamNhuan= (nam-4)/4;
    }
    if( !namnhuan(nam))
    {
        *sonamNhuan= (nam-4)/4+1;
    }
}
else if(nam<4)
{
    *sonamNhuan=0;
}
}
int main()
{
    int ngay, thang, nam;
    int soNgay;
    int tongNgay=0;
    int sonamNhuan;
    printf("Nhap vao ngay, thang, nam: ");
    scanf("%d %d %d",&ngay, &thang, &nam);
    tinhSoNamNhuan(ngay, thang, nam, &sonamNhuan);
    for (int i=1; i<(thang); i++)
    {
    switch (i)
    {
        case 1: soNgay= 31;
        break;
        case 2: soNgay= 28;
        break;
        case 3: soNgay= 31;
        break;
        case 4: soNgay= 30;
        break;
        case 5: soNgay= 31;
        break;
        case 6: soNgay= 30;
        break;
        case 7: soNgay= 31;
        break;
        case 8: soNgay= 31;
        break;
        case 9: soNgay= 30;
        break;
        case 10: soNgay= 31;
        break;
        case 11: soNgay= 30;
        break;
        case 12: soNgay= 31;
        break;
    }
        tongNgay= tongNgay + soNgay;
    }
    tongNgay= tongNgay+ (nam-1)*365+sonamNhuan + (ngay-1);
    printf("tong ngay %d\n",tongNgay);
    printf("snn %d\n",sonamNhuan);
    switch (tongNgay%7)
    {
        case 1: printf("Ngay %d / %d / %d la thu hai", ngay, thang, nam);
        break;
        case 2: printf("Ngay %d / %d / %d la thu ba", ngay, thang, nam);
        break;
        case 3: printf("Ngay %d / %d / %d la thu tu", ngay, thang, nam);
        break;
        case 4: printf("Ngay %d / %d / %d la thu nam", ngay, thang, nam);
        break;
        case 5: printf("Ngay %d / %d / %d la thu sau", ngay, thang, nam);
        break;
        case 6: printf("Ngay %d / %d / %d la thu bay", ngay, thang, nam);
        break;
        case 0: printf("Ngay %d / %d / %d la chu nhat", ngay, thang, nam);
        break;
    }
    return 0;
}