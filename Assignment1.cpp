#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <string>

using namespace std;

// hi testing
// hello testing
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
// Partition function utilized in quick sort method.
int partition(int array[], int low_index, int high_index) {
  int midpoint = low_index + (high_index - low_index) / 2;
  int pivot = array[midpoint];
  int temp = 0;

  bool find_high_index = false;
  // Finding index of highest element.
  while (!find_high_index) {
    // Checks elements below pivot are less than pivot.
    while (array[low_index] < pivot) {
      low_index += 1;
    }
    // Checks elements above pivot are greater than pivot.
    while (pivot < array[high_index]) {
      high_index -= 1;
    }
    // Ends partitioning if low index and high index move past pivot or meet.
    if (low_index >= high_index) {
      find_high_index = true;
    } else {
      // Continues partitioning by reassigning elements around pivot.
      temp = array[low_index];
      array[low_index] = array[high_index];
      array[high_index] = temp;
      low_index += 1;
      high_index -= 1;
    }
  }
  return high_index;
}


// Quick sort function utilizing partition function.
void quickSort(int array[], int low_index, int high_index) {
  // Continues until low index is greater than high index.
  if (low_index < high_index) {
    // Calls partition function to partition elements around pivot.
    int partition_index = partition(array, low_index, high_index);
    // Uses recursion to sort each partition on either side of pivot.
    quickSort(array, low_index, partition_index - 1);
    quickSort(array, partition_index + 1, high_index);
  }
}

//Heap-sort method

//Counting sort  method
void countSort(int array[], int size) {
  int max = array[0];
  int sorted[size + 1];
  int i = 0;

  // Find max element.
  for (i = 0; i < size; ++i) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  // Declare count array and initialize to zero set.
  int count[max + 1];
  for (i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Find and store the count of each element in array.
  for (i = 0; i < size; ++i) {
    count[array[i]]++;
  }

  // Take index from original array. Use to find element in count array.
  // Copy element into sorted array.
  for (i = size - 1; i >= 0; --i) {
    sorted[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy sorted array to original array.
  for (int i = 0; i < size; ++i) {
    array[i] = sorted[i];
  }
}

//Radix sort method


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
            quickSort(arr, 0, sampleSizes[j]);
			break;
		case 5:
			//Heap-sort
			break;
		case 6:
			//Counting sort
            countSort(arr, sampleSizes[j]);
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
