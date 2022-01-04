#ifndef CIN_HPP
#define CIN_HPP

#include <Ios/Istream.hpp>

namespace EnjoLib
{
class Cin : public Istream
{
    public:
        Cin();
        virtual ~Cin();

        STDFWD::istream & IStr() override;
        const STDFWD::istream & IStr() const override;

    protected:

    private:
        STDFWD::istream & m_istream;
};
}

#endif // CIN_HPP
