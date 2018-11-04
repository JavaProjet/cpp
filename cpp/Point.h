#ifndef Point_h
#define Point_h

using namespace std;

class Point{
	private : 
		int x,y;
	public :
		Point();
		~Point();
		Point(int x, int y);
		Point(Point&);
		int getX();
		int getY();
		void setX(int);
		void setY(int);
		Point& getPoint();
		Point& operator=(Point&);
		void deplace(int x, int y);
};

#endif //Point_h
