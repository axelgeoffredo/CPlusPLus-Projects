#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

bool num(char c){
    if (c >= '0' && c <= '9')
    return true;
    return false;
}
bool operation(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/')
    return true;

    return false;
}

int Count(char op, int op1, int op2){

    if(op == '+') return op1 +op2;
	else if(op == '-') return op1 - op2;
	else if(op == '*') return op1 * op2;
	else if(op == '/') return op1 / op2;
	else if(op == '^') return pow(op1,op2);

	else cout<<"Unexpected Error \n";
	return -1;

}
int main()
{
    string ex1;
    cout << "Postfix => ";
    getline(cin, ex1);
    int k = 1;

    vector <char> queue;
    for(int i=0;i<ex1.size();i++){
        queue.push_back(ex1[i]);
    }

    vector <int> stack;
    for (int j=0; j<queue.size();){
          if (queue.at(j) != '*' && queue.at(j) != '/' && queue.at(j) != '+' && queue.at(j) != '-' && queue.at(j) != '^'){
    stack.push_back(int(queue.at(j))-48);
    vector<char>::iterator start = queue.begin()+j;
    queue.erase(start);
          }

    else{
        vector<char>::iterator start = queue.begin();
        char x = queue.at(j);
        queue.erase(start);
    cout<<"Step "<<k<<" : "<<stack.at(stack.size()-2)<<x<<stack.at(stack.size()-1)<<" = ";
    int calculate= Count(x,stack.at(stack.size()-2), stack.at(stack.size()-1));
    k++;
        stack.pop_back();
        stack.pop_back();
        stack.push_back(calculate);

        cout<<stack.back()<<endl;


    }
    }
    cout<<"Answer: "<<stack.back()<<endl;
}




