#include "ClusteringTest.h"
#include <Statistical/KMeans1d.hpp>

#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

ClusteringTest::ClusteringTest(){}
ClusteringTest::~ClusteringTest(){}

void ClusteringTest::Run()
{
    KMeans1d kmeans(false);
    EnjoLib::VecF op;
    op.push_back((0));
    op.push_back((2));
    op.push_back((12));
    op.push_back((14));

    cout << "in:" << endl;
    for (const float & o : op)
    {
        cout << o << endl;
        kmeans.AddObservation(o);
    }
    int reductions = 2;
    EnjoLib::VecF ret = kmeans.Reduce(reductions);

    cout << "\nout: (reductions = " << reductions << ")" << endl;
    for (const float & o : ret)
    {
        cout << o << endl;
    }
        //float result = ret.at(0).level;
        //float expected = 1;

        //float result = ret.at(1).level;
        //float expected = 13;

}
