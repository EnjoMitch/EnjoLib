#include "pch_test.h"

#include <UnitTest++/UnitTest++.h>

#include <Util/AlgoSTDIVec.hpp>
#include <Util/VecF.hpp>
#include <Util/CoutBuf.hpp>
#include <Template/Array.hpp>
#include <STD/VectorCpp.hpp>

#include <utility>

using namespace EnjoLib;

class BlaArray
{
    public:
    BlaArray(int i = 0) 
    : val(i)
    {}
    virtual ~BlaArray(){}
    
    int val;
};

static Array<BlaArray> RetArrOne(int val)
{
    //BlaArray val(1);
    //Array<BlaArray> arrOne(val);
    return BlaArray(val);
}

static Array<BlaArray> RetArrEmpty()
{
    return Array<BlaArray>();
}

static Array<BlaArray> RetArrEmptyLocal()
{
    Array<BlaArray> ret;
    return ret;
}

static Array<float> RetArrTwo(int val)
{
    //BlaArray val(1);
    std::vector<float> ret;
    ret.push_back(val);
    ret.push_back(val);
    return ret;
}

TEST(Array_0)
{
    VecF data = std::vector<float>{2, 0, 1};
    AlgoSTDIVec<float>().Sort(&data);
    CHECK_EQUAL(data.at(0), 0);
    CHECK_EQUAL(data.at(1), 1);
    CHECK_EQUAL(data.at(2), 2);
}


TEST(Array_init)
{
    Array<float> arr;
    
    VecF data = std::vector<float>{2, 0, 1};
    //arr.Init(data.data(), data.size());
    arr.InitContainer(data);
    int i = 0;
    CHECK_EQUAL(data.at(i), arr.at(i)); ++i;
    CHECK_EQUAL(data.at(i), arr.at(i)); ++i;
    CHECK_EQUAL(data.at(i), arr.at(i)); ++i;
    
    const float modd = 5;
    const int idxMod = 1;
    arr.atw(idxMod) = modd;
}


TEST(Array_rw)
{
    Array<float> arr;
    VecF data = std::vector<float>{2, 0, 1};
    //arr.Init(data.data(), data.size());
    arr.InitContainer(data);
    
    const float modd = 5;
    const int idxMod = 1;
    arr.atw(idxMod) = modd;
    
    CHECK_EQUAL(data.at(0), arr.at(0));
    CHECK_EQUAL(modd, arr.at(idxMod));
}


TEST(Array_copy)
{
    Array<float> arr;
    VecF data = std::vector<float>{2, 0, 1};
    //arr.Init(data.data(), data.size());
    arr.InitContainer(data);
    
    Array<float> arr2 = arr;
    
    const int idxMod = 1;
    
    for (unsigned ii = 0; ii < arr2.size(); ++ii)
    {
        //LOGL << "arr2[" << ii << "] = " << arr2.at(ii) << NL3;
    }
    
    CHECK_EQUAL(arr.at(0), arr2.at(0));
    CHECK_EQUAL(arr.at(idxMod), arr2.at(idxMod));
    CHECK_EQUAL(arr.at(2), arr2.at(2));
    
    const float modd = 5;
    
    arr2.atw(idxMod) = modd;
    
    CHECK_EQUAL(data.at(0), arr.at(0));
    CHECK_EQUAL(arr.at(0), arr2.at(0));
    CHECK(arr.at(idxMod) != arr2.at(idxMod));
    CHECK_EQUAL(arr.at(2), arr2.at(2));
}

TEST(Array_iterators)
{
    VecF data = std::vector<float>{2, 0, 1};
    Array<float> arr(data);
    
    int i = 0;
    for (const auto & val : arr)
    {
        CHECK_EQUAL(data.at(i), val); ++i;
    }
}

TEST(Array_deleter) // TODO: not complete. Complete in tf
{
    struct Bla
    {
        
    };
    std::vector<Bla> data(3);
    Array<Bla> arr(data);
    
    Array<Bla> arr2;
    arr2 = arr;
    
    //int i = 0;
    for (const auto & val : arr)
    {
        (void)val;
        //CHECK_EQUAL(data.at(i), val); ++i;
    }
}

TEST(Array_one_element)
{
    float val = 1;
    Array<float> arrEmp;
    Array<float> arrOne(val);
    
    CHECK_EQUAL(true,  arrEmp.empty());
    CHECK_EQUAL(false, arrOne.empty());
    CHECK_EQUAL(val,   arrOne.at(0));
    CHECK_EQUAL(1,     arrOne.size());
}

TEST(Array_one_element_no_def_constructor)
{
    struct Bla
    {
        Bla(int i = 0) {}
    };
    Bla val(1);
    Array<Bla> arrOne(val);
    CHECK_EQUAL(false, arrOne.empty());
    CHECK_EQUAL(1,     arrOne.size());
}

TEST(Array_one_element_copy)
{
    const int val = 2;
    Array<BlaArray> arr2 = RetArrOne(val);
    //arr2 = std::move(arrOne);
    CHECK_EQUAL(false, arr2.empty());
    CHECK_EQUAL(1,     arr2.size());
    CHECK_EQUAL(val,   arr2.at(0).val);
}

TEST(Array_ret_empty)
{
    Array<BlaArray> arr2 = RetArrEmpty();
    //arr2 = std::move(arrOne);
    CHECK_EQUAL(true,  arr2.empty());
    CHECK_EQUAL(0,     arr2.size());
    //CHECK_EQUAL(0,     arr2.at(0).val);
}

TEST(Array_ret_empty_local)
{
    const Array<BlaArray> & arr2 = RetArrEmptyLocal();
    //arr2 = std::move(arrOne);
    CHECK_EQUAL(true,  arr2.empty());
    CHECK_EQUAL(0,     arr2.size());
    //CHECK_EQUAL(0,     arr2.at(0).val);
}

TEST(Array_ret_two)
{
    const int val = 2;
    Array<float> arr2 = RetArrTwo(val);
    //arr2 = std::move(arrOne);
    CHECK_EQUAL(false, arr2.empty());
    CHECK_EQUAL(2,     arr2.size());
    CHECK_EQUAL(val,   arr2.at(0));
    CHECK_EQUAL(val,   arr2.at(1));
}

TEST(Array_copy_empty)
{
    Array<float> arrEmpty;
    std::vector<float> ret;
    AR2VEC(arrEmpty, ret);
}

TEST(Array_clear)
{
    VecF data = std::vector<float>{2, 0, 1};
    Array<float> arr(data);
    arr.clear();
    CHECK_EQUAL(true, arr.empty());
    CHECK_EQUAL(0,    arr.size());
}
