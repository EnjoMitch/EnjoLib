#include "MapChoiceEnum.hpp"
#include "../MyChoiceEnum.h"

MapChoiceEnum::MapChoiceEnum(){}
MapChoiceEnum::~MapChoiceEnum(){}

void MapChoiceEnum::Register(long int * variable, MyChoiceEnum * checkbox)
{
    m_mapControl[variable] = checkbox;
}

void MapChoiceEnum::FromCheckToVariable()
{
    for (auto it = m_mapControl.begin(); it != m_mapControl.end(); ++it)
    {
        *(it->first) = it->second->GetSelection();
    }
}

void MapChoiceEnum::FromVariableToCheck()
{
    for (auto it = m_mapControl.begin(); it != m_mapControl.end(); ++it)
    {
         it->second->SetSelection(*(it->first));
    }
}
