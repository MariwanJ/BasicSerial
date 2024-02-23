//
// This file is a part of the Open Source BasicSleep
// MIT License
//
// Copyright (c) 2024
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//  Author :Mariwan Jalal    mariwan.jalal@gmail.com
//

#ifndef BASICSERIAL_H
#define BASICSERIAL_H
#include "mbed.h"

#define SLEEP(x) ThisThread::sleep_for(x)

//I keep this as float just so you know, that this will not be perfect
#define B600  1666666.6
#define B1200  833333.3
#define B2400  416666.6
#define B4800  208333.3
#define B9600  104166.6
#define B14400  69444.4
#define B19200  52083.3
#define B28800  34722.2
#define B38400  26041.6
#define B56000  17857.1
#define B57600  17361.1
#define B115200  8680.5
#define B128000  7812.5
#define B256000  3906.2

class BasicSerial {
public:
	BasicSerial(PinName txPin, PinName rxPin, uint32_t baud = B9600);
	BasicSerial(const BasicSerial& obj) = delete; //You cannot have copy constructor
	~BasicSerial();

	virtual void txBasic(unsigned char byte);
	virtual int rxBasic(unsigned char& byte);
private:
	DigitalOut m_tx;
	DigitalIn m_rx;
	int m_bitDuration;
	int m_halfBitDuration;
};
#endif
