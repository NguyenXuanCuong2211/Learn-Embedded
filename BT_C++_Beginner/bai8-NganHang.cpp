/*
 * File: bai8-NganHang.cpp
 * Author: Nguyen Xuan Cuong
 * Date:20/05/2023
 * Description: Create a class BankAccount with properties account number,
 *  account name, and balance, and methods to withdraw, deposit money, and check the account balance
 */
#include<stdio.h>
#include<string>
using namespace std;
/*
 * Function: class NGANHANG
 * Description: The class represents the properties and methods of the object NGANHANG
 * Input:
 *    None
 * Output:
 *    None
*/
class NGANHANG{
    private:
    string soTaiKhoan;
    string tenTaiKhoan;
    int soDu;
    public:
    NGANHANG(string stk, string ttk, int sd);
    void rutTien(int tien);
    void napTien(int tien);
    int kiemTraSoDu();
};
/*
 * Function: NGANHANG
 * Description: The constructor of class NGANHANG
 * Input:
 *    stk: account number
 *    ttk: account name
 *    sd: balance
 * Output:
 *    None
*/
NGANHANG::NGANHANG(string stk, string ttk, int sd)
{
    NGANHANG::soTaiKhoan=stk;
    NGANHANG::tenTaiKhoan=ttk;
    NGANHANG::soDu=sd;
}
/*
 * Function: rutTien()
 * Description: The constructor of class NGANHANG
 * Input:
 *    tien: money need to withdraw
 * Output:
 *    None
*/
void NGANHANG::rutTien(int tien){
    NGANHANG::soDu=NGANHANG::soDu -tien;
}
/*
 * Function: napTien()
 * Description: The constructor of class NGANHANG
 * Input:
 *    tien: money need to deposit
 * Output:
 *    None
*/
void NGANHANG::napTien(int tien){
    NGANHANG::soDu=NGANHANG::soDu+tien;
}
/*
 * Function: kiemTraSoDu()
 * Description: The constructor of class NGANHANG
 * Input:
 *    None
 * Output:
 *    Money of account balance
*/  
int NGANHANG::kiemTraSoDu(){
    return (NGANHANG::soDu);
}
int main()
{
    NGANHANG person1("12345", "Nguyen A", 20000);
    person1.napTien(1000);
    printf("Da nap 1000\n");
    printf("So du la: %d\n",person1.kiemTraSoDu());
    person1.rutTien(8000);
    printf("Da rut 8000\n");
    printf("So du la: %d\n",person1.kiemTraSoDu());
    return 0;
}