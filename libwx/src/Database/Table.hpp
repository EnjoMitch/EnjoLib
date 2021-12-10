#ifndef TABLE_H
#define TABLE_H

class wxString;

class Table
{
    public:
        Table();
        virtual ~Table();

        virtual wxString GetTableName() const = 0;

    protected:
    private:
};

#endif // TABLE_H
