#ifndef PIMPLT_HPP
#define PIMPLT_HPP

#include <Util/Pimpl.hpp>

class Pimp
{
    public:
    Pimp();
    double Dat() const;
   PIMPL
   public:
};

class PimpNotInit
{
   PIMPL_LAX
   public:
       double Dat() const;
};

class PimpCpy
{
    public:
    PimpCpy();
    double Dat() const;
    double & RW();
   PIMPL_CPY
   public:
};

#endif // PIMPLT_HPP
