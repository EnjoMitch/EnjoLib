#include "MultiDimIterTpl.hpp"
#include "IMultiDimIterConsumerTpl.hpp"

#include <Util/VecD.hpp>
#include <Util/CoutBuf.hpp>

using namespace EnjoLib;

void MultiDimIterTpl::StartIteration(const VVt & data, IMultiDimIterConsumerTpl & consumer)
{
    Vt res(data.size());
    IterateTpl(consumer, data, res);
}


void MultiDimIterTpl::IterateTpl(IMultiDimIterConsumerTpl & consumer, const VVt & data, Vt & res, unsigned d)
{
    const unsigned n = data.size();
    if (d >= n)   //stop clause
    {
        consumer.Consume(res);
        return;
    }

    const Vt & dataEl = data[d];
    //const unsigned sz = dataEl.size(); // slower
    for (unsigned i = 0; i < dataEl.size(); ++i)
    {
        res[d] = dataEl[i]; // Communicate via the vector "res"
        IterateTpl(consumer, data, res, d+1);
    }
}
