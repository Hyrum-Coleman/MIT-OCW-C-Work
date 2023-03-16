#pragma once
class Point
{

public:
	explicit Point(int x=0, int y=0) { mX = x; mY = y; }
	[[nodiscard]] int getX() const { return mX; }
	[[nodiscard]] int getY() const { return mY; }
	void setX(const int new_x) { mX = new_x; }
	void setY(const int new_y) { mY = new_y; }

public:
	void printPoint() const;

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
    [[nodiscard]] int getSize() const;
    void clear();
    [[nodiscard]] Point get(int position);
    [[nodiscard]] Point get(int position) const;

private: // Private guys
	int mLen{};
	Point* mPtr{};
	static constexpr int cBlockSize = 100;

private: // Private Functions
	void initialize(Point points[], int size);
	void resize(int newSize);
};



class Polygon
{
public: // Constructors Destructor
	Polygon(Point points[], int size);
	Polygon(PointArray &pArray);
	virtual ~Polygon() {--mNumPoly;}

public: // Public Functions
    virtual double area() {return 0;}
    static int getNumPolygons() {return mNumPoly;}
    [[nodiscard]] int getNumSides() const {return mPointArray.getSize();}
    [[nodiscard]] const PointArray *getPoints() {return &mPointArray;}
    virtual void printAttributes();

protected: // Protected Members
	PointArray mPointArray;
	static int mNumPoly;

};



class Rectangle : public Polygon {

public: // Constructors
    Rectangle(Point &botLeftPoint, Point &topRightPoint);
    Rectangle(int botLeftX, int botLeftY, int width, int height);

public: // public functions
    double area() override;
    void printAttributes() override;
    [[nodiscard]] int width() const;
    [[nodiscard]] int height() const;

private: // private members
    int mRectWidth;
    int mRectHeight;

private: // private functions
    void setWidth(Point botLeft, Point topRight);
    void setHeight(Point botLeft, Point topRight);
    void setWidth(int width);
    void setHeight(int height);
};



class Triangle : public Polygon {

public: // constructors
    Triangle(Point &a, Point &b, Point &c);

public: // public functions
    double area() override;
    [[nodiscard]] double aLen() const;
    [[nodiscard]] double bLen() const;
    [[nodiscard]] double cLen() const;

private: // private members
    double mALength;
    double mBLength;
    double mCLength;
};