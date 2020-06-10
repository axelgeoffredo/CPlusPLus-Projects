#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
vector<int> b;
vector<int> c;

//Function to del vector
int pop(int target)
{
int num;
switch(target){
case 1:
    num = a.back();
    a.pop_back();
    return num;
case 2:
    num = b.back();
    b.pop_back();
    return num;
case 3:
    num = c.back();
    c.pop_back();
    return num;
}
return 0;
}
//Function to add vector
void push(int target,int num)
{
switch(target){
case 1:
    a.push_back(num);
    break;
case 2:
    b.push_back(num);
    break;
case 3:
    c.push_back(num);
    break;
}
}
//Iteration for display
void display()
{
vector<int> ::iterator i;
cout<<"src: ";
    for(i=a.begin();i!=a.end();i++)
    {
        cout<<*i<<" ";
    }
cout<<" | dest:";
    for(i=c.begin();i!=c.end();i++)
    {
        cout<<*i<<" ";
    }
cout<<" | temp: ";
    for(i=b.begin();i!=b.end();i++)
    {
        cout<<*i<<" ";
    }
cout<<endl;

}
//Algorithm of Hanoi Tower Recursion
void moveDiscs(int num, int start, int dest, int temp)
{
    if (num == 1)
    {
        push(dest,pop(start));
        display();
        return;
    }
moveDiscs(num - 1, start, temp, dest);
push(dest,pop(start));
display();
moveDiscs(num - 1, temp, dest, start);
}


int main()
{
int n;
cout<<"Enter Hanoi Tower Height: ";
cin>>n;
int temp = n;
for (int i = 0; i<n; i++){
a.push_back(temp);
temp--;
}
display();
moveDiscs(n, 1, 3, 2);
cout<<"\n"<<" --- exit!"<<endl;
return 0;
}
