/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   compoundVertical.h
 * Author: Overlord Dan
 *
 * Created on April 5, 2018, 8:31 PM
 */

#ifndef COMPOUNDVERTICAL_H
#define COMPOUNDVERTICAL_H
#include "shape.h"
#include <vector>
#include <memory>

//if curr shape>prev shape
//  then +(boxwidth-prevwidth)/2
//else if shape<prev shape
//  then -(boxwidth-currwidth)/2

class compoundVertical : public Shape {
public:
    using Compound = std::vector<std::unique_ptr<Shape> >;
    compoundVertical()= delete;
    compoundVertical(Compound shapes);
    ~compoundVertical() override = default;
    const Compound getShapes() const;
    const BoundingBox getBoundingBox() const;
    
private:
    Compound _shapes;
};

#endif /* COMPOUNDVERTICAL_H */

