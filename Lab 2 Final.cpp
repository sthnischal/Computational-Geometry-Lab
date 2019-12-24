#include <iostream>
using namespace std;
class Point 
{ 
    public: int x,y; 
    void inputPoint()
	{ 
		cout<<"\n\tEnter the X-coordinate: ";
		cin>>x;
		cout<<"\tEnter the Y-coordinate: ";
		cin>>y;
    } 
    void displayPoint()
	{
		cout<<"("<<x<<" ,"<<y<<")";
    }
};

class Line
{
    public: template <class A, class B>
    void line(Point& a, Point& b)
	{
		cout<<"Start Point: ";
		a.inputPoint();
		cout<<"End Point: ";
		b.inputPoint();
    }
};

class TurnTest
{
	public: template <class A, class B, class C>
  	void TurnTestPoint(A& a, B& b, C& c)
	{
		cout<<"Given Line Segment: \n";
		cout<<"\tStart Point: ";
		a.inputPoint();
		cout<<"\n\tEnd Point: ";
		b.inputPoint();
		cout<<"\n\tTest Point for Turn Test: ";
		c.inputPoint();
		turnTest(a,b,c);
  	}
  
  	template <class A, class B, class C>
  	void turnTest(A& a, B& b, C& c)
	{
    	double area;
      	area = 0.5*(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y));
      	if(area>0)
		{
			cout<<" The point is LEFT to the line segment ";
			a.displayPoint();
			cout<<" , ";
			b.displayPoint();
      	}
      	else if(area<0)
		{
			cout<<" The point is RIGHT to the line segment ";
			a.displayPoint();
			cout<<" , ";
			b.displayPoint();
      	}
		else  //if area is 0 then collinear
		{
			cout<<" The point is COLLINEAR to the line segment  ";
			a.displayPoint();
			cout<<" , ";
			b.displayPoint();
      	}
  	}
};


class LineIntersection
{
    public: template<class A, class B>
    void checkIntersection(A& a, B& b)
	{
        Point p1,p2,p3,p4;
        double a1, a2, a3, a4; 
		cout<<"\n\tFIRST LINE";
		cout<<"\n\tStart Point:";
		p1.inputPoint();
		cout<<"\tEnd Point:";
		p2.inputPoint();
		cout<<"\n\tSECOND LINE";
		cout<<"\n\tStart Point:";
		p3.inputPoint();
		cout<<"\tEnd Point:";
		p4.inputPoint();
		a1 = computeArea(p1,p2,p3);
		a2 = computeArea(p1,p2,p4);
		a3 = computeArea(p3,p4,p1);
		a4 = computeArea(p3,p4,p2);
		
		
		if (a1 * a2 < 0 )
		{
			cout<<"The line intersect";
        }
        else if (a1 * a2 > 0 )
		{
			cout<<"No Intersection";
        }
		else
		{
			cout<<"May be improper intersect";
        }	
	}
        
    
    template<class A, class B, class C>
    double computeArea(A& a, B& b, C& c){
        return 0.5*(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y));    
    }
};
int main()
{
    int choice;
	cout<<" \t1. Turn Test\n";
	cout<<" \t2. Check Intersection between two lines\n";
	cout<<" \tEnter the choice ";
	cin>>choice;
    switch(choice){
        case 1: Point point1, point2, point3;
			TurnTest t1;
			t1.TurnTestPoint(point1, point2, point3);
        break;
        case 2: LineIntersection li;
                Line l1,l2;
				li.checkIntersection(l1,l2);
        break;
        default: cout<<"Invalid choice.\nEnter the correct choice number ";
    }
    return 0;
}

