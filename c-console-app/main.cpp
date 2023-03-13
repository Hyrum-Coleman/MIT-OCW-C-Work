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

    cout << "\nBIG BREAK\n";
    cout << Q_rsqrt(25) << "\n";

    cout << "\nPOLYGONS\n";

    auto polygon = new Polygon(*pArray);
    auto polygon2 = new Polygon (&point, 1);

    auto rectangle = new Rectangle(1, 1, 5, 4);
    double rectArea = rectangle->area();
    auto p1 = Point(28, 2);
    auto p2 = Point(5, 9);
    auto p3 = Point(16, 18);
    auto triangle = new Triangle(p1, p2, p3);
    double triArea = triangle->area();
    cout << "rectangle area: " << rectArea << "\n";
    cout << "triangle area: " << triArea << "\n";

    triangle->printAttributes(triangle);

    int numPoly = Polygon::getNumPolygons();

    cout << numPoly << "\n";

    delete p;
    delete pArray;
    delete polygon;
    numPoly = Polygon::getNumPolygons();
    cout << numPoly << "\n";
    delete polygon2;
    delete rectangle;
    return 0;
}