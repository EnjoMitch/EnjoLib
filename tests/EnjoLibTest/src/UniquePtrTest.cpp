#include "UniquePtrTest.h"
//#include <Template/SafePtr.hpp>
#include <Template/CorradePointer.h>
#include <Template/CorradePointer.h>
#include <Template/SharedPtr.hpp>
#include <Util/CoutBuf.hpp>

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
        LOGL << "Dest::~Dest()\n";
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
    ELO
    Corrade::Containers::Pointer<A> ptr;
    try
    {
        *ptr;
    }
    catch (std::exception & ex)
    {
        LOG << "Successfully thrown\n " << ex.what() << Endl;
    }
    try
    {
        LOG << (*ptr).a << Endl;
        LOG << ptr->a << Endl;
    }
    catch (std::exception & ex)
    {
        LOG << "Successfully thrown\n " << ex.what() << Endl;
    }
    Corrade::Containers::Pointer<A> barePtr = FactoryPolimorpmTest();
    try
    {
        *barePtr;
    }
    catch (std::exception & ex)
    {
        // Doesn't reach this!
        LOG << "Successfully thrown polimorph\n " << ex.what() << Endl;
    }

    ptr = Corrade::Containers::Pointer<A>(new A());
    LOG << "Val = " << ptr->a << Endl;

    {
        Corrade::Containers::Pointer<Dest> pdest = Corrade::Containers::Pointer<Dest>(new Dest);
    }
    LOG << "~Dest should have been called\n";

    {
        SharedPtr<Dest> pdest = SharedPtr<Dest>(new Dest);
    }
    LOG << "~Dest should have been called\n";
    }
    
    
void TestCorrade()
    {
        ELO
        Pointer<A> ptr;
    try
    {
        *ptr;
    }
    catch (std::exception & ex)
    {
        LOG << "Successfully thrown\n " << ex.what() << Endl;
    }
    try
    {
        LOG << (*ptr).a << Endl;
        LOG << ptr->a << Endl;
    }
    catch (std::exception & ex)
    {
        LOG << "Successfully thrown\n " << ex.what() << Endl;
    }
    Pointer<A> barePtr = FactorySafeTest();
    try
    {
        *barePtr;
    }
    catch (std::exception & ex)
    {
        // Doesn't reach this!
        LOG << "Successfully thrown polimorph\n " << ex.what() << Endl;
    }

    ptr = Pointer<A>(new A());
    LOG << "Val = " << ptr->a << Endl;

    {
        Pointer<Dest> pdest = Pointer<Dest>(new Dest);
        //Pointer<Dest> pdest(Pointer<Dest>(new Dest));
    }
    LOG << "~Dest should have been called\n";
}

UniquePtrTest::~UniquePtrTest(){}
UniquePtrTest::UniquePtrTest()
{
    TestUnique();
    TestCorrade();
}

