#include <iostream>
#include "geometry.h"

using namespace std;

int main()
{
    int llX;
    int llY;
    int trX;
    int trY;

    int triX1;
    int triY1;
    int triX2;
    int triY2;
    int triX3;
    int triY3;

    cout << "Enter coordinates for bottom left of rectangle (x, y): ";
    cin >> llX >> llY;
    cout << "Enter coordinates for top right of rectangle (x, y): ";
    cin >> trX >> trY;

    auto botLeftPoint = Point(llX, llY);
    auto topRightPoint = Point(trX, trY);
    auto userRect = new Rectangle(botLeftPoint, topRightPoint);

    cout << "\nEnter coordinates for first triangle point (x, y): ";
    cin >> triX1 >> triY1;
    cout << "Enter coordinates for second triangle point (x, y): ";
    cin >> triX2 >> triY2;
    cout << "Enter coordinates for third triangle point (x, y): ";
    cin >> triX3 >> triY3;

    auto triP1 = Point(triX1, triY1);
    auto triP2 = Point(triX2, triY2);
    auto triP3 = Point(triX3, triY3);

    auto userTri = new Triangle(triP1, triP2, triP3);

    cout << "\n\n";
    cout << "RECTANGLE ATTRIBUTES: \n";
    userRect->printAttributes();
    cout << "\nTRIANGLE ATTRIBUTES: \n";
    userTri->printAttributes();

    return 0;
}