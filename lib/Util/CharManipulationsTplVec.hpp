#ifndef CHARMANIPULATIONSTPLVEC_HPP
#define CHARMANIPULATIONSTPLVEC_HPP

#include "CharManipulationsTpl.hpp"

#include <STD/Vector.hpp>

namespace EnjoLib
{
class CharManipulationsTplVec
{
    public:
        CharManipulationsTplVec(){}
        virtual ~CharManipulationsTplVec(){}
        
        template <class T> std::vector<T> ToNumbersVec(const VecStr & in) const;

    protected:

    private:
};


template <class T> std::vector<T> CharManipulationsTplVec::ToNumbersVec(const VecStr & in) const
{
    std::vector<T> ret;
    const CharManipulationsTpl cman;
    for (size_t i = 0; i < in.size(); ++i)
    {
        const T & number = cman.ToNumber<T>(in.at(i));
        ret.push_back(number);
    }
    return ret;
}

}
#endif // CHARMANIPULATIONSTPLVEC_HPP
