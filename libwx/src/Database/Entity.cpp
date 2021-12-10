#include "Entity.hpp"

Entity::Entity()
: m_id(-1)
{
}

Entity::~Entity()
{
}

void Entity::SetId( int id )
{
    m_id = id;
}

int Entity::GetId() const
{
    return m_id;
}
