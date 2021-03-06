//
//  main.cpp
//  Computer Graphics PPM
//
//  Created by Miles Tucker on 8/30/17.
//  Copyright © 2017 Miles Tucker. All rights reserved.
//

#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include<sstream>
#include<cmath>
#include<iomanip>
#include "Tools.h"
#include "Image.h"
//#include "Line.h"
//#include "Circle.h"
//#include "Ellipse.h"
//#include "Polygon.h"
//#include "Transformations.h"
#include "Transformations3d.h"
#include "LightingUtils.h"
using namespace std;


vector<SphereCoordinates> getStars()
{
    vector<vector<Coordinates>>polygon;
      Pixels color1 = AssignPixels(0, 0, 255),color2  = AssignPixels(255, 255, 0),color3 = AssignPixels(255, 0, 0),color4 = AssignPixels(0, 255, 0), color5 = AssignPixels(0, 0, 255), color6 = AssignPixels(255, 255, 255), color7 = AssignPixels(0, 135, 167), starColor = AssignPixels(248, 247, 255);
    double ska = 0.2,skd = 0.6,sks = 0.25,sn = 10;

    Lighting lightingSpheres = AssignLighting(ska, skd, sks, sn);
    vector<SphereCoordinates> sphere;
    int r = 1;
    
    SphereCoordinates star1 = AssignSphereWithLighting(AssignCoordinates3d(150, 50, 70), r, color6, lightingSpheres);
    SphereCoordinates star2 = AssignSphereWithLighting(AssignCoordinates3d(120, 65, 70), r, color6, lightingSpheres);
    SphereCoordinates star3 = AssignSphereWithLighting(AssignCoordinates3d(30, 30, 70), r, color6, lightingSpheres);
    SphereCoordinates star4 = AssignSphereWithLighting(AssignCoordinates3d(63, 23, 86), r, color6, lightingSpheres);
    SphereCoordinates star5 = AssignSphereWithLighting(AssignCoordinates3d(70, 50, 70), r, color6, lightingSpheres);
    SphereCoordinates star6 = AssignSphereWithLighting(AssignCoordinates3d(80, 50, 50), r, color6, lightingSpheres);
    SphereCoordinates star7 = AssignSphereWithLighting(AssignCoordinates3d(-50, 50, 70), r, color6, lightingSpheres);
    SphereCoordinates star8 = AssignSphereWithLighting(AssignCoordinates3d(-120, 65, 70), r, color6, lightingSpheres);
    SphereCoordinates star9 = AssignSphereWithLighting(AssignCoordinates3d(-30, 30, 70), r, color6, lightingSpheres);
    SphereCoordinates star10 = AssignSphereWithLighting(AssignCoordinates3d(-63, 23, 86), r, color6, lightingSpheres);
    SphereCoordinates star11 = AssignSphereWithLighting(AssignCoordinates3d(-70, 50, 70), r, color6, lightingSpheres);
    SphereCoordinates star12 = AssignSphereWithLighting(AssignCoordinates3d(-80, 50, 50), r, color6, lightingSpheres);
    SphereCoordinates star13 = AssignSphereWithLighting(AssignCoordinates3d(150, 100, 70), r, color6, lightingSpheres);
    SphereCoordinates star14 = AssignSphereWithLighting(AssignCoordinates3d(120, 115, 70), r, color6, lightingSpheres);
    SphereCoordinates star15 = AssignSphereWithLighting(AssignCoordinates3d(30, 80, 70), r, color6, lightingSpheres);
    SphereCoordinates star16 = AssignSphereWithLighting(AssignCoordinates3d(63, 75, 86), r, color6, lightingSpheres);
    SphereCoordinates star17 = AssignSphereWithLighting(AssignCoordinates3d(70, 100, 70), r, color6, lightingSpheres);
    SphereCoordinates star18 = AssignSphereWithLighting(AssignCoordinates3d(80, 100, 50), r, color6, lightingSpheres);
    SphereCoordinates star19 = AssignSphereWithLighting(AssignCoordinates3d(-50, 100, 70), r, color6, lightingSpheres);
    SphereCoordinates star20 = AssignSphereWithLighting(AssignCoordinates3d(-120, 115, 70), r, color6, lightingSpheres);
    SphereCoordinates star21 = AssignSphereWithLighting(AssignCoordinates3d(-30, 80, 70), r, color6, lightingSpheres);
    SphereCoordinates star22 = AssignSphereWithLighting(AssignCoordinates3d(-63, 75, 86), r, color6, lightingSpheres);
    SphereCoordinates star23 = AssignSphereWithLighting(AssignCoordinates3d(-70, 100, 70), r, color6, lightingSpheres);
    SphereCoordinates star24 = AssignSphereWithLighting(AssignCoordinates3d(-80, 100, 50), r, color6, lightingSpheres);
    SphereCoordinates star25 = AssignSphereWithLighting(AssignCoordinates3d(170, 100, 70), r, color6, lightingSpheres);
    SphereCoordinates star26 = AssignSphereWithLighting(AssignCoordinates3d(180, 100, 50), r, color6, lightingSpheres);
    SphereCoordinates star27 = AssignSphereWithLighting(AssignCoordinates3d(-170, 100, 70), r, color6, lightingSpheres);
    SphereCoordinates star28 = AssignSphereWithLighting(AssignCoordinates3d(-150, 115, 70), r, color6, lightingSpheres);
    SphereCoordinates star29 = AssignSphereWithLighting(AssignCoordinates3d(-190, 80, 70), r, color6, lightingSpheres);
    SphereCoordinates star30 = AssignSphereWithLighting(AssignCoordinates3d(-130, 75, 86), r, color6, lightingSpheres);
    SphereCoordinates star31 = AssignSphereWithLighting(AssignCoordinates3d(130, 100, 70), r, color6, lightingSpheres);
    SphereCoordinates star32 = AssignSphereWithLighting(AssignCoordinates3d(-80, -20, 50), r, color6, lightingSpheres);
//    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(150, 50, 70), r, color6, lightingSpheres);
//    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(150, 50, 70), r, color6, lightingSpheres);
//    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(150, 50, 70), r, color6, lightingSpheres);
//    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(150, 50, 70), r, color6, lightingSpheres);
//    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(150, 50, 70), r, color6, lightingSpheres);
//    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(150, 50, 70), r, color6, lightingSpheres);
//    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(150, 50, 70), r, color6, lightingSpheres);
//    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(150, 50, 70), r, color6, lightingSpheres);
//    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(150, 50, 70), r, color6, lightingSpheres);
//    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(150, 50, 70), r, color6, lightingSpheres);
    sphere.push_back(star1);
    sphere.push_back(star2);
    sphere.push_back(star3);
    sphere.push_back(star4);
    sphere.push_back(star5);
    sphere.push_back(star6);
    sphere.push_back(star7);
    sphere.push_back(star8);
    sphere.push_back(star9);
    sphere.push_back(star10);
    sphere.push_back(star11);
    sphere.push_back(star12);
    sphere.push_back(star13);
    sphere.push_back(star14);
    sphere.push_back(star15);
    sphere.push_back(star16);
    sphere.push_back(star17);
    sphere.push_back(star18);
    sphere.push_back(star19);
    sphere.push_back(star20);
    sphere.push_back(star21);
    sphere.push_back(star22);
    sphere.push_back(star23);
    sphere.push_back(star24);
    sphere.push_back(star25);
    sphere.push_back(star26);
    sphere.push_back(star27);
    sphere.push_back(star28);
    sphere.push_back(star29);
    sphere.push_back(star30);
    sphere.push_back(star31);
    sphere.push_back(star32);

//    cout << "chicken" << endl;
   return sphere;

}
void animation()
{
    cout << "Running...." << endl;
        Pixels color1 = AssignPixels(0, 0, 255),color2  = AssignPixels(255, 255, 0),color3 = AssignPixels(255, 0, 0),color4 = AssignPixels(0, 255, 0), color5 = AssignPixels(0, 0, 255), color6 = AssignPixels(255, 255, 245), color7 = AssignPixels(0, 135, 167), starColor = AssignPixels(248, 247, 255), sun = AssignPixels(252, 212, 64), white = AssignPixels(255,255 ,255);
    double pka = 0.2,pkd = 0.6,pks = 0.25,pn = 5;
    double ska = 0.2,skd = 0.6,sks = 0.25,sn = 10;
    Lighting lightingPolygons = AssignLighting(pka, pkd, pks, pn);
    Lighting lightingSpheres = AssignLighting(ska, skd, sks, sn);
    vector<vector<Coordinates>>polygon;

//    vector<Coordinates>polygon1;
//    polygon1.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color7,lightingPolygons));
//    polygon1.push_back(AssignCoordinates3d(100,0,0));
//    polygon1.push_back(AssignCoordinates3d(100,0,100));
//    polygon1.push_back(AssignCoordinates3d(0,0,100));
    
    vector<Coordinates>polygon2;
    polygon2.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color2, lightingPolygons));
    polygon2.push_back(AssignCoordinates3d(0,100,0));
    polygon2.push_back(AssignCoordinates3d(0,100,100));
    polygon2.push_back(AssignCoordinates3d(0,0,100));
    
//    
//    vector<Coordinates>polygon3;
//    polygon3.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(100,60,100),starColor, lightingPolygons));
//    polygon3.push_back(AssignCoordinates3d(120,100,100));
//    polygon3.push_back(AssignCoordinates3d(140,60,100));
//    
//    vector<Coordinates>polygon4;
//    polygon4.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(10,30,85),starColor, lightingPolygons));
//    polygon4.push_back(AssignCoordinates3d(20,50,85));
//    polygon4.push_back(AssignCoordinates3d(30,30,85));
////    polygon4.push_back(AssignCoordinates3d(10,30,5));
//    
//    vector<Coordinates>polygon5;
//    polygon5.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(60,0,80),color1, lightingPolygons));
//    polygon5.push_back(AssignCoordinates3d(60,30,80));
//    polygon5.push_back(AssignCoordinates3d(60,30,10));
//    polygon5.push_back(AssignCoordinates3d(60,0,10));
//    
//    vector<Coordinates>polygon6;
//    polygon6.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(20,0,80),color6, lightingPolygons));
//    polygon6.push_back(AssignCoordinates3d(20,30,80));
//    polygon6.push_back(AssignCoordinates3d(20,30,10));
//    polygon6.push_back(AssignCoordinates3d(20,0,10));
    
//    polygon.push_back(polygon1);
    polygon.push_back(polygon2);
//    polygon.push_back(polygon3);
//    polygon.push_back(polygon4);
//    polygon.push_back(polygon5);
//    polygon.push_back(polygon6);

    double r = 20;
    double r2 = 10;
    double r3 = 20;
    double sunRadius = 25;
    int sf = 2;
    
    Pixels sphereColor1 = color3, sphereColor2 = color1, sphereColor3 = color7, sphereColor5 = white;

    int coPCounter = 0;
    int sunCounter = 1;
    

    vector<SphereCoordinates> sphere;
    vector<SphereCoordinates>stars;
    for(int i = 0 ; i< 150;i++)
    {
        stars = getStars();

        sphere.insert(sphere.begin(), stars.begin(), stars.end());

        Coordinates vrP = AssignCoordinates3d(130, 130, 130);
        Coordinates coP = AssignCoordinates3d(0, 0, 50);

        SphereCoordinates sphere4;
        if(i<75)
        {
            sphere4 = AssignSphereWithLighting(AssignCoordinates3d(120, 130, 50), sunRadius, sun, lightingSpheres);

            
        }
        else{
            
            sphere4 = AssignSphereWithLighting(AssignCoordinates3d(120, 130 - (sunCounter+=5), 50), sunRadius, sun, lightingSpheres);

        }


    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(150 - (i+5), 50, 70), r, sphereColor1, lightingSpheres);
    
    SphereCoordinates sphere2 = AssignSphereWithLighting(AssignCoordinates3d(-50 + (i+5), 50, 90), r2, sphereColor2, lightingSpheres);
    SphereCoordinates sphere3 = AssignSphereWithLighting(AssignCoordinates3d(50, 50+i, 70), r2, sphereColor3, lightingSpheres);
    SphereCoordinates sphere5 = AssignSphereWithLighting(AssignCoordinates3d(-125, -100, 70), r3, sphereColor5, lightingSpheres);
        
        if(sphere1.center.x >= (sphere2.center.x-r2) && sphere1.center.x <= (sphere2.center.x+r2) && sphere1.center.y >= (sphere2.center.y-r2) && sphere1.center.y <= (sphere2.center.y+r2) )
        {
            sphereColor1 = color4;
            sphereColor2 = color1;
        }
    
    sphere.push_back(sphere4);
    sphere.push_back(sphere1);
    sphere.push_back(sphere2);
    sphere.push_back(sphere3);
    sphere.push_back(sphere5);
    

    
    LightingUtils info(polygon, sphere);
    Coordinates lightSource = AssignCoordinates3d(200, 200, 50);
        

    info.setVRP(vrP);
    info.setLightSource(lightSource);
    
    double alpha = 45,beta = -45;
    Window w = ViewWindow(AssignCoordinates3d(-50, 50,0), AssignCoordinates3d(50, -50, 0));
    
    info.setWindow(w);
    info.setCOP(coP);
        vector<int>PolyR;
        vector<int>SphR;
        double degreesR = 5*i;
        PolyR.push_back(0);
        SphR.push_back(4);
        Coordinates p1 = AssignCoordinates3d(50, 50, 100);
        Coordinates p2 = AssignCoordinates3d(50, 50, 0);
        info.Rotate(SphR, PolyR, degreesR, p1, p2);

    info.testAlignment3dA(beta, alpha, coP.z);
    
    info.ScaleEnvironment(sf);
    //info.TranslateObjects(3);
    vector<Coordinates> pixels = info.getColoredPoints(coP);
    Image image;
    image.createCanvas(abs(info.getWindow().tl.x - info.getWindow().br.x)+1, abs(info.getWindow().br.y - info.getWindow().tl.y)+1, "255");
    image.uniformColor(245, 245, 245);
    image.DrawEnvironment(pixels);
    
    image.writePPM("animation"+to_string(i)+ ".jpg");
        sphere.clear();
    }
    cout << "Finished"<< endl;

}

void lightingAlgorithm4(){
    
    cout << "Running...." << endl;
    Pixels color1 = AssignPixels(255, 255, 255),color2  = AssignPixels(255, 255, 0),color3 = AssignPixels(255, 0, 0),color4 = AssignPixels(0, 255, 0);
    double pka = 0.2,pkd = 0.6,pks = 0.25,pn = 5;
    double ska = 0.2,skd = 0.6,sks = 0.25,sn = 10;
    Lighting lightingPolygons = AssignLighting(pka, pkd, pks, pn);
    Lighting lightingSpheres = AssignLighting(ska, skd, sks, sn);

    vector<vector<Coordinates>>polygon;
    
    vector<Coordinates>polygon1;
    polygon1.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color1,lightingPolygons));
    polygon1.push_back(AssignCoordinates3d(100,0,0));
    polygon1.push_back(AssignCoordinates3d(100,0,100));
    polygon1.push_back(AssignCoordinates3d(0,0,100));
    
    vector<Coordinates>polygon2;
    polygon2.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color1, lightingPolygons));
    polygon2.push_back(AssignCoordinates3d(0,100,0));
    polygon2.push_back(AssignCoordinates3d(0,100,100));
    polygon2.push_back(AssignCoordinates3d(0,0,100));
    
    vector<Coordinates>polygon3;
    polygon3.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color1, lightingPolygons));
    polygon3.push_back(AssignCoordinates3d(0,100,0));
    polygon3.push_back(AssignCoordinates3d(100,100,0));
    polygon3.push_back(AssignCoordinates3d(100,0,0));
    
    vector<Coordinates>polygon4;
    polygon4.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(10,30,85),color2, lightingPolygons));
    polygon4.push_back(AssignCoordinates3d(70,30,85));
    polygon4.push_back(AssignCoordinates3d(70,30,5));
    polygon4.push_back(AssignCoordinates3d(10,30,5));
    
    vector<Coordinates>polygon5;
    polygon5.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(60,0,80),color2, lightingPolygons));
    polygon5.push_back(AssignCoordinates3d(60,30,80));
    polygon5.push_back(AssignCoordinates3d(60,30,10));
    polygon5.push_back(AssignCoordinates3d(60,0,10));
    
    vector<Coordinates>polygon6;
    polygon6.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(20,0,80),color2, lightingPolygons));
    polygon6.push_back(AssignCoordinates3d(20,30,80));
    polygon6.push_back(AssignCoordinates3d(20,30,10));
    polygon6.push_back(AssignCoordinates3d(20,0,10));
    
    polygon.push_back(polygon1);
    polygon.push_back(polygon2);
    polygon.push_back(polygon3);
    polygon.push_back(polygon4);
    polygon.push_back(polygon5);
    polygon.push_back(polygon6);

    
    double r = 20;
    double r2 = 10;
    int sf = 2;
    vector<SphereCoordinates> sphere;
    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(50, 80, 50), r, color3, lightingSpheres);
    
    SphereCoordinates sphere2 = AssignSphereWithLighting(AssignCoordinates3d(80, 50, 70), r2, color4, lightingSpheres);

    sphere.push_back(sphere1);
    sphere.push_back(sphere2);

    LightingUtils info(polygon, sphere);
    Coordinates lightSource = AssignCoordinates3d(200, 200, 50);
    Coordinates vrP = AssignCoordinates3d(130, 130, 130);
    info.setVRP(vrP);
    info.setLightSource(lightSource);

    Coordinates coP = AssignCoordinates3d(0, 0, 50);
    double alpha = 45,beta = -45;
    Window w = ViewWindow(AssignCoordinates3d(-30, 30,0), AssignCoordinates3d(30, -30, 0));
    
    info.setWindow(w);
    info.setCOP(coP);
    info.testAlignment3dA(beta, alpha, coP.z);
    
    info.ScaleEnvironment(sf);
    //info.TranslateObjects(3);
    vector<Coordinates> pixels = info.getColoredPoints(coP);
    Image image;
    image.createCanvas(abs(info.getWindow().tl.x - info.getWindow().br.x)+1, abs(info.getWindow().br.y - info.getWindow().tl.y)+1, "255");
    image.uniformColor(245, 245, 245);
    image.DrawEnvironment(pixels);

    image.writePPM("environment.ppm");
    cout << "Finished"<< endl;
}

void threeDTransformations1(){
    
    cout << "Running...." << endl;
    Pixels color1 = AssignPixels(255, 255, 255),color2  = AssignPixels(255, 255, 0),color3 = AssignPixels(255, 0, 0),color4 = AssignPixels(0, 255, 0);
    double pka = 0.2,pkd = 0.6,pks = 0.25,pn = 5;
    double ska = 0.2,skd = 0.6,sks = 0.25,sn = 10;
    Lighting lightingPolygons = AssignLighting(pka, pkd, pks, pn);
    Lighting lightingSpheres = AssignLighting(ska, skd, sks, sn);
    
    vector<vector<Coordinates>>polygon;
    
    vector<Coordinates>polygon1;
    polygon1.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color1,lightingPolygons));
    polygon1.push_back(AssignCoordinates3d(100,0,0));
    polygon1.push_back(AssignCoordinates3d(100,0,100));
    polygon1.push_back(AssignCoordinates3d(0,0,100));
    
    vector<Coordinates>polygon2;
    polygon2.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color1, lightingPolygons));
    polygon2.push_back(AssignCoordinates3d(0,100,0));
    polygon2.push_back(AssignCoordinates3d(0,100,100));
    polygon2.push_back(AssignCoordinates3d(0,0,100));
    
    vector<Coordinates>polygon3;
    polygon3.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color1, lightingPolygons));
    polygon3.push_back(AssignCoordinates3d(0,100,0));
    polygon3.push_back(AssignCoordinates3d(100,100,0));
    polygon3.push_back(AssignCoordinates3d(100,0,0));
    
    vector<Coordinates>polygon4;
    polygon4.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(10,30,85),color2, lightingPolygons));
    polygon4.push_back(AssignCoordinates3d(70,30,85));
    polygon4.push_back(AssignCoordinates3d(70,30,5));
    polygon4.push_back(AssignCoordinates3d(10,30,5));
    
    vector<Coordinates>polygon5;
    polygon5.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(60,0,80),color2, lightingPolygons));
    polygon5.push_back(AssignCoordinates3d(60,30,80));
    polygon5.push_back(AssignCoordinates3d(60,30,10));
    polygon5.push_back(AssignCoordinates3d(60,0,10));
    
    vector<Coordinates>polygon6;
    polygon6.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(20,0,80),color2, lightingPolygons));
    polygon6.push_back(AssignCoordinates3d(20,30,80));
    polygon6.push_back(AssignCoordinates3d(20,30,10));
    polygon6.push_back(AssignCoordinates3d(20,0,10));
    
    polygon.push_back(polygon1);
    polygon.push_back(polygon2);
    polygon.push_back(polygon3);
    polygon.push_back(polygon4);
    polygon.push_back(polygon5);
    polygon.push_back(polygon6);
    
    
    double r = 20;
    double r2 = 10;
    int sf = 2;
    vector<SphereCoordinates> sphere;
    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(50, 80, 50), r, color3, lightingSpheres);
    
    SphereCoordinates sphere2 = AssignSphereWithLighting(AssignCoordinates3d(80, 50, 70), r2, color4, lightingSpheres);
    
    sphere.push_back(sphere1);
    sphere.push_back(sphere2);
    
    LightingUtils info(polygon, sphere);
    Coordinates lightSource = AssignCoordinates3d(200, 200, 50);
    Coordinates vrP = AssignCoordinates3d(120, 50, 120);
    info.setVRP(vrP);
    info.setLightSource(lightSource);
    
    Coordinates coP = AssignCoordinates3d(0, 0, 50);
    double alpha = 45,beta = 0;
    Window w = ViewWindow(AssignCoordinates3d(-30, 30,0), AssignCoordinates3d(30, -30, 0));
    
    info.setWindow(w);
    info.setCOP(coP);
    
    vector<int>sphTrans;
    sphTrans.push_back(0);
    sphTrans.push_back(1);

    vector<int>polyTrans;
    polyTrans.push_back(3);
//    polyTrans.push_back(4);
//    polyTrans.push_back(5);
    
    Coordinates T = AssignCoordinates3d(0, 30, 0);
    info.TranslateObjects(T, sphTrans, polyTrans);
    info.testAlignment3dA(beta, alpha, coP.z);

    info.ScaleEnvironment(sf);

    vector<Coordinates> pixels = info.getColoredPoints(coP);
    Image image;
    image.createCanvas(abs(info.getWindow().tl.x - info.getWindow().br.x)+1, abs(info.getWindow().br.y - info.getWindow().tl.y)+1, "255");
    image.uniformColor(245, 245, 245);
    image.DrawEnvironment(pixels);
    
    image.writePPM("3dTransProblem1.ppm");
    cout << "Finished"<< endl;
}

void threeDTransformations2(){
    
    cout << "Running...." << endl;
    Pixels color1 = AssignPixels(255, 255, 255),color2  = AssignPixels(255, 255, 0),color3 = AssignPixels(255, 0, 0),color4 = AssignPixels(0, 255, 0);
        double pka = 0.2,pkd = 0.6,pks = 0.25,pn = 5;
        double ska = 0.2,skd = 0.6,sks = 0.25,sn = 10;
        Lighting lightingPolygons = AssignLighting(pka, pkd, pks, pn);
        Lighting lightingSpheres = AssignLighting(ska, skd, sks, sn);
    
        vector<vector<Coordinates>>polygon;
    
        vector<Coordinates>polygon1;
        polygon1.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color1,lightingPolygons));
        polygon1.push_back(AssignCoordinates3d(100,0,0));
        polygon1.push_back(AssignCoordinates3d(100,0,100));
        polygon1.push_back(AssignCoordinates3d(0,0,100));
    
        vector<Coordinates>polygon2;
        polygon2.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color1, lightingPolygons));
        polygon2.push_back(AssignCoordinates3d(0,100,0));
        polygon2.push_back(AssignCoordinates3d(0,100,100));
        polygon2.push_back(AssignCoordinates3d(0,0,100));
    
        vector<Coordinates>polygon3;
        polygon3.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color1, lightingPolygons));
        polygon3.push_back(AssignCoordinates3d(0,100,0));
        polygon3.push_back(AssignCoordinates3d(100,100,0));
        polygon3.push_back(AssignCoordinates3d(100,0,0));
    
        vector<Coordinates>polygon4;
        polygon4.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(10,30,85),color2, lightingPolygons));
        polygon4.push_back(AssignCoordinates3d(70,30,85));
        polygon4.push_back(AssignCoordinates3d(70,30,5));
        polygon4.push_back(AssignCoordinates3d(10,30,5));
    
        vector<Coordinates>polygon5;
        polygon5.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(60,0,80),color2, lightingPolygons));
        polygon5.push_back(AssignCoordinates3d(60,30,80));
        polygon5.push_back(AssignCoordinates3d(60,30,10));
        polygon5.push_back(AssignCoordinates3d(60,0,10));
    
        vector<Coordinates>polygon6;
        polygon6.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(20,0,80),color2, lightingPolygons));
        polygon6.push_back(AssignCoordinates3d(20,30,80));
        polygon6.push_back(AssignCoordinates3d(20,30,10));
        polygon6.push_back(AssignCoordinates3d(20,0,10));
    
        polygon.push_back(polygon1);
        polygon.push_back(polygon2);
        polygon.push_back(polygon3);
        polygon.push_back(polygon4);
        polygon.push_back(polygon5);
        polygon.push_back(polygon6);
    
    
        double r = 20;
        double r2 = 10;
        int sf = 2;
        vector<SphereCoordinates> sphere;
        SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(50, 80, 50), r, color3, lightingSpheres);
    
        SphereCoordinates sphere2 = AssignSphereWithLighting(AssignCoordinates3d(80, 50, 70), r2, color4, lightingSpheres);
    
        sphere.push_back(sphere1);
        sphere.push_back(sphere2);

    LightingUtils info(polygon, sphere);

        Coordinates lightSource = AssignCoordinates3d(200, 200, 50);
        Coordinates vrP = AssignCoordinates3d(120, 50, 120);
        info.setVRP(vrP);
        info.setLightSource(lightSource);
    
        Coordinates coP = AssignCoordinates3d(0, 0, 50);
        double alpha = 45,beta = 0;
        Window w = ViewWindow(AssignCoordinates3d(-30, 30,0), AssignCoordinates3d(30, -30, 0));
    
        vector<int>sphScale;
        sphScale.push_back(0);
        vector<int>polyScale;
        polyScale.push_back(3);
        polyScale.push_back(4);
        polyScale.push_back(5);
    
        double objSf = 0.5;
        Coordinates sfCoordinate = AssignCoordinates3d(10, 0, 40);
    
        info.setWindow(w);
        info.setCOP(coP);
    
    
    info.ScaleObjects(polyScale, sphScale, sfCoordinate, objSf);
    info.testAlignment3dA(beta, alpha, coP.z);

    info.ScaleEnvironment(sf);

        vector<Coordinates> pixels = info.getColoredPoints(coP);
        Image image;
        image.createCanvas(abs(info.getWindow().tl.x - info.getWindow().br.x)+1, abs(info.getWindow().br.y - info.getWindow().tl.y)+1, "255");
        image.uniformColor(245, 245, 245);
        image.DrawEnvironment(pixels);
    
    image.writePPM("3dTransformations2.ppm");
    cout << "Finished"<< endl;
}

void threeDTransformations3(){
    
    cout << "Running...." << endl;
    Pixels color1 = AssignPixels(255, 255, 255),color2  = AssignPixels(255, 255, 0),color3 = AssignPixels(255, 0, 0),color4 = AssignPixels(0, 255, 0);
    double pka = 0.2,pkd = 0.6,pks = 0.25,pn = 5;
    double ska = 0.2,skd = 0.6,sks = 0.25,sn = 10;
    Lighting lightingPolygons = AssignLighting(pka, pkd, pks, pn);
    Lighting lightingSpheres = AssignLighting(ska, skd, sks, sn);
    
    vector<vector<Coordinates>>polygon;
    
    vector<Coordinates>polygon1;
    polygon1.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color1,lightingPolygons));
    polygon1.push_back(AssignCoordinates3d(100,0,0));
    polygon1.push_back(AssignCoordinates3d(100,0,100));
    polygon1.push_back(AssignCoordinates3d(0,0,100));
    
    vector<Coordinates>polygon2;
    polygon2.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color1, lightingPolygons));
    polygon2.push_back(AssignCoordinates3d(0,100,0));
    polygon2.push_back(AssignCoordinates3d(0,100,100));
    polygon2.push_back(AssignCoordinates3d(0,0,100));
    
    vector<Coordinates>polygon3;
    polygon3.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(0,0,0),color1, lightingPolygons));
    polygon3.push_back(AssignCoordinates3d(0,100,0));
    polygon3.push_back(AssignCoordinates3d(100,100,0));
    polygon3.push_back(AssignCoordinates3d(100,0,0));
    
    vector<Coordinates>polygon4;
    polygon4.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(10,30,85),color2, lightingPolygons));
    polygon4.push_back(AssignCoordinates3d(70,30,85));
    polygon4.push_back(AssignCoordinates3d(70,30,5));
    polygon4.push_back(AssignCoordinates3d(10,30,5));
    
    vector<Coordinates>polygon5;
    polygon5.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(60,0,80),color2, lightingPolygons));
    polygon5.push_back(AssignCoordinates3d(60,30,80));
    polygon5.push_back(AssignCoordinates3d(60,30,10));
    polygon5.push_back(AssignCoordinates3d(60,0,10));
    
    vector<Coordinates>polygon6;
    polygon6.push_back(AssignPointsAndColorAndLighting(AssignCoordinates3d(20,0,80),color2, lightingPolygons));
    polygon6.push_back(AssignCoordinates3d(20,30,80));
    polygon6.push_back(AssignCoordinates3d(20,30,10));
    polygon6.push_back(AssignCoordinates3d(20,0,10));
    
    polygon.push_back(polygon1);
    polygon.push_back(polygon2);
    polygon.push_back(polygon3);
    polygon.push_back(polygon4);
    polygon.push_back(polygon5);
    polygon.push_back(polygon6);
    
    
    double r = 20;
    double r2 = 10;
    int sf = 2;
    vector<SphereCoordinates> sphere;
    SphereCoordinates sphere1 = AssignSphereWithLighting(AssignCoordinates3d(50, 80, 50), r, color3, lightingSpheres);
    
    SphereCoordinates sphere2 = AssignSphereWithLighting(AssignCoordinates3d(80, 50, 70), r2, color4, lightingSpheres);
    
    sphere.push_back(sphere1);
    sphere.push_back(sphere2);
//


    LightingUtils info(polygon, sphere);
    Coordinates TCoordinate = AssignCoordinates3d(0, 30, 0);

    Coordinates lightSource = AssignCoordinates3d(200, 200, 50);
    Coordinates vrP = AssignCoordinates3d(120, 50, 120);
    info.setVRP(vrP);
    info.setLightSource(lightSource);
    Coordinates coP = AssignCoordinates3d(0, 0, 50);
    double alpha = 45,beta = 0;
    Window w = ViewWindow(AssignCoordinates3d(-30, 30,0), AssignCoordinates3d(30, -30, 0));
    vector<int>TPoly;
    vector<int>TSph;
    TSph.push_back(1);

    info.TranslateObjects(TCoordinate, TSph, TPoly);
    info.setWindow(w);
    info.setCOP(coP);
    vector<int>SphR;
    vector<int>PolyR;
    double degreesR = 45;
    SphR.push_back(0);
    PolyR.push_back(3);
    PolyR.push_back(4);
    PolyR.push_back(5);
    Coordinates p1 = AssignCoordinates3d(60, 0, 80);
    Coordinates p2 = AssignCoordinates3d(60, 0, 10);

    info.Rotate(SphR, PolyR, degreesR, p1, p2);
    info.testAlignment3dA(beta, alpha, coP.z);
    info.ScaleEnvironment(sf);

    vector<Coordinates> pixels = info.getColoredPoints(coP);
    Image image;
    image.createCanvas(abs(info.getWindow().tl.x - info.getWindow().br.x)+1, abs(info.getWindow().br.y - info.getWindow().tl.y)+1, "255");
    image.uniformColor(245, 245, 245);
    image.DrawEnvironment(pixels);
    
    image.writePPM("3dtransproblem3.ppm");
    cout << "Finished"<< endl;
}

//void problem10()
//{
//    Image info;
//    info.createCanvas(320, 240, "255");
//    info.uniformColor(255, 255, 255);
//    
//    Circle head(160,200,20);
//    //head.fillCircle();
//    info.Draw(head.getPoints(), 0, 0, 0);
//    info.Draw(head.getFillPoints(), 255, 255, 0);
//
//    
//    Line neck(160, 180,160,170);
//   //cout << "neck size: " << neck.drawLine(neck.getInitialVertexPoints()).size() << endl;
//    info.Draw(neck.drawLine(neck.getInitialVertexPoints()), 0, 0, 0);
//    
//    Polygon body;
//    std::vector<std::pair <int,int>>polygonPoints;
//    polygonPoints.push_back(std::pair<int, int>(130,170));
//    polygonPoints.push_back(std::pair<int, int>(190,170));
//    polygonPoints.push_back(std::pair<int, int>(190,110));
//    polygonPoints.push_back(std::pair<int, int>(130,110));
//    body.getPolygonPoints(polygonPoints);
//    body.drawPolygon();
//    body.fill();
//    info.Draw(body.getFillPoints(), 0, 0, 255);
//    info.Draw(body.getPoints(), 255, 0, 0);
//
//    Line rightArm(130,170, 100,100);
//    info.Draw(rightArm.drawLine(rightArm.getInitialVertexPoints()), 0, 0, 0);
//
//    Line leftArm(190,170, 220,100);
//    info.Draw(leftArm.drawLine(leftArm.getInitialVertexPoints()), 0, 0, 0);
//    
//    Circle rightHand(100,100,10);
//    //rightHand.fillCircle();
//    info.Draw(rightHand.getFillPoints(), 255, 0, 0);
//    info.Draw(rightHand.getPoints(), 0, 255, 0);
//
//    
//    Circle leftHand(220,100,10);
//    //leftHand.fillCircle();
//    info.Draw(leftHand.getFillPoints(), 255, 0, 0);
//    info.Draw(leftHand.getPoints(), 0, 255, 0);
//
//    Line rightLeg(140,110,120,50);
//    info.Draw(rightLeg.drawLine(rightLeg.getInitialVertexPoints()), 0, 0, 0);
//
//    Line leftLeg(180,110,200,50);
//    info.Draw(leftLeg.drawLine(leftLeg.getInitialVertexPoints()), 0, 0, 0);
//
//    Ellipse rightFoot(120,50,20,5);
//    rightFoot.fillEllipse();
//    info.Draw(rightFoot.getFillPoints(), 0, 255, 0);
//    info.Draw(rightFoot.getPoints(), 0, 0, 255);
//    
//    Ellipse leftFoot(200,50,20,5);
//    leftFoot.fillEllipse();
//    info.Draw(leftFoot.getFillPoints(), 0, 255, 0);
//    info.Draw(leftFoot.getPoints(), 0, 0, 255);
//
//    Line pole(100,125, 100,50);
//    Polygon flag;
//    std::vector<std::pair <int,int>>flagPoints;
//    flagPoints.push_back(std::pair<int, int>(100,125));
//    flagPoints.push_back(std::pair<int, int>(100,95));
//    flagPoints.push_back(std::pair<int, int>(60,110));
//    flag.Translate(flagPoints, 0, 35);
//    flag.Rotate(flag.Transformations::getPoints(), 100, 100, 45);
//    flag.Scale(flag.Transformations::getPoints(), 100, 100, 1.25, 1.25);
//    flag.getPolygonPoints(flag.Transformations::getPoints());
//    flag.drawPolygon();
//    flag.fill();
//    
//    pole.Translate(pole.getInitialVertexPoints(), 0, 35);
//    pole.Rotate(pole.getPoints(), 100, 100, 45);
//    pole.Scale(pole.getPoints(), 100, 100, 1.25, 1.25);
//    
//    info.Draw(pole.drawLine(pole.getPoints()), 0, 0, 0);
//    
//    info.Draw(flag.getPoints(), 0, 0, 0);
//    info.Draw(flag.getFillPoints(), 255, 0, 255);
//
//    
//    info.writePPM("problem10.ppm");
//
//
//}
//
//void manAndCar()
//{
//    Image info;
//    info.createCanvas(1000, 500, "255");
//    info.uniformColor(245, 245, 245);
//    
//    int xT = 0;
//    int yT = 0;
//    double degrees = 0;
//    double rotate = 0;
//    Polygon grass;
//    std::vector<std::pair <int,int>>grassPoints;
//    grassPoints.push_back(std::pair<int, int>(0, 0));
//    grassPoints.push_back(std::pair<int, int>(0, 250));
//    grassPoints.push_back(std::pair<int, int>(1000, 250));
//    grassPoints.push_back(std::pair<int, int>(1000, 0));
//    grass.getPolygonPoints(grassPoints);
//    grass.drawPolygon();
//    grass.fill();
//    info.Draw(grass.getFillPoints(), 44, 176, 55);
//    info.Draw(grass.getPoints(), 44, 176, 55);
//    
//    Polygon sky;
//    std::vector<std::pair <int,int>>skyPoints;
//    skyPoints.push_back(std::pair<int, int>(0, 500));
//    skyPoints.push_back(std::pair<int, int>(1000, 500));
//    skyPoints.push_back(std::pair<int, int>(1000, 250));
//    skyPoints.push_back(std::pair<int, int>(0, 250));
//    sky.getPolygonPoints(skyPoints);
//    sky.drawPolygon();
//    sky.fill();
//    info.Draw(sky.getFillPoints(), 0,191,255);
//    info.Draw(sky.getPoints(), 0,191,255);
//    
//    Circle sun(900,400,35);
//    sun.buildCircle(sun.getCircleCenterPoints());
//    sun.fillCircle();
//    
//    Circle head(750,200,20);
//    head.buildCircle(head.getCircleCenterPoints());
//    head.fillCircle();
//    Line neck(750, 180,750,170);
//    
//    Polygon humanBody;
//    std::vector<std::pair <int,int>>humanBodyPoints;
//    humanBodyPoints.push_back(std::pair<int, int>(720,170));
//    humanBodyPoints.push_back(std::pair<int, int>(780,170));
//    humanBodyPoints.push_back(std::pair<int, int>(780,110));
//    humanBodyPoints.push_back(std::pair<int, int>(720,110));
//    humanBody.getPolygonPoints(humanBodyPoints);
//    humanBody.drawPolygon();
//    humanBody.fill();
//    Line rightLeg(730,110,710,50);
//    Line leftLeg(770,110,790,50);
//    Ellipse rightFoot(710,50,20,5);
//    rightFoot.buildEllipse(rightFoot.getEllipseCenterPoints());
//    rightFoot.fillEllipse();
//    Ellipse leftFoot(790,50,20,5);
//    leftFoot.buildEllipse(leftFoot.getEllipseCenterPoints());
//    leftFoot.fillEllipse();
//    
//    for(int i =1;i<=95;i++)
//    {
//        info.uniformColor(245, 245, 245);
//        double lineLength;
//        
//        std::vector<std::pair <int,int>>roofPoints;
//        roofPoints.push_back(std::pair<int, int>(155, 160));
//        roofPoints.push_back(std::pair<int, int>(200, 180));
//        roofPoints.push_back(std::pair<int, int>(300, 180));
//        roofPoints.push_back(std::pair<int, int>(320, 160));
//        Polygon roof;
//        roof.Translate(roofPoints, xT, yT);
//        roof.getPolygonPoints(roof.Transformations::getPoints());
//        roof.drawPolygon();
//        //Draws car roof
//        roof.fill();
//        
//        //Draws main body
//        
//        std::vector<std::pair <int,int>>bodyPoints;
//        Polygon body;
//        bodyPoints.push_back(std::pair<int, int>(335, 160));
//        bodyPoints.push_back(std::pair<int, int>(335, 110));
//        bodyPoints.push_back(std::pair<int, int>(185, 110));
//        bodyPoints.push_back(std::pair<int, int>(185, 160));
//        body.Translate(bodyPoints, xT, yT);
//        body.getPolygonPoints(body.Transformations::getPoints());
//        body.drawPolygon();
//        body.fill();
//        
//        
//        Ellipse doorHandle(200, 135,10,5);
//        doorHandle.Translate(doorHandle.getEllipseCenterPoints(), xT, yT);
//        doorHandle.buildEllipse(doorHandle.Transformations::getPoints());
//        doorHandle.fillEllipse();
//        
//        
//        
//        //Draws front body
//        
//        std::vector<std::pair <int,int>>frontPoints;
//        Polygon front;
//        frontPoints.push_back(std::pair<int, int>(330, 160));
//        frontPoints.push_back(std::pair<int, int>(415, 160));
//        frontPoints.push_back(std::pair<int, int>(405, 150));
//        frontPoints.push_back(std::pair<int, int>(405, 140));
//        frontPoints.push_back(std::pair<int, int>(415, 140));
//        frontPoints.push_back(std::pair<int, int>(405, 120));
//        frontPoints.push_back(std::pair<int, int>(330, 120));
//        front.Translate(frontPoints, xT, yT);
//        front.getPolygonPoints(front.Transformations::getPoints());
//        front.drawPolygon();
//        front.fill();
//        
//        
//        //Draws Rear body
//        
//        std::vector<std::pair <int,int>>rearPoints;
//        Polygon rear;
        //cool back figure out later
        /*rearPoints.push_back(std::pair<int, int>(185, 110));
         rearPoints.push_back(std::pair<int, int>(85, 110));
         rearPoints.push_back(std::pair<int, int>(95, 125));
         rearPoints.push_back(std::pair<int, int>(85, 140));
         rearPoints.push_back(std::pair<int, int>(155, 160));
         rearPoints.push_back(std::pair<int, int>(185, 160));
         */
        /*rearPoints.push_back(std::pair<int, int>(185, 110));
        rearPoints.push_back(std::pair<int, int>(85, 110));
        rearPoints.push_back(std::pair<int, int>(85, 160));
        rearPoints.push_back(std::pair<int, int>(155, 160));
        rearPoints.push_back(std::pair<int, int>(185, 160));
        rear.Translate(rearPoints, xT, yT);
        rear.getPolygonPoints(rear.Transformations::getPoints());
        rear.drawPolygon();
        rear.fill();
        
        Circle  wheel1(160,120,25);
        wheel1.Translate(wheel1.getCircleCenterPoints(), xT, yT);
        wheel1.buildCircle(wheel1.Transformations::getPoints());
        wheel1.fillCircle();
        
        Line rim(135, 120, 185, 120);
        rim.Rotate(rim.getInitialVertexPoints(), 160, 120, rotate);
        rim.Translate(rim.getPoints(), xT, 0);
        rim.drawLine(rim.getPoints());
        
        Circle  wheel2(360,120,25);
        wheel2.Translate(wheel2.getCircleCenterPoints(), xT, yT);
        wheel2.buildCircle(wheel2.Transformations::getPoints());
        wheel2.fillCircle();
        Line rim2(335, 120, 385, 120);
        rim2.Rotate(rim2.getInitialVertexPoints(), 360, 120, rotate);
        rim2.Translate(rim2.getPoints(), xT, 0);
        rim2.drawLine(rim2.getPoints());
        std::vector<std::pair <int,int>>LeftArmPoint;
        std::vector<std::pair <int,int>>RightArmPoint;
        
        Line rightArm(720,170, 690,100);
        rightArm.Rotate(rightArm.getInitialVertexPoints(), 720, 170, -degrees);
        int intRotateArmX;
        int intRotateArmY;
        if(i<20)
        {
            RightArmPoint = rightArm.getPoints();
            rightArm.drawLine(rightArm.getPoints());
        }
        else{
             intRotateArmX = 5*cos(rightArm.convertDegreesToRadians(15)) + 720;
             intRotateArmY = 5*sin(rightArm.convertDegreesToRadians(15)) + 170;
             rightArm.Translate(rightArm.getPoints(), intRotateArmX, intRotateArmY);
            rightArm.Rotate(rightArm.getPoints(), 720, 170, -degrees+(i*2));
            RightArmPoint = rightArm.getPoints();
            rightArm.drawLine(rightArm.getPoints());
        }
        
        
        Line leftArm(780,170, 810,100);
        leftArm.Rotate(leftArm.getInitialVertexPoints(), 780, 170, degrees);
        LeftArmPoint = leftArm.getPoints();
        leftArm.drawLine(leftArm.getPoints());
        
        Circle rightHand(RightArmPoint[1].first,RightArmPoint[1].second,10);
        rightHand.buildCircle(rightHand.getCircleCenterPoints());
        rightHand.fillCircle();
        
        
        
        Circle leftHand(LeftArmPoint[1].first,LeftArmPoint[1].second,10);
        leftHand.buildCircle(leftHand.getCircleCenterPoints());
        leftHand.fillCircle();
        
        Line pole(690,125, 690,50);
        Polygon flag;
        std::vector<std::pair <int,int>>flagPoints;
        flagPoints.push_back(std::pair<int, int>(690,125));
        flagPoints.push_back(std::pair<int, int>(690,95));
        flagPoints.push_back(std::pair<int, int>(650,110));
        flag.Translate(flagPoints, 0, 35);
        flag.Rotate(flag.Transformations::getPoints(), 690, 100, 45);
        flag.Scale(flag.Transformations::getPoints(), 690, 100, 1.25, 1.25);
        if(i==1)
        {
            flag.getPolygonPoints(flag.Transformations::getPoints());
            flag.drawPolygon();
            flag.fill();
        }
        
        int xDiff;
        int yDiff;
        if(rightHand.getCircleCenterPoints()[0].first<690)
        {
            xDiff = -abs(rightHand.getCircleCenterPoints()[0].first-690);
            yDiff = (rightHand.getCircleCenterPoints()[0].second-100);
            
        }
        else{
            xDiff = abs(rightHand.getCircleCenterPoints()[0].first-690);
            yDiff = (rightHand.getCircleCenterPoints()[0].second-100);
        }
        
        pole.Translate(pole.getInitialVertexPoints(), 0, 35);
        pole.Rotate(pole.getPoints(), 690, 100, 45);
        pole.Scale(pole.getPoints(), 690, 100, 1.25, 1.25);
        
        if(i>1)
        {
            pole.Translate(pole.getPoints(), xDiff, yDiff);
            
        }
        
        int flagXDiff;
        int flagYDiff;
        {
            if(pole.getPoints()[0].first<690)
            {
                flagXDiff = -abs(pole.getPoints()[0].first-flag.Transformations::getPoints()[0].first);
                flagYDiff = (pole.getPoints()[0].second-flag.Transformations::getPoints()[0].second);
                
            }
            else{
                flagXDiff = abs(pole.getPoints()[0].first-flag.Transformations::getPoints()[0].first);
                flagYDiff = (pole.getPoints()[0].second-flag.Transformations::getPoints()[0].second);
            }
            
        }
        
        
        if(i>1)
        {
            flag.Translate(flag.Transformations::getPoints(), flagXDiff, flagYDiff);
            flag.getPolygonPoints(flag.Transformations::getPoints());
            flag.drawPolygon();
            flag.fill();
            
        }
        
        
        info.Draw(grass.getFillPoints(), 44, 176, 55);
        info.Draw(grass.getPoints(), 44, 176, 55);
        info.Draw(sky.getFillPoints(), 0,191,255);
        info.Draw(sky.getPoints(), 0,191,255);
        info.Draw(sun.getFillPoints(), 255, 255, 0);
        info.Draw(sun.getPoints(), 255, 255, 0);
        info.Draw(roof.getFillPoints(),135,206,250);
        info.Draw(roof.getPoints(),0, 0, 0);
        info.Draw(body.getFillPoints(), 135,206,250);
        info.Draw(body.getPoints(), 0, 0, 0);
        info.Draw(doorHandle.getPoints(), 0, 0, 0);
        info.Draw(doorHandle.getFillPoints(), 0, 0, 0);
        info.Draw(front.getFillPoints(), 0, 0, 244);
        info.Draw(front.getPoints(), 0, 0, 244);
        info.Draw(rear.getFillPoints(), 120, 0, 233);
        info.Draw(rear.getPoints(), 120, 0, 233);
        info.Draw(wheel1.getFillPoints(),102, 102, 102);
        info.Draw(wheel2.getFillPoints(),102, 102, 102);
        info.Draw(rim.getLinePoints(), 0, 0, 0);
        info.Draw(rim2.getLinePoints(), 0, 0, 0);
        
        
        info.Draw(head.getPoints(), 0, 0, 0);
        info.Draw(head.getFillPoints(), 255, 255, 0);
        info.Draw(neck.drawLine(neck.getInitialVertexPoints()), 0, 0, 0);
        info.Draw(humanBody.getFillPoints(), 0, 0, 255);
        info.Draw(humanBody.getPoints(), 255, 0, 0);
        info.Draw(rightLeg.drawLine(rightLeg.getInitialVertexPoints()), 0, 0, 0);
        info.Draw(leftLeg.drawLine(leftLeg.getInitialVertexPoints()), 0, 0, 0);
        info.Draw(rightFoot.getFillPoints(), 0, 255, 0);
        info.Draw(rightFoot.getPoints(), 0, 0, 255);
        info.Draw(leftFoot.getFillPoints(), 0, 255, 0);
        info.Draw(leftFoot.getPoints(), 0, 0, 255);
        info.Draw(rightArm.getLinePoints(), 0, 0, 0);
        info.Draw(leftArm.getLinePoints(),0,0,0);
        info.Draw(rightHand.getFillPoints(), 255, 0, 0);
        info.Draw(rightHand.getPoints(), 0, 255, 0);
        info.Draw(leftHand.getFillPoints(), 255, 0, 0);
        info.Draw(leftHand.getPoints(), 0, 255, 0);
        
        info.Draw(pole.drawLine(pole.getPoints()), 0, 0, 0);
        
        info.Draw(flag.getPoints(), 0, 0, 0);
        info.Draw(flag.getFillPoints(), 255, 0, 255);
        
        
        stringstream ss;//create a stringstream
        ss << i;//add number to the stream
        string write;
        if(i<=9)
        {
            write = "manAndCarNewVertex00" + ss.str() + ".jpg";
            
        }
        else if(i>9 && i<100){
            write = "manAndCarNewVertex0" + ss.str() + ".jpg";
        }
        else{
            write = "manAndCarNewVertex" + ss.str() + ".jpg";
        }
        cout << "write: " << write << endl;
        info.writePPM(write);
        
        
        if(i<20)
        {
            degrees+=5;
        }
        
        else{
            xT+=8;
            yT+=0;
            rotate+=10;
        }
        
        /*info.Draw(rear.getFillPoints(), 120, 0, 233);
         info.Draw(rear.getPoints(), 120, 0, 233);
         info.writePPM("manAndCar.jpg");
         
        cout << "Progress: %" << setprecision(2) <<100* double((i)/86.00) << endl;
        //std::cout << "Progress: %" << setprecision(2) <<100* double((i)/86.00) << "\r" << std::flush;
    }
    

}
*/
/*
void Line3d()
{
    Image info;
    info.createCanvas(600, 500, "255");
    info.uniformColor(245, 245, 245);
     vector<Coordinates>initialVertexPoints;
    initialVertexPoints.push_back(convert3dTo2d(35, 40,70,20 ));
    initialVertexPoints.push_back(convert3dTo2d(20, 30, 50,20));
    Line line(initialVertexPoints[0].x,initialVertexPoints[0].y, initialVertexPoints[1].x,initialVertexPoints[1].y);
    line.Translate3d(line.getInitialVertexPoints(), 160, 120);
    line.Scale((line.getPoints()), 160, 120, 80, 80);
    
   // cout << "final points: x: " << line.getPoints()[0].x << " y: " << line.getPoints()[0].y << endl;
    //cout << "final points: x: " << line.getPoints()[1].x << " y: " << line.getPoints()[1].y << endl;

    info.Draw(line.drawLine(roundVectorPoints(line.getPoints())), 255, 0, 0);
    
    info.writePPM("3dLine.jpg");
}

double convertDegreesToRadians(int degrees)
{
    return degrees * M_PI/ 180.00;
}

int doubleNumber(int num)
{
    return num*2;
}
/*
/*
void alignment3dA(Image & image, vector<Coordinates>vectorPoints,int beta, int alpha, Coordinates vrpPoints)
{
    Transformations3d info;
    
    //info.initializeUVNPoints();
    
    
    vector<Transformations3d::UVN> first = info.initializeUVNPoints();
    vector<Transformations3d::UVN> second = info.tiltUVNPoints(first, beta);
    
    vector<Transformations3d::UVN> third = info.rotateUVNPoints(second, alpha);
    
    vector<Transformations3d::UVN> testUVN;

    
   // Coordinates vrpPoints = AssignCoordinates3d(36, 25, 74);
    
    vectorPoints = info.wireFrame3dAlignment(vectorPoints, vrpPoints, third, 25);
    for(int i =0; i<vectorPoints.size();i++)
     {
     cout << "x: " << vectorPoints[i].x << " y: " << vectorPoints[i].y << " z: " << vectorPoints[i].z <<endl;
     }
 
    vector<Coordinates> newVector;
    for(int i =0;i<vectorPoints.size();i++)
    {
        newVector.push_back(convert3dTo2d(vectorPoints[i].x, vectorPoints[i].y, vectorPoints[i].z, 20));
    }
    //cout << "converted 3d to 2d: " << endl;
    for(int i =0; i<newVector.size();i++)
    {
        cout << "x: " << newVector[i].x << " y: " << newVector[i].y << endl;
    }

    Line line(newVector[0].x, newVector[0].y, newVector[1].x, newVector[1].y);
    
    line.Translate(line.getInitialVertexPoints(), 180, 120);
    line.Rotate(line.getPoints(), 180, 120, 180);
    line.Scale(line.getPoints(), 180, 120, 10, 10);

    //cout << "After display algorithm: " << endl;
    for(int i =0; i<line.getPoints().size();i++)
    {
       // cout << "x: " << round(line.getPoints()[i].x) << " y: " << round(line.getPoints()[i].y) << endl;
    }

    image.Draw(line.drawLine(roundVectorPoints(line.getPoints())), 255, 0, 0);

}



void house3dPoints(int beta, int alpha, string problem, Coordinates vrpPoints)
{
    Image image;
    image.createCanvas(400, 240, "255");
    image.uniformColor(255, 255, 255);
    
    vector<Coordinates>vectorPoints;
    vectorPoints.push_back(AssignCoordinates3d(0, 0, 54));
    vectorPoints.push_back(AssignCoordinates3d(0, 10, 54));
    alignment3dA(image, vectorPoints, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints2;
    vectorPoints2.push_back(AssignCoordinates3d(0, 0, 54));
    vectorPoints2.push_back(AssignCoordinates3d(16, 0, 54));
    alignment3dA(image, vectorPoints2, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints3;
    vectorPoints3.push_back(AssignCoordinates3d(16, 0, 54));
    vectorPoints3.push_back(AssignCoordinates3d(16, 10, 54));
    alignment3dA(image, vectorPoints3, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints4;
    vectorPoints4.push_back(AssignCoordinates3d(16, 10, 54));
    vectorPoints4.push_back(AssignCoordinates3d(8, 16, 54));
    alignment3dA(image, vectorPoints4, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints5;
    vectorPoints5.push_back(AssignCoordinates3d(8, 16, 54));
    vectorPoints5.push_back(AssignCoordinates3d(0, 10, 54));
    alignment3dA(image, vectorPoints5, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints6;
    vectorPoints6.push_back(AssignCoordinates3d(8, 16, 54));
    vectorPoints6.push_back(AssignCoordinates3d(8, 16, 30));
    alignment3dA(image, vectorPoints6, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints7;
    vectorPoints7.push_back(AssignCoordinates3d(8, 16, 30));
    vectorPoints7.push_back(AssignCoordinates3d(16, 10, 30));
    alignment3dA(image, vectorPoints7, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints8;
    vectorPoints8.push_back(AssignCoordinates3d(16, 10, 30));
    vectorPoints8.push_back(AssignCoordinates3d(16, 0, 30));
    alignment3dA(image, vectorPoints8, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints9;
    vectorPoints9.push_back(AssignCoordinates3d(16, 0, 30));
    vectorPoints9.push_back(AssignCoordinates3d(16, 0, 54));
    alignment3dA(image, vectorPoints9, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints10;
    vectorPoints10.push_back(AssignCoordinates3d(16, 10, 54));
    vectorPoints10.push_back(AssignCoordinates3d(16, 10, 30));
    alignment3dA(image, vectorPoints10, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints11;
    vectorPoints11.push_back(AssignCoordinates3d(8, 16, 30));
    vectorPoints11.push_back(AssignCoordinates3d(0, 10, 30));
    alignment3dA(image, vectorPoints11, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints12;
    vectorPoints12.push_back(AssignCoordinates3d(0, 10, 30));
    vectorPoints12.push_back(AssignCoordinates3d(0, 10, 54));
    alignment3dA(image, vectorPoints12, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints13;
    vectorPoints13.push_back(AssignCoordinates3d(0, 0, 54));
    vectorPoints13.push_back(AssignCoordinates3d(0, 0, 30));
    alignment3dA(image, vectorPoints13, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints14;
    vectorPoints14.push_back(AssignCoordinates3d(0, 0, 30));
    vectorPoints14.push_back(AssignCoordinates3d(0, 10, 30));
    alignment3dA(image, vectorPoints14, beta, alpha, vrpPoints);
    
    vector<Coordinates>vectorPoints15;
    vectorPoints15.push_back(AssignCoordinates3d(0, 0, 30));
    vectorPoints15.push_back(AssignCoordinates3d(16, 0, 30));
    alignment3dA(image, vectorPoints15, beta, alpha, vrpPoints);
    
    string write;

        write = "3dHouse" + problem + ".jpg";
        

    image.writePPM(write);
}
*/

int main(int argc, const char * argv[]) {
    // insert code here...

    //threeDTransformations1();
    //threeDTransformations2();
    //threeDTransformations3();
    animation();
       return 0;
    
}
