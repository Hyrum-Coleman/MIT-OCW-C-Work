#pragma once
class Point
{
private:
	int mX, mY;
public:
	Point(int x=0, int y=0) { mX = x; mY = y; }
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

public:
	void push_back(const Point& point);
	void insert(const int position, const Point& point);
	void remove(const int postition);

private:
	int mLen;
	Point* mPtr;
	static const int cBlockSize = 100;

private:
	void initialize(Point points[], int size);
	void resize(int newSize);
};