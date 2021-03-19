// The MIT License (MIT)
//
// Copyright (c) 2018 Mateusz Pusz
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

#include <units/data/data.h>

/* ************** DERIVED DIMENSIONS THAT INCLUDE UNITS WITH SPECIAL NAMES **************** */

namespace {

using namespace units::data;

// information

static_assert(1_q_B == 8_q_b);
static_assert(1024_q_b == 1_q_Kib);
static_assert(1024_q_B == 1_q_KiB);
static_assert(8 * 1024_q_b == 1_q_KiB);
static_assert(8 * 1_q_Kib == 1_q_KiB);

static_assert(1_q_kb == 1000_q_b);
static_assert(2000_q_Mib == 2097152_q_kb);

static_assert(1_q_Kib == 1024_q_b);
static_assert(1_q_Mib == 1024_q_Kib);
static_assert(1_q_Gib == 1024_q_Mib);
static_assert(1_q_Tib == 1024_q_Gib);
static_assert(1_q_Pib == 1024_q_Tib);

// bitrate

}
