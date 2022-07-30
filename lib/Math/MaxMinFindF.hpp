#ifndef MAXMINFINDF_H
#define MAXMINFINDF_H

#include "MaxMinFind.hpp"

namespace EnjoLib
{
class MaxMinFindF : public MaxMinFind<float>
{
    public:
        using MaxMinFind<float>::MaxMinFind;
        virtual ~MaxMinFindF() {}

    protected:

    private:
};
}

#endif // MAXMINFINDF_H
