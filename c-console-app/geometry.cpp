#include "geometry.h"
#include <iostream>
#include <cstring>
#include <cmath>

/*

 Array Hack

*/

Point constructorPoints[4];

Point * updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3, const Point &p4 = Point(0,0))
{
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
}


void Point::printPoint() const
{
    std::cout << "(" << mX << ", " << mY << ")\n";
}


/*

POINT ARRAY CLASS

*/

/*

Public Definitions

*/

PointArray::PointArray()
{
    mPtr = nullptr;
    mLen = 0;
}

PointArray::PointArray(Point points[], int size)
{
    initialize(points, size);
}

PointArray::PointArray(const PointArray &pv)
{
    initialize(pv.mPtr, pv.mLen);
}

PointArray::PointArray(Point* point)
{
    initialize(point, 1);
}

PointArray::PointArray(Point point)
{
    initialize(&point, 1);
}

PointArray::~PointArray()
{
    delete[] mPtr;
}

/*

Public Functions

*/

void PointArray::push_back(const Point& point)
{
    resize(mLen + 1);
    mPtr[mLen - 1] = point;
}

void PointArray::insert(const int position, const Point& point)
{
    Point* tempPtr = mPtr + position;
    memcpy((tempPtr + 1), (tempPtr), (mLen - position - 1) * sizeof(Point));
    resize(mLen + 1);
    *tempPtr = point;
}

void PointArray::remove(const int position)
{
    Point *tempPtr = mPtr + position;
    memcpy((tempPtr), (tempPtr + 1), (mLen - position - 1) * sizeof(Point));
    resize(mLen - 1);
}

int PointArray::getSize() const {
    return mLen;
}

void PointArray::clear() {
    delete[] mPtr;
    mPtr = nullptr;
    mLen = 0;
}

Point PointArray::get(const int position) {
    return *(mPtr + position);
}

Point PointArray::get(const int position) const {
    return *(mPtr + position);
}

/*

Private Functions

*/

void PointArray::initialize(Point points[], int size)
{
    mPtr = new Point[((size/cBlockSize) + 1) * cBlockSize];
    mLen = size;
    memcpy(mPtr, points, size * sizeof(Point));
}

void PointArray::resize(int newSize) // important to remember cBlockSize = 100
{
    if ((newSize / cBlockSize) > (mLen / cBlockSize)) // integer division hack
    {
        auto* hold = new Point[((newSize / cBlockSize) + 1) * cBlockSize];
        memcpy(hold, mPtr, mLen * sizeof(Point));
        delete[] mPtr;
        mLen = newSize;
        mPtr = hold;
    }
    else
    {
        mLen = newSize;
    }
}


/*

POLYGON CLASS

*/

int Polygon::mNumPoly = 0;


/*

PUBLIC DEFINITIONS

*/

Polygon::Polygon(Point points[], int size) :
    mPointArray(points, size) {
        ++mNumPoly;
    }

Polygon::Polygon(PointArray &pArray) :
    mPointArray(pArray){
        ++mNumPoly;
    }

void Polygon::printAttributes() {
    std::cout << "Area: " << area() << "\n";
    for(int i = 0; i<mPointArray.getSize(); i++)
    {
        auto tempPoint = mPointArray.get(i);
        std::cout << "Point " << i << ": " << "(" << tempPoint.getX() << ", " << tempPoint.getY() << ")\n";

    }
}


/*

 Rectangle Class

*/

/*

Public Definitions

*/

Rectangle::Rectangle(Point &botLeftPoint, Point &topRightPoint) :
Polygon(updateConstructorPoints(botLeftPoint, Point (botLeftPoint.getX(), topRightPoint.getY()), topRightPoint, Point (topRightPoint.getX(), botLeftPoint.getY())), 4)
{
    mRectWidth = abs(botLeftPoint.getX() - topRightPoint.getX());
    mRectHeight = abs(botLeftPoint.getY() - topRightPoint.getY());
}

Rectangle::Rectangle(int botLeftX, int botLeftY, int width, int height) :
Polygon(updateConstructorPoints(Point (botLeftX, botLeftY), Point (botLeftX, botLeftY + height), Point (botLeftX + width, botLeftY + height), Point (botLeftX + width, botLeftY)), 4)
{
    mRectWidth = width;
    mRectHeight = height;
}

/*

 Public Functions

*/

double Rectangle::area() {
    return mRectHeight * mRectWidth;
}

void Rectangle::printAttributes() {
    Polygon::printAttributes();
    std::cout << "Width: " << mRectWidth << "\n";
    std::cout << "Height: " << mRectHeight << "\n";
}

/*

 Triangle Class

*/

/*

 Public Definitions

*/

Triangle::Triangle(Point &p1, Point &p2, Point &p3) :
Polygon(updateConstructorPoints(p1, p2, p3), 3)
{
    mALength = sqrt( pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2) );
    mBLength = sqrt(pow(p2.getX() - p3.getX(), 2) + pow(p2.getY() - p3.getY(), 2));
    mCLength = sqrt(pow(p1.getX() - p3.getX(), 2) + pow(p1.getY() - p3.getY(), 2));
}

/*

 Public Functions

*/

double Triangle::area() {
    double s = (mALength + mBLength + mCLength) / 2.0;
    return sqrt(s * (s - mALength) * (s - mBLength) * (s - mCLength));
}
