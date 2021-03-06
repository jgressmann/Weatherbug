/* The MIT License (MIT)
 *
 * Copyright (c) 2016, 2017 Jean Gressmann <jean@0x42.de>
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

#include "Network.h"
#include "Misc.h"

static Network_SendCallback s_DataReceivedCallback NOINIT;
static uint8_t s_Id NOINIT;
static uint8_t s_Ttl NOINIT;

void
Network_SetSendCallback(Network_SendCallback callback) {
    s_DataReceivedCallback = callback;
}

void
Network_Send(NetworkPacket* packet) {
    s_DataReceivedCallback(packet);
}

void
Network_SetAddress(uint8_t id) {
    s_Id = id;
}

uint8_t
Network_GetAddress() {
    return s_Id;
}

uint8_t
Network_GetTtl() {
    return s_Ttl;
}

void
Network_SetTtl(uint8_t ttl) {
    s_Ttl = ttl;
}
