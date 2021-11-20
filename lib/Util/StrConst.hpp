#ifndef STRCONST_HPP
#define STRCONST_HPP

namespace EnjoLib {
    
class Str;
class StrConst
{
    public:
        StrConst();
        StrConst(const char * str);
        StrConst(const Str & str);
        virtual ~StrConst();
        
        const char * c_str() const;
        Str String() const;

    protected:

    private:
        void Init(const char * str);
        
        char m_buf [1024];
};
}

#endif // STRCONST_HPP
