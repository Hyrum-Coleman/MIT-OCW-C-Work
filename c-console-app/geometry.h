#pragma once
class Point
{

public:
	explicit Point(int x=0, int y=0) { mX = x; mY = y; }
	int getX() const { return mX; }
	int getY() const { return mY; }
	void setX(const int new_x) { mX = new_x; }
	void setY(const int new_y) { mY = new_y; }

public:
	void printPoint();

private:
	int mX, mY;
};

class PointArray
{
public: // Public guys
	PointArray();
	PointArray(Point points[], int size);
	PointArray(const PointArray& pv);
	explicit PointArray(Point *point);
	explicit PointArray(Point point);
	~PointArray();

public: // Public Functions
	void push_back(const Point& point);
	void insert(int position, const Point& point);
	void remove(int position);
     int getSize() const;
    void clear();
    Point get(int position);
    Point get(int position) const;

private: // Private guys
	int mLen{};
	Point* mPtr{};
	static const int cBlockSize = 100;

private: // Private Functions
	void initialize(Point points[], int size);
	void resize(int newSize);
};

class Polygon
{
public:

public:

private:
	PointArray mPointArray;
	static int mNumPoly;

private:
};