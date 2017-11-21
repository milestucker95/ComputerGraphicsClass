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
                Coordinates newPoint = AssignPointsAndColorAndLighting(AssignCoordinates3d(x, y, z), sphere.center.color, sphere.lighting);
                newPoint.isPoly = false;
                Coordinates nVector = subtractVectors(newPoint, sphere.center);
                newPoint.nVector.A = nVector.x;
                newPoint.nVector.B = nVector.y;
                newPoint.nVector.C = nVector.z;

                return newPoint;
                
            }
        }
        return AssignPointsAndColor(AssignCoordinates3d(INT_MAX, INT_MAX, INT_MAX), AssignPixels(0, 0, 0));
        
        
    }
    
    Coordinates SphereShadowIntersection(SphereCoordinates sphere, Coordinates i, int r)
    {
       vector<Coordinates>sphereIntersections;

        double A, B,C;
        A = pow((LightSource.x - i.x),2.0) + pow((LightSource.y - i.y),2.0) + pow((LightSource.z - i.z),2.0);
        B = 2.0 * ((LightSource.x - i.x)*(i.x - sphere.center.x) + (LightSource.y - i.y)*(i.y - sphere.center.y)
                   + (LightSource.z - i.z)*(i.z - sphere.center.z));
        C = pow((i.x - sphere.center.x),2.0) + pow((i.y - sphere.center.y),2.0) + pow((i.z - sphere.center.z),2.0) - pow(r,2.0);
        
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
                
                x = i.x + min * (LightSource.x - i.x);
                y = i.y + min * (LightSource.y - i.y);
                z = i.z + min * (LightSource.z - i.z);
                
                Coordinates newPoint = AssignPointsAndColor(AssignCoordinates3d(x, y, z), sphere.center.color);
                newPoint.t = min;
                
                return newPoint;
                
            }
        }
        Coordinates noPointFound = AssignPointsAndColor(AssignCoordinates3d(INT_MAX, INT_MAX, INT_MAX), AssignPixels(0, 0, 0));
        noPointFound.t = -1;
        return noPointFound;
        
        
    }
    
    
    Coordinates PolygonIntersection(vector<Coordinates> vertices, Coordinates coP, Coordinates currentWindow, int i)
    {
        vector<Coordinates>polygonIntersections;
        //Get the normal vector
        NVector nVector = PolygonPlaneAlgorithm(vertices);
        //Choosing what plane the object is on
        char plane = ChoosingMajorPlane(nVector);
        double denominator = (nVector.A*(currentWindow.x - coP.x) + nVector.B*(currentWindow.y - coP.y) + nVector.C*(currentWindow.z - coP.z));
        double t = -(((nVector.A * coP.x) + (nVector.B * coP.y) + (nVector.C * coP.z) + nVector.D)/denominator);
        double x,y,z;

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
                    newPoint.shapeNumber = i;
                return newPoint;
                
            }
        }

        return AssignPointsAndColor(AssignCoordinates3d(INT_MAX, INT_MAX, INT_MAX), AssignPixels(0, 0, 0));;
    }
    
    Coordinates PolygonShadowIntersection(vector<Coordinates> vertices, Coordinates i)
    {
        //Get the normal vector
        NVector nVector = PolygonPlaneAlgorithm(vertices);
        //Choosing what plane the object is on
        char plane = ChoosingMajorPlane(nVector);
        double denominator = (nVector.A*(LightSource.x - i.x) + nVector.B*(LightSource.y - i.y) + nVector.C*(LightSource.z - i.z));
        double t = -(((nVector.A * i.x) + (nVector.B * i.y) + (nVector.C * i.z) + nVector.D)/denominator);
        double x,y,z;

        if(denominator != 0 && t>0)
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
            Coordinates polygonIntersection = PolygonIntersection(polys[i], coP, currentWindow, i);
            
            intersections.push_back(polygonIntersection);
                
        }
        
        Coordinates tempIntersections;
        //find shortest distance of intersections
        if(intersections.size() >0)
        {
            double min = sqrt(pow(intersections[0].x - coP.x,2.0)+ pow(intersections[0].y - coP.y,2.0) + pow(intersections[0].z - coP.z,2.0));
            
            tempIntersections = intersections[0];
            for(int i = 1;i<intersections.size();i++)
            {
                double d = sqrt(pow(intersections[i].x - coP.x,2.0)+ pow(intersections[i].y - coP.y,2.0) + pow(intersections[i].z - coP.z,2.0));
                
                if(d<min)
                {
                    min = d;
                    tempIntersections = intersections[i];
                }
            }
            
            if(tempIntersections.x == INT_MAX && tempIntersections.y == INT_MAX && tempIntersections.z == INT_MAX)
            {
                return AssignPointsAndColor(currentWindow, AssignPixels(0, 0, 0));
            }
            double pa,pd,ps, Ils = 1, sh = 1;
            if(ShadowRayTracingDistance(tempIntersections, polys, spheres))
            {
                sh = 0; Ils = 0.5;
            }
            pa = AmbientLight(tempIntersections.lighting.ka, 1);
            pd = DiffuseReflection(tempIntersections.nVector.A, tempIntersections.nVector.B, tempIntersections.nVector.C, tempIntersections.lighting.kd, currentWindow,tempIntersections, coP, tempIntersections.isPoly,Ils);
            ps = specularReflection(tempIntersections.nVector.A, tempIntersections.nVector.B, tempIntersections.nVector.C, tempIntersections.lighting.ks, tempIntersections.lighting.n, currentWindow, tempIntersections, coP, tempIntersections.isPoly, Ils);

            tempIntersections.color.r = int(tempIntersections.color.r * (pa + pd) + (ps*sh));
            tempIntersections.color.g = int(tempIntersections.color.g * (pa + pd) + (ps*sh));
            tempIntersections.color.b = int(tempIntersections.color.b * (pa + pd) + (ps*sh));

            return tempIntersections;
            
        }
        else
        {
            return AssignPointsAndColor(currentWindow, AssignPixels(0, 0, 0));
        }
    }
    
    bool ShadowRayTracingDistance(Coordinates currentIntersection, vector<vector<Coordinates>>polys, vector<SphereCoordinates>spheres)
    {
        
        for(int i = 0; i<spheres.size(); i++)
        {
            Coordinates sphereIntersection = SphereShadowIntersection(spheres[i], currentIntersection, spheres[i].r);
            if(sphereIntersection.t>0 && sphereIntersection.t<=1 )
            {
                return true;
            }
        }
       
        for(int i = 0; i<polys.size(); i++)
        {
            Coordinates polygonIntersection = PolygonShadowIntersection(polys[i], currentIntersection);
            if(polygonIntersection.t>0 && polygonIntersection.t<=1 && currentIntersection.shapeNumber != i)
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
        
//        dimensions.tl = AssignCoordinates3d(0, max(window.tl.y, window.br.y), 0);
//        dimensions.br = AssignCoordinates3d(max(window.tl.x, window.br.x), 0, 0);
//        dimensions.pixels = window.pixels;
        dimensions = window;
        
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
        window.tl.z = window.tl.z * 1.5;
        window.br.x = window.br.x * sf;
        window.br.y = window.br.y * sf;
        window.br.z = window.br.z * 1.5;
        
        LightSource.x = LightSource.x * sf;
        LightSource.y = LightSource.y * sf;
        LightSource.z = LightSource.z * sf;
        
    }
    
    void testAlignment3dA(int beta, int alpha, double viewPlane)
    {
        Transformations3d info;
        
        vector<Transformations3d::UVN> first = info.initializeUVNPoints();
        vector<Transformations3d::UVN> second = info.tiltUVNPoints(first, beta);
        
        vector<Transformations3d::UVN> third = info.rotateUVNPoints(second, alpha);
        
        
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
    
    void TranslateObjects(Coordinates T, vector<int>sphs, vector<int> poly)
    {
        double xT = T.x, yT = T.y, zT = T.z;
        
        
        for(int i = 0;i<poly.size();i++)
        {
            int polyToChange = poly[i];
            for(int j = 0;j <polygons[polyToChange].size();j++)
            {

                polygons[polyToChange][j].x += xT;
                polygons[polyToChange][j].y += yT;
                polygons[polyToChange][j].z += zT;

            }
        }
        
        for(int i =0;i<sphs.size();i++)
        {
            int sphChange= sphs[i];

            spheres[sphChange].center.x += xT;
            spheres[sphChange].center.y += yT;
            spheres[sphChange].center.z += zT;
        }

    }
    
    void ScaleObjects( vector<int>polys, vector<int>sphs, Coordinates T, double sFactor)
    {
        for(int i = 0 ;i<polys.size();i++)
        {
            int polyToChange = polys[i];
            for(int j = 0;j <polygons[polyToChange].size();j++)
            {

                polygons[polyToChange][j].x -= T.x;
                polygons[polyToChange][j].y -= T.y;
                polygons[polyToChange][j].z -= T.z;
            
                polygons[polyToChange][j].x *= sFactor;
                polygons[polyToChange][j].y *= sFactor;
                polygons[polyToChange][j].z *= sFactor;
                
                polygons[polyToChange][j].x += T.x;
                polygons[polyToChange][j].y += T.y;
                polygons[polyToChange][j].z += T.z;
            }
        }
        
        for(int i =0;i<sphs.size();i++)
        {
            int sphereToChange = sphs[i];
            spheres[sphereToChange].center.x -= T.x;
            spheres[sphereToChange].center.y -= T.y;
            spheres[sphereToChange].center.z -= T.z;
            
            spheres[sphereToChange].center.x *= sFactor;
            spheres[sphereToChange].center.y *= sFactor;
            spheres[sphereToChange].center.z *= sFactor;
            spheres[sphereToChange].r *= sFactor;

            spheres[sphereToChange].center.x += T.x;
            spheres[sphereToChange].center.y += T.y;
            spheres[sphereToChange].center.z += T.z;
        }
    }

    void Rotate(vector<int>sphs,vector<int>polys, double degrees, Coordinates p1, Coordinates p2)
    {
        double degreesToRadians = Degrees_to_Radians(degrees);
        Coordinates UVector = RotateUVector(p1, p2);
        double a = sqrt(pow(UVector.x,2) + pow(UVector.z,2));
        double beta = acos(UVector.z/a);
        double betaRadians = Degrees_to_Radians(beta);
        double U = sqrt(pow(UVector.x,2) + pow(UVector.y,2) + pow(UVector.z,2));
        double alpha = acos(a/U);
        double alphaRadians = Degrees_to_Radians(alpha);
        double xT,yT,zT;
        
        //Translate center
        xT = p1.x;
        yT = p1.y;
        zT = p1.z;
        for(int i =0; i<sphs.size();i++)
        {

            spheres[sphs[i]].center.x-=xT;
            spheres[sphs[i]].center.y-=yT;
            spheres[sphs[i]].center.z-=zT;
            spheres[sphs[i]].center = RotateAboutYAxis(spheres[sphs[i]].center, -beta);
            spheres[sphs[i]].center = RotateAboutXAxis(spheres[sphs[i]].center, alpha);
            spheres[sphs[i]].center = RotateAboutZAxis(spheres[sphs[i]].center, degreesToRadians);
            spheres[sphs[i]].center = RotateAboutXAxis(spheres[sphs[i]].center, -alpha);
            spheres[sphs[i]].center = RotateAboutYAxis(spheres[sphs[i]].center, beta);
            spheres[sphs[i]].center.x+=xT;
            spheres[sphs[i]].center.y+=yT;
            spheres[sphs[i]].center.z+=zT;
        }
    
        for(int i =0; i<polys.size();i++)
        {
            int polyToChange = polys[i];

            for(int j = 0; j<polygons[polyToChange].size();j++)
            {

                polygons[polyToChange][j].x -= xT;
                polygons[polyToChange][j].y -= yT;
                polygons[polyToChange][j].z -= zT;
                
                polygons[polyToChange][j] = RotateAboutYAxis(polygons[polyToChange][j], -beta);
                polygons[polyToChange][j] = RotateAboutXAxis(polygons[polyToChange][j], alpha);
                polygons[polyToChange][j] = RotateAboutZAxis(polygons[polyToChange][j], degreesToRadians);
                polygons[polyToChange][j] = RotateAboutXAxis(polygons[polyToChange][j], -alpha);
                polygons[polyToChange][j] = RotateAboutYAxis(polygons[polyToChange][j], beta);

                polygons[polyToChange][j].x += xT;
                polygons[polyToChange][j].y += yT;
                polygons[polyToChange][j].z += zT;

            }
            
        }
    }
    
    Coordinates RotateAboutXAxis(Coordinates points, double radians)
    {
        double x0,y0,z0;
        x0 = points.x;
        y0 = points.y * cos(radians) - points.z * sin(radians);
        z0 = points.z * cos(radians) + points.y * sin(radians);
        
        return AssignPointsAndColorAndLighting(AssignCoordinates3d(x0,y0,z0),points.color, points.lighting);
    }
    
    Coordinates RotateAboutYAxis(Coordinates points, double radians)
    {
        
        double x0,y0,z0;
        x0 = points.x * cos(radians) + points.z * sin(radians);
        y0 = points.y;
        z0 = points.z * cos(radians) - points.x * sin(radians);
        
        return AssignPointsAndColorAndLighting(AssignCoordinates3d(x0,y0,z0),points.color, points.lighting);

    }
    
    Coordinates RotateAboutZAxis(Coordinates points, double radians)
    {
        double x0,y0,z0;
        x0 = points.x * cos(radians) - points.y * sin(radians);
        y0 = points.y * cos(radians) + points.x * sin(radians);
        z0 = points.z;
        
        return AssignPointsAndColorAndLighting(AssignCoordinates3d(x0,y0,z0),points.color, points.lighting);
    }
    
    Coordinates RotateUVector(Coordinates p1, Coordinates p2)
    {
        return subtractVectors(p2, p1);
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
    
    inline float Degrees_to_Radians(float angle){ //printf("this is the angle in radian: %f\n", (angle * 1.0 * M_PI)/(1.0 * 180));
        return (angle * 1.0 * M_PI)/(1.0 * 180); }

};

#endif /* LightingUtils_h */
