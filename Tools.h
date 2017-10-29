//
//  Tools.h
//  Computer Graphics PPM
//
//  Created by Miles Tucker on 8/30/17.
//  Copyright © 2017 Miles Tucker. All rights reserved.
//

#ifndef Tools_h
#define Tools_h
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
struct Pixels{
    int r, g, b;
};

struct Lighting{
    double ka,kd,ks, n;
};
struct Coordinates{
    double x, y, z;
    Pixels color;
    Lighting lighting;
  //  Coordinates*next;

};

struct SphereCoordinates{
    Coordinates center;
    double r;
    Lighting lighting;
    //  Coordinates*next;
    
};

struct Polygon{
    vector<Coordinates> points;
    Pixels color;
    //  Coordinates*next;
    
};

struct Window {
    Coordinates tl;
    Coordinates br;
    vector<Coordinates> pixels;
    
};

double round(double d)
{
    if(std::abs(d) - int(d) >=0.50)
    {
        return ceil(d);
    }
    else
        return floor(d);
}

double dotProduct(Coordinates nVector, Coordinates lightRay)
{
    double dotProd;
    
    dotProd = (nVector.x * lightRay.x) + (nVector.y * lightRay.y) + (nVector.z * lightRay.z);
    
    return dotProd;
    
}

int newRound(double d)
{
    return (int)d;
}



vector<Coordinates> roundVectorPoints(vector <Coordinates> points)
{
    for(int i =0;i<points.size();i++)
    {
        points[i].x = round(points[i].x);
        //cout << "rounded points x: " << round(points[i].x) << endl;
        points[i].y = round(points[i].y);
        //cout << "rounded points y: " << round(points[i].y) << endl;

        points[i].z = round(points[i].z);
    }
    
    return points;
}

Coordinates AssignCoordinates2d(double x, double y)
{
    Coordinates coordinates;
    coordinates.x = x;
    coordinates.y = y;
    coordinates.z = 0;
 
    return coordinates;
}

Coordinates AssignCoordinates3d(double x, double y, double z)
{
    Coordinates coordinates;
    coordinates.x = x;
    coordinates.y = y;
    coordinates.z = z;
    
    return coordinates;
}

Coordinates multiplyVectors(Coordinates nVector, Coordinates lightRay)
{
    Coordinates newVector;
    
    newVector = AssignCoordinates3d(nVector.x * lightRay.x, nVector.y * lightRay.y, nVector.z * lightRay.z);
    
    return newVector;
}

double magnitudeOfVector(Coordinates v)
{
    return sqrt(pow(v.x,2.0) + pow(v.y,2.0) + pow(v.z,2.0));

}

Coordinates negateVector(Coordinates v)
{
    v.x = -v.x;
    v.y = -v.y;
    v.z = -v.z;
    
    return v;
}

Coordinates scaleVector(Coordinates v, double scale)
{
    v.x = scale * v.x;
    v.y = scale * v.y;
    v.z = scale * v.z;
    
    return v;
}

Coordinates subtractVectors(Coordinates v1, Coordinates v2)
{
    return AssignCoordinates3d(v1.x-v2.x, v1.y-v2.y, v1.z-v2.z);
}
Coordinates convert3dTo2d(double x, double y, double z, int d)
{
    Coordinates coordinates;
    coordinates.x = ((x/float(z))*d);
    coordinates.y = ((y/float(z))*d);
    coordinates.z = 0;
    
    //std::cout << "x: " << coordinates.x << " y: " << coordinates.y << std::endl;
    return coordinates;
    
}
Pixels AssignPixels(int r, int g, int b)
{
    Pixels pixel;
    pixel.r = r;
    pixel.g = g;
    pixel.b = b;

    
    return pixel;
}

Coordinates AssignPointsAndColor(Coordinates point, Pixels color)
{
    Coordinates coordinates;
    coordinates.x = point.x;
    coordinates.y = point.y;
    coordinates.z = point.z;
    coordinates.color = color;
    
    
    return coordinates;
}

Coordinates AssignPointsAndColorAndLighting(Coordinates point, Pixels color, double ka,double kd, double ks, double n)
{
    Coordinates coordinates;
    coordinates.x = point.x;
    coordinates.y = point.y;
    coordinates.z = point.z;
    coordinates.color = color;
    coordinates.lighting.ka = ka;
    coordinates.lighting.kd = kd;
    coordinates.lighting.ks = ks;
    coordinates.lighting.n = n;
    
    
    return coordinates;
}
SphereCoordinates AssignSphereWithLighting(Coordinates point, double r, Pixels color, double ka,double kd, double ks, double n )
{
    SphereCoordinates s;
    s.center.x = point.x;
    s.center.y = point.y;
    s.center.z = point.z;
    s.r = r;
    s.center.color = color;
    s.lighting.ka = ka;
    s.lighting.kd = kd;
    s.lighting.ks = ks;
    s.lighting.n = n;
    
    return s;
}

SphereCoordinates AssignSphere(Coordinates point, double r, Pixels color )
{
    SphereCoordinates s;
    s.center.x = point.x;
    s.center.y = point.y;
    s.center.z = point.z;
    s.r = r;
    s.center.color = color;
    
    return s;
}


Window ViewWindow(Coordinates tl, Coordinates br) {
    Window window;
    window.tl = tl;
    window.br = br;
    return window;
}

#endif /* Tools_h */
