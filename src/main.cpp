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

#include "mbed.h"
#include "threadSerial.h"
#include<string>

int main() {
	BasicSerial rs232(PB_10, PB_11, B1200);
	SLEEP(1s);
	const char* t = "Test Thread Serial";
	std::string buf;
	while (1) {
		unsigned char byte;
		while (!(buf.size() >= 40)) {
			if (rs232.rxThread(byte) != -1)
				buf.push_back(byte);
			SLEEP(1ms);
		}

		printf(buf.c_str());
		fflush(NULL);
		for (int i = 0; i < buf.size(); i++) {
			rs232.txThread(buf[i]);
		}
		buf.clear();
		SLEEP(1ms);
	}
}