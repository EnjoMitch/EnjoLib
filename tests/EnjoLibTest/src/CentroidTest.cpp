#include "CentroidTest.h"

#include <Statistical/Centroid.hpp>
#include <Statistical/VectorD.hpp>
#include <STD/Iostream.hpp>
#include <sstream>

using namespace EnjoLib;
using namespace std;

CentroidTest::CentroidTest()
{
    Centroid<VectorD> centr;

    srand(time(NULL));
    int numVec = 5;
    int dims = 8;


    vector<VectorD> samples;
    for (int n = 0; n < numVec; ++n)
    {
        VectorD in;
        for (int i = 0; i < dims; ++i)
        {
            double y = (1.0 * rand() / (RAND_MAX));
            in.push_back(y);
        }
        samples.push_back(in);
        ostringstream ossFile;
        ossFile << "var" << n;
        cout << in.PrintPython(ossFile.str().c_str());
    }

    VectorD centroid = centr.Calc(samples);
    cout << centroid.PrintPython("centroid");

}

CentroidTest::~CentroidTest()
{
    //dtor
}
