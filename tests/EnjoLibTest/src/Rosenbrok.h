#ifndef ROSENBROK_H
#define ROSENBROK_H


class Rosenbrok
{
    public:
        Rosenbrok();
        virtual ~Rosenbrok();
        double Eval( const double x[2] ) const;
    protected:
    private:
};

#endif // ROSENBROK_H
