#ifndef MAPCONTROLTPL_HPP
#define MAPCONTROLTPL_HPP

#include "IMapControl.hpp"
#include <map>

template <class Var, class Control>
class MapControlTpl : public IMapControl
{
    public:
        MapControlTpl() {}
        virtual ~MapControlTpl() {}

        void Register(Var * variable, Control * checkbox)
        {
            m_mapControl[variable] = checkbox;
        }

        void FromCheckToVariable() override
        {
            for (auto it = m_mapControl.begin(); it != m_mapControl.end(); ++it)
            {
                *(it->first) = it->second->GetValue();
            }
        }

        void FromVariableToCheck() override
        {
            for (auto it = m_mapControl.begin(); it != m_mapControl.end(); ++it)
            {
                 it->second->SetValue(*(it->first));
            }
        }

    protected:

    private:

        std::map<Var *, Control *> m_mapControl;
};

#endif // MAPCONTROLTPL_HPP
