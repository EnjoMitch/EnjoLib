#ifndef MAXMINFINDD_HPP
#define MAXMINFINDD_HPP

#include "MaxMinFind.hpp"

namespace EnjoLib
{
class MaxMinFindD : public MaxMinFind<double>
{
    public:
        using MaxMinFind<double>::MaxMinFind;
        virtual ~MaxMinFindD() {}

    protected:

    private:
};
}

#endif // MAXMINFINDD_HPP
