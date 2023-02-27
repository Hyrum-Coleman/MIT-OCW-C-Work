#pragma once
class Point
{
private:
	int mX, mY;
public:
	explicit Point(int x=0, int y=0) { mX = x; mY = y; }
	[[nodiscard]] int getX() const { return mX; }
	[[nodiscard]] int getY() const { return mY; }
	void setX(const int new_x) { mX = new_x; }
	void setY(const int new_y) { mY = new_y; }
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
    [[nodiscard]] int getSize() const;
    void clear();
    Point get(int position);
    [[nodiscard]] Point get(int position) const;

private: // Private guys
	int mLen{};
	Point* mPtr{};
	static const int cBlockSize = 100;

private: // Private Functions
	void initialize(Point points[], int size);
	void resize(int newSize);
};