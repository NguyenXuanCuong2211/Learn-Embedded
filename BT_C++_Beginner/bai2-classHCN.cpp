/*
 * File: bai2-classHCN.cpp
 * Author: Nguyen Xuan Cuong
 * Date:20/05/2023
 * Description: Make a rectangle with properties length, width and methods to calculate perimeter, area, diagonal
 * and check if it is a square or not
 */
#include <stdio.h>
#include <stdint.h>
#include <math.h>
/*
 * Function: class HINHCHUNHAT
 * Description: The class represents the properties and methods of the object HINHCHUNHAT
 * Input:
 *    None
 * Output:
 *    None
*/
class HINHCHUNHAT {
    private:
    int chieuDai;
    int chieuRong;
    public:
    HINHCHUNHAT(int cd, int cr);
    int chuVi();
    int dienTich();
    float duongCheo();
    bool kiemTra();
};
/*
 * Function: HINHCHUNHAT
 * Description: The constructor of class HINHCHUNHAT
 * Input:
 *    cd: length of rectangle
 *    cr: width of rectangle 
 * Output:
 *    None
*/
    HINHCHUNHAT::HINHCHUNHAT(int cd, int cr)
    {
        HINHCHUNHAT::chieuDai= cd;
        HINHCHUNHAT::chieuRong=cr;
    }
/*
* Function: chuVi()
 * Description: A method of class HINHCHUNHAT
 * Input:
 *    None 
 * Output:
 *    the perimeter of rectangle
*/
    int HINHCHUNHAT::chuVi(){
        return (HINHCHUNHAT::chieuRong+ HINHCHUNHAT::chieuDai)*2;
    }
/*
* Function: dienTich()
 * Description: A method of class HINHCHUNHAT
 * Input:
 *    None 
 * Output:
 *    the area of rectangle
*/
    int HINHCHUNHAT::dienTich(){
        return HINHCHUNHAT::chieuDai* HINHCHUNHAT::chieuRong;
    }
/*
* Function: dienTich()
 * Description: A method of class HINHCHUNHAT
 * Input:
 *    None 
 * Output:
 *    the diagonal of rectangle
*/
    float HINHCHUNHAT::duongCheo(){
        return sqrt(pow(HINHCHUNHAT::chieuDai,2)+pow(HINHCHUNHAT::chieuRong,2));
    }
/*
* Function: kiemTra()
 * Description: A method of class HINHCHUNHAT
 * Input:
 *    None 
 * Output:
 *    check if it is a square or not
*/
    bool HINHCHUNHAT::kiemTra(){
        if(HINHCHUNHAT::chieuDai==HINHCHUNHAT::chieuRong)
        {
            return true;
        }
        else return false;
    }
int main ()
{
    HINHCHUNHAT hcn1(5,3), hcn2(20,10);
    printf("Chu vi hcn1 la %d\n",hcn1.chuVi());
    printf("Dien tich hcn1 la %d\n",hcn1.dienTich());
    printf("Do dai duong cheo hcn1 la %0.2f\n",hcn1.duongCheo());
    printf("hcn1 la hinh vuong la %d\n",hcn1.kiemTra());
    printf("Chu vi hcn2 la %d\n",hcn2.chuVi());
    return 0;
}