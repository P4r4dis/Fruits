#ifndef             __TEST_FRUITBOX__
# define            __TEST_FRUITBOX__

#include <string>
#include <iostream>
#include "test_FruitNode.hpp"

class                       FruitBox
{
    public:
        FruitBox(int size);
        ~FruitBox(void);

        int                 nbFruit(void) const;
        bool                putFruit(Fruit *f);
                bool                unsortedPutFruit(Fruit *f);

        Fruit               *pickFruit(void);
        FruitNode           *head(void) const;

        int                 getSize(void) const;

        void                setHead(FruitNode *f);
        void                setNbFruit(int nbFruit);
        void                printList(void);


    protected:
    private:
        const int           m_size;
        int                 m_nbFruit;
        FruitNode           *m_head;
};
#endif //          !__TEST_FRUITBOX__