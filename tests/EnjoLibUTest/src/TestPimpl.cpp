#include "pch_test.h"

#include "TestPimpl.h"
#include "PimplT.hpp"
#include <Util/VecD.hpp>
#include <UnitTest++/UnitTest++.h>

using namespace EnjoLib;

TEST(Pimpl_1)
{
    Pimp pmp3;
    Pimp pmp;
    //Pimp pmp2 = pmp;  // Should fail
    //pmp3 = pmp;       // Should fail
    pmp.Dat();
    CHECK(true);
}

TEST(PimpNotInit_2)
{
    PimpNotInit pmp;
    //pmp.Dat();
}

TEST(PimpNotInit_1)
{
    PimpNotInit pmp;
    try
    {
       pmp.Dat();
       CHECK(false); // Shouldn't reach here.
    }
    catch(std::exception & ex)
    {
        CHECK(true);
    }
}

TEST(Pimpl_Copy1)
{
    PimpCpy pmp3;
    PimpCpy pmp;
    PimpCpy pmp2 = pmp;  
    pmp3 = pmp;       
    pmp.Dat();
    pmp2.Dat();
    pmp3.Dat();
    CHECK(true);
}

TEST(Pimpl_Copy_check)
{
    PimpCpy pmp3;
    PimpCpy pmp;
    pmp.RW() = 10;
    PimpCpy pmp2 = pmp; 
    CHECK_EQUAL(pmp.Dat(), pmp2.Dat());
    CHECK(pmp.Dat() != pmp3.Dat());
    pmp3 = pmp; 
    CHECK_EQUAL(pmp.Dat(), pmp3.Dat());      
    CHECK(true);
}

struct CalcRet
{
    EnjoLib::VecD coeffsA;
    EnjoLib::VecD coeffsASmooth;
    EnjoLib::VecD coeffsAChange;

    bool IsValid() const
    {
        return coeffsA.size() > 3;
    }
};

static CalcRet CalcLocal()
{
    CalcRet ret;
    return ret;
}

TEST(VecCheck)
{
    const CalcRet & calc = CalcLocal();
    calc.coeffsASmooth.size();
    CHECK(true);
}

