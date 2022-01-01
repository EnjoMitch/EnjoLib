#ifndef COUT_HPP
#define COUT_HPP

#include <Ios/Ostream.hpp>

namespace EnjoLib
{
class Cout : public Ostream
{
    public:
        Cout();
        virtual ~Cout();

        STDFWD::ostream & OStr() override;
        const STDFWD::ostream & OStr() const override;

    protected:

    private:
        std::ostream & m_ostream;
};
}

#endif // COUT_HPP
