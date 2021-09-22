# Assignment 1
In this assignment, we are going to be investigating the actual performance of different sorting methods.  Additionally, we will implement 1 sorting method on a linked list.  

# TASKS - WORKLOAD

- 1.)
  - a.	Bubble sort -Travis
  - b.	Insertion sort-Guillermo
  - c.	Merge-sort-Charlie
  - d.	Quicksort-Avery
  - e.	Heap-sort-Travis
  - f.	Counting sort-Avery
  - g.	Radix-sort-Charlie

##### Sort arrays size n= 10,100,500,5000,2500
- 2.) get runtimes on all of these
- 3.) 50 student single link list-Charlie API
  - First Name, Last Name, MNumber and may include any other additional information you wish
  - Bubble sort / merge-sort / quicksort -Charlie Adaptation?
- 4.) Group write-up with instructions:


# Introduction to GitHub and Collaboration with other developers
Before starting to work in this repository there are a few things that one should know for anyone that does not have experience collaborating within GitHub: 

#### Cloning repository
If you don't have it already, I recommend you donwload [Git | Git Bash](https://git-scm.com/downloads) and use the following command to clone the repository:

```bash
git clone https://github.com/Charlie3169/Assignment1.git
```

This will create a copy of the current version of the project wherever you run the above command on your pc.

#### How do you make changes or submit your modfied code to the repository?

After making the changes you need to the repo, you can perform the following commands:

```bash
git status
```
`git status` will let you see the following:

![git status example](https://user-images.githubusercontent.com/46385276/134091485-8059214e-9f0f-41bf-b4fe-5dca0bae9094.png)

- What branch you are working on
- The files that were changed 
- Which files are currently staged and which are not 

Before sending your changes over to the repo, you need to staged them. You do this by using:
```bash
git add .
```

`git add .` will add all changes to staging.

```bash
git commit -m <commit message here>
```

`git commit` will stage these changes and also append a short description to it. This is what `-m` does. After `-m` you would type something relevant to your changes. Take this example:

```bash
git commit -m Add quick sort method
```

##### Oh yeah, another note. The messages are written in present tense. Don't ask me why. I am not sure. This is the standard. 

After staging your changes you are not done yet. You need to send them to the remote repository AKA here.

```bash
git push
```

`git push` will send all of your changes here and the rest of the developers will be able to take a look at it.

#### IMPORTANT NOTE
You must never commit directly to the main branch. Please fork the repository, OR create a new branch

Here are some useful resources:

- [How to fork a repository](https://docs.github.com/en/get-started/quickstart/fork-a-repo)
- [How to create a new branch](https://zepel.io/blog/how-to-create-a-new-branch-in-github/)
- [forking vs branching](https://stackoverflow.com/questions/3611256/forking-vs-branching-in-github)

#### Scope
When making any modifications to a repository while working with other developers, only work within your scope. This means that one should not change or modify code that others would be working on simultaniously as you.

For instance, If I find myself working on an issue that focuses on one method within a class, I should only be coding within that method OR make additions that would not interfere with others.

Ex:

```cpp
class SomeClass {
  private:
  // I can also add variables IF AND ONLY IF these would not break/interfere with other developer's assignments
  public:
    void assignedMethod() {
      // I can only work here
    }
```

It is best to work on separete files, so researching how to **header files** work is highly encoraged.

Here are some useful resources:

- [classes and header files](https://www.learncpp.com/cpp-tutorial/class-code-and-header-files/)
- [geeksforgeeks - header files](https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/)

## Notes
If you are a begginer I highly recommend you getting [GitHub Desktop](https://desktop.github.com/). This will make the process of cloning and branching easier for you.

I will be updating this as necessary.


Regards, 
Heavenly~
