#include <iostream>
#include "geometry.h"

using namespace std;


int main()
{
    auto *p = new Point(2, 5);
    cout << "(" << p->getX() << ", " << p->getY() << ")\n";
    p->setX(56);
    cout << "(" << p->getX() << ", " << p->getY() << ")\n";

    auto* pointArray = new PointArray(p);

    delete p;
    return 0;
}