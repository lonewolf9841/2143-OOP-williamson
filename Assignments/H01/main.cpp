///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           John Williamson
// Email:            john.c.williamson88@gmail.com
// Label:            H01
// Title:            Proper Code Commenting
// Course:           CMPS 2143
// Semester:         FALL 2020
//
// Description:
//       describe program here thoroughly 
//
// Usage:
//         N/A
//
// Files:  
//         main.cpp
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int A[100];   //global array with constant size of 100

/*************************************** 
* Struct: Node
*
* Description:
*        A linked list node that holds integers
*
*        int data    : holds integers for list
*        Node* next  : pointer that points the next node
*
* Methods:
*        Node(int)   : initializes the node
*
****************************************/

struct Node
{
    int x;
    Node* next;
    Node()
    {
        x = -1;
        next = NULL;
    }
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

/**
 * Class: List
 *
 * Description:
 *
 *      This class creates a linked list that allows the
 *      user to add integers to the end of the list
 *      or insert them into the middle. The list can
 *      can also print its contents or display them as
 *      if it were an array.
 *
 * Public Methods:
 *
 *                       List()
 *     - void            Push(int val)
 *     - void            Insert(int val) 
 *     - void            PrintTail()
 *     - string          Print()
 *     - int             Pop() NOT IMPLIMENTED
 *     - List            operator+(const List& Rhs)
 *     - int             operator[](int index)
 *     - friend          ostream& operator<<(ostream& os, List L)
 *
 * Private Methods:
 *
 *     - None
 *
 * Usage:
 *     List L1;
 *     List L2;
 *     L1.Push(i); 
 *     L2.Push(i); 
 *     L1.PrintTail();
 *     L2.PrintTail();
 *     List L3 = L1 + L2;
 */

class List
{        
private:
    Node* Head;  //pointer to head (beginning) of list
    Node* Tail;  //pointer to tail (end) of list
    int Size;    //size of list

public:
    /**
    * Constructor
    */
    List()
    {
        Head = Tail = NULL;  //intialize head and tail to NULL
        Size = 0;            //iniialize size to 0
    }

 /***********************************************
 * Public: Push
 *
 * Description:
 *         Adds an integer to the end of the list
 *
 * Params:
 *         int val : number to be put into list
 *         
 * Returns:
 *         void
 *
 ************************************************/

    void Push(int val)
    {
        // allocate new memory and init node
        Node* Temp = new Node(val);

        //if head and tail are empty
        //ponit both to temp
        if (!Head && !Tail)        
        {
            Head = Tail = Temp;
        }
        //link node to temp
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;                   //increment size by one
    }

/***********************************************
* Public: Insert
*
* Description:
*         Adds an integer to the middle of the list
*
* Params:
*         int val : number to be put into list
*
* Returns:
*         void
*
************************************************/
    void Insert(int val)
    {
        // allocate new memory and init node
        Node* Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }

/***********************************************
* Public: PrintTail
*
* Description:
*         Prints the number contained at the end of the list
*         to the screen
*
* Params:
*         None
*
* Returns:
*         void
*
************************************************/
    void PrintTail()
    {
        cout << Tail->x << endl;
    }

/***********************************************
* Public: Print
*
* Description:
*         Prints all the numbers contained in the list
*         to the screen as a string
*
* Params:
*         None
*
* Returns:
*         string : the contents of the list in the as
*                  a string
*
************************************************/
    string Print()
    {
        Node* Temp = Head;
        string list;

        while (Temp != NULL)
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

/***********************************************
* Public: Pop
*
* Description:
*        CURRENTLY NOT IMPLIMENTED
*
* Params:
*         None
*
* Returns:
*         int
*
************************************************/
    int Pop()
    {
        Size--;
        return 0; 
    }

/***********************************************
* Public: operator+
*
* Description:
*        CURRENTLY NOT IMPLIMENTED
*
* Params:
*        const List& :passed by reference
*
* Returns:
*        List : a new list comprised of two other lists
*
************************************************/
    List operator+(const List& Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node* Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }
/***********************************************
* Public: operator[]
*
* Description:
*        Returns int value as if the list were an array
*
* Params:
*         int index
*
* Returns:
*         int : value and selected node
*
************************************************/
    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index)
    {
        Node* Temp = Head;

        //out of bounds testing
        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }

        //goes to indexed node and returns value
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

/***********************************************
* Public: operator<<
*
* Description:
*        Returns int value as if the list were an array
*
* Params:
*         ostream& os
*         List L
*
* Returns:
*         os 
*
************************************************/
    friend ostream& operator<<(ostream& os, List L)
    {
        os << L.Print();
        return os;
    }
};

int main(int argc, char** argv)
{
    List L1;                        //create class "L1"
    List L2;                        //create class "L2"

    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);                //add numbers 0-24 to list
    }

    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);                //add numbers 50-99 to list
    }

    //cout << L1 << endl;
    L1.PrintTail();               //print list L1
    L2.PrintTail();               //print list L2

    List L3 = L1 + L2;           //create new class "L3" by adding L1 and L2
    cout << L3 << endl;

    cout << L3[5] << endl;      //display contents of the 5th position of L3
    return 0;
}