#ifndef ALGOVARIADIC_H
#define ALGOVARIADIC_H

namespace EnjoLib
{
class AlgoVariadic
{
    public:
        AlgoVariadic(){}
        virtual ~AlgoVariadic(){}

        template <typename T, typename U>
        bool AllEqual(const T &t, const U &u) {
            return t == u;
        }

        template <typename T, typename U, typename... Others>
        bool AllEqual(const T &t, const U &u, Others const &... args) {
            return (t == u) && AllEqual(u, args...);
        }

    protected:

    private:
};
}

/*
Example:

if (allequal(a,b,c,'X') || allequal(a,b,c,'O')) { ... }
*/

#endif // ALGOVARIADIC_H
