#ifndef                 __LEMON__
    #define             __LEMON__

#include <string>

class                   Lemon
{
    public:
        Lemon(void);
        ~Lemon(void);

        std::string     getName(void) const;
        int             getVitamins(void) const;

        void            setVitamins(int Vitamins);
    protected:
    private:
        std::string     _name;
        int             _vitamins;
};
#endif //               !__LEMON__