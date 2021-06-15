#ifndef EXCEPT_HPP
#define EXCEPT_HPP

#include <Util/Str.hpp>
#include <exception>

namespace EnjoLib {
    
class Except : public std::exception
{
    public:
        Except(const Str & msg);
        virtual ~Except();
        
        const char * what() const noexcept override;

    protected:

    private:
        Str m_msg;
};

class ExceptGeneral : public Except
{
    public:
        ExceptGeneral(const Str & msg) : Except(msg) {}
        virtual ~ExceptGeneral(){}
};

class ExceptInvalidArg : public Except
{
    public:
        ExceptInvalidArg(const Str & msg) : Except(msg) {}
        virtual ~ExceptInvalidArg(){}
};

class ExceptLogicError : public Except
{
    public:
        ExceptLogicError(const Str & msg) : Except(msg) {}
        virtual ~ExceptLogicError(){}
};

class ExceptRuntimeError : public Except
{
    public:
        ExceptRuntimeError(const Str & msg) : Except(msg) {}
        virtual ~ExceptRuntimeError(){}
};

class ExceptNotImpl : public Except
{
    public:
        ExceptNotImpl() : Except("Not implemented.") {}
        ExceptNotImpl(const Str & msg) : Except(msg) {}
        virtual ~ExceptNotImpl(){}
};

class ExceptLengthError : public Except
{
    public:
        ExceptLengthError(const Str & msg) : Except(msg) {}
        virtual ~ExceptLengthError(){}
};

}
#endif // EXCEPT_HPP
