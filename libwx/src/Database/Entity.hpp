#ifndef ENTITY_H
#define ENTITY_H

class wxString;

class Entity
{
    public:
        Entity();
        virtual ~Entity();
        int GetId() const;
        void SetId( int id );

        virtual wxString GetTableName() const = 0;
        virtual wxString GetIdColumn() const = 0;
        virtual wxString GetUpdateValues() const = 0;
        virtual wxString GetInsertValues() const = 0;
    protected:
    private:

        int m_id;
};

#endif // ENTITY_H
