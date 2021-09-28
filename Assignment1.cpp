#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

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

	Student()
	{
		firstName = "";
		lastName = "";
		mNumber = 0;
	}

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

	nodePtr curr;
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
		nodePtr n = new Node;

		n->next = NULL;
		n->student = newStudent;

		if (head != NULL)
		{
			curr = head;

			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = n;
		}
		else
		{
			head = n;
		}
	}

	void getStudentData( string const fileName )
	{
		ifstream studentFile( fileName );

		if (studentFile.is_open())
		{
			string firstName, lastName, mNum;
			int mNumber;

			while (!studentFile.eof())
			{
				studentFile >> firstName >> lastName >> mNum;

				mNumber = stoi( mNum );

				Student newStudent( firstName, lastName, mNumber );
				push( newStudent );
			}

			studentFile.close();
		}
		else
		{
			cout << "Failed to load data..." << endl;
		}
	}

	void printData()
	{
		curr = head;

		while (curr != NULL)
		{
			string name = curr->student.getFirstName() + " " + curr->student.getLastName();

			cout << name << " " << curr->student.getMNumber() << endl;

			curr = curr->next;
		}
	}
};

//Bubble sort method

//Insertion sort method
////////////////////////////////////////////////////////////
void insertionSort( int array[], int const arraySize )
{
	int j, temp = 0;

	for (int i = 1; i < arraySize; i++)
	{
		j = i;

		while (j > 0 && array[j] < array[j - 1])
		{
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j -= 1;
		}
	}
}
////////////////////////////////////////////////////////////

//Merge sort method
////////////////////////////////////////////////////////////
void merge( int array[], int const left, int const mid, int const right )
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	int indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
	{
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
		{
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of left[], if there are any
	while (indexOfSubArrayOne < subArrayOne)
	{
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo)
	{
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort( int array[], int const begin, int const end )
{
	if (begin >= end)
		return; // Returns recursively

	int mid = begin + (end - begin) / 2;
	mergeSort( array, begin, mid );
	mergeSort( array, mid + 1, end );
	merge( array, begin, mid, end );
}
////////////////////////////////////////////////////////////

//Quicksort method
////////////////////////////////////////////////////////////

// Partition function utilized in quick sort method.
int partition( int array[], int low_index, int high_index ) {
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
		}
		else {
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
void quickSort( int array[], int low_index, int high_index ) {
	// Continues until low index is greater than high index.
	if (low_index < high_index) {
		// Calls partition function to partition elements around pivot.
		int partition_index = partition( array, low_index, high_index );
		// Uses recursion to sort each partition on either side of pivot.
		quickSort( array, low_index, partition_index - 1 );
		quickSort( array, partition_index + 1, high_index );
	}
}
////////////////////////////////////////////////////////////

//Heap-sort method

//Counting sort  method
////////////////////////////////////////////////////////////
void countSort( int array[], int size ) {
	int max = array[0];
	int* sorted = new int[size + 1];
	int i = 0;

	// Find max element.
	for (i = 0; i < size; ++i) {
		if (array[i] > max) {
			max = array[i];
		}
	}

	// Declare count array and initialize to zero set.
	int* count = new int[max + 1];
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
////////////////////////////////////////////////////////////

//Radix sort method
////////////////////////////////////////////////////////////

int getMax( int arr[], int n )
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void helperSort( int arr[], int n, int exp )
{
	int* output = new int[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixSort( int arr[], int n )
{
	int m = getMax( arr, n );

	for (int exp = 1; m / exp > 0; exp *= 10)
		helperSort( arr, n, exp );
}
////////////////////////////////////////////////////////////

typedef chrono::high_resolution_clock Clock;

int main()
{
	// Initialize seed
	srand( (unsigned)time( 0 ) );

	const int numberOfSorts = 7;
	const int sampleSizes[] = { 10, 100, 500, 5000, 250000 };

	int input = 0;
	string algoPicked;

	cout << "1: Bubble" << endl
		<< "2: Insertion" << endl
		<< "3: Merge" << endl
		<< "4: Quick" << endl
		<< "5: Heap" << endl
		<< "6: Counting" << endl
		<< "7: Radix" << endl
		<< "Enter the number of the sort to test: ";

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
			algoPicked = "Bubble";
			break;
		case 2:
			insertionSort( arr, sampleSizes[j] );
			algoPicked = "Insertion";
			break;
		case 3:
			//Merge sort
			mergeSort( arr, 0, sampleSizes[j] - 1 );
			algoPicked = "Merge";
			break;
		case 4:
			//Quicksort
			quickSort( arr, 0, sampleSizes[j] );
			algoPicked = "Quick";
			break;
		case 5:
			//Heap-sort
			algoPicked = "Heap";
			break;
		case 6:
			//Counting sort
			countSort( arr, sampleSizes[j] );
			algoPicked = "Counting";
			break;
		case 7:
			//Radix sort
			radixSort( arr, sampleSizes[j] );
			algoPicked = "Radix";
			break;

		default:
			cout << "Invalid input" << endl;
			break;
		}

		auto endTime = Clock::now();

		cout << algoPicked << " Sort " << "with " << sampleSizes[j] << " values: "
			<< chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count()
			<< " nanoseconds" << endl;

		// cleanup
		delete[] arr;
	}

	return 0;
}