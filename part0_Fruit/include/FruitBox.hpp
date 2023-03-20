#ifndef             __FRUITBOX__
# define            __FRUITBOX__

#include <string>
#include <iostream>
#include "FruitNode.hpp"

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
        void                printList(void);
    
    protected:
    private:
        const int           m_size;
        int                 m_nbFruit;
        FruitNode           *m_head;
};
#endif //          !__FRUITBOX__