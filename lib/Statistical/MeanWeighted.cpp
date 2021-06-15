#include "MeanWeighted.hpp"
#include "Assertions.hpp"

using namespace EnjoLib;

MeanWeighted::MeanWeighted()
{
    //ctor
}

MeanWeighted::~MeanWeighted()
{
    //dtor
}

void MeanWeighted::AddValWeight(double val, double weight)
{
    m_vals.push_back(val);
    m_weights.push_back(weight);
}

void MeanWeighted::AddValDist(double val, double dist)
{
    m_vals.push_back(val);
    Assertions::IsFalse(dist == 0, "Dist can't be zero for now.");
    m_weights.push_back(1 / dist);
}

double MeanWeighted::GetMean() const
{
    double sumWeight = 0;
    double sumValWeight = 0;
    for (unsigned i = 0; i < m_vals.size(); ++i)
    {
        const double weight = m_weights.at(i);
        const double valWeight = m_vals.at(i) * weight;

        sumWeight += weight;
        sumValWeight += valWeight;
    }
    if (sumWeight == 0)
    {
        return 0;
    }
    const double mean = sumValWeight / sumWeight;
    return mean;
}
