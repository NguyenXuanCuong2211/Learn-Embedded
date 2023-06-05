#include<iostream>
#include<string>
#include<vector>
#include<stdint.h>
#include<iomanip>
using namespace std;
class Beverage
{
    private:
    uint8_t ID;
    string Name;
    double Price;
    public:
    Beverage(string name, double price);
    Beverage();
    uint8_t getID();
    string getName();
    double getPrice();
    void setName(string name);
    void setPrice(double price);
};
Beverage::Beverage(string name, double price)
{
    static int id =1;
    ID = id;
    id++;
    Name = name;
    Price = price;
}
uint8_t Beverage::getID()
{
    return ID;
}
string Beverage::getName()
{
    return Name;
}
double Beverage::getPrice()
{
    return Price;
}
void Beverage::setName(string name)
{
    Name = name;
}
void Beverage::setPrice(double price)
{
    Price = price;
}

class Manager
{
    private:
    vector<Beverage> DatabaseManager;
    uint8_t QuantityOfTable;
    void SetQuantityTable();
    void AddBeverage();
    void ChangeBeverage();
    void DeleteBeverage();
    void ListOfBeverage();
    public:
    Manager(uint8_t QuantityOfTable);
    uint8_t GetQuantityOfTable();
    vector<Beverage> getDatabase();
};
uint8_t Manager::GetQuantityOfTable()
{
    return QuantityOfTable;
}
void Manager::ListOfBeverage()
{
    //similar2
    for (Beverage each: DatabaseManager)
    {
        cout<<setw(12)<<each.getID()<<setw(12)<<each.getName()<<setw(12)<<each.getPrice()<<endl;
    }
}
void Manager::DeleteBeverage()
{
    string name;
    bool flag=0;
    do{
    cout << "Type name of beverage you want to change: ";
    cin >> name;
    for (int i=0; i< DatabaseManager.size();i++)
    {
        if(DatabaseManager[i].getName()==name)
        {
            flag = 1;
            DatabaseManager.erase(DatabaseManager.begin()+i);
            break;
        }
    }
    }
    while(flag=0);
}
void Manager::ChangeBeverage()
{
    string name;
    bool flag=0;
    do{
    cout << "Type name of beverage you want to change: ";
    cin >> name;
    for (Beverage each: DatabaseManager)
    {
        if (each.getName()==name)
        {
            //Similar1
            flag=1;
            string name;
            cout << "Type name of beverage: ";
            cin >> name;
            double price;
            cout <<endl << "Type price of beverage: ";
            cin >> price;
            cout <<endl;
            Beverage beverage1 (name, price);
            DatabaseManager.push_back(beverage1);
            break;
        }
    }
    }
    while(flag==0);
}
void Manager::AddBeverage()
{
    //similar1
    string name;
    cout << "Type name of beverage: ";
    cin >> name;
    double price;
    cout <<endl << "Type price of beverage: ";
    cin >> price;
    Beverage beverage1 (name, price);
    DatabaseManager.push_back(beverage1);
}
void Manager::SetQuantityTable()
{
    cout << "Type quantity of Table: ";
    cin >> QuantityOfTable;
    cout << endl;
}
Manager::Manager(uint8_t quantityOftable=10)
{
    uint8_t num;
    QuantityOfTable = quantityOftable;
    cout << "Manager" <<endl;
    cout << "1. Add Beverage"<<endl;
    cout << "2. Change Beverage"<<endl;
    cout << "3. Delete Beverage"<<endl;
    cout << "4. List of Beverage"<<endl;
    cout << "5. Set quantity of table"<<endl;
    cout << "0. Return"<<endl;
    cout << "Type..."<<endl;
    cin >> num;
    while (num<0||num>5)
    {
        cout << "Type again..." <<endl;
    }
    switch (num)
    {
        case 1: AddBeverage();
        break;
        case 2: ChangeBeverage();
        break;
        case 3: DeleteBeverage();
        break;
        case 4: ListOfBeverage();
        break;
        case 5: SetQuantityTable( );
        break;
        case 0: 
        break;
    }
}
typedef enum{
    Empty,
    Full
}StatusTable;
typedef struct {
    Beverage nameBeverage;
    uint8_t quantityBeverage;
}Oder;
typedef struct {
    uint8_t numberOfTable;
    StatusTable status;
    vector<Oder> databaseOder;
} Table;
class Staff 
{
    private:
    vector <Beverage> DatabaseBeverage;
    vector<Table> DatabaseTable;
    void OderBeverage(uint8_t table);
    void ChangeBeverage(uint8_t table);
    void DeleteBeverage(uint8_t table);
    void ListOfOder(uint8_t table);
    void Payment(uint8_t table);
    void createTable(uint8_t table);
    public:
    Staff(const vector<Beverage> DatabaseManager, uint8_t QuantityOfTable);
};
void Staff::Payment(uint8_t table)
{
    DatabaseTable[table-1].status=Empty;
    DatabaseTable[table-1].databaseOder.clear();
}
void Staff::ListOfOder(uint8_t table)
{
    for (Oder each: DatabaseTable[table-1].databaseOder)
    {
        cout<<setw(12)<<each.nameBeverage.getID()<<setw(12)<<each.nameBeverage.getName()<<setw(12)<<each.nameBeverage.getPrice()<<setw(12)<<each.quantityBeverage<<endl;
    }
}
void Staff::DeleteBeverage(uint8_t table)
{
    string name;
    uint8_t flag=0;
    do{
    cout<<"Type Beverage name you want to delete: ";
    cin>>name;
    for(int i=0;i<DatabaseTable[table-1].databaseOder.size();i++)
    {
        if(DatabaseTable[table-1].databaseOder[i].nameBeverage.getName()==name)
        {
            flag=1;
            DatabaseTable[table-1].databaseOder.erase(DatabaseTable[table-1].databaseOder.begin()+i);
        }
    }
    }
    while(flag==0);
}
void Staff::ChangeBeverage(uint8_t table)
{
    string name;
    uint8_t id;
    uint8_t quantityofbeverage;
    cout <<"Type Beverage name you want to change: ";
    cin >> name; cout <<endl;
    for(int i=0;i<DatabaseTable[table-1].databaseOder.size();i++)
    {
        if(DatabaseTable[table-1].databaseOder[i].nameBeverage.getName()==name)
        {
            //similar3
            cout<<"Type change ID:...";
            cin>>id; cout<<endl;
            cout<<"Type change quantity of Beverage: ";
            cin>>quantityofbeverage; cout<<endl;
            for (int j=0; j<DatabaseBeverage.size();j++)
            { 
            if(DatabaseBeverage[j].getID()==id)
            {
            DatabaseTable[table-1].databaseOder[i].nameBeverage=DatabaseBeverage[j];
            DatabaseTable[table-1].databaseOder[i].quantityBeverage=quantityofbeverage;
            break;
            }
            }
        }
    }
}
void Staff::OderBeverage(uint8_t table)
{
    //similar2
    uint8_t id;
    static uint8_t indexOder=0;
    uint8_t quantityofbeverage;
    Oder oder;
    cout <<"Order Beverage:"<<endl;
    for (Beverage each: DatabaseBeverage)
    {
        cout<<setw(12)<<each.getID()<<setw(12)<<each.getName()<<setw(12)<<each.getPrice()<<endl;
    }
    //similar3
    cout<<"Type ID:...";
    cin>>id; cout<<endl;
    cout<<"Type quantity of Beverage: ";
    cin>>quantityofbeverage; cout<<endl;
    for (int i=0; i<DatabaseBeverage.size();i++)
    {
        if(DatabaseBeverage[i].getID()==id)
        {
            oder.nameBeverage=DatabaseBeverage[i];
            oder.quantityBeverage=quantityofbeverage;
            DatabaseTable[table-1].databaseOder.push_back(oder);
            break;
        }
    }
    indexOder++;
}
void Staff::createTable(uint8_t table)
{
    uint8_t num;
    DatabaseTable[table-1].status= Full;
    cout << endl << "Table: "<<table << endl;
    cout <<"1. Oder Beverage"<<endl;
    cout <<"2. Change Beverage"<<endl;
    cout <<"3. Delete Beverage"<<endl;
    cout <<"4. List of Oder"<<endl;
    cout <<"5. Payment"<<endl;
    cout <<"0. Return"<<endl;
    cout <<"Type:..."<<endl;
    cin >> num;
    while (num<0|| num>5)
    {
        cout<<"ERROR SYNTAX"<<endl;
        cout<<"Type again"<<endl;
        cin >>num;
    }
    switch (num)
    {
        case 1: OderBeverage(table);
        break;
        case 2: ChangeBeverage(table);
        break;
        case 3: DeleteBeverage(table);
        break;
        case 4: ListOfOder(table);
        break;
        case 5: Payment(table);
        break;
        case 0: 
        break;
    }

}
Staff::Staff(const vector<Beverage> DatabaseManager, uint8_t QuantityOfTable)
{
    Table table;
    uint8_t numberOfTable;
    for(Beverage beverage : DatabaseManager)
    {
        DatabaseBeverage.push_back(beverage);
    }
    for(int i=1; i <=QuantityOfTable;i++)
    {
        table.numberOfTable =i;
        table.status = Empty;
    }
    cout << "Nhan vien:" <<endl;
    cout << "Ban: ";
    for (Table each: DatabaseTable )
    {
        cout << " | " <<table.numberOfTable;
    }
    cout << endl << "     ";
     for (Table each: DatabaseTable )
    {
        if(table.status==Empty)
        {
            cout << " | x";
        }
        else cout << " |0";  
    }
    cout << endl << "Nhap ban:..." <<endl;
    cin >> numberOfTable;
    createTable(numberOfTable);
}
int main()
{
    uint8_t number;
    cout <<"Main Page"<<endl;
    cout <<"1. Manager"<<endl;
    cout <<"2. Staff"<<endl;
    cout <<"Type..."<<endl;
    cin >>number;
    while(number!=1 && number !=2){
        cout<<"Type again..."<<endl;
    }
    Manager manager1;
    Manager *ptr= &manager1;
    if(number==1) ptr;
    if (number==2) 
    {
    Staff staff1(manager1.getDatabase(), manager1.GetQuantityOfTable());
    }
    return 0;
}
