#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Employee{
private:
    string name;
    int number;
    string hiredate;
public:

class InvalidEmpNum{};
    Employee(){
    name = "";
    number = 0;
    hiredate= "";
    }
    Employee(string n, int num, string h){
    name = n;
    number = num;
    hiredate = h;
    }
    void setName(string n){
    name = n;
    }
    string getName() const {
    return name;
    }
    void setNum(int num){
    if (num >=0 && num <=9999)
    number = num;
    else
        throw InvalidEmpNum();
    }
    int getNum() const{
    return number;
    }

    void setHire(string h){
    hiredate = h;
    }
    string getHire()const{
    return hiredate;
    }
};
class ProductionWorker : public Employee{
private:
    int shift;
    double pay;
public:
    class InvalidShiftNum{};
    class InvalidPayRate{};
    ProductionWorker(): Employee(){
    shift = 0;
    pay = 0.0;
    }

    ProductionWorker(string n, int num, string h, int s, double p):Employee(n, num, h){
    shift = s;
    pay = p;
    }
    void setShift(int s){
    if (s == 1 || s == 2)
    shift = s;
    else
        throw InvalidShiftNum();
    }
    int getShiftN() const{
    return shift;
    }


    void setPay(double p){
    if (p >=0)
    pay = p;
    else
        throw InvalidPayRate();
    }
    double getPay()const{
    return pay;
    }

    void WorkerInfo(){
    cout<<"Name: "<<Employee::getName()<<endl;
    cout<<"Number: "<<Employee::getNum()<<endl;
    cout<<"Hire Date: "<<Employee::getHire()<<endl;
    cout<<"Shift Number: "<<getShiftN()<<endl;
    cout<<"Shift: ";
    if (getShiftN() == 1){
        cout<<"Day Shift"<<endl;
    }
    else if (getShiftN() == 2){
        cout<<"Night Shift"<<endl;
    }
    cout<<"Hourly Pay: $"<<getPay()<<endl;
    }



};
int main()
{
    ProductionWorker p1;
    ProductionWorker p2;
    ProductionWorker p3;
    ProductionWorker p4;
    try{
        p1.setName("John Jones");
        p1.setNum(123);
        p1.setHire("1/1/2006");
        p1.setShift(2);
        p1.setPay(18.00);
    p1.WorkerInfo();
    }
    catch (ProductionWorker::InvalidEmpNum){
        cout<<"Error: Invalid employee number.\n";
    }

    catch (ProductionWorker::InvalidShiftNum){
        cout<<"Error: Invalid shift number.\n";
    }

    catch (ProductionWorker::InvalidPayRate){
        cout<<"Error: Invalid pay rate.\n";

    }
    try{
        p2.setName("John Jones");
        p2.setNum(99999);
        p2.setHire("1/1/2006");
        p2.setShift(2);
        p2.setPay(18.00);
    p2.WorkerInfo();
    }
    catch (ProductionWorker::InvalidEmpNum){
        cout<<"Error: Invalid employee number.\n";
    }

    catch (ProductionWorker::InvalidShiftNum){
        cout<<"Error: Invalid shift number.\n";
    }

    catch (ProductionWorker::InvalidPayRate){
        cout<<"Error: Invalid pay rate.\n";

    }
    try{
        p3.setName("John Jones");
        p3.setNum(123);
        p3.setHire("1/1/2006");
        p3.setShift(0);
        p3.setPay(18.00);
    p3.WorkerInfo();


    }
   catch (ProductionWorker::InvalidEmpNum){
        cout<<"Error: Invalid employee number.\n";
    }

    catch (ProductionWorker::InvalidShiftNum){
        cout<<"Error: Invalid shift number.\n";
    }

    catch (ProductionWorker::InvalidPayRate){
        cout<<"Error: Invalid pay rate.\n";

    }
    try{
        p4.setName("John Jones");
        p4.setNum(123);
        p4.setHire("1/1/2006");
        p4.setShift(2);
        p4.setPay(-99);
    p4.WorkerInfo();

    }
   catch (ProductionWorker::InvalidEmpNum){
        cout<<"Error: Invalid employee number.\n";
    }

    catch (ProductionWorker::InvalidShiftNum){
        cout<<"Error: Invalid shift number.\n";
    }

    catch (ProductionWorker::InvalidPayRate){
        cout<<"Error: Invalid pay rate.\n";

    }

    cout<<endl;

    return 0;

}
