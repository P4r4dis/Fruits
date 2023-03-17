#ifndef             __TEST_FRUIT__
# define            __TEST_FRUIT__

#include <string>
#include <iostream>
class                       Fruit
{
    public:
        Fruit(void);
        ~Fruit(void);

        std::string         getName(void) const;
        int                 getVitamins(void) const;

        void                setName(std::string name);
        void                setVitamins(int vitamins);
    protected:
    private:
        std::string         m_name;
        int                 m_vitamins;

};
#endif //          !__TEST_FRUIT__