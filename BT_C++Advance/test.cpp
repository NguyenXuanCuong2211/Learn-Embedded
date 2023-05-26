#include <iostream>
#include <string>
using namespace std;
int main() {
    string ten1, ten2;
    cin>>ten1;
    cin>>ten2;
    cout<<ten1<<"   "<<ten2<<endl;
    if(ten1>ten2) cout<<ten1<<" lon hon "<<ten2<<endl;
    if(ten1<ten2) cout<<ten1<<" nho hon "<<ten2<<endl;

    return 0;
}