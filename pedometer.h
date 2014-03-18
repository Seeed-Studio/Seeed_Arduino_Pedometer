/*
* pedometer.h 
*  
* Copyright (c) 2014 seeed technology inc. 
* Author  		: 	lawliet.zou(lawliet.zou@gmail.com)
* Create Time	: 	Mar 18, 2014 
* Change Log 	: 
*
* The MIT License (MIT)
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#include <ADXL345.h>
#include "arduino.h"

#define MAX_AXIS                3
#define MAX_WINDOW              3
#define SAMPLING_MODEL_NUMBER   60
#define MODEL_STANDARD_VALUE    20

enum Axis{
    X_AXIS = 0,
    Y_AXIS = 1,
    Z_AXIS = 2,
};

class Pedometer{
public:
    void init(void);
    void stepCalc(void);
    uint16_t stepCount;
    
private:
    void sensorInit(void);
    void updateModelAxis(void);
    void getValue(void);
    void getValidValue(void);
        
    ADXL345 adxl; 
    Axis _model_axis;
    int _model_val;
    int _curr_val;   
    int _model_ratio;
    int _last_val;
};