//
//  LightingUtils.h
//  Computer Graphics PPM
//
//  Created by Miles Tucker on 10/15/17.
//  Copyright © 2017 Miles Tucker. All rights reserved.
//

#ifndef LightingUtils_h
#define LightingUtils_h
#include "Tools.h"
#include<cmath>
#include<climits>
//#include "Polygon.h"


class LightingUtils {
private:
    vector<vector<Coordinates>>polygons;
    vector<SphereCoordinates> spheres;
    double radius;
    double xL, yL;
    double dn;
    Coordinates vrP;
    Window window;
    Coordinates LightSource;
    int r,g,b;
    
public:
    struct NVector{
        double A, B, C,D;
        
    };
    vector<Coordinates> Intersections;
    vector<Coordinates> totalPoints;
    
    
    LightingUtils(vector<vector<Coordinates>> polys, vector<SphereCoordinates>sphs)
    {
        polygons = polys;
        spheres = sphs;
    }
    NVector PolygonPlaneAlgorithm(vector<Coordinates>points)
    {
        NVector nVector;
        Coordinates VPoints13;
        Coordinates VPoints12;
        VPoints12 = AssignCoordinates3d(points[1].x-points[0].x, points[1].y-points[0].y, points[1].z-points[0].z);
        VPoints13 = AssignCoordinates3d(points[2].x-points[0].x, points[2].y-points[0].y, points[2].z-points[0].z);
        
        nVector.A = VPoints13.y * VPoints12.z - VPoints13.z * VPoints12.y;
        nVector.B = VPoints13.z * VPoints12.x - VPoints13.x * VPoints12.z;
        nVector.C = VPoints13.x * VPoints12.y - VPoints13.y * VPoints12.x;
        
        nVector.D = -((nVector.A * points[0].x) + (nVector.B * points[0].y) + (nVector.C * points[0].z));
        
        return nVector;
    }
    
    char ChoosingMajorPlane(NVector nVector)
    {
        if(abs(nVector.A)>= abs(nVector.B) && abs(nVector.A) >= abs(nVector.C))return 'A';
        else if(abs(nVector.B) >= abs(nVector.A) && abs(nVector.B) >= abs(nVector.C))return 'B';
        else return 'C';
        
    }
    
    vector<Coordinates> AssignMultiplePointsToPolygonPlane(vector<Coordinates>points, char plane)
    {
        if(plane == 'A')
        {
            for(int i = 0 ; i<points.size();i++)
            {
                points[i].x = points[i].y;
                points[i].y = points[i].z;
                points[i].z = 0;
                
            }
        }
        
        else if(plane == 'B')
        {
            for(int i = 0 ; i<points.size();i++)
            {
                points[i].x = points[i].x;
                points[i].y = points[i].z;
                
            }
        }
        
        else{
            for(int i = 0 ; i<points.size();i++)
            {
                points[i].z = 0;
                
            }
        }
        
        return points;
    }
    
    Coordinates AssignPointToPlane(Coordinates points, char plane)
    {
        if(plane == 'A')
        {
            points.x = points.y;
            points.y = points.z;
            points.z = 0;
        }
        
        else if(plane == 'B')
        {
            points.x = points.x;
            points.y = points.z;
        }
        
        else{
            
            points.z = 0;
        }
        
        return points;
    }
    
    //Function checks if point is on the polygon surface
    bool CheckOnSurface(vector<Coordinates>points, Coordinates testPoint, char plane)
    {
        //counter variables for lines to left, right, and equal to test point
        int countLeft = 0;
        int countRight = 0;
        int verticesCounter = 0;
        int size = points.size()-1;
        //converting testpoint to 2d for appropriate plane
        testPoint = AssignPointToPlane(testPoint, plane);
        points = AssignMultiplePointsToPolygonPlane(points, plane);
        for(int n =1;n<points.size();n++)
        {
            
            
            //t must be in range [0,1]
            if(points[n].y != points[n-1].y)
            {
                double t = (testPoint.y - points[n-1].y)/(points[n].y - points[n-1].y);
                double i = points[n-1].x + t * (points[n].x - points[n-1].x);
                double j = points[n-1].y + t * (points[n].y - points[n-1].y);
                
                if(t>=0 && t<=1)
                {
                    if(i>=testPoint.x)countRight+=1;
                    if(i<=testPoint.x) countLeft +=1;
                }
            }
        }
        
        if(points[size].y != points[0].y)
        {
            
            double t = (testPoint.y - points[size].y)/(points[0].y - points[size].y);
            double i = points[size].x + t * (points[0].x - points[size].x);
            double j = points[size].y + t * (points[0].y - points[size].y);
            if(t>=0 && t<=1)
            {
                if(i>=testPoint.x)countRight+=1;
                if(i<=testPoint.x) countLeft +=1;
            }
        }
        //returns true if the test point is on the surface, false otherwise
        return ((countLeft >0 && countRight >0));
        
        
    }
    
    
    Coordinates SphereIntersection(SphereCoordinates sphere, Coordinates coP, Coordinates currentWindow, int r)
    {
        vector<Coordinates>sphereIntersections;
        double A, B,C;
        A = pow((currentWindow.x - coP.x),2.0) + pow((currentWindow.y - coP.y),2.0) + pow((currentWindow.z - coP.z),2.0);
        B = 2.0 * ((currentWindow.x - coP.x)*(coP.x - sphere.center.x) + (currentWindow.y - coP.y)*(coP.y - sphere.center.y)
                   + (currentWindow.z - coP.z)*(coP.z - sphere.center.z));
        C = pow((coP.x - sphere.center.x),2.0) + pow((coP.y - sphere.center.y),2.0) + pow((coP.z - sphere.center.z),2.0) - pow(r,2.0);
        
        double t1 = (-B + sqrt( pow(B,2.0) - (4.0 * A * C)))/(2.0*A);
        double t2 = (-B - sqrt( pow(B,2.0) - (4.0 * A * C)))/(2.0*A);
        
        if((pow(B,2.0) - (4 * A * C)>=0) && t1>=0 && t2>=0)
        {
            if(t1>0 && t2>0 && t1!=t2)
            {
                double min;
                if(t1<=t2)min = t1;
                else min = t2;
                
                double x,y,z;

                x = coP.x + min * (currentWindow.x - coP.x);
                y = coP.y + min * (currentWindow.y - coP.y);
                z = coP.z + min * (currentWindow.z - coP.z);
                //cout << "x : " << x << " y: " << y << " z: " << z << endl;
                Coordinates newPoint = AssignPointsAndColorAndLighting(AssignCoordinates3d(x, y, z), sphere.center.color, sphere.lighting);
                newPoint.isPoly = false;
                Coordinates nVector = subtractVectors(newPoint, sphere.center);
                newPoint.nVector.A = nVector.x;
                newPoint.nVector.B = nVector.y;
                newPoint.nVector.C = nVector.z;

//                double pa,pd,ps;
                //Change color based on light source for intersection points
//
//                pa = AmbientLight(sphere.lighting.ka, 1);
//                Coordinates nVector = subtractVectors(newPoint, sphere.center);
//                pd = DiffuseReflection(nVector.x, nVector.y, nVector.z, sphere.lighting.kd, currentWindow,newPoint, coP,false);
//                ps = specularReflection(nVector.x, nVector.y, nVector.z, sphere.lighting.ks, sphere.lighting.n, currentWindow, newPoint, coP,false);
               // cout << "sphere pa pd ps: " << pa << "   " << pd << "   " << ps << endl;
//                newPoint.color.r = newPoint.color.r * (pa + pd) + ps;
//                newPoint.color.g = newPoint.color.g * (pa + pd) + ps;
//                newPoint.color.b = newPoint.color.b * (pa + pd) + ps;
                //cout << "newPoint : " << newPoint.color.r << " " << newPoint.color.g << " " << newPoint.color.b << endl;
               // cout << "new Point sphere: " << newPoint.x << " " << newPoint.y << " " << newPoint.z << endl;
                return newPoint;
                
            }
        }
        //cout << "int max: " << INT_MAX << endl;
        return AssignPointsAndColor(AssignCoordinates3d(INT_MAX, INT_MAX, INT_MAX), AssignPixels(0, 0, 0));
        
        
    }
    
    Coordinates SphereShadowIntersection(SphereCoordinates sphere, Coordinates coP, Coordinates i, int r)
    {
       vector<Coordinates>sphereIntersections;
        //Coordinates i = AssignCoordinates3d(50, 50, 40);

        double A, B,C;
        A = pow((LightSource.x - i.x),2.0) + pow((LightSource.y - i.y),2.0) + pow((LightSource.z - i.z),2.0);
        B = 2.0 * ((LightSource.x - i.x)*(i.x - sphere.center.x) + (LightSource.y - i.y)*(i.y - sphere.center.y)
                   + (LightSource.z - i.z)*(i.z - sphere.center.z));
        C = pow((i.x - sphere.center.x),2.0) + pow((i.y - sphere.center.y),2.0) + pow((i.z - sphere.center.z),2.0) - pow(r,2.0);
        
        double t1 = (-B + sqrt( pow(B,2.0) - (4.0 * A * C)))/(2.0*A);
        double t2 = (-B - sqrt( pow(B,2.0) - (4.0 * A * C)))/(2.0*A);
        //cout << "checking for sphere shadow" << endl;
        //test intersection
       
       
        if((pow(B,2.0) - (4 * A * C)>=0) && t1>=0 && t2>=0)
        {
            if(t1>0 && t2>0 && t1!=t2)
            {
                double min;
                if(t1<=t2)min = t1;
                else min = t2;
             
               // cout << "sphere min: " << min << endl;
                double x,y,z;
                
                x = i.x + min * (LightSource.x - i.x);
                y = i.y + min * (LightSource.y - i.y);
                z = i.z + min * (LightSource.z - i.z);
                
                Coordinates newPoint = AssignPointsAndColor(AssignCoordinates3d(x, y, z), sphere.center.color);
                newPoint.t = min;
                double pa,pd,ps;
                //Change color based on light source for intersection points
                
                //pa = AmbientLight(sphere.lighting.ka, 1);
                //Coordinates nVector = subtractVectors(newPoint, sphere.center);
                //pd = DiffuseReflection(nVector.x, nVector.y, nVector.z, sphere.lighting.kd, currentWindow,newPoint, coP,false);
//                ps = specularReflection(nVector.x, nVector.y, nVector.z, sphere.lighting.ks, sphere.lighting.n, currentWindow, newPoint, coP,false);
//                newPoint.color.r = newPoint.color.r * (pa + pd) + ps;
//                newPoint.color.g = newPoint.color.g * (pa + pd) + ps;
//                newPoint.color.b = newPoint.color.b * (pa + pd) + ps;
                
                return newPoint;
                
            }
        }
        Coordinates noPointFound = AssignPointsAndColor(AssignCoordinates3d(INT_MAX, INT_MAX, INT_MAX), AssignPixels(0, 0, 0));
        noPointFound.t = -1;
        return noPointFound;
        
        
    }
    
    
    Coordinates PolygonIntersection(vector<Coordinates> vertices, Coordinates coP, Coordinates currentWindow)
    {
        vector<Coordinates>polygonIntersections;
        //Get the normal vector
        NVector nVector = PolygonPlaneAlgorithm(vertices);
        //Choosing what plane the object is on
        char plane = ChoosingMajorPlane(nVector);
        double denominator = (nVector.A*(currentWindow.x - coP.x) + nVector.B*(currentWindow.y - coP.y) + nVector.C*(currentWindow.z - coP.z));
        double t = -(((nVector.A * coP.x) + (nVector.B * coP.y) + (nVector.C * coP.z) + nVector.D)/denominator);
        double x,y,z;
        Coordinates i = AssignCoordinates3d(50, 50, 40);

        if(denominator != 0 && t>=0)
        {
            x = coP.x + t * (currentWindow.x - coP.x);
            y = coP.y + t * (currentWindow.y - coP.y);
            z = coP.z + t * (currentWindow.z - coP.z);
            
            Coordinates newPoint = AssignPointsAndColorAndLighting(AssignCoordinates3d(x, y, z), vertices[0].color, vertices[0].lighting);
            newPoint.nVector.A = nVector.A;
            newPoint.nVector.B = nVector.B;
            newPoint.nVector.C = nVector.C;
            newPoint.isPoly = true;
            
            
            
            if(CheckOnSurface(vertices, newPoint, plane)) {
                //Change color based on light source for intersection points
//                double pa,pd,ps;
//                pa = AmbientLight(vertices[0].lighting.ka, 1);
//                pd = DiffuseReflection(nVector.A, nVector.B, nVector.C, vertices[0].lighting.kd, currentWindow,newPoint, coP, true);
//                ps = specularReflection(nVector.A, nVector.B, nVector.C, vertices[0].lighting.ks, vertices[0].lighting.n, currentWindow, newPoint, coP, true);
//                newPoint.color.r = newPoint.color.r * (pa + pd) + ps;
//                newPoint.color.g = newPoint.color.g * (pa + pd) + ps;
//                newPoint.color.b = newPoint.color.b * (pa + pd) + ps;
               // cout << "new Point polygon: " << newPoint.x << " " << newPoint.y << " " << newPoint.z << endl;
               // cout << "polygon pa pd ps: " << pa << "   " << pd << "   " << ps << endl;

                //cout << "in poly algo: " << newPoint.nVector.A << endl;
                return newPoint;
                
            }
        }
       // cout << "hello" << endl;

        return AssignPointsAndColor(AssignCoordinates3d(INT_MAX, INT_MAX, INT_MAX), AssignPixels(0, 0, 0));;
    }
    
    Coordinates PolygonShadowIntersection(vector<Coordinates> vertices, Coordinates coP, Coordinates i, Coordinates currentWindow)
    {
        vector<Coordinates>polygonIntersections;
        //Get the normal vector
        NVector nVector = PolygonPlaneAlgorithm(vertices);
        //Choosing what plane the object is on
        char plane = ChoosingMajorPlane(nVector);
        double denominator = (nVector.A*(LightSource.x - i.x) + nVector.B*(LightSource.y - i.y) + nVector.C*(LightSource.z - i.z));
        double t = -(((nVector.A * i.x) + (nVector.B * i.y) + (nVector.C * i.z) + nVector.D)/denominator);
        double x,y,z;
        //cout << "t: " << t << endl;


        if(denominator != 0 && t>=0)
        {
            x = i.x + t * (LightSource.x - i.x);
            y = i.y + t * (LightSource.y - i.y);
            z = i.z + t * (LightSource.z - i.z);
            
            Coordinates newPoint = AssignPointsAndColor(AssignCoordinates3d(x, y, z), vertices[0].color);
            newPoint.t = t;
            
            if(CheckOnSurface(vertices, newPoint, plane)) {
            
                
                return newPoint;
                
            }
        }
        Coordinates noPointFound = AssignPointsAndColor(AssignCoordinates3d(INT_MAX, INT_MAX, INT_MAX), AssignPixels(0, 0, 0));
        noPointFound.t = -1;
        return noPointFound;
    }
    
    Coordinates RayTracingDistance(Coordinates coP,Coordinates currentWindow, vector<vector<Coordinates>>polys, vector<SphereCoordinates>spheres)
    {
        vector<Coordinates>intersections;
        
        for(int i = 0; i<spheres.size(); i++)
        {
            Coordinates sphereIntersection = SphereIntersection(spheres[i], coP, currentWindow, spheres[i].r);
            intersections.push_back(sphereIntersection);
        }
        
        for(int i = 0; i<polys.size(); i++)
        {
            Coordinates polygonIntersection = PolygonIntersection(polys[i], coP, currentWindow);
            
            intersections.push_back(polygonIntersection);
                
        }
        
        Coordinates tempIntersections;
        //find shortest distance of intersections
        if(intersections.size() >0)
        {
            double min = sqrt(pow(intersections[0].x - coP.x,2.0)+ pow(intersections[0].y - coP.y,2.0) + pow(intersections[0].z - coP.z,2.0));
            
            tempIntersections = intersections[0];
            tempIntersections.color = intersections[0].color;
            //tempIntersections.lighting = intersections[0].lighting;
            for(int i = 1;i<intersections.size();i++)
            {
                double d = sqrt(pow(intersections[i].x - coP.x,2.0)+ pow(intersections[i].y - coP.y,2.0) + pow(intersections[i].z - coP.z,2.0));
                
                if(d<min)
                {
                    min = d;
                    tempIntersections = intersections[i];
                    
                    tempIntersections.color = intersections[i].color;
                }
            }
            
            if(tempIntersections.x == INT_MAX && tempIntersections.y == INT_MAX && tempIntersections.z == INT_MAX)
            {
                return AssignPointsAndColor(currentWindow, AssignPixels(0, 0, 0));
            }
            double pa,pd,ps, Ils = 1, sh = 1;
            if(ShadowRayTracingDistance(tempIntersections, polys, spheres, coP, currentWindow))
            {sh = 0; Ils = 0.5;}
            pa = AmbientLight(tempIntersections.lighting.ka, 1);
            pd = DiffuseReflection(tempIntersections.nVector.A, tempIntersections.nVector.B, tempIntersections.nVector.C, tempIntersections.lighting.kd, currentWindow,tempIntersections, coP, tempIntersections.isPoly,Ils);
            ps = specularReflection(tempIntersections.nVector.A, tempIntersections.nVector.B, tempIntersections.nVector.C, tempIntersections.lighting.ks, tempIntersections.lighting.n, currentWindow, tempIntersections, coP, tempIntersections.isPoly, Ils);

            tempIntersections.color.r = tempIntersections.color.r * (pa + pd) + (ps*sh);
            tempIntersections.color.g = tempIntersections.color.g * (pa + pd) + (ps*sh);
            tempIntersections.color.b = tempIntersections.color.b * (pa + pd) + (ps*sh);

            return tempIntersections;
            
        }
        else
        {
            return AssignPointsAndColor(currentWindow, AssignPixels(0, 0, 0));
        }
    }
    
    bool ShadowRayTracingDistance(Coordinates currentIntersection, vector<vector<Coordinates>>polys, vector<SphereCoordinates>spheres, Coordinates coP, Coordinates currentWindow)
    {
        
        for(int i = 0; i<spheres.size(); i++)
        {
            Coordinates sphereIntersection = SphereShadowIntersection(spheres[i], coP, currentIntersection, spheres[i].r);
            if(sphereIntersection.t>0 && sphereIntersection.t<=1 && (sphereIntersection.x != currentIntersection.x || sphereIntersection.y != currentIntersection.y ||sphereIntersection.z != currentIntersection.z))
            {
                return true;
            }
        }
       
        for(int i = 0; i<polys.size(); i++)
        {
            Coordinates polygonIntersection = PolygonShadowIntersection(polys[i], coP, currentIntersection, currentWindow);
            if(polygonIntersection.t>0 && polygonIntersection.t<=1 && (polygonIntersection.x != currentIntersection.x || polygonIntersection.y != currentIntersection.y ||polygonIntersection.z != currentIntersection.z))
            {
                return true;
            }
        }
        
        return false;
    }

    Window displayWindow(Window window, double dn){
        
        Window dimensions;
        window.tl.z = 0;
        window.br.z = 0;
        
        xL = min(window.tl.x, window.br.x);
        yL = min(window.tl.y, window.br.y);
        
        window.tl.x-=xL;
        window.br.x-=xL;
        window.tl.y-=yL;
        window.br.y-=yL;
        
        dimensions.tl = AssignCoordinates3d(0, max(window.tl.y, window.br.y), 0);
        dimensions.br = AssignCoordinates3d(max(window.tl.x, window.br.x), 0, 0);
        dimensions.pixels = window.pixels;
        
        for (int i = 0; i < dimensions.pixels.size(); i++) {
            Coordinates cur_coord = dimensions.pixels[i];
            
            cur_coord = AssignPointsAndColor(AssignCoordinates3d(cur_coord.x - xL, cur_coord.y - yL, cur_coord.z - 0), cur_coord.color);
            dimensions.pixels[i] = cur_coord;
            
        }
        
        return dimensions;
    }
    
    void ScaleEnvironment(double sf)
    {
        
        for(int i =0;i<polygons.size();i++)
        {
            for(int j =0;j<polygons[i].size();j++)
            {
                
                polygons[i][j].x = polygons[i][j].x * sf;
                polygons[i][j].y = polygons[i][j].y * sf;
                polygons[i][j].z = polygons[i][j].z * sf;
            }
        }
        
        
        for(int i =0;i<spheres.size();i++)
        {
            spheres[i].center.x = spheres[i].center.x * sf;
            spheres[i].center.y = spheres[i].center.y * sf;
            spheres[i].center.z = spheres[i].center.z * sf;
            spheres[i].r = spheres[i].r * sf;
        }
        
        
        window.tl.x = window.tl.x * sf;
        window.tl.y = window.tl.y * sf;
        window.tl.z = window.tl.z * sf;
        window.br.x = window.br.x * sf;
        window.br.y = window.br.y * sf;
        window.br.z = window.br.z * sf;
        
        LightSource.x = LightSource.x * sf;
        LightSource.y = LightSource.y * sf;
        LightSource.z = LightSource.z * sf;
        
    }
    
    Window ChangeZWLocation(Window window, double zw)
    {
        
        window.tl.z = zw;
        window.br.z = zw;
        
        
        return window;
    }
    
    void testAlignment3dA(int beta, int alpha, double viewPlane)
    {
        Transformations3d info;
        
        
        
        vector<Transformations3d::UVN> first = info.initializeUVNPoints();
        vector<Transformations3d::UVN> second = info.tiltUVNPoints(first, beta);
        
        vector<Transformations3d::UVN> third = info.rotateUVNPoints(second, alpha);
        
        vector<Transformations3d::UVN> testUVN;
        
        
        for(int i =0;i<polygons.size();i++)
        {
            for(int j = 0;j<polygons[i].size();j++)
            {
                polygons[i][j] = info.wireFrame3dAlignment(polygons[i][j], vrP, third, dn);
            }
            
        }
        
        for(int i =0;i<spheres.size();i++)
        {
            spheres[i].center = info.wireFrame3dAlignment(spheres[i].center, vrP, third, dn);
            
        }
        
        LightSource = info.wireFrame3dAlignment(LightSource, vrP, third, dn);
        
        window.tl.z -= viewPlane;
        window.br.z -= viewPlane;
    }
    
    double AmbientLight(double ka, double I)
    {
        return ka * I;
    }
    
    double DiffuseReflection(double x, double y, double z, double kd,Coordinates currentWindow, Coordinates intersection, Coordinates coP, bool isPoly, double Ils)
    {
        Coordinates normalVector = AssignCoordinates3d(x, y, z);
        
        Coordinates RayVector = subtractVectors(currentWindow, coP);
        double dp = dotProduct(normalVector, RayVector);
        Coordinates LightRay = subtractVectors(LightSource, intersection);
        
        double pd;

        if(isPoly)
        {
            if(dp>0)
            {
                normalVector = negateVector(normalVector);
            }
        }
        double dotProductNormalLightRay = dotProduct(normalVector, LightRay);
        if (dotProductNormalLightRay/(magnitudeOfVector(LightRay) * magnitudeOfVector(normalVector))>0)
            pd = (Ils * kd ) *(dotProductNormalLightRay/(magnitudeOfVector(LightRay) * magnitudeOfVector(normalVector)));
        else
            pd = 0;
        
        return pd;
    }
    
    double specularReflection(double x, double y, double z, double ks, double n, Coordinates currentWindow, Coordinates intersection, Coordinates coP, bool isPoly,double Ils)
    {
        Coordinates normalVector = AssignCoordinates3d(x, y, z);
        Coordinates RayVector = subtractVectors(currentWindow, coP);
        double dp = dotProduct(normalVector, RayVector);
        Coordinates LightRay = subtractVectors(LightSource, intersection);
        double pd;
       // double Ils = 1;
        if(isPoly)
        {
            if(dp>0)
            {
                normalVector = negateVector(normalVector);
            }
        }

        Coordinates normalVectorDividedByMagnitude = AssignCoordinates3d(normalVector.x/magnitudeOfVector(normalVector), normalVector.y/magnitudeOfVector(normalVector),normalVector.z/magnitudeOfVector(normalVector));
        
        Coordinates LightRayDividedByMagnitude = AssignCoordinates3d(LightRay.x/magnitudeOfVector(LightRay), LightRay.y/magnitudeOfVector(LightRay),LightRay.z/magnitudeOfVector(LightRay));
        Coordinates RayVectorDividedByMagnitude = AssignCoordinates3d(RayVector.x/magnitudeOfVector(RayVector), RayVector.y/magnitudeOfVector(RayVector),RayVector.z/magnitudeOfVector(RayVector));
        
        Coordinates negateRayVector = negateVector(RayVector);
        Coordinates negatedRayVectorDividedByMagnitude = AssignCoordinates3d(negateRayVector.x/magnitudeOfVector(negateRayVector),negateRayVector.y/magnitudeOfVector(negateRayVector),negateRayVector.z/magnitudeOfVector(negateRayVector));
        double cosine = dotProduct(subtractVectors(scaleVector( scaleVector(normalVectorDividedByMagnitude,2) , dotProduct(normalVectorDividedByMagnitude, LightRayDividedByMagnitude)), LightRayDividedByMagnitude), negatedRayVectorDividedByMagnitude);

        double ps;
            
        if(cosine<=0)ps = 0;
        else ps = 255 * Ils * ks * pow(cosine,n);

        return ps;
        
    }
    

    void setCOP( Coordinates coP)
    {
        dn = coP.z;
    }
    
    vector<Coordinates> getColoredPoints(Coordinates coP)
    {
        
        for(int i = window.tl.y;i>= window.br.y; i--)
        {
            for(int j = window.tl.x;j<=window.br.x;j++)
            {
                Coordinates currentWindow = AssignCoordinates3d(j,i, window.br.z);
                currentWindow.color = RayTracingDistance(coP, currentWindow, polygons, spheres).color;
                //currentWindow.color = ShadowRayTracingDistance(AssignCoordinates3d(0, 0, 0), polygons, spheres, coP, currentWindow).color;
                
                window.pixels.push_back(currentWindow);
            }
        }
        
        window = displayWindow(window, coP.z);
        
        return window.pixels;
    }
    
    void setWindow(Window w)
    {
        window = w;
    }
    
    void setVRP(Coordinates vrp)
    {
        vrP = vrp;
    }
    
    Window getWindow()
    {
        return window;
    }
    
    void setLightSource(Coordinates ls)
    {
        LightSource = ls;
    }

};

#endif /* LightingUtils_h */
