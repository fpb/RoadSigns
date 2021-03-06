//
//  Shapes.h
//  RoadSigns
//
//  Created by Fernando Birra on 2/14/13.
//  Copyright (c) 2013 Fernando Birra. All rights reserved.
//

#ifndef __RoadSigns__Shapes__
#define __RoadSigns__Shapes__

#include <iostream>

#include <cv.h>

class Shape {
public:
    Shape(int cx, int cy, int radius, int length, int nsides):radius(radius), nsides(nsides), length(length), centerx(cx), centery(cy)
    {
    }
    virtual ~Shape() {};
    virtual void drawOn(cv::Mat &img) = 0;
    virtual int getLeft() { return centerx - length/2; };
    virtual int getRight() { return centerx + length/2+1; };
    virtual int getTop() { return centery - length/2; };
    virtual int getBottom() { return centery + length/2+1; };
    
    
public:
    int radius;
    int nsides;
    int length;
    int centerx, centery;
};

class Circle : public Shape {
public:
    Circle(int cx, int cy, int radius, int length) : Shape(cx, cy, radius, length, 0) {};
    virtual ~Circle() {};
    
    virtual void drawOn(cv::Mat &img) {
        cv::circle(img, cv::Point(centerx, centery), radius, cv::Scalar(0,0,255), 1);
    }
};

class Triangle : public Shape {
public:
    Triangle(int cx, int cy, int radius, int length): Shape(cx, cy, radius, length, 3) {};
    virtual ~Triangle() {};

    virtual void drawOn(cv::Mat &img) {
        float R = 2*radius;
        float cos30 = (float) cos(M_PI/6.0);
//        float sin30 = (float) sin(M_PI/6.0);
        
        cv::line(img, cv::Point(centerx-R*cos30,centery+radius), cv::Point(centerx, centery-R), cv::Scalar(0,255,255),1);
        cv::line(img, cv::Point(centerx, centery-R), cv::Point(centerx+R*cos30, centery+radius), cv::Scalar(0,255,255),1);
        cv::line(img, cv::Point(centerx+R*cos30, centery+radius), cv::Point(centerx-R*cos30,centery+radius), cv::Scalar(0,255,255),1);
//        cv::circle(img, cv::Point(centerx, centery), radius, cv::Scalar(0,255,255));
    }
};

class Square : public Shape {
public:
    Square(int cx, int cy, int radius, int length): Shape(cx, cy, radius, length, 4) {};
    virtual ~Square() {};

    virtual void drawOn(cv::Mat &img) {
        cv::rectangle(img, cv::Point(centerx-radius, centery-radius), cv::Point(centerx+radius, centery+radius), cv::Scalar(255,0,0),1);
    }
};

class Octagon : public Shape {
public:
    Octagon(int cx, int cy, int radius, int length) : Shape(cx, cy, radius, length, 8) {};
    virtual  ~Octagon() {};

    virtual void drawOn(cv::Mat &img) {
        cv::circle(img, cv::Point(centerx, centery), radius, cv::Scalar(255,255,0));
    }
};

#endif /* defined(__RoadSigns__Shapes__) */
