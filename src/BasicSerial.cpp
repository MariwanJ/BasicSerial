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

#include "BasicSerial.h"

// Constructor
BasicSerial::BasicSerial(PinName txPin, PinName rxPin, uint32_t baud) :
	m_tx(txPin), m_rx(rxPin, PullUp), m_bitDuration(baud), m_halfBitDuration(baud / 2) {
}

//Destructor
BasicSerial::~BasicSerial() {
}

//Basic to send 8 bits (10 with stop bits)
void BasicSerial::txBasic(unsigned char byte) {
	// Send start bit (low)
	m_tx.write(0);
	wait_ns(m_bitDuration);
	// Send data bits (8 bits)
	for (int i = 0; i < 8; ++i) {
		m_tx.write((byte >> i) & 1);
		wait_ns(m_bitDuration);
	}
	// Send stop bit (high)
	m_tx.write(1);
	wait_ns(m_bitDuration);
}

//Basic to receive 8 bit (10 with stop bits)
int BasicSerial::rxBasic(unsigned char& byte) {
	// Wait for start bit
	int counter = 0;
	byte = 0;
	while (m_rx.read() == 1) {
		counter++;
		wait_ns(m_halfBitDuration);
		if (counter > 1000) {
			return -1;//failed
		}
	}
	wait_ns(m_bitDuration);
	// Receive data bits (8 bits)
	for (int i = 0; i < 8; ++i) {
		byte |= (m_rx.read() << i);
		wait_ns(m_bitDuration);
	}
	// Wait for stop bit
	while (m_rx.read() == 0) {
		// Wait for the stop bit // TODO : How long??? this will cause issue
	}
	wait_ns(m_bitDuration);
	return 1;
}