#ifndef IOMANIP_HPPP
#define IOMANIP_HPPP

namespace EnjoLib {

class Ostream;
class IoManip
{
    public:
        IoManip();
        virtual ~IoManip();

        static Ostream & SetPrecision(Ostream & ostr, int prec);
        static Ostream & SetW(Ostream & ostr, int width);
        static Ostream & SetFill(Ostream & ostr, char toFill);
        static Ostream & Fixed(Ostream & ostr);
        static Ostream & Scientific(Ostream & ostr);

    protected:

    private:
};
}

#endif // IOMANIP_HPP
