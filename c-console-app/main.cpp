#include <iostream>
#include "geometry.h"

using namespace std;

float Q_rsqrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long*)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float*)&i;
    y = y * (threehalfs - (x2 * y * y));

    return y;
}


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

    cout << "BIG BREAK\n";
    cout << Q_rsqrt(25) << "\n";

    delete p;
    delete pArray;
    return 0;
}