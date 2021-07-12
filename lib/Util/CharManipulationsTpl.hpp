#ifndef CHARMANIPULATIONSTPL_H
#define CHARMANIPULATIONSTPL_H

#include <Util/CharManipulations.hpp>
#include <Statistical/Assertions.hpp>
#include <Util/Except.hpp>
#include <Util/VecStr.hpp>

#include <Util/Osstream.hpp>
#include <Util/Isstream.hpp>

namespace EnjoLib
{
class CharManipulationsTpl
{
    public:
        CharManipulationsTpl(){}
        virtual ~CharManipulationsTpl(){}

        template <class T> bool ToNumber(const EnjoLib::Str & in, T * d) const;
        template <class T> T    ToNumber(const Str & in) const;

    protected:

    private:
};

template <class T> bool CharManipulationsTpl::ToNumber(const EnjoLib::Str & in, T * number) const
{
    *number = 0;
    Isstream ss;
    ss.str(CharManipulations().Trim(in).c_str());
    if ( ! (ss >> *number) )
        return false;
    return true;
}

template <class T> T CharManipulationsTpl::ToNumber(const Str & in) const
{
    T number;
    if (!ToNumber<T>(in, &number))
    {
        const Str msg = "Not number: '" + in + "'";
        throw EnjoLib::ExceptInvalidArg(msg.c_str());
    }

    return number;
}

}

#endif // CHARMANIPULATIONSTPL_H
