#include <iostream>

namespace
{
  class Base
  {
  public:
    Base(int i) : base(i)
    {}
    virtual void print(void)
    {
      std::cout << "Inside Base::print() function\n";
    }
    virtual void set(void)
    {
      std::cout << "Inside Base::set() function\n";
    }
    virtual ~Base() = default;
  private:
    int base;
  };

  class Derived : public Base
  {
  public:
    Derived(int i) :
      Base(i*2),
      derived(i)
    {}
    virtual void print(void)
    {
      std::cout << "Inside Derived::print() function\n";
    }
    virtual void set(void)
    {
      std::cout << "Inside Derived::set() function\n";
    }
    virtual ~Derived() = default;
  private:
    int derived;
  };
}

int main(void)
{
  {
    std::cout << "Test the Base class virtual functions...\n";

    Base b(1000);
    long* vptrAddress = (long*)&b;
    std::cout << "The address of the virtual table is " << vptrAddress << "\n";

    typedef void (*func)(void);
    func fptr = (func)*((long*)(*(long*)(&b)));
    std::cout << "Calling Base::print() by its address: ";
    fptr();

    fptr = (func)*((long*)(*(long*)(&b)) + 1);
    std::cout << "Calling Base::set() by its address: ";
    fptr();

    std::cout << "\n";
  }

  {
    std::cout << "Test the Derived class virtual functions...\n";

    Derived d(1000);
    long* vptrAddress = (long*)&d;
    std::cout << "The address of the virtual table is " << vptrAddress << "\n";

    typedef void (*func)(void);
    func fptr = (func)*((long*)(*(long*)(&d)));
    std::cout << "Calling Derived::print() by its address: ";
    fptr();

    fptr = (func)*((long*)(*(long*)(&d)) + 1);
    std::cout << "Calling Derived::set() by its address: ";
    fptr();

    std::cout << "\n";
  }

  return 0;
}