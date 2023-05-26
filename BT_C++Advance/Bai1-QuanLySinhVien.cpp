/*
 * File: Bai1-QuanLySinhVien.cpp
 * Author: Nguyen Xuan Cuong
 * Date:24/05/2023
 * Description: Make a class SinhVien with properties: ID, name, sex, age, math scores, physical scores, chemistry scores,
 *  average scores, academic achievement. Make a class Menu with functions: 1.Them sinh vien, 2. Cap nhat thong tin sinh vien boi ID,
 * 3. Xoa sinh vien boi ID", 4. Tim kiem sinh vien theo ten", 5. Sap xep sinh vien theo diem trung binh GPA"<<endl
 * 6. Sap xep sinh vien theo ten", 7. Hien thi danh sach sinh vien".
 */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>   
#include<stdint.h> 
#include<iomanip>
#include <algorithm>
using namespace std;
typedef enum{
    NU,
    NAM,
    null
}TypeGioiTinh;
typedef enum{
    GIOI,
    KHA,
    TRUNG_BINH,
    YEU,
    ERROR
}TypeHocLuc;

/*
 * Function: class SinhVien
 * Description: The class represents the properties ID, name, sex, age, math scores, physical scores, chemistry scores,
 *  average scores, academic achievement and methods of the object SinhVien
 * Input:
 *    None
 * Output:
 *    None
*/
class SinhVien
{
    private:
    uint8_t ID;
    string name;
    TypeGioiTinh gioiTinh;
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB;
    TypeHocLuc hocLuc;
    public:
    SinhVien(string ten, TypeGioiTinh gioiTinh, int tuoi, float diemToan, float diemLy, float diemHoa);
    uint8_t getID();
    void setName(string ten);
    string getName();
    void setGioiTinh(TypeGioiTinh gioitinh);
    TypeGioiTinh getGioiTinh();
    void setTuoi(int tuoi);
    int getTuoi();
    void setDiemToan(float diemtoan);
    float getDiemToan();
    void setDiemLy(float diemly);
    float getDiemLy();
    void setDiemHoa(float diemhoa);
    float getDiemHoa();
    float getDiemTrungBinh();
    TypeHocLuc getHocLuc();
};
/*
 * Function: SinhVien
 * Description: A method of class SinhVien
 * Input:
 *    ten: name of student
 *    gioitinh: sex of student
 *    tuoi: age of student
 *    diemtoan: math scores of student
 *    diemly: phisical scores of student
 *    diemhoa: chemistry scores of student
 * Output:
 *    None
*/
SinhVien::SinhVien(string ten="None", TypeGioiTinh gioitinh=NAM, int tuoi=0, float diemtoan=0, float diemly=0, float diemhoa=0)
{
    static uint8_t id=1;
    SinhVien::ID=id;
    id++;
    name= ten;
    gioiTinh= gioitinh;
    this->tuoi=tuoi;
    diemToan=diemtoan;
    diemLy=diemly;
    diemHoa=diemhoa;
}
/*
 * Function: getID
 * Description: A method of class SinhVien
 * Input:
 *    None
 * Output:
 *    ID of student
*/
uint8_t SinhVien::getID(){
    return this->ID;
}
/*
 * Function: setName
 * Description: A method of class SinhVien
 * Input:
 *    name of student
 * Output:
 *    None
*/
void SinhVien::setName(string ten){
    this->name=ten;
}
string SinhVien::getName(){
    return this->name;
}
/*
 * Function: setGioiTinh
 * Description: A method of class SinhVien
 * Input:
 *    sex of student
 * Output:
 *    None
*/
void SinhVien::setGioiTinh(TypeGioiTinh gioitinh){
    this->gioiTinh=gioitinh;
}
TypeGioiTinh SinhVien::getGioiTinh(){
    return this->gioiTinh;
}
void SinhVien::setTuoi(int tuoi){
    this->tuoi=tuoi;
}
int SinhVien::getTuoi(){
    return this->tuoi;
}
void SinhVien::setDiemToan(float diemtoan){
    this->diemToan=diemtoan;
}
float SinhVien::getDiemToan(){
    return this->diemToan;
}
void SinhVien::setDiemLy(float diemly){
    this->diemLy=diemly;
}
float SinhVien::getDiemLy(){
    return this->diemLy;
}
void SinhVien::setDiemHoa(float diemhoa){
    this->diemHoa=diemhoa;
}
float SinhVien::getDiemHoa(){
    return this->diemHoa;
}
float SinhVien::getDiemTrungBinh(){
    diemTB= (diemHoa+diemToan+diemLy)/3;
    return diemTB;
}
TypeHocLuc SinhVien::getHocLuc(){
    if(this->diemTB>=8){
        this->hocLuc=GIOI;
        return GIOI;
    } 
    if(this->diemTB<8&&diemTB>=6.5){
        this->hocLuc=KHA;
        return KHA;
    } 
    if(this->diemTB<6.5&&diemTB>=5){
        this->hocLuc=TRUNG_BINH;
        return TRUNG_BINH;
    } 
    if (this->diemTB<5){
        this->hocLuc=YEU;
        return YEU;
    }
    return ERROR;
}

class Menu{
    private:
        vector <SinhVien> Database;
    public:
        Menu();
        void themSinhVien();
        void capNhatThongTinBoiID();
        void xoaSinhVienBoiID();
        void timSinhVienTheoTen();
        void sapXepSinhVienTheoGPA();
        void sapXepSinhVienTheoTen();
        void hienThiDanhSach();
};
Menu::Menu()
{
    int phim=0;
    lua_chon:
    do{
    cout<<"Nhap phim de thao tac:"<<endl;
    cout<<"1. Them sinh vien"<<endl;
    cout<<"2. Cap nhat thong tin sinh vien boi ID"<<endl;
    cout<<"3. Xoa sinh vien boi ID"<<endl;
    cout<<"4. Tim kiem sinh vien theo ten"<<endl;
    cout<<"5. Sap xep sinh vien theo diem trung binh GPA"<<endl;
    cout<<"6. Sap xep sinh vien theo ten"<<endl;
    cout<<"7. Hien thi danh sach sinh vien"<<endl;
    cin>>phim;
    }
    while(phim<1||phim>7);
    switch(phim)
    {
        case 1: 
        label1:
            themSinhVien();
            do{
            cout<<"Nhap phim de chon:"<<endl;
            cout<<"1. Them sinh vien"<<endl;
            cout<<"2. Quay lai"<<endl;
            cin>>phim;
            }
            while(phim<1||phim>2);
            if(phim==1) goto label1;
            if(phim==2) goto lua_chon;
        case 2: 
        label2:
            capNhatThongTinBoiID(); 
            do{
            cout<<"Nhap phim de chon:"<<endl;
            cout<<"1. Cap nhat thong tin sinh vien boi ID"<<endl;
            cout<<"2. Quay lai"<<endl;
            cin>>phim;
            }
            while(phim<1||phim>2);
            if(phim==1) goto label2;
            if(phim==2) goto lua_chon;
        case 3: 
        label3:
            xoaSinhVienBoiID(); 
            do{
            cout<<"Nhap phim de chon:"<<endl;
            cout<<"1. Xoa sinh vien boi ID"<<endl;
            cout<<"2. Quay lai"<<endl;
            cin>>phim;
            }
            while(phim<1||phim>2);
            if(phim==1) goto label3;
            if(phim==2) goto lua_chon;
        case 4: 
        label4:
            timSinhVienTheoTen(); 
            do{
            cout<<"Nhap phim de chon:"<<endl;
            cout<<"1. Tim kiem sinh vien theo ten"<<endl;
            cout<<"2. Quay lai"<<endl;
            cin>>phim;
            }
            while(phim<1||phim>2);
            if(phim==1) goto label4;
            if(phim==2) goto lua_chon;
        case 5: 
        label5:
            sapXepSinhVienTheoGPA(); 
            do{
            cout<<"Nhap phim de chon:"<<endl;
            cout<<"1. Sap xep sinh vien theo diem trung binh GPA"<<endl;
            cout<<"2. Quay lai"<<endl;
            cin>>phim;
            }
            while(phim<1||phim>2);
            if(phim==1) goto label5;
            if(phim==2) goto lua_chon;
        case 6: 
        label6:
            sapXepSinhVienTheoTen(); 
            do{
            cout<<"Nhap phim de chon:"<<endl;
            cout<<"1. Sap xep sinh vien theo ten"<<endl;
            cout<<"2. Quay lai"<<endl;
            cin>>phim;
            }
            while(phim<1||phim>2);
            if(phim==1) goto label6;
            if(phim==2) goto lua_chon;
        case 7: 
        label7:
            hienThiDanhSach();
            do{
            cout<<"Nhap phim de chon:"<<endl;
            cout<<"1. Hien thi danh sach sinh vien"<<endl;
            cout<<"2. Quay lai"<<endl;
            cin>>phim;
            }
            while(phim<1||phim>2);
            if(phim==1) goto label7;
            if(phim==2) goto lua_chon; 
    }
}
void Menu::sapXepSinhVienTheoTen(){
    for(int i=0;i<this->Database.size();i++)
    {
        for(int j=i+1;j<this->Database.size();j++)
        {
            if(Database[i].getName()>Database[j].getName())
            {
                iter_swap(Database.begin()+i, Database.begin() + j);
            }
        }
    }
}
void Menu::sapXepSinhVienTheoGPA(){
    for(int i=0;i<this->Database.size();i++)
    {
        for(int j=i+1;j<this->Database.size();j++)
        {
            if(Database[i].getDiemTrungBinh()>Database[j].getDiemTrungBinh())
            {
                iter_swap(Database.begin()+i, Database.begin() + j);
            }
        }
    }
}
void Menu::timSinhVienTheoTen(){
    string ten;
    cout<<"Nhap ten sinh vien can tim kiem"<<endl;
    cin>>ten;
    for (SinhVien sv : Database){
        if(sv.getName()==ten){
        printf("%d",sv.getID());
        cout<<setw(10)<<sv.getName()<<setw(10);
        if(sv.getGioiTinh()==NAM) cout<<"NAM";
        else cout <<"NU";
        cout<<setw(10)<<sv.getTuoi()<<setw(10)<<sv.getDiemToan()<<setw(10)<<sv.getDiemLy()<<setw(10)<<sv.getDiemHoa()<<setw(10)<<setprecision(3)<<sv.getDiemTrungBinh()<<endl;
        }
        break;
}
}
void Menu::themSinhVien(){
    cout<<"Thong tin sinh vien"<<endl;
    string ten;
    string s_gioiTinh;
    TypeGioiTinh gioiTinh;
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;
    cout<<"Nhap ten:..."<<endl;
    cin>>ten;
    cout<<"Nhap gioi tinh(NAM/NU):..."<<endl;
    cin>>s_gioiTinh;
    if(s_gioiTinh=="Nam") gioiTinh=NAM;
    else if(s_gioiTinh=="Nu") gioiTinh=NU;
    else gioiTinh=null;
    cout<<"Nhap diem toan:..."<<endl;
    cin>>diemToan;
    cout<<"Nhap diem ly:..."<<endl;
    cin>>diemLy;
    cout<<"Nhap diem hoa:..."<<endl;
    cin>>diemHoa;
    cout<<"Nhap tuoi:..."<<endl;
    cin>>tuoi;
    SinhVien sv(ten, gioiTinh, tuoi, diemToan, diemLy, diemHoa);
    Menu::Database.push_back(sv);
}
void Menu::capNhatThongTinBoiID(){
    int id;
    cout<<"Nhap ID cua sinh vien can cap nhat thong tin"<<endl;
    cin>>id;
    for(int i=0;i<Database.size();i++)
    {
        if(Database[i].getID()==id)
        {
    string ten;
    string s_gioiTinh;
    TypeGioiTinh gioiTinh;
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;
    cout<<"Nhap ten:..." <<endl;
    cin>>ten;
    cout<<"Nhap gioi tinh(NAM/NU):..."<<endl;
    cin>>s_gioiTinh;
    if(s_gioiTinh=="Nam") gioiTinh=NAM;
    else if(s_gioiTinh=="Nu") gioiTinh=NU;
    else gioiTinh=null;
    cout<<"Nhap diem toan:..."<<endl;
    cin>>diemToan;
    cout<<"Nhap diem ly:..."<<endl;
    cin>>diemLy;
    cout<<"Nhap diem hoa:..."<<endl;
    cin>>diemHoa;
    cout<<"Nhap tuoi:..."<<endl;
    cin>>tuoi;
    Database[i].setDiemHoa(diemHoa);
    Database[i].setDiemLy(diemLy);
    Database[i].setDiemToan(diemToan);
    Database[i].setGioiTinh(gioiTinh);
    Database[i].setName(ten);
    Database[i].setTuoi(tuoi);
    break;
    }  
    } 
}
void Menu::xoaSinhVienBoiID(){
    int idXoa;
    cout<<"Nhap id sinh vien can xoa thong tin: "<<endl;
    cin >>idXoa;
    for (SinhVien sv : Database){
        if(sv.getID()==idXoa) Menu::Database.erase(Database.begin()+idXoa-1);
}
}
void Menu::hienThiDanhSach()
{
    
    cout<< "Danh sach sinh vien:"<<endl;
    for (SinhVien sv : Database){
        printf("%d",sv.getID());
        cout<<setw(10)<<sv.getName()<<setw(10);
        if(sv.getGioiTinh()==NAM) cout<<"NAM";
        else cout <<"NU";
        cout<<setw(10)<<sv.getTuoi()<<setw(10)<<sv.getDiemToan()<<setw(10)<<sv.getDiemLy()<<setw(10)<<sv.getDiemHoa()<<setw(10)<<setprecision(3)<<sv.getDiemTrungBinh()<<endl;
    }
}

int main()
{
    Menu quanlySV;
    return 0;
}