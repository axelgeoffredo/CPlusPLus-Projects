#include<iostream>
#include<cmath>
#include<stack>
#include<iomanip>
#include<vector>

using namespace std;

int  calc(char token, int num1, int num2);
bool hasPrec(char op1, char op2);
int  getWeight( char op );
bool in2postfix( deque<char> &operatorSTK, string &infixQ, string &postfixQ );
int  postfixCalc( string postfixQ );

int main() {
    string infix;      // infix expression
    string infixQ;     // infix Queue
    string postfixQ;   // postfix Queue
    deque<char> operatorSTK; // for resolving (^, *, /, +, -) In-Coming Priority
    operatorSTK = {' '};
    cout << "Please enter an INFIX expression: ";
    getline(cin, infix);

    for(char c:infix) {
        if( isdigit(c) || c=='^' || c=='(' || c==')' ||
           c=='+' || c=='-' || c=='*' || c=='/')
            infixQ += c;
    }

    if( !in2postfix( operatorSTK, infixQ, postfixQ ) ) {
        cout << "failed the conversion to postfix!";
        exit(EXIT_FAILURE);
    }

    cout << "\nPostfix => " << postfixQ << endl;
    int k = 1;


    vector <char> queue;
    int answer;
    for (int i = 0; i < postfixQ.size(); i++) {
        queue.push_back(postfixQ[i]);
    }

    vector <int> stack;

    for (int i=0; i<queue.size();) {
        if (queue.at(i) != '*' && queue.at(i) != '/' && queue.at(i) != '+' &&
            queue.at(i) != '-' && queue.at(i) != '^') {
            stack.push_back(int(queue.at(i))-48);
            vector <char>::iterator it = queue.begin() + i;
            queue.erase(it);

        }
        else {
            vector<char>::iterator it = queue.begin();
            char temp = queue.at(i);
            queue.erase(it);


            cout << "Step " << k << ": "<<stack.at(stack.size()-2) << temp << stack.at(stack.size()-1)<<" = ";
            int compute = calc(temp,stack.at(stack.size()-2), stack.at(stack.size()-1));

            k++;
            stack.pop_back();
            stack.pop_back();
            stack.push_back(compute);

            cout<<stack.back()<<endl;
            answer = stack.back();
        }

    }
    cout<< "Answer: " << answer << endl;


    return 0;
}

bool in2postfix( deque<char> &operatorSTK, string &infixQ, string &postfixQ ) {
    bool result = true;
    cout << endl;
    // Infix to Postfix Conversion, parsing left to right:
    while(true){

        cout << "OP Stack: ";
        for(auto x:operatorSTK) cout << x;
        for(int i=0; i<(15 - operatorSTK.size()); i++) cout << ' ';
        cout << setw(20) << right << "Postfix Queue: " << postfixQ << endl;

        if( infixQ.empty() )
        break; // infix Q is empty - done!

        // parsing the infixQ left to right, reading the front of infixQ
        char in = infixQ[0];
        infixQ.erase(0,1);

        if( '0'<= in && in<='9')
        { postfixQ += in;
        continue;
        }

        switch( in ){
         case '(': // push into the operator operatorSTK
         operatorSTK.push_back(in);
         break;

         case ')':  // pop operator operatorSTK to postfix postfixQ
         while(true) {
         char op = operatorSTK.back();
         operatorSTK.pop_back();
         cout<<"OP Stack: ";
         for(auto x:operatorSTK) cout << x;
        for(int i=0; i<(15 - operatorSTK.size()); i++) cout << ' ';
        cout << setw(20) << right << "Postfix Queue: " << postfixQ << endl;
         if( op == '(' ) break;
         postfixQ += op ;  // add to postfix
         } break;


         case '+': case '-': case '*': case '/': case '^':
         {
         char op = operatorSTK.back();
         while( !operatorSTK.empty() && hasPrec(op, in ) ) { // ICP In-Coming Priority
         postfixQ += op;
         operatorSTK.pop_back();
         op = operatorSTK.back();
         cout<<"OP Stack: ";
         for(auto x:operatorSTK) cout << x;
         for(int i=0; i<(15 - operatorSTK.size()); i++) cout << ' ';
        cout << setw(20) << right << "Postfix Queue: " << postfixQ << endl;
         }
         operatorSTK.push_back(in);
         break;
         }
         }

        if(in=='#')
        break;
    }


    while( !operatorSTK.empty() ) {

        char op = operatorSTK.back(); operatorSTK.pop_back();
        postfixQ += op ;
    }
    cout<<"OP Stack: ";
    for(auto x:operatorSTK) cout << x;
    for(int i=0; i<(15 - operatorSTK.size()); i++) cout << ' ';
    cout << setw(20) << right << "Postfix Queue: " << postfixQ << endl;

    return result;
}

// Two argumented Calculator
int calc(char token, int num1, int num2){
    int result;
    switch(token) {
        case '*': result = num1 * num2; break;
        case '/': result = num1 / num2; break;
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '^': result = pow(num1, num2); break;
    }
    return result;
}

// Compare ISP: In-Stack Priority Weight
bool hasPrec(char op1, char op2) {
    int op_pr1 = getWeight(op1);
    int op_pr2 = getWeight(op2);
    if(op_pr1 == op_pr2) {
        if(op1 == '^') return false;
        return true;
    }
    return op_pr1 >= op_pr2 ? true:false;
}

// Determine ISP: In-Stack Priority Weight
int getWeight( char op ) {
    int w = -1;
    switch (op) {
        case '+':
        case '-': w = 1; break;
        case '*':
        case '/': w = 2; break;
        case '^': w = 3; break;
    }
    return w;
}
