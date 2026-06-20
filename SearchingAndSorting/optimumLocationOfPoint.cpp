#include <iostream>
#define sqr(x) ((x) * (x))
#define EPS 1e-6
#define N 5
#include <cmath>


using namespace std;
/**
 * we are given a line in the fox ax+by+c
 * and we are given some point above the line
 *
 * we need to find a point on the line who total
 * distance from all the points is minimum
 *
 * if we imagine a distance-x cordination
 * as we move x to the extreme right or extreme left the distance increases
 * somewhere in between the at some x value the distance is minimum
 *
 * so the distance-x curve is a u-shaped curve and not monotonically
 * increasing nor decreasing hence we cannot apply binary search
 *
 * if not binary you can apply ternary search(dividing the curve in 3 parts )
 *
 * FYI:
 * 1e6: 1000,000
 * -1e6: 1000,000
 * 1e-6: 0.000001
 */

// we need a structure to define a point on the graph
struct point {
    int x;
    int y;
    point(){};
    point(int x, int y) :x(x),y(y){

    }
};
struct line{
    int a,b,c;
    line(){};
    line(int a, int b, int c) : a(a), b(b), c(c) {

    }
};

// method to calculate distance
double dist(double x, double y, point p) {
    return  sqrt(sqr(x-p.x)+sqr(y-p.y));
}

// method that calculates distance front a point on line to
// all given coordinates
double totalDistance(point p[],int n,line l,double X) {
    double res=0;
    double Y=-1*(l.c+l.a*X)/l.b;
    for (int i = 0; i < n; i++) {
        res+=dist(X, Y, p[i]);
    }
    return res;
}


int main(int argc, char *argv[])
{


    double low=-1e6;
    double high=1e6;
    line l(1, -1, -3);
    int points[N][2] = {
        { -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }
    };
    point p[N];
    for (int i = 0; i < N; i++) {
        p[i]=point(points[i][0],points[i][1]);
    }

    while ((high-low)>EPS) {
        double mid1=low+(high-low)/3;
        double mid2=high-(high-low)/3;
        double dist1=totalDistance(p,N ,l, mid1);
        double dist2=totalDistance(p,N ,l, mid2);
        if (dist1<dist2) {
            high=mid2;
        } else {
            low=mid1;
        }
    }
    cout<< totalDistance(p, N, l, (low+high)/2)<<endl;



}
