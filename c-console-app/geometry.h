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
public:
	PointArray();
	PointArray(Point points[], int size);
	PointArray(const PointArray& pv);
	PointArray(Point *point);
	PointArray(Point point);
	~PointArray();

private:
	int mLen;
	Point* mPtr;
	static const int cBlockSize = 100;

private:
	void initialize(Point points[], int size);
	void resize(int n);
};