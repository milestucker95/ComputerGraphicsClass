//
//  Polygon.h
//  Computer Graphics PPM
//
//  Created by Miles Tucker on 9/1/17.
//  Copyright © 2017 Miles Tucker. All rights reserved.
//

#ifndef Polygon_h
#define Polygon_h
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include "Tools.h"
#include<cmath>
#include "Line.h"
#include "Transformations.h"
using namespace std;


class Polygon: public Line{

private:
    vector<Coordinates>polygonVertexPoints;
    vector<Coordinates>polygonLinePoints;
    vector<Coordinates>totalPoints;
    
public:
    
    Polygon(){
        
    }
   
    Polygon(vector<Coordinates>newPoints)
    {
        totalPoints = newPoints;
    }
    
    void getPolygonPoints(vector<Coordinates>newPoints){
        
        for(int i =0; i<newPoints.size();i++)
        {
            //cout << "x: " << newPoints[i].first << " y: " << newPoints[i].second << endl;
            polygonVertexPoints.push_back(AssignCoordinates2d(newPoints[i].x, newPoints[i].y));
            
        }
        //polygonVertexPoints.push_back(std::pair<int, int>(newPoints[0].first, newPoints[0].second));
        polygonLinePoints.insert(polygonLinePoints.end(), polygonVertexPoints.begin(), polygonVertexPoints.end());
    }
    
    void drawPolygon()
    {
        int size = polygonVertexPoints.size();
        //cout << "polygon points size: " << size << endl;
        for(int i =1;i<polygonVertexPoints.size();i++)
        {
            //cout << "draw " << endl;
            vector<Coordinates>initialPoints = Line :: Line(polygonVertexPoints[i-1].x, polygonVertexPoints[i-1].y,polygonVertexPoints[i].x, polygonVertexPoints[i].y).getInitialVertexPoints();
            
            vector<Coordinates>edgePoints = Line::drawLine(initialPoints);
            
            polygonLinePoints.insert(polygonLinePoints.end(), edgePoints.begin(), edgePoints.end());

            
        }
        
        vector<Coordinates>initialPoints = Line :: Line(polygonVertexPoints[0].x, polygonVertexPoints[0].y,polygonVertexPoints[size-1].x, polygonVertexPoints[size-1].y).getInitialVertexPoints();
        
        vector<Coordinates>edgePoints = Line::drawLine(initialPoints);
        
        polygonLinePoints.insert(polygonLinePoints.end(), edgePoints.begin(), edgePoints.end());

        //cout << "total size " << totalPoints.size() << endl;
    }
    
    void fill()
    {
        
        for(int i = findMinYVal()+1;i<findMaxYVal();i++)
        {
            addFillerPoints(i);

        }
        
        
        
    }
    
    void addFillerPoints(int a)
    {
        vector<int> intersections;
        
        intersections = findXIntersections(polygonVertexPoints, a);
        int size = intersections.size();
        
        for(int i = 0;i<intersections.size();i+=2)
        {
            int count = intersections[i];
            int limit = intersections[i+1];
            for(int j = count+1; j<limit;j++)
            {
                totalPoints.push_back(AssignCoordinates2d(j, a));

            }
        }
    }
    int findMinYVal()
    {
        int min = polygonVertexPoints[0].y;
        for(int i = 0;i<polygonVertexPoints.size();i++)
            {
                if(polygonVertexPoints[i].y<min)
                {
                    min = polygonVertexPoints[i].y;
                }
            }
        return min;
    }
    
    int findMaxYVal()
    {
        int max = polygonVertexPoints[0].y;
        for(int i = 0;i<polygonVertexPoints.size();i++)
        {
            if(polygonVertexPoints[i].y>max)
            {
                max = polygonVertexPoints[i].y;
            }
        }
        return max;
    }
    
    vector<int> sortVector(vector<int> intersections)
    {
        int temp;
        for(int i =0;i<intersections.size();i++)
        {
            for(int i = 0; i<intersections.size()-1;i++)
            {
                if(intersections[i]> intersections[i+1])
                {
                temp = intersections[i];
                intersections[i] = intersections[i+1];
                intersections[i+1] = temp;
                }
            }
        }
        return intersections;
    }
    
    vector<int> findXIntersections(vector<Coordinates> points, int val)
    {
        vector<int> intersections;
        int size = points.size();
        for(int i =1;i<points.size();i++)
        {
            double xIntercept;
            if(abs(points[i-1].x-points[i].x) == 0)
            {
               // cout << "horizontal val: " << val << endl;
                xIntercept = (double(points[i].x - points[i-1].x)/double(points[i].y-points[i-1].y))*val - (double(points[i].x - points[i-1].x)/double(points[i].y-points[i-1].y))*points[i-1].y + points[i-1].x;
            }
            else if (abs(points[i-1].y-points[i].y) == 0)
            {
                xIntercept = -1;
            }
            
            else{
                    double m = double(points[i].y-points[i-1].y)/double(points[i].x-points[i-1].x);
                    int b = points[i-1].y - m*(points[i-1].x);
                    xIntercept = (val-b)/m;
                    xIntercept = round(xIntercept);
            }
            
            if(xIntercept!=-1 && isInBound(points[i-1].x, points[i].x, points[i-1].y, points[i].y,  xIntercept, val))
            {
                if(std::find(intersections.begin(), intersections.end(), xIntercept) == intersections.end()) {
                intersections.push_back(xIntercept);
                }

            }
        }
        double xIntercept;
        if(abs(points[size-1].x-points[0].x) == 0)
        {
            xIntercept = (double(points[size-1].x - points[0].x)/double(points[0].y-points[size-1].y))*val - (double(points[0].x - points[size-1].x)/double(points[0].y-points[size-1].y))*points[size-1].y + points[size-1].x;
        }
        else if (abs(points[size-1].y-points[0].y) == 0)
        {
            xIntercept = -1;
        }
        
        else{
            double m = double(points[0].y-points[size-1].y)/double(points[0].x-points[size-1].x);
            int b = points[size-1].y - m*(points[size-1].x);
            xIntercept = (val-b)/m;
            xIntercept = round(xIntercept);
        }
        
        if(xIntercept!=-1 && isInBound(points[size-1].x, points[0].x, points[size-1].y, points[0].y,  xIntercept, val))
        {
            /*if(val ==140){cout << "val: " << val << endl;
             //cout << "x: " << xIntercept << endl;
             }
             */
            if(std::find(intersections.begin(), intersections.end(), xIntercept) == intersections.end())
            {
                intersections.push_back(xIntercept);

            }
            
        }


        intersections = sortVector(intersections);

        return intersections;
    }
    
    bool isInBound(int xSt, int xEnd,int ySt, int yEnd, int xVal, int yVal)
    {
        if(xSt > xEnd)
        {
            if(ySt>yEnd)
            {
                if((xVal>=xEnd && xVal<= xSt) && (yVal>=yEnd && yVal<= ySt))
                {
                    return (true);
                }
            
            else{
               // cout << " out of bounds" << endl;
                return false;

                }
            }
            
            else{
                if((xVal>=xEnd && xVal<= xSt) && (yVal>=ySt && yVal<= yEnd))
                {
                   // cout << " in bound" << endl;
                    return (true);
                }
                
                else{
                   // cout << " out of bounds" << endl;
                    return false;
                    
                }
            }

        }
        else{
            
            if(ySt<yEnd)
            {
                if((xVal>=xSt && xVal<= xEnd) && (yVal>=ySt && yVal<= yEnd) )
                {
               // cout << "xSt: " << xSt << " xEnd: " <<xEnd << " xVal: " << xVal << endl;
               // cout << " in bounds" << endl;
                return (true);

                }
                else{
                  //  cout << " out of bounds" << endl;
                    return false;
                }
            }
            
            else
            {
                if((xVal>=xSt && xVal<= xEnd) && (yVal>=yEnd && yVal<= ySt) )
                {
                 //   cout << " in bounds" << endl;
                    return (true);
                    
                }
                else{
                   // cout << " out of bounds" << endl;
                    return false;
                }
            }

        }
    }
    
    bool isVertexPoint(int x, int y)
    {

        
        for(int i =0;i<polygonVertexPoints.size();i++)
        {
            if(x == polygonVertexPoints[i].x && y == polygonVertexPoints[i].y)return true;
        }
        return false;
    }
    
    vector<Coordinates> getPoints()
    {
        return polygonLinePoints;
    }
    vector<Coordinates> getPolygonPoints()
    {
        return polygonVertexPoints;
    }
    
    vector<Coordinates> getFillPoints()
    {
        return totalPoints;
    }
};
#endif /* Polygon_h */
