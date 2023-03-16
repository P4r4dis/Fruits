#ifndef                 __BANANA__
    #define             __BANANA__

#include <string>

class                   Banana
{
    public:
        Banana(void);
        ~Banana(void);

        std::string     getName(void) const;
        int             getVitamins(void) const;

        void            setVitamins(int Vitamins);
    protected:
    private:
        std::string     _name;
        int             _vitamins;
};
#endif //               !__BANANA__