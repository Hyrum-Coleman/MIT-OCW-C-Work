#include <iostream>
#include "geometry.h"

using namespace std;


int main()
{
    auto *p = new Point(2, 5);
    auto point = Point(3, 7);
    p->printPoint();
    p->setX(56);
    p->printPoint();

    auto *pArray = new PointArray(p);
    pArray->push_back(point);
    pArray->push_back(*p);
    pArray->push_back(Point(133, 422));
    pArray->remove(2);
    pArray->insert(1, Point(3, 4));
    int arrLen = pArray->getSize();
    Point somePoint = pArray->get(3);

    cout << arrLen << '\n';
    somePoint.printPoint();

    delete p;
    delete pArray;
    return 0;
}