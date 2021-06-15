#ifndef ENUMCLASSWRAPPER_H
#define ENUMCLASSWRAPPER_H

namespace EnjoLib
{

/// Saves compilation time on new enum members
template <class Enum>
class EnumClassWrapper
{
    public:
        EnumClassWrapper() {m_type = Enum(0);}
        EnumClassWrapper(Enum type) {m_type = type;}
        EnumClassWrapper(long int type)  {m_type = Enum(type);}
        virtual ~EnumClassWrapper(){}

        Enum GetType() const {return m_type;}


    protected:

    private:
        Enum m_type;
};

}
#endif // ENUMCLASSWRAPPER_H
