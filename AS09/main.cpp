#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class SubsError{
    int number;
    public: SubsError(int var):number(var){}
    int getValue(){ return number; }
};

class IntLinkedQueue {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *front; //
    Node *rear; //
    Node *p;
    Node *pp;
    int size; //

public:
    // Default Constructor
    IntLinkedQueue() : front(nullptr), rear(nullptr), size(0) {}
    // Destructor; // return all dynamically allocated nodes
    ~IntLinkedQueue() {
    }

    void append(int n){
        p = new Node;
        p->next = nullptr;
        p->data = n;
        (front) ? rear = rear->next = p : front = rear = p;
        size++;
    };

    bool isEmpty(){
    if (front == nullptr)
        return true;
    else
        return false;
    }

    int getSize(){
    cout<<"Number of Entries in Queue: "<<size-1<<endl;
    }

    void add(int n){
    if (isEmpty())
        append(n);
    else{
        p = new Node;
        p->next = nullptr;
        p->data = n;
        (front) ? rear = rear->next = p : front = rear = p;
        size++;
    }
}

    void remove(){
        if(isEmpty())
            cout <<"The List is Empty."<<endl;

        else if (front == rear){
            delete front;
            front == nullptr;
            rear == nullptr;
            front = nullptr;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    void clear(){
        Node *current;
        Node *next;
        current = front;
            while(current!=rear){
            next = current -> next;
            delete current;
            current = next;
            }
        front = nullptr;
    }
    void display(){
    Node *current;
    current = front;
    if(front==nullptr)
        cout<<"List is Empty."<<endl;
    else{
        while(current != nullptr){
            cout<<current->data;
            current = current->next;
            cout<<", ";
        }

    }
}
      string toString(){
          string content;
          Node *current;
          current = front;
          while(current != nullptr){
            content += current->data;
            current = current->next;
          }
          return content;
    }
};
void menu(){
    cout<<"\n--- AS9 IntLinkedQueue Test Menu ---"<<endl;
    cout<<"        N - to bulk create New Queue"<<endl;
    cout<<"        D - to Display"<<endl;
    cout<<"        E - is Empty?"<<endl;
    cout<<"        A - to Add"<<endl;
    cout<<"        R - to Remove"<<endl;
    cout<<"        L - Length of Queue?"<<endl;
    cout<<"        C - to Clear"<<endl;
    cout<<"        Q - to Q this program"<<endl;
    cout<<"        H - this menu"<<endl;
    }
int main()
{
 bool stay = true;

	// create one instance for each of the test classes
	cout << "\nInstanciate an object of Queue\n";
	string catchVar; // To hold values popped off the Queue
	IntLinkedQueue q;

	cout << "\nFirst, test with hard-wired data sets!\n"
		 << "For example, \nyou may use one set of tokens for all test classes: \n";
	string choice; // user input for choices
	string str; // user input for list, delimiter, ...
	int s[] = {1, 3, 5, 7, 9};

	vector <int> input(s, end(s));

	// show the initial item list
	int input_size = input.size();
	for (auto item : input ) {
		cout << item << ((input_size <= 1) ? " " : ", ");
		input_size--;
	}
	cout << endl;

	// initialize the Queue class instances
	for (auto i: input) q.add( i );
	cout << "\nUse menu to test a Queue class instance.\n";

    menu();

	// main menu while
	while(stay) {  // main menu while starts
		cout << "\n	Enter your command: ";
		stay = true;
		cin >> choice;
		cin.ignore();
		int pos;
		string input;
		string token;
		int item;
		stringstream sst;
		stringstream ss;
		int Queue_size;

if(choice.size() == 1) {
            char ch = choice[0];
            vector<string> dump;
            string value;
            switch(ch) { // main menu switch starts
                case 'n':
                case 'N':
                {
                    // if(!q.isEmpty()) q.clear();
                    cout << "\t\tEnter a line of comma (,) delmited data set: ";
                    getline (cin, input); // user input -> string
                    ss << input; // string -> stream
                    while ( getline(ss, token, ',') ) { // stream -> string token
                        stringstream sst(token);
                        sst >> item;
                        q.append(item);
                    }
                    break;
                }
                case 'd':
                case 'D':
                    q.display();
                break;

                case 'e':
                case 'E':
                    if (q.isEmpty()==true)
                        cout<<"List is Empty."<<endl;
                    else
                        cout<<"List is Not Empty."<<endl;

                    break;

                case 'a':
                case 'A':
                    int a;
                    cout<< "Enter a Number: ";
                    cin>>a;
                    cout<< "You have entered: "<<a<<endl;
                    q.add(a);
                    q.display();
                    break;

                case 'r':
                case 'R' :
                    q.remove();
                    q.display();
                    break;

                case 'l':
                case 'L':
                    cout<<endl;
                    q.getSize();
                    break;

                case 'c':
                case 'C':
                    q.clear();
                    break;

                case 'q': // exit Queue sub-menu
                case 'Q':
                    stay = false;
                    break;

                case 'h': // help - display menu
                case 'H':
                case '?':
                    menu();
                    break;

                default:
                    cout << "\nInvalid Selection!\nTry again!\n\n";

            } // end of menu switch
        } // only process single character
    } // end of main menu while
    cout << "Program exit!\n";
} // end of main
