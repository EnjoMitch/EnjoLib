#include <Statistical/3rdParty/EigenUtil.hpp>

#include <Eigen/Dense>

EigenUtil::EigenUtil()
{
    //ctor
}

EigenUtil::~EigenUtil()
{
    //dtor
}

Eigen::VectorXd EigenUtil::ConvertVector2Eigen( const EnjoLib::VecD & vec )
{
    const int nrows = vec.size();
    Eigen::VectorXd veceig(nrows);
    for ( int i = 0; i < nrows; ++i )
            veceig(i) = vec.at(i);

    return veceig;
}