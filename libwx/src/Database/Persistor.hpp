#ifndef PERSISTOR_H
#define PERSISTOR_H

class wxString;
class Entity;
class DatabaseAbstract;
class Table;

class Persistor
{
    public:
        Persistor( DatabaseAbstract * db );
        virtual ~Persistor();
        void Presist( Entity * entity ) const;
        void Delete( Entity * entity ) const;
        void DeleteTable( const Table & table ) const;
    protected:
    private:
        wxString PrepareStatementGetLastId( const Entity & entity ) const;
        wxString PrepareStatementInsert( const Entity & entity ) const;
        wxString PrepareStatementUpdate( const Entity & entity ) const;
        wxString PrepareStatementDelete( const Entity & entity ) const;

        DatabaseAbstract * m_db;
};

#endif // PERSISTOR_H
