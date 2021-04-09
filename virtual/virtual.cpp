#include <iostream>

namespace single
{
  class Base
  {
  public:
    Base(long i) : base(i)
    {}
    virtual void print(void)
    {
      std::cout << "Inside Base::print() function\n";
    }
    virtual void scan(void)
    {
      std::cout << "Inside Base::scan()  function\n";
    }
    virtual ~Base(void)
    { }

    long base;
  };

  class Derived : public Base
  {
  public:
    Derived(long i) :
      Base(i*2),
      derived(i)
    {}
    virtual void print(void)
    {
      std::cout << "Inside Derived::print() function\n";
    }
    virtual void scan(void)
    {
      std::cout << "Inside Derived::scan()  function\n";
    }
    virtual void send(void)
    {
      std::cout << "Inside Derived::send()  function\n";
    }
    virtual ~Derived(void)
    { }

    long derived;
  };
}

namespace multiple
{
  class BaseOne
  {
  public:
    BaseOne(long i) : base1(i)
    {}
    virtual void print(void)
    {
      std::cout << "Inside BaseOne::print() function\n";
    }
    virtual void scan(void)
    {
      std::cout << "Inside BaseOne::scan()  function\n";
    }
    virtual ~BaseOne(void)
    { }

    long base1;
  };

  class BaseTwo
  {
  public:
    BaseTwo(long i) : base2(i)
    {}
    virtual void set(void)
    {
      std::cout << "Inside BaseTwo::set()   function\n";
    }
    virtual void get(void)
    {
      std::cout << "Inside BaseTwo::get()   function\n";
    }
    virtual ~BaseTwo(void)
    { }

    long base2;
  };

  class Derived : public BaseOne,
                  public BaseTwo
  {
  public:
    Derived(long i) :
      BaseOne(i*2),
      BaseTwo(i*3),
      derived(i)
    {}
    virtual void print(void)
    {
      std::cout << "Inside Derived::print() function\n";
    }
    virtual void scan(void)
    {
      std::cout << "Inside Derived::scan()  function\n";
    }
    virtual void set(void)
    {
      std::cout << "Inside Derived::set()   function\n";
    }
    virtual void get(void)
    {
      std::cout << "Inside Derived::get()   function\n";
    }
    virtual void send(void)
    {
      std::cout << "Inside Derived::send()  function\n";
    }
    virtual ~Derived(void)
    { }

    long derived;
  };
}

int main(void)
{
  using pointer_type = long*;
  using function_type = void(*)(void);

  std::cout << "The size of a pointer type is: " << sizeof(pointer_type) << "\n";
  std::cout << "The size of a data type is:    " << sizeof(long) << "\n\n";

  // Access the virtual functions of the Base class with vptr
  {
    using namespace single;

    std::cout << "Test the Base class virtual functions...\n";

    Base b(1000);
    std::cout << "The size of b is: " << sizeof(Base) << "\n";

    // &b is the address of the object b
    // the first sizeof(pointer_type) bytes is the address of the virtual table
    pointer_type vptrAddress = (pointer_type)&b;
    std::cout << "The address of the virtual table is " << vptrAddress << "\n";

    // referencing the virtual table address, *(pointer_type)(&b))
    // gives the address of the first virtual function
    function_type fptr = (function_type)*((pointer_type)(*(pointer_type)(&b)));
    std::cout << "Calling Base::print() by its address:      ";
    fptr();

    // by adding an offset of 1, get the address of the second virtual function
    fptr = (function_type)*((pointer_type)(*(pointer_type)(&b)) + 1);
    std::cout << "Calling Base::scan()  by its address:      ";
    fptr();

    // by adding an offset of 2, get the address of the virtual destructor
    // cannot be invoked, though
    fptr = (function_type)*((pointer_type)(*(pointer_type)(&b)) + 2);
    std::cout << "Calling Base::~Base() by its address:      \n";

    // by adding an offset of 3, get the address of the member variable
    long member = *((pointer_type)(&b) + 1);
    std::cout << "Calling Base::base    by its address:      " << member << "\n";

    std::cout << "\n";
  }

  // Access the virtual functions of the Derived class with vptr
  {
    using namespace single;

    std::cout << "Test the single inheritance Derived class virtual functions...\n";

    Derived d(1000);
    std::cout << "The size of d is: " << sizeof(Derived) << "\n";

    long* vptrAddress = (long*)&d;
    std::cout << "The address of the virtual table is " << vptrAddress << "\n";

    function_type fptr;
    fptr = (function_type)*((pointer_type)(*(pointer_type)(&d)));
    std::cout << "Calling Derived::print()     by its address:   ";
    fptr();

    fptr = (function_type)*((pointer_type)(*(pointer_type)(&d)) + 1);
    std::cout << "Calling Derived::scan()      by its address:   ";
    fptr();

    fptr = (function_type)*((pointer_type)(*(pointer_type)(&d)) + 4);
    std::cout << "Calling Derived::send()      by its address:   ";
    fptr();

    long member = *((pointer_type)(&d) + 1);
    std::cout << "Calling Base::base           by its address:   " << member << "\n";

    member = *((pointer_type)(&d) + 2);
    std::cout << "Calling Derived::derived     by its address:   " << member << "\n";

    std::cout << "\n";
  }

  // Access the virtual functions of the Derived class with vptr
  {
    using namespace multiple;

    std::cout << "Test the multiple inheritance Derived class virtual functions...\n";

    Derived d(1000);
    std::cout << "The size of d is: " << sizeof(Derived) << "\n";

    long* vptrAddress = (long*)&d;
    std::cout << "The address of the virtual table is " << vptrAddress << "\n";

    function_type fptr = (function_type)*((pointer_type)(*(pointer_type)(&d)));
    std::cout << "Calling Derived::print() by its address:   ";
    fptr();

    fptr = (function_type)*((pointer_type)(*(pointer_type)(&d)) + 1);
    std::cout << "Calling Derived::scan()  by its address:   ";
    fptr();

    long member = *((pointer_type)(&d) + 1);
    std::cout << "Calling BaseOne::base1   by its address:      " << member << "\n";

    fptr = (function_type)*((pointer_type)(*(pointer_type)(&d)) + 4);
    std::cout << "Calling Derived::set()   by its address:   ";
    fptr();

    fptr = (function_type)*((pointer_type)(*(pointer_type)(&d)) + 5);
    std::cout << "Calling Derived::get()   by its address:   ";
    fptr();

    fptr = (function_type)*((pointer_type)(*(pointer_type)(&d)) + 6);
    std::cout << "Calling Derived::send()  by its address:   ";
    fptr();

    member = *((pointer_type)(&d) + 3);
    std::cout << "Calling BaseTwo::base2   by its address:      " << member << "\n";

    member = *((pointer_type)(&d) + 4);
    std::cout << "Calling Derived::derived by its address:      " << member << "\n";

    std::cout << "\n";
  }

  return 0;
}
