/*
 * File: bai6-classPhanSo.cpp
 * Author: Nguyen Xuan Cuong
 * Date:20/05/2023
 * Description: Create a class Fraction with properties numerator and denominator, and methods to perform basic arithmetic operations 
 * such as addition, subtraction, multiplication, and division
 */
#include <iostream>
#include <stdint.h>
using namespace std;
/*
 * Function: class PHANSO
 * Description: The class represents the properties and methods of the object PHANSO
 * Input:
 *    None
 * Output:
 *    None
*/
class PHANSO
{
    private:
    uint8_t tuSo;
    uint8_t mauSo;
    public:
    PHANSO (uint8_t ts, uint8_t ms);
    float getPS();
};
/*
 * Function: PHANSO
 * Description: The constructor of class PHANSO
 * Input:
 *    ts: numerator
 *    ms: denominator
 * Output:
 *    None
*/
PHANSO::PHANSO (uint8_t ts=0, uint8_t ms=1)
{
    PHANSO::tuSo=ts;
    PHANSO::mauSo=ms;
}
/*
 * Function: getPS()
 * Description: A method of class PHANSO
 * Input:
 *    None
 * Output:
 *    value of fraction
*/
float PHANSO::getPS()
{
    return float(PHANSO::tuSo)/PHANSO::mauSo;
}
/*
 * Function: class PHEPTOAN
 * Description: The class represents the properties and methods of perform basic arithmetic operations 
 * such as addition, subtraction, multiplication, and division
 * Input:
 *    None
 * Output:
 *    None
*/
class PHEPTOAN
{
    private:
    PHANSO phanSo1, phanSo2;
    public:
    PHEPTOAN(PHANSO ps1, PHANSO ps2);
    float phepCong();
    float phepTru();
    float phepNhan();
    float phepChia();
};
/*
 * Function: PHEPTOAN
 * Description: The constructor of class PHEPTOAN
 * Input:
 *    ps1: fraction 1
 *    ps2: fraction 2
 * Output:
 *    None
*/
PHEPTOAN::PHEPTOAN(PHANSO ps1, PHANSO ps2)
{
    PHEPTOAN::phanSo1= ps1;
    PHEPTOAN::phanSo2=ps2; 
}
/*
 * Function: phepCong()
 * Description: The constructor of class PHEPTOAN
 * Input:
 *    None
 * Output:
 *    total of two fractions
*/
float PHEPTOAN::phepCong()
{
    return (phanSo1.getPS()+phanSo2.getPS());
}
/*
 * Function: phepTru()
 * Description: The constructor of class PHEPTOAN
 * Input:
 *    None
 * Output:
 *    subtraction of two fractions
*/
float PHEPTOAN::phepTru(){
    return (phanSo1.getPS()-phanSo2.getPS());
}
/*
 * Function: phepNhan()
 * Description: The constructor of class PHEPTOAN
 * Input:
 *    None
 * Output:
 *    multiplication of two fractions
*/
float PHEPTOAN::phepNhan(){
    return (phanSo1.getPS()*phanSo2.getPS());
}
/*
 * Function: phepChia()
 * Description: The constructor of class PHEPTOAN
 * Input:
 *    None
 * Output:
 *    division of two fractions
*/
float PHEPTOAN::phepChia(){
    return (phanSo1.getPS()/phanSo2.getPS());
}
int main()
{
    PHANSO ps1(3,5), ps2(5,3), ps3(11,22);
    PHEPTOAN phepToan1(ps1,ps3);
    cout<<"PHEP CONG: " << phepToan1.phepCong()<<endl;
    cout<<"PHEP TRU: " << phepToan1.phepTru()<<endl;
    cout<<"PHEP NHAN: " << phepToan1.phepNhan()<<endl;
    cout<<"PHEP CHIA: " << phepToan1.phepChia()<<endl; 
    return 0;
}