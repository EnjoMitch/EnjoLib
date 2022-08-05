#ifndef BUILDERTPL_HPP
#define BUILDERTPL_HPP

namespace EnjoLib
{
/// Builder design pattern.
template <class TRet, class TMapKey, class TMapVal>
class BuilderTpl
{
    public:
        BuilderTpl()
        : m_obj(*this)
        {
        }
        virtual ~BuilderTpl(){}

        /// Use to add new parameters
        BuilderTpl & operator()(const TMapKey & key, const TMapVal & val);
        TRet Finalize() const;

    protected:

    private:
        TRet m_obj;
};

template <class TRet, class TMapKey, class TMapVal>
BuilderTpl<TRet, TMapKey, TMapVal>  & BuilderTpl<TRet, TMapKey, TMapVal>::operator()(const TMapKey & idd, const TMapVal & val)
{
    m_obj.Add(idd, val);
    return *this;
}

template <class TRet, class TMapKey, class TMapVal>
TRet BuilderTpl<TRet, TMapKey, TMapVal>::Finalize() const
{
    return m_obj;
}
}
#endif // BUILDERTPL_HPP
