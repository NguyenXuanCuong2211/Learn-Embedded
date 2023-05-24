/*
 * File: bai3-classHinhTron.cpp
 * Author: Nguyen Xuan Cuong
 * Date:20/05/2023
 * Description: Make a circle with radius and methods to calculate perimeter and area of circle
 */
#include<stdio.h>
#include<math.h>
#define pi 3.14
/*
 * Function: class HINHTRON
 * Description: The class represents the properties and methods of the object HINHTRON
 * Input:
 *    None
 * Output:
 *    None
*/
class HINHTRON{
    private:
    int banKinh;
    public:
    HINHTRON(int bk);
    float chuVi();
    float dienTich();
};
/*
 * Function: HINHTRON
 * Description: The constructor of class HINHTRON
 * Input:
 *    bk: Radius of circle
 * Output:
 *    None
*/
HINHTRON::HINHTRON(int bk){
    HINHTRON::banKinh=bk;
}
/*
 * Function: chuVi()
 * Description: A method of class HINHTRON
 * Input:
 *    None
 * Output:
 *    perimeter of circle
*/
float HINHTRON::chuVi()
{
    return 2*pi*HINHTRON::banKinh;
}
/*
 * Function: dienTich()
 * Description: A method of class HINHTRON
 * Input:
 *    None
 * Output:
 *    area of circle
*/
float HINHTRON::dienTich()
{
    return pi*pow(HINHTRON::banKinh,2);
}
int main()
{
    HINHTRON ht1(22);
    printf("chu vi hinh tron ht1 la %0.2f\n",ht1.chuVi());
    printf("dien tich hinh tron ht1 la %0.2f",ht1.dienTich());
    return 0;
}