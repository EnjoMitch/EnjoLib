#include "../pch/wx_pch.h"

#include <wx/string.h>

#include "Persistor.hpp"
#include "Entity.hpp"
#include "Table.hpp"
#include "DatabaseAbstract.hpp"

Persistor::Persistor( DatabaseAbstract * db )
    : m_db( db )
{
}

Persistor::~Persistor()
{
}

void Persistor::Presist( Entity * entity ) const
{
    if ( entity->GetId() < 0 )
    {
        m_db->ExecuteStatement( PrepareStatementInsert( *entity ) );
        int newId = m_db->ExecuteStatementReturnInt( PrepareStatementGetLastId( *entity ) );
        entity->SetId( newId );
    }
    else
    {
        m_db->ExecuteStatement( PrepareStatementUpdate( *entity ) );
    }
}

void Persistor::Delete( Entity * entity ) const
{
    if ( entity->GetId() >= 0 )
    {
        m_db->ExecuteStatement( PrepareStatementDelete( *entity ) );
        entity->SetId(-1);
    }
}

void Persistor::DeleteTable( const Table & table ) const
{
    wxString s;
    s << "DELETE FROM " << table.GetTableName() << ";";
    m_db->ExecuteStatement( s );
}


wxString Persistor::PrepareStatementDelete( const Entity & entity ) const
{
    wxString s;
    s << "DELETE FROM " << entity.GetTableName();
    s << " WHERE " << entity.GetIdColumn() << "=" << entity.GetId() << ";";
    return s;
}

wxString Persistor::PrepareStatementGetLastId( const Entity & entity ) const
{
    wxString s;
    s << "SELECT " << entity.GetIdColumn() << " FROM " << entity.GetTableName();
    s << " ORDER BY " << entity.GetIdColumn() << " DESC LIMIT 1;";
    return s;
}

wxString Persistor::PrepareStatementInsert( const Entity & entity ) const
{
    wxString s;
    s << "INSERT INTO " << entity.GetTableName() << " VALUES ";
    s << " ( " << entity.GetInsertValues() << " );";
    return s;
}

wxString Persistor::PrepareStatementUpdate( const Entity & entity ) const
{
    wxString s;
    s << "UPDATE " << entity.GetTableName();
    s << " SET " << entity.GetUpdateValues();
    s << " WHERE " << entity.GetIdColumn() << "=" << entity.GetId() << ";";
    return s;
}
