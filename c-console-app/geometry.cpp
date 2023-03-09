#include "geometry.h"
#include <iostream>
#include <cstring>
#include <utility>

void Point::printPoint()
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


/*

PUBLIC DEFINITIONS

*/

Polygon::Polygon(Point points[], int size) :
    mPointArray(points, size) {
        ++mNumPoly;
    }

Polygon::Polygon(PointArray pArray)
{

}

/*

Private Functions

*/

void Polygon::initialize()
{

}
