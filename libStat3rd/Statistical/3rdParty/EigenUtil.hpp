#ifndef EIGENUTIL_HPP
#define EIGENUTIL_HPP

#include <Util/VecD.hpp>
#include <Eigen/Dense>

class EigenUtil
{
    public:
        EigenUtil();
        virtual ~EigenUtil();
        
        static Eigen::VectorXd ConvertVector2Eigen( const EnjoLib::VecD & vec );

    protected:

    private:
};

#endif // EIGENUTIL_HPP
