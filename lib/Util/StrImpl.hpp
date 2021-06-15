#ifndef STR_H
#define STR_H

#include <STD/String.hpp>

namespace boost { namespace serialization
{
    class access; }
}

namespace EnjoLib
{
class StrImpl
{
    public:
        StrImpl(const std::string & inp);
        virtual ~StrImpl();
        
        std::string dat;

    protected:

    private:
        friend class boost::serialization::access;
        // When the class Archive corresponds to an output archive, the
        // & operator is defined similar to <<.  Likewise, when the class Archive
        // is a type of input archive the & operator is defined similar to >>.
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version)
        {
            ar & dat;
        }
};
}
#endif // STR_H
