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
    cout << "Enter a postfix expression, q to quit: ";
    getline(cin, ex1);
    cout<< "Opr_Stack ____________ Postfix_Queue_"<<endl;
    cout<<"                           "<<right<<ex1<<endl;

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
    for (int k=0;k<stack.size();k++){
        cout<<stack.at(k);
    }
    cout<<"                           "<<right<<" ";

    for (int l = 0; l<queue.size();l++){
        cout<<queue.at(l);
    }
    cout<<"\n";
    }
    else{
        vector<char>::iterator start = queue.begin();
        char x = queue.at(j);
        queue.erase(start);
        cout<<"                           "<<left<<" "<<" ";

        for(int k=0;k<queue.size();k++){
            cout<< queue.at(k);
        }
    cout<<"\n";

    for (int l=0; l<stack.size()-2; l++){
        cout<<stack.at(l);
    }
    cout<<"("<<stack.at(stack.size()-2)<<x<<stack.at(stack.size()-1)<<")"<<endl;
    int calculate= Count(x,stack.at(stack.size()-2), stack.at(stack.size()-1));

        stack.pop_back();
        stack.pop_back();
        stack.push_back(calculate);

        for(int m = 0; m <stack.size(); m++){
            cout<<stack.at(m);
        }
        cout<<"                           "<<right<<" ";
        for (int n = 0; n<queue.size(); n++){
            cout<<queue.at(n);
        }
        cout<<endl;

    }
    }
}




