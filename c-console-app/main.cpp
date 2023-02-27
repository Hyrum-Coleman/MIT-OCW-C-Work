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

    auto* pointArray = new PointArray(p);
    pointArray->push_back(point);

    delete p;
    delete[] pointArray;
    return 0;
}