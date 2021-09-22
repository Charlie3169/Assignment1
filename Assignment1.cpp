#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <string>

using namespace std;

// hi testing
/*
	Student class representing a student
*/
class Student
{
private:
	string firstName;
	string lastName;
	int mNumber;

public:

	Student();

	Student( string firstName, string lastName, int mNumber )
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->mNumber = mNumber;
	}

	/*
		Getter : Student First Name
	*/
	string getFirstName()
	{
		return firstName;
	}

	/*
		Getter : Student Last Name
	*/
	string getLastName()
	{
		return lastName;
	}

	/*
		Getter : Student ID Number
	*/
	int getMNumber()
	{
		return mNumber;
	}
};

//Bare bones linked list
class LinkedList
{
private:
	// Node structure with a type definition for pointers
	// To create a node pointer, you can use both Node* or nodePtr
	typedef struct Node
	{
		Student student;
		Node* next;
	}*nodePtr;

	// Pointers
	// Head pointer | Beginning of list
	nodePtr head;

	// Current Pointer | Used to designate current element
	nodePtr curr;

	// Temporary pointer
	nodePtr temp;

public:
	// Declare empty list on constructor
	LinkedList()
	{
		head = NULL;
		curr = NULL;
		temp = NULL;
	}

	// Deconstruct A.K.A delete sys32
	~LinkedList()
	{
		curr = head;
		nodePtr nextNode = NULL;

		while (curr != NULL)
		{
			nextNode = curr->next;
			delete curr;
			curr = nextNode;
		}
		head = NULL;
	}

	// Appends a new node to the list
	void push( const Student& newStudent )
	{
		nodePtr newNode = new Node;
		newNode->student = newStudent;
		newNode->next = NULL;

		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			curr = head;

			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = newNode;
		}
	}
};

//Bubble sort method

//Insertion sort method

//Merge sort method

//Quicksort method

//Heap-sort method

//Counting sort  method

//Radix sort method

//Create random array with values from 0 to 2n

typedef chrono::high_resolution_clock Clock;

int main()
{
	// Initialize seed
	srand( (unsigned)time( 0 ) );

	// Student Class works

	Student s( "John", "Johnson", 123456 );
	cout << s.getFirstName() << " " << s.getLastName() << " " << s.getMNumber() << endl;

	const int numberOfSorts = 7;
	const int sampleSizes[] = { 10, 100, 500, 5000, 250000 };

	int input = 0;

	cout << "1: Bubble" << endl
		<< "2: Insertion" << endl
		<< "3: Merge" << endl
		<< "4: Quick" << endl
		<< "5: Heap" << endl
		<< "6: Counting" << endl
		<< "7: Radix" << endl
		<< "Enter the number of the sort to test: " << endl;

	cin >> input;
	cout << endl;

	for (int j = 0; j < sizeof( sampleSizes ) / sizeof( sampleSizes[0] ); ++j)
	{
		//Create random array from sampleSizes[j]
		int* arr = new int[sampleSizes[j]];

		// Populate Array with random intigers ranging from 0 to 2n where n is the size of array
		for (int i = 0; i < sampleSizes[j]; i++) {
			arr[i] = (rand() % (2 * sampleSizes[j]));
		}

		auto startTime = Clock::now();

		switch (input)
		{
		case 1:
			//Bubble sort
			break;
		case 2:
			//Insertion sort
			break;
		case 3:
			//Merge sort
			break;
		case 4:
			//Quicksort
			break;
		case 5:
			//Heap-sort
			break;
		case 6:
			//Counting sort
			break;
		case 7:
			//Radix sort
			break;

		default:
			cout << "Invalid input" << endl;
			break;
		}

		auto endTime = Clock::now();

		cout << "Sort " << input << " with " << sampleSizes[j] << " values: "
			<< chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count()
			<< " nanoseconds" << endl;

		// cleanup
		delete[] arr;
	}

	return 0;
}
