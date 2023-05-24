/*
 * File: bai10-classBook.cpp
 * Author: Nguyen Xuan Cuong
 * Date:20/05/2023
 * Description: Create a class Book with attributes book title, author, publication year, and quantity,
 *  and methods to print book information, borrow books, and return books.
 */
#include<iostream>
#include<string>
using namespace std;
/*
 * Function: class BOOK
 * Description: The class represents the properties and methods of the object BOOK
 * Input:
 *    None
 * Output:
 *    None
*/
class BOOK 
{
    private:
    string tenSach;
    string tacGia;
    int namXuatBan;
    int soLuong;
    public:
    BOOK(string name, string author, int nXB, int sL);
    void thongTinSach();
    void muonSach(int n);
    void traSach(int n);
};
/*
 * Function: BOOK
 * Description: The constructor of class BOOK
 * Input:
 *    name: name of book
 *    author: author of book
 *    nXB: publication year of book
 *    sL: quantity of book 
 * Output:
 *    None
*/
BOOK::BOOK (string name, string author, int nXB, int sL){
    BOOK::tenSach= name;
    BOOK::tacGia=author;
    BOOK::namXuatBan=nXB;
    BOOK::soLuong=sL;
}
/*
 * Function: thongTinSach()
 * Description: The method of class BOOK
 * Input:
 *    None
 * Output:
 *    print information of book
*/
void BOOK::thongTinSach()
{
    cout<< "Sach: "<<BOOK::tenSach<<" - Tac gia: "<<BOOK::tacGia<<" - Xuat Ban Nam: "<<BOOK::namXuatBan<<" - So Luong: "<<BOOK::soLuong<<endl;
}
/*
 * Function: muonSach()
 * Description: The method of class BOOK
 * Input:
 *    quantity of borrow books
 * Output:
 *    None
*/
void BOOK::muonSach(int n)
{
    cout<< "Da muon "<<n<<" quyen sach "<<BOOK::tenSach<<endl;
    BOOK::soLuong=BOOK::soLuong-n;
}
/*
 * Function: traSach()
 * Description: The method of class BOOK
 * Input:
 *    quantity of return books
 * Output:
 *    None
*/
void BOOK::traSach(int n)
{
    cout<< "Da tra "<<n<<" quyen sach "<<BOOK::tenSach<<endl;
    BOOK::soLuong=BOOK::soLuong+n;
}

int main()
{
    BOOK sach1("Truyen Kieu","Nguyen Du",1800,500);
    sach1.thongTinSach();
    sach1.muonSach(50);
    sach1.thongTinSach();
    return 0;
}