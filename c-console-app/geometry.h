#pragma once
class Point
{
private:
	int mX, mY;
public:
	Point(int x = 0, int y = 0) { mX = x; mY = y; }
	int getX() const { return mX; }
	int getY() const { return mY; }
	void setX(const int new_x) { mX = new_x; }
	void setY(const int new_y) { mY = new_y; }
};

class PointArray
{
private:
	int mLen;
	int *mPtr;

public:
	PointArray() { mPtr = new int[0]; }
	PointArray(Point points[], int size) { mPtr = new int[size]; }
};