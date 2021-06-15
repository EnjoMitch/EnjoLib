#ifndef LOSS_HPP
#define LOSS_HPP

#include <3rdParty/stdfwd.hh>
#include <Util/Str.hpp>
//#include <Template/SharedPtr.hpp>
#include <Util/VecD.hpp>
#include <Util/Pimpl.hpp>

#include <cstdint>

namespace EnjoLib
{
struct Loss
{
    Loss(double sum = 0, double stdDev = 0);
    virtual ~Loss();

    double GetRelDiff() const;
    EnjoLib::Str PrintRel() const;

    bool operator < (const Loss & other) const;
    bool operator == (const int64_t & i) const;
    
    const stdfwd::map<int, VecD> & labelIdErrors() const;
    stdfwd::map<int, VecD> & labelIdErrors();

    double sum;
    double stdDev;
    double regA;
    double regB;
    double correlDistError;
    double correlTargetError;
    //SharedPtr<stdfwd::map<int, VecD>> labelIdErrors;
    
    PIMPL_CPY
};

}

#endif // LOSS_HPP
