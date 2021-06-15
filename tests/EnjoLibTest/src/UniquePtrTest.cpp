#include "UniquePtrTest.h"
//#include <Template/SafePtr.hpp>
#include <Template/CorradePointer.h>
#include <Template/CorradePointer.h>
#include <Template/SharedPtr.hpp>

#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;
using namespace Corrade::Containers;
//Containers;

struct A
{
    float a = 5;
};
struct Dest
{
    virtual ~Dest()
    {
        cout << "Dest::~Dest()\n";
    }
    float a = 5;
};

Corrade::Containers::Pointer<A> FactoryPolimorpmTest()
{
    return Corrade::Containers::Pointer<A>(nullptr);
}

Pointer<A> FactorySafeTest()
{
    return Pointer<A>(nullptr);
}

static void TestUnique()
{
    Corrade::Containers::Pointer<A> ptr;
    try
    {
        *ptr;
    }
    catch (std::exception & ex)
    {
        cout << "Successfully thrown\n " << ex.what() << endl;
    }
    try
    {
        cout << (*ptr).a << endl;
        cout << ptr->a << endl;
    }
    catch (std::exception & ex)
    {
        cout << "Successfully thrown\n " << ex.what() << endl;
    }
    Corrade::Containers::Pointer<A> barePtr = FactoryPolimorpmTest();
    try
    {
        *barePtr;
    }
    catch (std::exception & ex)
    {
        // Doesn't reach this!
        cout << "Successfully thrown polimorph\n " << ex.what() << endl;
    }

    ptr = Corrade::Containers::Pointer<A>(new A());
    cout << "Val = " << ptr->a << endl;

    {
        Corrade::Containers::Pointer<Dest> pdest = Corrade::Containers::Pointer<Dest>(new Dest);
    }
    cout << "~Dest should have been called\n";

    {
        SharedPtr<Dest> pdest = SharedPtr<Dest>(new Dest);
    }
    cout << "~Dest should have been called\n";
    }
    
    
void TestCorrade()
    {

        Pointer<A> ptr;
    try
    {
        *ptr;
    }
    catch (std::exception & ex)
    {
        cout << "Successfully thrown\n " << ex.what() << endl;
    }
    try
    {
        cout << (*ptr).a << endl;
        cout << ptr->a << endl;
    }
    catch (std::exception & ex)
    {
        cout << "Successfully thrown\n " << ex.what() << endl;
    }
    Pointer<A> barePtr = FactorySafeTest();
    try
    {
        *barePtr;
    }
    catch (std::exception & ex)
    {
        // Doesn't reach this!
        cout << "Successfully thrown polimorph\n " << ex.what() << endl;
    }

    ptr = Pointer<A>(new A());
    cout << "Val = " << ptr->a << endl;

    {
        Pointer<Dest> pdest = Pointer<Dest>(new Dest);
        //Pointer<Dest> pdest(Pointer<Dest>(new Dest));
    }
    cout << "~Dest should have been called\n";
}

UniquePtrTest::~UniquePtrTest(){}
UniquePtrTest::UniquePtrTest()
{
    TestUnique();
    TestCorrade();


}

