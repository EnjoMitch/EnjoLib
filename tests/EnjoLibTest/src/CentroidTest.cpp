#include "CentroidTest.h"

#include <Statistical/Centroid.hpp>
#include <Statistical/VectorD.hpp>
#include <Template/Array.hpp>
#include <Math/RandomMath.hpp>
#include <Ios/Osstream.hpp>
#include <Util/CoutBuf.hpp>

using namespace EnjoLib;
using namespace std;

CentroidTest::CentroidTest()
{
    ELO
    Centroid<VectorD> centr;

    const RandomMath rmath;
    rmath.RandSeed();
    int numVec = 5;
    int dims = 8;


    vector<VectorD> vsamples;
    for (int n = 0; n < numVec; ++n)
    {
        VectorD in;
        for (int i = 0; i < dims; ++i)
        {
            double y = rmath.Rand(0, 1);
            in.push_back(y);
        }
        vsamples.push_back(in);
        Osstream ossFile;
        ossFile << "var" << n;
        LOG << in.PrintPython(ossFile.str().c_str());
    }
    Array<VectorD> samples(vsamples);
    VectorD centroid = centr.Calc(samples);
    LOG << centroid.PrintPython("centroid");
}

CentroidTest::~CentroidTest()
{
    //dtor
}
