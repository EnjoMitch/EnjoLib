#include "MovingWindow.hpp"
#include <Statistical/Assertions.hpp>

using namespace EnjoLib;

MovingWindow::~MovingWindow(){}
MovingWindow::MovingWindow(int len, const EnjoLib::VecD & dataIn)
: m_len(len)
, m_dataIn(dataIn)
{
    Assertions::SizesAtLeast(len, 2, "MovingWindow::MovingWindow(): len");
}

bool MovingWindow::IsValid() const
{
    return GetNumSets() > 0;
}

int MovingWindow::GetNumSets() const
{
    int diff = m_dataIn.size() - m_len + 1;
    return diff;
}

EnjoLib::Matrix MovingWindow::GetSets() const
{
    if (not IsValid())
    {
        return Matrix();
    }
    Matrix ret(GetNumSets());
    for (int i = m_len, k = 0; i <= int(m_dataIn.size()); ++i, ++k)
    {
        VecD set1;
        for (int j = i - m_len, f = 0; j < i; ++j, ++f)
        {
            set1.Add(m_dataIn.at(j));
            //set1.at(f) = (m_dataIn.at(j));
        }
        //ret.Add(set1);
        ret.at(k) = set1;
    }
    return ret;
}
