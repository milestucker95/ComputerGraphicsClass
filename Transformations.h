//
//  Transformations.h
//  Computer Graphics PPM
//
//  Created by Miles Tucker on 9/15/17.
//  Copyright © 2017 Miles Tucker. All rights reserved.
//

#ifndef Transformations_h
#define Transformations_h
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Transformations{
    
private:
    vector<Coordinates>receivedVertexPoints;

public:

    Transformations()
    {
        
    }
    
    void Translate(vector<Coordinates> points, int shiftX, int shiftY)
    {
        receivedVertexPoints.clear();

        for(int i =0;i<points.size();i++)
        {
            receivedVertexPoints.push_back(AssignCoordinates2d(points[i].x + shiftX, points[i].y + shiftY));
        }
        
    }
    
    void Translate3d(vector<Coordinates> points, double shiftX, double shiftY)
    {


        double xC = ((findXMax(points) + findXMin(points))/(float)(2));
        double yC = ((findYMax(points) + findYMin(points))/(float)(2));
        

        double newShiftX = shiftX - xC;
        double newShiftY = shiftY - yC;
        
        receivedVertexPoints.clear();
        
        for(int i =0;i<points.size();i++)
        {
            receivedVertexPoints.push_back(AssignCoordinates2d(points[i].x + newShiftX, points[i].y + newShiftY));
            
        }

    }

    void Rotate(vector<Coordinates> vertexPoints, int xRotate, int yRotate, double degrees)
    {
        receivedVertexPoints.clear();

        double radians = convertDegreesToRadians(degrees);
        int xT = xRotate;
        int yT = yRotate;
        for(int i =0;i<vertexPoints.size();i++)
        {
            vertexPoints[i].x -= xT;
            vertexPoints[i].y -= yT;

            int prevXn = vertexPoints[i].x;

            double xn = round((vertexPoints[i].x * cos(radians)) - (vertexPoints[i].y * sin(radians)));
            double yn = round((vertexPoints[i].y * cos(radians)) + (vertexPoints[i].x * sin(radians)));

             vertexPoints[i].x = xn;
             vertexPoints[i].y = yn;
            
            vertexPoints[i].x += xT;
            vertexPoints[i].y += yT;

        }
        receivedVertexPoints.insert(receivedVertexPoints.begin(), vertexPoints.begin(),vertexPoints.end());

    }
    
    void Scale(vector<Coordinates> points, int xTranslatePoint, int yTranslatePoint, double scaleX, double scaleY)
    {
        receivedVertexPoints.clear();
        int xT = xTranslatePoint;
        int yT = yTranslatePoint;
        
        for(int i =0;i<points.size();i++)
        {
            points[i].x -= xT;
            points[i].y -= yT;
            points[i].x = points[i].x * scaleX;
            points[i].y = points[i].y * scaleY;
            points[i].x += xT;
            points[i].y += yT;
            
        }
        receivedVertexPoints.insert(receivedVertexPoints.begin(), points.begin(),points.end());

    }

    
    double findXMin(vector<Coordinates> points)
    {
        double min = points[0].x;
        
        for(int i =0;i<points.size();i++)
        {
            if(points[i].x<min)
            {
                min = points[i].x;
            }
        }
        
        return min;
    }
    
    double findXMax(vector<Coordinates> points)
    {
        double max = points[0].x;
        
        for(int i =0;i<points.size();i++)
        {
            if(points[i].x>max)
            {
                max = points[i].x;
            }
        }
        
        return max;
    }
    
    double findYMin(vector<Coordinates> points)
    {
        double min = points[0].y;
        
        for(int i =0;i<points.size();i++)
        {
            if(points[i].y<min)
            {
                min = points[i].y;
            }
        }
        
        return min;
    }
    
    double findYMax(vector<Coordinates> points)
    {
        double max = points[0].y;
        
        for(int i =0;i<points.size();i++)
        {
            if(points[i].y>max)
            {
                max = points[i].y;
            }
        }
        
        return max;
    }
    
    
    vector<Coordinates> getPoints()
    {
        return receivedVertexPoints;
    }
    
    double convertDegreesToRadians(int degrees)
    {
        return degrees * M_PI/ 180.00;
    }

};
#endif /* Transformations_h */
