# Assignment 1
In this assignment, we are going to be investigating the actual performance of different sorting methods.  Additionally, we will implement 1 sorting method on a linked list.  

## Change Log:
This section will state the changes made from the main branch.

#### LinkedList Class
- Small modification to the node Struct:
  - Moved inside of LinkedList as a private member.
  - Added a type definition for easy pointer readability.

- Members:
  - Addition of curr and temp pointers for easier use.

- Methods:
  - Adjusted both constructor and deconstructor to fit current structure.
  - Modified push parameter to accept a Student reference

#### Main
- Additions:
  - Intialized seed for random number generation.
  - Declared a dynamically allocated array for various tests.
  - Populated array with random numbers meeting the provided constraints.
