#ifndef UTILWX_H
#define UTILWX_H

namespace EnjoLib {
    
class UtilWx
{
    public:
        UtilWx();
        virtual ~UtilWx();
        
        static wxString GetHomeDir();
        static bool IsLinux();

    protected:

    private:
};

}
#endif // UTILWX_H
