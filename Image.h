//
//  Image.h
//  Computer Graphics PPM
//
//  Created by Miles Tucker on 8/30/17.
//  Copyright © 2017 Miles Tucker. All rights reserved.
//

#ifndef Image_h
#define Image_h
#include<iostream>
#include<fstream>
#include<string>
#include "Tools.h"
using namespace std;

class Image{
private:
    int width;
    int height;
    string max;
    int total;
    Pixels* pixels;
    
public:
    
    Image()
    {
    
    }
    Image(int w, int h, string m)
    {
        width = w;
        height = h;
        max = m;
    }

    void createCanvas(int w, int h, string m)
    {
    
        width = w;
        height = h;
        total = width*height;
        //printf("Total: %d\n", total);
        max = m;
        pixels = new Pixels[total];
    }
    
    void uniformColor(int r, int g, int b)
    {
        
        //Generating color of image
        for(int x = 0; x<total; x++)
        {
            pixels[x].r = r;
            pixels[x].b = b;
            pixels[x].g = g;
            
        }
        
    }
    
    void Draw(vector<Coordinates>vertexPoints, int r, int g, int b)
    {
        
        for(int i =0;i<vertexPoints.size();i++)
        {
            if(inBounds(vertexPoints[i].x, vertexPoints[i].y))
            {
                int index = indexTranslator(vertexPoints[i].x, vertexPoints[i].y);

            pixels[index].r = r;
            pixels[index].b = b;
            pixels[index].g = g;
            }
        }

    }
    
    void DrawEnvironment(vector<Coordinates>vertexPoints)
    {
       // cout << "size of pixels: "<< vertexPoints.size() << endl;
        for(int i =0;i<vertexPoints.size();i++)
        // for(int i =0;i<3721;i++)
        {
           
                Coordinates p = vertexPoints[i];
                if (p.x >= 0 && p.x < width && p.y >= 0 && p.y < height) {
                    pixels[i].r = vertexPoints[i].color.r;
                    pixels[i].b = vertexPoints[i].color.b;
                    pixels[i].g = vertexPoints[i].color.g;
                    
                    //cout << "pixels: " << pixels[i].r << " " << pixels[i].g  << " " << pixels[i].b << endl;
                }

        }
        /*
        for(int i =0;i<vertexPoints.size();i++)
        {
            if(inBounds(vertexPoints[i].x, vertexPoints[i].y))
            {
                cout << "in bound" << endl;
                int index = indexTranslator(vertexPoints[i].x, vertexPoints[i].y);
                
                pixels[index].r = vertexPoints[i].color.r;
                pixels[index].b = vertexPoints[i].color.b;
                pixels[index].g = vertexPoints[i].color.g;
            }
        }
        */
    }

    
    bool inBounds(int x, int y)
    {
        return (x>=0 && x<=width && y>=0 && y<=height);
    }
    
    int indexTranslator(int x, int y)
    {
        int index = x + width*(height - y - 1)+1;
        return index;
    }
    
    void writePPM(string name)
    {
        ofstream image (name);
        image << "P3" << endl;
        image << width << " " << height << endl;
        image << max << endl;
        
        for(int i = 0;i< total;i++)
        {
            image <<pixels[i].r << " " << pixels[i].g << " " << pixels[i].b << " " << endl;
        }
        //open image in app
      // system("open manAndCar.jpg");
    }
};
#endif /* Image_h */
