#ifndef             __TEST_FRUITBOX__
# define            __TEST_FRUITBOX__

#include <string>
#include <iostream>
#include "test_FruitNode.hpp"

class                       FruitBox
{
    public:
        FruitBox(const int size);
        ~FruitBox(void);

        int                 nbFruit(void) const;
        bool                putFruit(Fruit *f);
        Fruit               *pickFruit(void);
        FruitNode           *head(void) const;

        int                 getSize(void) const;

        void                setHead(FruitNode *f);

    protected:
    private:
        const int           m_size;
        int                 m_nbFruit;
        FruitNode           *m_head;
};
#endif //          !__TEST_FRUITBOX__