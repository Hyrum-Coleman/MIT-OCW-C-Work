#pragma once
class Point
{
private:
	int mX, mY;
public:
	Point(int x=0, int y=0) { this->mX = x; this->mY = y; }
	int getX() const { return mX; }
	int getY() const { return mY; }
	void setX(const int new_x) { mX = new_x; }
	void setY(const int new_y) { mY = new_y; }
};

class PointArray
{
private:
	int mLen;
	Point *mPtr;

public:
	PointArray();
	PointArray(Point points[], int size)
    {
        this->mPtr = new Point[size];
        mPtr = points;
        this->mLen = size;

    }
};