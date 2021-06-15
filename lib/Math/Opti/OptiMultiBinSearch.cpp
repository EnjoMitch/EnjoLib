#include "OptiMultiBinSearch.hpp"
#include "OptiMultiSubject.hpp"
#include <Math/MultiDimIter/MultiDimIterTpl.hpp>
//#include <Statistical/VectorD.hpp>
#include <STD/VectorCpp.hpp>
#include <cstddef>
#include <Util/CoutBuf.hpp>

using namespace EnjoLib;
using namespace std;

OptiMultiBinSearch::OptiMultiBinSearch()
: m_subj(NULL)
{
    //ctor
}

OptiMultiBinSearch::~OptiMultiBinSearch()
{
    //dtor
}

Result<VecD > OptiMultiBinSearch::Run( OptiMultiSubject & subj, int numSlices, double eps)
{
    m_subj = &subj;
    const VecD & start = subj.GetStart();
    const std::vector<OptiMultiSubject::Bounds> & bounds = subj.GetBounds();
    m_vopt = VecD(bounds.size());

    std::vector<OptiMultiSubject::Bounds> newBounds = bounds;
    //for (unsigned dim = 0; dim < bounds.size())
    MultiDimIterTpl::VVt data;
    do
    {
        MultiDimIterTpl iter;
        data.clear();
        for (const OptiMultiSubject::Bounds & b : newBounds)
        {
            VecD spaceElements;
            const double len = b.max - b.min;
            const double delta = len / double(numSlices + 1);
            for (int i = 0; i <= numSlices + 1; ++i)
            {
                const double element = b.min + i * delta;
                spaceElements.push_back(element);
            }
            data.push_back(spaceElements.Data());
        }

        iter.StartIteration(data, *this);
        //numSlices *= 2;
        //numSlices++;
        //MultiDimIterTpl<double>::VVt dataNew;

        std::vector<OptiMultiSubject::Bounds> newNewBounds;
        //for (const OptiMultiSubject::Bounds & b : newBounds)
        for (unsigned dim = 0; dim < newBounds.size(); ++dim)
        {
            const OptiMultiSubject::Bounds & b = newBounds.at(dim);
            VecD spaceElements;
            const double len = b.max - b.min;
            const double delta = len / double(numSlices + 1);

            double min = m_vopt.at(dim) - delta;
            double max = m_vopt.at(dim) + delta;
            OptiMultiSubject::Bounds nb(min, max);
            newNewBounds.push_back(nb);

            //cout << "min, max = " << nb.min << ", " << nb.max << endl;
        }
        //cout << endl;
        newBounds = newNewBounds;
    } while(m_epsReached > eps);



    return Result<VecD >(m_vopt, false);
}

void OptiMultiBinSearch::Consume(const EnjoLib::VecD & data)
{
    double val = m_subj->Get(data.data(), data.size());

    if (m_yopt == 0 || val < m_yopt)
    {
        m_yopt = val;
        VecD vdata(data);
        VecD vopt(m_vopt);
        double len = (vdata-vopt).Len();
        m_epsReached = len;
        m_vopt = data;
        //cout << "min = " << val << endl;
    }
}

