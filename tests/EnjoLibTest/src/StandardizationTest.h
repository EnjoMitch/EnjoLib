#ifndef STANDARDIZATIONTEST_H
#define STANDARDIZATIONTEST_H

namespace EnjoLib
{
    class VecD;
    class Matrix;
}

class StandardizationTest
{
    public:
        StandardizationTest();
        virtual ~StandardizationTest(){}

    protected:

    private:
        EnjoLib::VecD GetVec() const;
        EnjoLib::Matrix GetMat() const;
        void TestVec() const;
        void TestMat() const;
        void TestMatStdDev() const;
};

#endif // STANDARDIZATIONTEST_H
