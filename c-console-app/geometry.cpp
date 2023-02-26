#include "geometry.h"
#include <string.h>
#include <utility>


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

void PointArray::initialize(Point points[], int size)
{
    mPtr = new Point[size];
    mLen = size;
    memcpy(mPtr, points, size * sizeof(Point));
}

PointArray::~PointArray()
{
    delete[] mPtr;
}

void PointArray::resize(int n)
{
    if ((n / cBlockSize) > (mLen / cBlockSize))
    {
        Point* hold = new Point[((n / cBlockSize) + 1) * cBlockSize];
        memcpy(hold, mPtr, mLen * sizeof(Point));
        delete[] mPtr;
        mLen = n;
        mPtr = hold;
    }
    else
    {
        mLen = n;
    }
}