//
//  Transformations3d.h
//  Computer Graphics PPM
//
//  Created by Miles Tucker on 9/29/17.
//  Copyright © 2017 Miles Tucker. All rights reserved.
//

#ifndef Transformations3d_h
#define Transformations3d_h
#include<iostream>
#include<cmath>
#include<vector>
#include "Tools.h"
using namespace std;
class Transformations3d{
    
private:
    
    
     vector<Coordinates>receivedVertexPoints;
    
     public:
    struct UVN{
        float first,second,third;
    };
     vector<UVN> initializeUVNPoints()
     {
         vector<UVN>uvnPoints;

     uvnPoints.push_back(AssignUVNCoordinates(1,0,0));
     uvnPoints.push_back(AssignUVNCoordinates(0, 1, 0));
     uvnPoints.push_back(AssignUVNCoordinates(0, 0, 1));

         return uvnPoints;
     }
    
    vector<UVN> rotateUVNPoints(vector<UVN>uvnPoints, float degrees)
    {
        float radians = Degrees_to_Radians(degrees);

        vector<UVN>uvnPrimePoints;
        for(int i =0;i<uvnPoints.size();i++)
        {
            float first, second, third;
            first = uvnPoints[i].first * cos(radians) + uvnPoints[i].third * sin(radians);
            second = uvnPoints[i].second;
            third = uvnPoints[i].third * cos(radians) - uvnPoints[i].first * sin(radians);
            uvnPrimePoints.push_back(AssignUVNCoordinates(first, second, third));
        }
        //cout << "final rotated uvn Points: " << endl;
       /* for(int i =0; i<uvnPrimePoints.size();i++)
        {
            cout << uvnPrimePoints[i].first << " " << uvnPrimePoints[i].second << " " << uvnPrimePoints[i].third << endl;
        }
         */
        return uvnPrimePoints;
    }
    
    vector<UVN> tiltUVNPoints(vector<UVN>uvnPoints, float degrees)
    {
        float radians = Degrees_to_Radians(degrees);

        vector<UVN>uvnPrimePoints;

        for(int i =0;i<uvnPoints.size();i++)
        {
            double first, second, third;
            first = uvnPoints[i].first;
            second = (uvnPoints[i].second * cos(radians))- (uvnPoints[i].third * sin(radians));
            third = (uvnPoints[i].third * cos(radians)) + (uvnPoints[i].second * sin(radians));
            uvnPrimePoints.push_back(AssignUVNCoordinates(first, second, third));
        }
        
        //cout << "tilted points: " << endl;
        /*for(int i =0; i<uvnPrimePoints.size();i++)
        {
            cout << uvnPrimePoints[i].first << " " << uvnPrimePoints[i].second << " " << uvnPrimePoints[i].third << endl;
        }
         */
      
        return uvnPrimePoints;
    }
    
    Coordinates wireFrame3dAlignment(Coordinates vertexPoints, Coordinates vrpPoints, vector<UVN>uvnPoints, int dn)
    {
            vertexPoints.x  = vertexPoints.x - vrpPoints.x;
            vertexPoints.y = vertexPoints.y - vrpPoints.y;
            vertexPoints.z = vertexPoints.z - vrpPoints.z;
            
            double x, y, z;
            x = vertexPoints.x * uvnPoints[0].first + (vertexPoints.y * uvnPoints[0].second )+ vertexPoints.z * uvnPoints[0].third;
            y = vertexPoints.x * uvnPoints[1].first + (vertexPoints.y * uvnPoints[1].second )+ vertexPoints.z * uvnPoints[1].third;
            z = vertexPoints.x * uvnPoints[2].first + (vertexPoints.y * uvnPoints[2].second )+ vertexPoints.z * uvnPoints[2].third;

            z = z-dn;
            vertexPoints.x = x;
            vertexPoints.y = y;
            vertexPoints.z = z;
            
           // printf("Vertices[i]: (%.4f, %.4f, %.4f)\n", x, y, z);
        
        return vertexPoints;
    }
    
     UVN AssignUVNCoordinates(double u, double v, double n)
     {
         UVN coordinates;
         coordinates.first = u;
         coordinates.second = v;
         coordinates.third = n;
     
         return coordinates;
     }
    

    double convertDegreesToRadians(int degrees)
    {
        return degrees * M_PI/ 180.00;
    }
    
    inline float Degrees_to_Radians(float angle){ //printf("this is the angle in radian: %f\n", (angle * 1.0 * M_PI)/(1.0 * 180));
        return (angle * 1.0 * M_PI)/(1.0 * 180); }
};

#endif /* Transformations3d_h */
