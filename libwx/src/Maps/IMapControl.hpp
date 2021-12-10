#ifndef IMAPCONTROL_HPP
#define IMAPCONTROL_HPP

class IMapControl
{
    public:
        IMapControl();
        virtual ~IMapControl();

        virtual void FromCheckToVariable() = 0;
        virtual void FromVariableToCheck() = 0;

    protected:

    private:
};

#endif // IMAPCONTROL_HPP
