#include "MultiDimIter.h"
#include <Math/MultiDimIter/MultiDimIterTpl.hpp>
#include <Math/MultiDimIter/IMultiDimIterConsumerTpl.hpp>
#include <STD/VectorCpp.hpp>

#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

MultiDimIter::MultiDimIter(){}
MultiDimIter::~MultiDimIter(){}

class Consumer : public IMultiDimIterConsumerTpl
{
    public:
    void Consume(const EnjoLib::VecD & data) override;
};

void Consumer::Consume(const EnjoLib::VecD & data)
{
    for (int i = 0; i < int(data.size()); i++)
    {
        cout << data[i] << ' ';
    }
    cout << endl;
}

class ConsumerDummy : public IMultiDimIterConsumerTpl
{
    void Consume(const EnjoLib::VecD & data) override {}
};

void MultiDimIter::Run()
{
    Consumer consumer;
    //ConsumerDummy consumer;
    MultiDimIterTpl iter;
    MultiDimIterTpl::VVt size;

    size.push_back(vector<double>{0, 1});
    size.push_back(vector<double>{0, 1, 2, 3});
    size.push_back(vector<double>{0, 1});

    /*
    // Hard core test
    size.push_back({0, 1, 2, 3, 3, 4, 6, 7, 8, 9});
    size.push_back({0, 1, 2, 3, 3, 4, 6, 7, 8, 9});
    size.push_back({0, 1, 2, 3, 3, 4, 6, 7, 8, 9});
    size.push_back({0, 1, 2, 3, 3, 4, 6, 7, 8, 9});
    size.push_back({0, 1, 2, 3, 3, 4, 6, 7, 8, 9});
    size.push_back({0, 1, 2, 3, 3, 4, 6, 7, 8, 9});
    size.push_back({0, 1, 2, 3, 3, 4, 6, 7, 8, 9});
    size.push_back({0, 1, 2, 3, 3, 4, 6, 7, 8, 9});
    size.push_back({0, 1, 2, 3, 3, 4, 6, 7, 8, 9});
    */
    iter.StartIteration(size, consumer);
}
