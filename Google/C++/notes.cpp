/* What are the differences between C and C++? */
1. C++ is a kind of superset of C, most of C programs except few exceptions (See this and this) work in C++ as well.
2. C is a procedural programming language, but C++ supports both procedural and Object Oriented programming.
3. Since C++ supports object oriented programming, it supports features like function overloading, templates, inheritance, virtual functions, friend functions. These features are absent in C.
4. C++ supports exception handling at language level, in C exception handling is done in traditional if-else style.
5. C++ supports references, C doesnt.


/* define a custom comparison function */
example: sort number by occurrences

bool cmp(int a, int b) {
    return occurrences[a] < occurrences[b];
}

sort(data.begin(), data.end(), cmp);

NOTE: < generates descendingly sorted result


/* template */
void swap(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void swap(char& x, char& y) {
    char tmp = x;
    x = y;
    y = tmp;
}

void swap(string& x, string& y) {
    string tmp = x;
    x = y;
    y = tmp;
}

// we could use template
template <typename T>
void swap(T& x, T& y) {
    T tmp = x;
    x = y;
    y = tmp;
};

NOTE: C++ templates can make programs "bloated" by increasing the amount of code that needs to be compiled. Remember the three different swap functions we created earlier? Behind the scenes, the C++ compiler is generating all three of those functions: one for ints, one for strings, and one for characters. Using templates saves us time and makes our code shorter, but we're definitely not saving any space.


/* multiple inheritance */
#include<iostream>
using namespace std;

class A {
    public:
        A()  { cout << "A's constructor called" << endl; }
};

class B {
    public:
        B()  { cout << "B's constructor called" << endl; }
};

class C: public B, public A  { // Note the order 
    public:
        C()  { cout << "C's constructor called" << endl; }
};

int main() {
    C c;
    return 0;
}

STDOUT:   
B's constructor called
A's constructor called
C's constructor called

The destructors are called in reverse order of constructors.


/* The default constructor of Person is called. When we use virtual keyword, the default constructor of grandparent class is called by default even if the parent classes explicitly call parameterized constructor. */
#include<iostream>
using namespace std;
class Person {
    public:
        Person(int x)  { cout << "Person::Person(int ) called" << endl;   }
        Person()     { cout << "Person::Person() called" << endl;   }
};

class Faculty : virtual public Person {
    public:
        Faculty(int x):Person(x)   {
            cout<<"Faculty::Faculty(int ) called"<< endl;
        }
};

class Student : virtual public Person {
    public:
        Student(int x):Person(x) {
            cout<<"Student::Student(int ) called"<< endl;
        }
};

class TA : public Faculty, public Student  {
    public:
        TA(int x):Student(x), Faculty(x)   {
            cout<<"TA::TA(int ) called"<< endl;
        }
};

/* use below code to call grandparent's parameterized constructor */
class TA : public Faculty, public Student  {
public:
    TA(int x):Student(x), Faculty(x), Person(x)   {
        cout<<"TA::TA(int ) called"<< endl;
    }
};

int main()  {
    TA ta1(30);
}

NOTE: In general, it is not allowed to call the grandparents constructor directly, it has to be called through parent class. It is allowed only when virtual keyword is used.




/* compiler generating default methods of a class */
- The default constructor with no parameters
- The destructor
- The copy constructor and the assignment operator

All of those generated methods will be generated with the public access specifier

/* How can you force the compiler not to generate the above mentioned methods? */
- Declare and define them yourself: the ones that make sense in your class context. The default no-parameters constructor will not be generated if the class has at least one constructor with parameters declared and defined.
- Declare them private: disallow calls from the outside of the class and DO NOT define them (do not provide method bodies for them): disallow calls from member and friend functions; such a call will generate a linker error.


/* When must you use a constructor initialization list? */
- Constant and reference data members of a class may only be initialized, never assigned, so you must use a constructor initialization list to properly construct (initialize) those members.
- In inheritance, when the base class does not have a default constructor or you want to change a default argument in a default constructor, you have to explicitly call the base class constructor in the initialization list.



/* How can you make sure a C++ function can be called as e.g. void foo(int, int) but not as any other type like void foo(long, long)? */
void foo(int a, int b) {
    // whatever
}
// delete all others through a template
template <typename T1, typename T2> void foo(T1 a, T2 b) = delete;

/* malloc() vs new, free vs delete */
- new is an operator, while malloc() is a function.
- new returns exact data type, while malloc() returns void *.
- new calls constructors( class instances are initalized and deinitialized automatically), while malloc() does not (classes wont get initalized or deinitialized automatically)


/* operator overloading */
#include<iostream>
using namespace std;
 
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}
    Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    void print() { cout << real << " + i" << imag << endl; }
};


// below is global operator function
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}
    void print() { cout << real << " + i" << imag << endl; }
    // The global operator function is made friend of this class so
    // that it can access private members
    friend Complex operator + (Complex const &, Complex const &);
};
 
Complex operator + (Complex const &c1, Complex const &c2) {
     return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"
    c3.print();
    return 0;
}


/* copy constructor */
Point(int x1, int y1) { x = x1; y = y1; }
// Copy constructor
Point(const Point &p2) {x = p2.x; y = p2.y; }

Copy Constructor may be called in following cases:
- When an object of the class is returned by value.
- When an object of the class is passed (to a function) by value as an argument.
- When an object is constructed based on another object of the same class.
- When compiler generates a temporary object.

NOTE: Default constructor does only shallow copy.


/* vtable and vptr */
https://www.quora.com/What-are-vTable-and-VPTR-in-C++



