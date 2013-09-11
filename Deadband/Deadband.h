/*
Deadband.h - An Arduino library for implementing deadband on digital values.
https://github.com/cellularmitosis/Deadband
v0.1 (Sept 7, 2013)

Deadband: see http://en.wikipedia.org/wiki/Deadband%23Backlash

If you've ever used a mill or a lathe which had some slop in the carriage, 
or an old car which had slop in the steering, that's deadband.

The Deadband library allows you to create "digital slop".

Copyright (c) 2013 Jason Pepas

This software is released under the terms of the MIT License:

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef Deadband_h
#define Deadband_h

#include <stdlib.h>
#include <stdint.h>

struct _DeadbandFilter
{
	uint8_t numberOfLSBsToConsume;
	uint16_t deadbandWindowLowerEdge;
	uint16_t previousOutput;
};

typedef struct _DeadbandFilter DeadbandFilter;

DeadbandFilter* createDeadbandFilter(uint8_t numberOfLSBsToConsume);
uint16_t deadband(DeadbandFilter *filter, uint16_t newInput);

#endif // Deadband_h
