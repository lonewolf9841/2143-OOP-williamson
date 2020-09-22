## H02

- Name: John Williamson
- Date: 21 Sep 2020
- Class: 2143 OOP

## Definitions

#### Abstraction
Abstraction is one of the key concepts of object-oriented programming (OOP) languages. Its main goal is to handle complexity by hiding unnecessary details from the user. That enables the user to implement more complex logic on top of the provided abstraction without understanding or even thinking about all the hidden complexity.

#### Attributes / Properties
Attributes are nothing but the properties of objects in the system.
Example: Employee can have attribute 'name' and 'address' with assigned values as:

1. Simple attributes
Attributes can be of primitive data type such as, integer, string, real etc. which can take literal value.
Example: 'ID' is simple attribute and value is 07.

2. Complex attributes
Attributes which consist of collections or reference of other multiple objects are called as complex attributes.
Example: Collection of Employees consists of many employee names.

3. Reference attributes
Attributes that represent a relationship between objects and consist of value or collection of values are called as reference attributes.
Example: Manager is reference of staff object.

#### Class
In object-oriented programming, a class is a blueprint for creating objects (a particular data structure), providing initial values for state (member variables or attributes), and implementations of behavior (member functions or methods).

The user-defined objects are created using the class keyword. The class is a blueprint that defines a nature of a future object. An instance is a specific object created from a particular class. Classes are used to create and manage new objects and support inheritance—a key ingredient in object-oriented programming and a mechanism of reusing code.

#### Class Variable
Object-oriented programming allows for variables to be used at the class level or the instance level. Variables are essentially symbols that stand in for a value you’re using in a program.

At the class level, variables are referred to as class variables

#### Composition
Composition is one of the fundamental concepts in object-oriented programming. It describes a class that references one or more objects of other classes in instance variables. This allows you to model a has-a association between objects.

You can find such relationships quite regularly in the real world. A car, for example, has an engine and modern coffee machines often have an integrated grinder and a brewing unit.

#### Encapsulation
Encapsulation refers to the bundling of data with the methods that operate on that data, or the restricting of direct access to some of an object's components.[1] Encapsulation is used to hide the values or state of a structured data object inside a class, preventing unauthorized parties' direct access to them

#### Friends
Friend Class A friend class can access private and protected members of other class in which it is declared as friend. It is sometimes useful to allow a particular class to access private members of other class. For example a LinkedList class may be allowed to access private members of Node.

#### Inheritance
Inheritance is the mechanism of basing an object or class upon another object (prototype-based inheritance) or class (class-based inheritance), retaining similar implementation. Also defined as deriving new classes (sub classes) from existing ones such as super class or base class and then forming them into a hierarchy of classes.

#### Instance Variable
An instance variable is a variable defined in a class (i.e. a member variable), for which each instantiated object of the class has a separate copy, or instance. An instance variable is similar to a class variable.[

#### Member Variable
A member variable (sometimes called a member field) is a variable that is associated with a specific object, and accessible for all its methods (member functions). 

#### Method
Methods are functions that belongs to the class.

#### Multiple Inheritance
Multiple inheritance a feature of some object-oriented programming languages in which a class or an object inherits characteristics and properties from more than one parent class or object. This is contrary to the single inheritance property, which allows an object or class to inherit from one specific object or class. Although there are certain benefits associated with multiple inheritance, it does increase ambiguity and complexity when not designed or implemented properly. 

#### Object
In computer science, an object can be a variable, a data structure, a function, or a method, and as such, is a value in memory referenced by an identifier.

In the class-based and object-oriented programming paradigms, object refers to a particular instance of a class, where the object can be a combination of variables, functions, and data structures. 

#### Overloading
In C++, we can make operators to work for user defined classes. This means C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading.

#### Polymorphism
In computer science, it describes the concept that objects of different types can be accessed through the same interface. Each type can provide its own, independent implementation of this interface. It is one of the core concepts of object-oriented programming (OOP).

#### Public / Private / Protected
A public member is accessible from anywhere outside the class but within a program. You can set and get the value of public variables without any member.

A private member variable or function cannot be accessed, or even viewed from outside the class. Only the class and friend functions can access private members.

A protected member variable or function is very similar to a private member but it provided one additional benefit that they can be accessed in child classes which are called derived classes.

#### Virtual
A virtual function is a member function which is declared within a base class and is re-defined(Overriden) by a derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the function.

    Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call.
    They are mainly used to achieve Runtime polymorphism
    Functions are declared with a virtual keyword in base class.
    The resolving of function call is done at Run-time.
