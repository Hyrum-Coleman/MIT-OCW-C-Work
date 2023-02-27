#include <iostream>
#include "geometry.h"

using namespace std;


int main()
{
    auto *p = new Point(2, 5);
    auto point = Point(3, 7);
    cout << "(" << p->getX() << ", " << p->getY() << ")\n";
    p->setX(56);
    cout << "(" << p->getX() << ", " << p->getY() << ")\n";

    auto *pArray = new PointArray(p);
    pArray->push_back(point);
    pArray->push_back(*p);
    pArray->remove(1);
    pArray->remove(0);
    pArray->push_back(Point(133, 422));
    int arrLen = pArray->getSize();

    cout << arrLen << '\n';

    delete p;
    delete pArray;
    return 0;
}