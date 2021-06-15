#ifndef TESTCLASSES_HPP
#define TESTCLASSES_HPP

#include <Util/Str.hpp>
#include <STD/String.hpp>

class Sym
    {
        public:
        const EnjoLib::Str & GetName() const;

        const EnjoLib::Str m_name;
        std::string m_nameCurPrefix;


        Sym(const EnjoLib::Str & name);

    };
#endif // TESTCLASSES_HPP
