#ifndef                 __TEST_LEMON__
    #define             __TEST_LEMON__

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
#endif //               !__TEST_LEMON__