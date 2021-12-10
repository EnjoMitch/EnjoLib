#ifndef DATABASEABSTRACT_H
#define DATABASEABSTRACT_H

class wxString;

class DatabaseAbstract
{
    public:
        DatabaseAbstract();
        virtual ~DatabaseAbstract();
        virtual void ExecuteStatement( const wxString & statement ) = 0;
        virtual int ExecuteStatementReturnInt( const wxString & statement ) = 0;
    protected:
    private:
};

#endif // DATABASEABSTRACT_H
