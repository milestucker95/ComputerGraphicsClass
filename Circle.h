//
//  Circle.h
//  Computer Graphics PPM
//
//  Created by Miles Tucker on 8/30/17.
//  Copyright © 2017 Miles Tucker. All rights reserved.
//

#ifndef Circle_h
#define Circle_h
#include "Tools.h"
using namespace std;

class Circle: public Transformations{
private:
    int xCenter;
    int yCenter;
    int radius;
    vector<Coordinates>circle;
    vector<Coordinates>vectorPoints;
    vector<Coordinates>fillCirclePoints;
    
    
    
    
public:
    Circle()
    {
        
    }
    
    Circle(int xC, int yC, int rC)
    {
        xCenter = xC;
        yCenter = yC;
        radius = rC;
        vectorPoints.push_back(AssignCoordinates2d(xC, yC));
        //buildCircle();
    }
    vector<Coordinates>iteratorPoints;
    
    void buildCircle(vector<Coordinates>points)
    {
        double x = radius;
        int y = 0;
        
        while(x>y)
        {
            calculateNextPoint(x, y, points);
        }
    }
    
    void calculateNextPoint(double & newX, int & yC,vector<Coordinates>points)
    {
        //yC++;
        newX = sqrt((pow(radius,2)) - pow(yC,2));
        newX =  round(newX);
        circlePoints(newX, yC, points);
        yC++;
        
    }
    
    void circlePoints(int x, int y,vector<Coordinates>points){
        circle.push_back(AssignCoordinates2d(points[0].x + x, points[0].y + y));
        circle.push_back(AssignCoordinates2d(points[0].x - x, points[0].y  + y));
        circle.push_back(AssignCoordinates2d(points[0].x + x, points[0].y  - y));
        circle.push_back(AssignCoordinates2d(points[0].x - x, points[0].y  - y));
        circle.push_back(AssignCoordinates2d(points[0].x + y, points[0].y  + x));
        circle.push_back(AssignCoordinates2d(points[0].x - y, points[0].y  + x));
        circle.push_back(AssignCoordinates2d(points[0].x + y, points[0].y  - x));
        circle.push_back(AssignCoordinates2d(points[0].x - y, points[0].y  - x));
    }
    
    
    
    void fillCircle()
    {
        //iterator(points[0].first, points[0].second, points[0].first + radius, points[0].first - radius);
        
        for(int i =0; i<circle.size();i++)
        {
            for(int j = i; j<circle.size();j++)
            {
                if(circle[j].y == circle[i].y && circle[j].x != circle[i].x)
                {
                    iterator(circle[i].x, circle[i].y, circle[j].x, 0);
                    
                }
                
            }
            
        }
        
        fillCirclePoints.insert(fillCirclePoints.end(), iteratorPoints.begin(), iteratorPoints.end());
        
        
    }
    
    void iterator(int x1, int y1, int x2, int x3)
    {
        
        
        if(x1<x2)
        {
            for(int i = x1+1; i<x2;i++)
            {
                if(!isAnOutlinePoint(i, y1))
                {
                    iteratorPoints.push_back(AssignCoordinates2d(i, y1));
                }
                
                
            }
        }
        if(x3!=0)
        {
            for(int i = x3+1; i<x1;i++)
            {
                if(!isAnOutlinePoint(i, y1))
                {
                    iteratorPoints.push_back(AssignCoordinates2d(i, y1));
                }
                
            }
        }
        else if(x1 == x2)
            return;
        
        else{
            for(int i = x2+1; i<x1;i++)
            {
                if(!isAnOutlinePoint(i, y1))
                {
                    iteratorPoints.push_back(AssignCoordinates2d(i, y1));
                }
                
            }
        }
    }
    
    bool isAnOutlinePoint(int x, int y)
    {
        for(int i =0;i<circle.size();i++)
        {
            if(circle[i].x == x && circle[i].y == y)return true;
        }
        
        return false;
    }
    
    int getX() const
    {
        return xCenter;
    }
    
    int getY() const
    {
        return yCenter;
    }
    
    int getRadius() const
    {
        return radius;
    }
    
    
    vector<Coordinates> getCircleCenterPoints()
    {
        return vectorPoints;
    }
    
    vector<Coordinates> getPoints()
    {
        return circle;
    }
    
    vector<Coordinates> getFillPoints()
    {
        return fillCirclePoints;
    }
};

#endif /* Circle_h */

