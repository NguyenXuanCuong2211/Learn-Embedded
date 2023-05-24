/*
 * File: bai9-classCar.cpp
 * Author: Nguyen Xuan Cuong
 * Date:20/05/2023
 * Description: Create a class Car with attributes color, engine type, and mileage, and methods to calculate maintenance cost, 
 * check mileage, and print information about the car.
 */
#include<iostream>
#include<string>
using namespace std;
/*
 * Function: class CAR
 * Description: The class represents the properties and methods of the object CAR
 * Input:
 *    None
 * Output:
 *    None
*/
class CAR
{
    private:
    string color;
    string model;
    int distance;
    public:
    CAR(string cl, string ml, int dis);
    int KM ();
    void thongTinXe();
    int phiBaoTri();
};
/*
 * Function: CAR
 * Description: The constructor of class CAR
 * Input:
 *    cl: color of car
 *    ml: model of car
 *    dis: check mileage
 * Output:
 *    None
*/
CAR::CAR(string cl, string ml, int dis)
{
    CAR::color=cl;
    CAR::model=ml;
    CAR::distance=dis;
}
/*
 * Function: KM()
 * Description: A method of class CAR
 * Input:
 *    None
 * Output:
 *    check mileage
*/
int CAR::KM()
{
    return CAR::distance;
}
/*
 * Function: thongTinXe()
 * Description: A method of class CAR
 * Input:
 *    None
 * Output:
 *    print information of the car
*/
void CAR::thongTinXe()
{
    cout<<"MAU XE: "<<CAR::color<<" - KIEU DONG CO: "<<CAR::model<<" - DA DI DUOC: "<<CAR::distance<<" KM"<<endl;
}
/*
 * Function: phiBaoTri()
 * Description: A method of class CAR
 * Input:
 *    None
 * Output:
 *    maintenance cost of car
*/
int CAR::phiBaoTri()
{
    int phi;
    phi=CAR::distance*100;
    return phi;
}
int main()
{
    CAR xe1("Blue", "IRF305",5000);
    xe1.thongTinXe();
    cout<<"Phi bao tri xe la: "<<xe1.phiBaoTri()<<endl;
    return 0;
}