[![GitHub license](https://img.shields.io/github/license/mpusz/units?cacheSeconds=3600&color=informational&label=License)](./LICENSE.md)
[![Conan CI](https://img.shields.io/github/workflow/status/mpusz/units/Conan%20CI/master?label=Conan)](https://github.com/mpusz/units/actions?query=workflow%3A%22Conan%20CI%22+branch%3Amaster)
[![CMake CI](https://img.shields.io/github/workflow/status/mpusz/units/CMake%20Test%20Package%20CI/master?label=CMake)](https://github.com/mpusz/units/actions?query=workflow%3A%22CMake+Test+Package+CI%22+branch%3Amaster)
[![GitHub Workflow Documentation](https://img.shields.io/github/workflow/status/mpusz/units/Documentation/master?label=Documentation)](https://github.com/mpusz/units/actions?query=workflow%3ADocumentation+branch%3Amaster)
[![Conan stable](https://api.bintray.com/packages/mpusz/conan-mpusz/mp-units%3Ampusz/images/download.svg?version=0.6.0%3Astable)](https://bintray.com/mpusz/conan-mpusz/mp-units%3Ampusz/0.6.0%3Astable/link)
[![Conan testing](https://api.bintray.com/packages/mpusz/conan-mpusz/mp-units%3Ampusz/images/download.svg)](https://bintray.com/mpusz/conan-mpusz/mp-units%3Ampusz/_latestVersion)

# `mp-units` - A Units Library for C++

**The mp-units library is the subject of ISO standardization for C++23/26. More on this can
be found in ISO C++ paper [P1935](https://wg21.link/p1935) and
[CppCon 2020 talk](https://www.youtube.com/watch?v=7dExYGSOJzo). We are actively looking for
parties interested in field trialing the library.**


## Documentation

An extensive project documentation including installation instructions and user's
guide can be found on [mp-units GitHub Pages](https://mpusz.github.io/units).


## TL;DR

`mp-units` is a compile-time enabled Modern C++ library that provides compile-time dimensional
analysis and unit/quantity manipulation. The basic idea and design heavily bases on
`std::chrono::duration` and extends it to work properly with many dimensions.

Here is a small example of possible operations:

```cpp
#include <units/physical/si/derived/area.h>
#include <units/physical/si/derived/frequency.h>
#include <units/physical/si/derived/speed.h>

using namespace units::physical::si;

// simple numeric operations
static_assert(10_q_km / 2 == 5_q_km);

// unit conversions
static_assert(1_q_h == 3600_q_s);
static_assert(1_q_km + 1_q_m == 1001_q_m);

// dimension conversions
static_assert(1_q_km / 1_q_s == 1000_q_m_per_s);
static_assert(2_q_km_per_h * 2_q_h == 4_q_km);
static_assert(2_q_km / 2_q_km_per_h == 1_q_h);

static_assert(2_q_m * 3_q_m == 6_q_m2);

static_assert(10_q_km / 5_q_km == 2);

static_assert(1000 / 1_q_s == 1_q_kHz);
```

_Try it on the [Compiler Explorer](https://godbolt.org/z/YWch6d)._

This library requires some C++20 features (concepts, classes as NTTPs, ...). Thanks to
them the user gets a powerful but still easy to use interface and all unit conversions
and dimensional analysis can be performed without sacrificing on accuracy. Please see
the below example for a quick preview of basic library features:

```cpp
#include <units/physical/si/derived/speed.h>
#include <units/physical/si/international/derived/speed.h>
#include <units/format.h>
#include <iostream>

using namespace units::physical;

constexpr Speed auto avg_speed(Length auto d, Time auto t)
{
  return d / t;
}

int main()
{
  using namespace units::physical::si::literals;
  Speed auto v1 = avg_speed(220_q_km, 2_q_h);
  Speed auto v2 = avg_speed(si::length<si::international::mile>(140), si::time<si::hour>(2));
  Speed auto v3 = quantity_cast<si::metre_per_second>(v2);
  Speed auto v4 = quantity_cast<int>(v3);

  std::cout << v1 << '\n';   // 110 km/h
  std::cout << v2 << '\n';   // 70 mi/h
  std::cout << v3 << '\n';   // 31.2928 m/s
  std::cout << v4 << '\n';   // 31 m/s
}
```

_Try it on the [Compiler Explorer](https://godbolt.org/z/8dh4cv)._
