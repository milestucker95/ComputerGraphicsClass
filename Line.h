//
//  Line.h
//  Computer Graphics PPM
//
//  Created by Miles Tucker on 8/30/17.
//  Copyright © 2017 Miles Tucker. All rights reserved.
//

#ifndef Line_h
#define Line_h
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include "Tools.h"
#include "Transformations.h"
using namespace std;


class Line: public Transformations{
private:
    double xStart;
    double yStart;
   // int zStart;
    double xEnd;
    double yEnd;
    //int zEnd;
    int D;

public:
    Line()
    {
        
    }
    Line( double xSt, double ySt, double xE, double yE)
    {
        xStart = xSt;
        yStart = ySt;
        //zStart = zSt;
        xEnd = xE;
        yEnd = yE;
       // cout << "xstart: " << xStart << " ystart: " << yStart << endl;
        //cout << "xEnd: " << xEnd << " yEnd: " << yEnd << endl;
        //zEnd = zE;
        //D = d;
        initialVertexPoints.push_back(AssignCoordinates2d(xStart, yStart));
        initialVertexPoints.push_back(AssignCoordinates2d(xEnd, yEnd));
    }
    vector<Coordinates>initialVertexPoints;
    vector<Coordinates>vertexPoints;

    vector<Coordinates>fillPoints;

    vector<Coordinates> drawLine( vector<Coordinates>vertexPoints)
    {
        int xSt = vertexPoints[0].x;
        int ySt = vertexPoints[0].y;
        int xE = vertexPoints[1].x;
        int yE = vertexPoints[1].y;
        
        if(abs(ySt-yE)==0)
        {
            if(xSt<= xE)
            {
                for(int i = xSt+1; i< xE;i++)
                {
                    fillPoints.push_back(AssignCoordinates2d(i, ySt));

                }
            }
            
            else{
                for(int i = xE+1; i< xSt;i++)
                {
                    fillPoints.push_back(AssignCoordinates2d(i, ySt));
                }
            }
        }
        
        else if (abs(xSt-xE)==0)
        {
            for(int i = ySt+1; i < yE; i++)
            {
                fillPoints.push_back(AssignCoordinates2d(xSt, i));
            }
            
            for(int i = yE+1; i < ySt; i++)
            {
                fillPoints.push_back(AssignCoordinates2d(xSt, i));
            }
        }
        
        else{
            double m = (yE - ySt)/ double(xE - xSt);
            int yIntercept = ySt - m*(xSt);
            
            if(abs(ySt-yE) > abs(xSt-xE))
            {
                if(ySt < yE)
                {
                    double newX = 0;
                    for(int i = ySt+1; i < yE;i++)
                    {
                        newX = (i-yIntercept)/m;
                        newX = round(newX);
                        fillPoints.push_back(AssignCoordinates2d(newX, i));

                       // insert(newX, i);
                    }
                }
                
                else{
                    double newX = 0;
                    for(int i = yE+1; i < ySt;i++)
                    {
                        newX = (i-yIntercept)/m;
                        newX = round(newX);
                        fillPoints.push_back(AssignCoordinates2d(newX, i));
                       // insert(newX, i);
                    }

                }
            }
            
            else{
                if(xSt < xE)
                {
                    double newY = 0;
                    for(int i = xSt+1; i < xE;i++)
                    {
                        newY = (m*i) + yIntercept;
                        newY = round(newY);
                        fillPoints.push_back(AssignCoordinates2d(i, newY));

                    }
                }
                
                else{
                    double newY = 0;
                    for(int i = xE+1; i < xSt;i++)
                    {
                        newY = (m*i) + yIntercept;
                        newY = round(newY);
                        fillPoints.push_back(AssignCoordinates2d(i, newY));
                    }
                    
                }

            }
        }
        
        return fillPoints;
        
    }
    
    vector<Coordinates> drawLine3d( vector<Coordinates>vertexPoints)
    {
        cout << vertexPoints[0].z << endl;
        int xSt = round((vertexPoints[0].x/vertexPoints[0].z)*D);
        int ySt = round(vertexPoints[0].y / vertexPoints[0].z)*D;
        int xE = round(vertexPoints[1].x/vertexPoints[1].z)*D;
        int yE = round(vertexPoints[1].y / vertexPoints[1].z)*D;
        
        if(abs(ySt-yE)==0)
        {
            if(xSt<= xE)
            {
                for(int i = xSt+1; i< xE;i++)
                {
                    fillPoints.push_back(AssignCoordinates2d(i, ySt));
                    
                }
            }
            
            else{
                for(int i = xE+1; i< xSt;i++)
                {
                    fillPoints.push_back(AssignCoordinates2d(i, ySt));
                }
            }
        }
        
        else if (abs(xSt-xE)==0)
        {
            for(int i = ySt+1; i < yE; i++)
            {
                fillPoints.push_back(AssignCoordinates2d(xSt, i));
            }
            
            for(int i = yE+1; i < ySt; i++)
            {
                fillPoints.push_back(AssignCoordinates2d(xSt, i));
            }
        }
        
        else{
            double m = (yE - ySt)/ double(xE - xSt);
            int yIntercept = ySt - m*(xSt);
            
            if(abs(ySt-yE) > abs(xSt-xE))
            {
                if(ySt < yE)
                {
                    double newX = 0;
                    for(int i = ySt+1; i < yE;i++)
                    {
                        newX = (i-yIntercept)/m;
                        newX = round(newX);
                        fillPoints.push_back(AssignCoordinates2d(newX, i));
                        
                        // insert(newX, i);
                    }
                }
                
                else{
                    double newX = 0;
                    for(int i = yE+1; i < ySt;i++)
                    {
                        newX = (i-yIntercept)/m;
                        newX = round(newX);
                        fillPoints.push_back(AssignCoordinates2d(newX, i));
                        // insert(newX, i);
                    }
                    
                }
            }
            
            else{
                if(xSt < xE)
                {
                    double newY = 0;
                    for(int i = xSt+1; i < xE;i++)
                    {
                        newY = (m*i) + yIntercept;
                        newY = round(newY);
                        fillPoints.push_back(AssignCoordinates2d(i, newY));
                        
                    }
                }
                
                else{
                    double newY = 0;
                    for(int i = xE+1; i < xSt;i++)
                    {
                        newY = (m*i) + yIntercept;
                        newY = round(newY);
                        fillPoints.push_back(AssignCoordinates2d(i, newY));
                    }
                    
                }
                
            }
        }
        
        return fillPoints;
        
    }

    
    vector<Coordinates> getInitialVertexPoints()
    {
        return initialVertexPoints;
    }
    
    vector<Coordinates> getLinePoints()
    {
        return fillPoints;
    }
    
};
#endif /* Line_h */
