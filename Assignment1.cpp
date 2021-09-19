#include <iostream>
#include <iomanip>
#include <chrono> 
#include <cstdlib>
#include <string>

using namespace std;

class Student
{
    private:
        string firstName;
        string lastName;
        int mNumber;
        
    public:

        Student(){}

        Student(string firstName, string lastName, int mNumber)
        {
            this->firstName = firstName;
            this->lastName = lastName;
            this->mNumber = mNumber;
        }

        string getFirstName()
		{
			return firstName;
		}

        string getLastName()
		{
			return lastName;
		}

        int getMNumber()
        {
            return mNumber;
        }
       
};

struct Node
{       
    Student student;
    Node *next;     
};


//Bare bones linked list
class LinkedList
{
    private:
        Node* head; 
    
    public:
        LinkedList()
        {   
            head = NULL;
        }

        ~LinkedList()
        {   
            //Might need this idk
        }
    
        void push(Student newStudent)
        {
            Node* newNode = new Node();
            newNode->student = newStudent;
            newNode->next = NULL;

            if(head == NULL)
            {
                head = newNode;
            }
            else
            {
                Node* currentNode = head;
                while (currentNode->next != NULL)
                {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
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
    //The student class isn't working for me and I have no clue why
    //It doesn't seem to be able to see it or something

    //Student s("John", "Johnson", 123456);
    //cout << s.getFirstName << " " << s.getLastName << " " << s.getMNumber << endl;

        
    const int numberOfSorts = 7;
    const int sampleSizes[] = {10, 100, 500, 5000, 250000};
    
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
    
    for(int j = 0; j < sizeof(sampleSizes)/sizeof(sampleSizes[0]); ++j)
    {
        //Create random array from sampleSizes[j]

        auto startTime = Clock::now();
        
        switch(input)
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
        
    }

    



    



    return 0;

}
