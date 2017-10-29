//
//  Ellipse.h
//  Computer Graphics PPM
//
//  Created by Miles Tucker on 8/31/17.
//  Copyright © 2017 Miles Tucker. All rights reserved.
//

#ifndef Ellipse_h
#define Ellipse_h
#include "Tools.h"
#include "Image.h"
#include <cmath>
using namespace std;

class Ellipse: public Transformations{
private:
    int xCenter;
    int yCenter;
    int aRadius;
    int bRadius;
    vector<std::pair <int,int>>ellipsePoints;
    vector<std::pair <int,int>>ellipseCenterPoints;
    vector<std::pair <int,int>>fillEllipsePoints;
    vector<std::pair <int,int>>iteratorPoints;

public:
    Ellipse()
    {
        
    }
    
    Ellipse(int xC, int yC, int a, int b)
    {        
        xCenter = xC;
        yCenter = yC;
        aRadius = a;
        bRadius = b;
        ellipseCenterPoints.push_back(std::pair<int, int>(xC, yC));
    }
    
    void buildEllipse(vector<std::pair <int,int>>ellipseCenterPoints)
    {
        double x = aRadius;
        int y = 0;
        bool region = true;
        while(pow(aRadius,2)*y < pow(bRadius,2)*x)
        {
            calculateNextPoint(x, y, region, ellipseCenterPoints);
        }
        region = false;

        while(pow(aRadius,2)*y >= pow(bRadius,2)*x)
        {
            calculateNextPoint(x, y,region,ellipseCenterPoints );
        }
        
        
    }
    
    void calculateNextPoint(double & newX, int & yC, bool region, vector<std::pair <int,int>>ellipseCenterPoints)
    {
        if(region)
        {
        yC++;
        newX = sqrt(pow(aRadius,2) * (1 - (1/ (pow(bRadius,2))*(pow(yC,2)))));
        newX =  round(newX);
        EllipsePoints(newX, yC, ellipseCenterPoints);
        }
        
        else{
            newX--;
            yC = sqrt(pow(bRadius,2) * (1 - (1/ (pow(aRadius,2))*(pow(newX,2)))));
            yC =  round(yC);
            EllipsePoints(newX, yC, ellipseCenterPoints);
        }
        
    }
    
    void EllipsePoints(int x, int y, vector<std::pair <int,int>>ellipseCenterPoints){
        
        ellipsePoints.push_back(std::pair<int, int>(ellipseCenterPoints[0].first + x, ellipseCenterPoints[0].second + y));
        ellipsePoints.push_back(std::pair<int, int>(ellipseCenterPoints[0].first - x, ellipseCenterPoints[0].second + y));
        ellipsePoints.push_back(std::pair<int, int>(ellipseCenterPoints[0].first + x, ellipseCenterPoints[0].second - y));
        ellipsePoints.push_back(std::pair<int, int>(ellipseCenterPoints[0].first - x, ellipseCenterPoints[0].second - y));
    }
    
    void fillEllipse()
    {

        //iterator(xCenter, yCenter, xCenter + aRadius, xCenter - aRadius);
        
        for(int i =0; i<ellipsePoints.size();i++)
        {
            for(int j = i; j<ellipsePoints.size();j++)
            {
                if(ellipsePoints[j].second == ellipsePoints[i].second && ellipsePoints[j].first != ellipsePoints[i].first)
                {
                    iterator(ellipsePoints[i].first, ellipsePoints[i].second, ellipsePoints[j].first, 0);
                    
                }
                
            }
            
        }
        
        fillEllipsePoints.insert(fillEllipsePoints.end(), iteratorPoints.begin(), iteratorPoints.end());

        
    }
    
    void iterator(int x1, int y1, int x2, int x3)
    {
        if(x1<x2)
        {
            for(int i = x1+1; i<x2;i++)
            {
                iteratorPoints.push_back(std::pair<int, int>(i, y1));
                
                
            }
        }
        if(x3!=0)
        {
            for(int i = x3+1; i<x1;i++)
            {
                iteratorPoints.push_back(std::pair<int, int>(i, y1));
                
            }
        }
        else if(x1 == x2)
            return;
        
        else{
            for(int i = x2+1; i<x1;i++)
            {
                iteratorPoints.push_back(std::pair<int, int>(i, y1));
                
            }
        }
    }
    
    bool isAnOutlinePoint(int x, int y)
    {
        for(int i =0;i<ellipsePoints.size();i++)
        {
            if(ellipsePoints[i].first == x && ellipsePoints[i].second == y)return true;
        }
        
        return false;
    }
    
    vector<std::pair <int,int>> getEllipseCenterPoints()
    {
        return ellipseCenterPoints;
    }
    
    vector<std::pair <int,int>> getPoints()
    {
        return ellipsePoints;
    }
    
    vector<std::pair <int,int>> getFillPoints()
    {
        return fillEllipsePoints;
    }
    
};
#endif /* Ellipse_h */
