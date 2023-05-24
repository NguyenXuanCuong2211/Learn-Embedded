/*
 * File: bai4-classDongVat.cpp
 * Author: Nguyen Xuan Cuong
 * Date:24/05/2023
 * Description: Make a class animal with properties: name, age, weight, height and methods to calculate BMI index,
   compare age and weight of different animals.
 */
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string>
#include<stdint.h>
using namespace std;
/*
 * Function: class animal
 * Description: The class represents the properties and methods of the object animal
 * Input:
 *    None
 * Output:
 *    None
*/
class animal 
{
    private:
    string name;
    uint8_t age;
    float weight;
    float height;
    public:
    animal(string ten, uint8_t tuoi, float nang, float cao);
    string getName();
    uint8_t getAge();
    float getWeight();
    float getHeight();
    float calBMI();
};
/*
 * Function: animal
 * Description: The constructor of class animal
 * Input:
 *    ten: name of animal
 *    tuoi: age of animal
 *    nang: weight of animal
 *    cao: height of animal 
 * Output:
 *    None
*/
animal::animal(string ten="ERROR", uint8_t tuoi=0, float nang=0, float cao=0)
{
    animal::name=ten;
    animal::age=tuoi;
    animal::weight=nang;
    animal::height=cao;
}
/*
* Function: getName()
 * Description: A method of class animal
 * Input:
 *    None 
 * Output:
 *    name of animal
*/
string animal::getName()
{
    return animal::name;
}
/*
 * Function: getAge()
 * Description: A method of class animal
 * Input:
 *    None 
 * Output:
 *    age of animal
*/
uint8_t animal::getAge()
{
    return animal::age;
}
/*
 * Function: getWeight()
 * Description: A method of class animal
 * Input:
 *    None 
 * Output:
 *    weight of animal
*/
float animal::getWeight()
{
    return animal::weight;
}
/*
 * Function: getHeight()
 * Description: A method of class animal
 * Input:
 *    None 
 * Output:
 *    height of animal
*/
float animal::getHeight()
{
    return animal::height;
}
/*
 * Function: calBMI()
 * Description: A method of class animal that calculate BMI index of animal.
 * Input:
 *    None 
 * Output:
 *    BMI index of animal
*/
float animal::calBMI()
{
    int BMI= animal::weight/(pow(animal::height,2));
    return BMI;
}
/*
 * Function: class COMPARE
 * Description: The class represents the properties and methods of the object compare animal
 * Input:
 *    None
 * Output:
 *    None
*/
class COMPARE
{
    private:
    animal first;
    animal second;
    public:
    void setAnimal(animal mot, animal hai);
    void compareAge();
    void compareWeight();
};
/*
 * Function: setAnimal()
 * Description: A method of class COMPARE that reference animal parameter 
 * Input:
 *    mot: first animal
 *    hai: second animal 
 * Output:
 *    None
*/
void COMPARE::setAnimal(animal mot, animal hai)
{
    COMPARE::first=mot;
    COMPARE::second=hai;
}
/*
 * Function: compareAge()
 * Description: A method of class COMPARE that compare age of two animal
 * Input:
 *    None 
 * Output:
 *    None
*/
void COMPARE::compareAge()
{
    if(COMPARE::first.getAge()>COMPARE::second.getAge())
    {
        printf("%s nhieu tuoi hon %s\n",COMPARE::first.getName().c_str(),COMPARE::second.getName().c_str());
    }
    else if(COMPARE::first.getAge()<COMPARE::second.getAge())
    {
        printf("%s nho tuoi hon %s\n",COMPARE::first.getName().c_str(),COMPARE::second.getName().c_str());
    }
    else{
        printf("%s bang tuoi %s\n",COMPARE::first.getName().c_str(),COMPARE::second.getName().c_str());
    }
}
/*
 * Function: compareWeight()
 * Description: A method of class COMPARE that compare weight of two animal
 * Input:
 *    None 
 * Output:
 *    None
*/
void COMPARE::compareWeight()
{
    if(this->first.getWeight()>this->second.getWeight())
    {
        printf("%s nang hon %s\n",COMPARE::first.getName().c_str(),COMPARE::second.getName().c_str());
    }
    else if(this->first.getWeight()<this->second.getWeight())
    {
        printf("%s nhe hon %s\n",COMPARE::first.getName().c_str(),COMPARE::second.getName().c_str());
    }
    else{
        printf("%s nang bang %s\n",COMPARE::first.getName().c_str(),COMPARE::second.getName().c_str());
    }
}
int main()
{
    animal cho("DOG",5,12.8,0.4), meo("MEO",3,6.8,0.3);
    cout << cho.calBMI()<<endl;
    cout << meo.calBMI()<<endl;
    COMPARE comp;
    comp.setAnimal(cho,meo);
    comp.compareAge();
    comp.compareWeight();
    return 0;
}


