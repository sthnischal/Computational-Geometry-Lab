#include <iostream> 
using namespace std; 
class Point 
{ 
    public: int x,y; 
  
    void inputPoint()
	    { 
       cout<<"\tEnter the X coordinate: ";
       cin>>x;
       cout<<"\tEnter the Y coordinate: ";
       cin>>y;
    } 
    void displayPoint(){
        cout<<"("<<x<<" ,"<<y<<")";
    }
}; 
class Line{
    public: template <class A, class B>
    void line(A& a, B& b){
        cout<<"\tFirst Point: "<<endl;
        a.inputPoint();
        cout<<"\tLast Point: "<<endl;
        b.inputPoint();
        cout<<"\t The line segment is: ";
        a.displayPoint();
        cout<<" to ";
        b.displayPoint();
    }
};
class PLC{
    public: template <class A, class B, class C>
    void plc(A& fp, B& lp, C& tp){
        cout<<"\tFirst Point: "<<endl;
        fp.inputPoint();
        cout<<"\tLast Point: "<<endl;
        lp.inputPoint();
        cout<<"\tTest Point: "<<endl;
        tp.inputPoint();
        
        if(Area (fp,lp,tp) ==0) {
      		//test for start point
		  if(tp.x==fp.x && tp.y==fp.y){
            cout<<"\n\t The test point is ("<<tp.x<<","<<tp.y<<")";
            cout<<" start point";
        }
		//test for terminal point
		else if(tp.x==lp.x && tp.y==lp.y){
            cout<<"\n\t The test point is ("<<tp.x<<","<<tp.y<<")";
            cout<<"terminal point";
        }

		else{
			//check for between
            if((tp.x>fp.x || tp.y>fp.y) && (tp.x<lp.x || tp.y<lp.y)){
                cout<<"\n\t The test point ("<<tp.x<<","<<tp.y<<")";
                cout<<" lies between the given line segment.";
            }
			//check for behind
			else if(tp.x<fp.x || tp.y<fp.y){
                cout<<"\n\t The test point ("<<tp.x<<","<<tp.y<<")";
                cout<<" is behind the given line segment.";
            }
			//check for beyond
			else {
                cout<<"\n\t The test point ("<<tp.x<<","<<tp.y<<")";
                cout<<" is beyond the given line segment.";
            }
		}       
		}
		else {
			 //test for point is not start or end point
        cout<<"The point is out of bound";
        }
    }
		
		template<class A, class B, class C>
    	double Area(A& a, B& b, C& c){
        return 0.5*(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y));    
    }  
};
  
int main() { 
    int choice;

    cout<<"\t1. Implementation of Point"<<endl;
    cout<<"\t2. Implementation of Line Segment"<<endl;
    cout<<"\t3. Test for PLC"<<endl;
    cout<<"\n\tEnter the choice: ";
    
	cin>>choice;
    switch(choice){
        case 1: Point p1;
                p1.inputPoint();
                cout<<"\n\tThe point is: ";
                p1.displayPoint();
            break;
        case 2: Point point1, point2; 
                Line line1;
                line1.line<Point, Point>(point1,point2);
            break;
        case 3: Point firstPt, lastPt, testPt;
                PLC plc;
                plc.plc<Point,Point,Point>(firstPt,lastPt,testPt);
            break;
        default: cout<<"Invalid choice "<<endl; 
    	}

    return 0; 
}

