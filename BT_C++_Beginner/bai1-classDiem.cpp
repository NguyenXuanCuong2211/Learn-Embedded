/*
 * File: bai1-classDiem.cpp
 * Author: Nguyen Xuan Cuong
 * Date:20/05/2023
 * Description: Make a point class in coordinate system and write methods to calculate distance of two point, 
 * calculate area of the triangle formed by three point
 */
#include<stdio.h>
#include<math.h>
/*
 * Function: class DIEM
 * Description: The class represents the properties and methods of the object DIEM
 * Input:
 *    None
 * Output:
 *    None
*/
class DIEM
{
private:
    int X;
    int Y;
public:
    DIEM(int x=0, int y=0);
    int getX();
    int getY();
};
/*
 * Function: DIEM
 * Description: The constructor of class DIEM
 * Input:
 *    x: hoanh do
 *    y: tung do
 * Output:
 *    None
*/
DIEM::DIEM(int x, int y)
{
    DIEM::X=x;
    DIEM::Y=y;
}
/*
* Function: getX()
 * Description: A method of class DIEM
 * Input:
 *    None 
 * Output:
 *    hoanh do cua diem
*/
int DIEM::getX()
{
    return DIEM::X;
}
/*
* Function: getY()
 * Description: A method of class DIEM
 * Input:
 *    None 
 * Output:
 *    tung do cua diem
*/
int DIEM::getY()
{
    return DIEM::Y;
}
/*
 * Function: class KHOANGCACH
 * Description: The class represents the properties and methods of the object calculate distance of two points
 * Input:
 *    None
 * Output:
 *    None
*/
class KHOANGCACH{
    private:
    DIEM A;
    DIEM B;
    public:
    KHOANGCACH(DIEM a, DIEM b);
    float khoangCach();
};
/*
 * Function: DIEM
 * Description: The constructor of class KHOANGCACH
 * Input:
 *    a: a point of class DIEM
 *    b: a point of class DIEM
 * Output:
 *    None
*/
KHOANGCACH::KHOANGCACH(DIEM a, DIEM b){
    KHOANGCACH::A=a;
    KHOANGCACH::B=b;
}
/*
* Function: khoangCach()
 * Description: A method of class KHOANGCACH
 * Input:
 *    None 
 * Output:
 *    distance of two points
*/
float KHOANGCACH::khoangCach()
{
    float kc;
    kc= sqrt(pow(A.getX()-B.getX(),2)+pow(A.getY()-B.getY(),2));
    return kc;
}
/*
 * Function: class DIENTICH
 * Description: The class represents the properties and methods of the object DIENTICH - calculate the area of triangle formed by three points
 * Input:
 *    None
 * Output:
 *    None
*/
class DIENTICH{
    private:
    DIEM A,B,C;
    public:
    DIENTICH(DIEM a, DIEM b, DIEM c);
    float dienTich();
};
/*
 * Function: DIENTICH
 * Description: The constructor of class DIENTICH
 * Input:
 *    a: point a
 *    b: point b
 *    c: point c
 * Output:
 *    None
*/
DIENTICH::DIENTICH(DIEM a, DIEM b, DIEM c)
{
    DIENTICH::A=a;
    DIENTICH::B=b;
    DIENTICH::C=c;
}
/*
* Function: dienTich()
 * Description: A method of class DIENTICH
 * Input:
 *    None 
 * Output:
 *    the area of triangle formed by three points
*/
float DIENTICH::dienTich()
{
    float dt;
    dt= 0.5* abs((A.getX()-B.getX())*(C.getY()-A.getY())-(C.getX()-A.getX())*(B.getY()-A.getY()));
    return dt;
}

int main()
{
    DIEM A(3,4), B(5,6), C(8,4);
    KHOANGCACH distance(A,B);
    DIENTICH tamGiac(A,B,C);
    printf("Khoang cach hai diem A va B la: %0.2f\n", distance.khoangCach());
    printf("Dien tich tam giac ABC la: %0.2f",tamGiac.dienTich());
}