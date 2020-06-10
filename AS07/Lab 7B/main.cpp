#include <iostream>
using namespace std;
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}

   // Constructor declaration
   SimpleVector(int);

   // Copy constructor declaration
   SimpleVector(const SimpleVector &);

   // Destructor declaration
   ~SimpleVector();

   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;

   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();

   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

template <class T>
class SortableVector : public SimpleVector<T>
{
public:
   // Default constructor
   SortableVector() : SimpleVector<T>()
    {}

   // Constructor declaration
   SortableVector(int size): SimpleVector<T>(size)
   { }

   // Copy constructor declaration
   SortableVector(const SortableVector &);
    void Sort();
};
    template <class T>
    SortableVector<T>::SortableVector(const SortableVector &obj):SimpleVector<T>(obj.size())
    {
        for(int count=0; count< this->size(); count++)
            this->operator[](count) = obj[count];
    }
    template <class T>
    void SortableVector<T>::Sort(){
	for (int i = 0; i<this->size()-1; i++)
	{
		for (int count = 0; count < (this->size() - 1); count++)
		{
			if (this->operator[](count) > this->operator[](count + 1))
			{
				swap(this->operator[](count), this->operator[](count + 1));
			}
		}
	}
}
int main() {
	const int SIZE = 5;  // The array size

	// Define SortableVector objects.
	SortableVector<int> intTable(SIZE);
	SortableVector<double> doubleTable(SIZE);
	// Place values into the arrays in descending order.
	for (int x = 0; x < SIZE ; x++) {
		intTable[x] = SIZE - x;
		doubleTable[x]= SIZE - (x * 1.1f);
	}

	// Display the values in the arrays.
	cout << "Before sorting, these values are in intTable:\n";
	for (int x = 0; x < SIZE; x++){
		cout << intTable[x] << "  ";
	}
	cout << "\nBefore sorting, these values are in doubleTable:\n";
	for (int x = 0; x < SIZE; x++){
		cout << doubleTable[x] << "  ";
	}
	intTable.Sort();
    doubleTable.Sort();

	cout << "\nAfter sorting, these values are in intTable:\n";
	for (int x = 0; x < SIZE; x++)
		cout << intTable[x] << "  ";
	cout << "\nAfter sorting, these values are in doubleTable:\n";
	for (int x = 0; x < SIZE; x++)
		cout << doubleTable[x] << "  ";
}
