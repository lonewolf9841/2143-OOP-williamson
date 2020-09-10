///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Terry Griffin
// Email:            terry.griffin@msutexas.edu
// Label:            L02
// Title:            Array Based Stack Example
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//       Example implementation of an array based stack that holds integers.
//
// Usage:
//       Nothing special right now.
//
// Files:            
//       None
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * Stack
 *
 * Description:
 *      Integer array based stack implementation
 *
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 *
 * Private Methods:
 *      - None
 *
 * Usage:
 *
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *
 */
class Stack 
{
private:
    int* stack;       //array pointer
    int capacity; //max stack size
    int top;      //current top (index)
    int size;     //current num items
public:
    /**
     * Stack:
     *    Constructor.
     * Params:
     *    void
     *
     * Returns:
     *     Void
     */
    Stack() 
    {
        capacity = 10;          // set array size
        stack = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }

    /**
     * Stack:
     *    Constructor.
     * Params:
     *    int : capacity
     *
     * Returns:
     *     Void
     */
    Stack(int cap) 
    {
        capacity = cap;         // set array size      
        stack = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }

    /**
     * Push:
     *    Push item onto stack.
     * Params:
     *    int : data
     *
     * Returns:
     *     Void
     */
    void Push(int data) 
    {
        if (Full())                        //checking if array is already full
        //resizes if array full
        {
            int* biggerStack = new int[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                biggerStack[i] = stack[i];     //copy old array items to new array
            }
            delete[] stack;                    //delete old array
            stack = biggerStack;               //adjust pointer to new array
            capacity = capacity * 2;           //change capacity to twice original size
        }
        //normal action if array isn't full
        top++;              // move top of stack up
        size++;             // increment size
        stack[top] = data;      // add item to array
    }

    /**
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     *
     * Returns:
     *     int
     */
    int Pop()
    {
        if (Empty())
        {
            cout << "Error: Stack empty!\n";
                return -1;
        }
        int data = stack[top];  // pull item from stack
        top--;              // shrink the stack
        size--;             // update our size  
        return data;        // send item back
    }

    /**
     * Empty:
     *    is the stack empty?
     * Params:
     *    void
     *
     * Returns:
     *     bool : true == stack is empty
     */
    bool Empty() {
        //return size == 0;
        return top == -1;
    }

    /**
     * Full:
     *    is the stack full?
     * Params:
     *    void
     *
     * Returns:
     *     bool : true == stack is full
     */
    bool Full() {
        return top == capacity - 1;
    }

    /**
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     *
     * Returns:
     *     void
     */
    void Print() {
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }

    /**
     * Overloaded ostream <<
     *    Lets us print a stack using cout
     * Params:
     *    ostream &os   : instance of ostream passed in by reference
     *    const Stack   : instance of stack passed in using const so
     *                    it cannot be changed
     *
     * Returns:
     *     ostream
     */
    friend ostream& operator<<(ostream& os, const Stack s) {
        for (int i = s.top; i >= 0; i--) {
            os << s.stack[i] << endl;
        }
        return os;
    }
};

int main()
{
    Stack Stack_1;           // calls default constructor
    ifstream infile;                        //read input file
    infile.open("input.txt");
    string PushOrPop;                    
    int value;                              
    while (infile >> PushOrPop)            
    {
        if (PushOrPop == "push")            //reads push
        {
            infile >> value;                 
            Stack_1.Push(value);            //pushes value to stack
        }
        if (PushOrPop == "pop")            //reads pop
        {
            Stack_1.Pop();                 //pops that shit
        }
    }
   
    infile.close();                         //close file
    Stack_1.Print();                              //prints stack values to screen

    return 0;
}
