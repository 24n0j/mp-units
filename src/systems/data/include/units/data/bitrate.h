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

#pragma once

#include <units/data/information.h>
#include <units/derived_dimension.h>
#include <units/isq/si/time.h>
#include <units/quantity.h>

namespace units::data {

struct bit_per_second : unit<bit_per_second> {};
struct dim_bitrate : derived_dimension<dim_bitrate, bit_per_second, exponent<dim_information, 1>, exponent<isq::si::dim_time, -1>> {};

struct kibibit_per_second : deduced_unit<kibibit_per_second, dim_bitrate, kibibit, isq::si::second> {};
struct mebibit_per_second : deduced_unit<mebibit_per_second, dim_bitrate, mebibit, isq::si::second> {};
struct gibibit_per_second : deduced_unit<gibibit_per_second, dim_bitrate, gibibit, isq::si::second> {};
struct tebibit_per_second : deduced_unit<tebibit_per_second, dim_bitrate, tebibit, isq::si::second> {};
struct pebibit_per_second : deduced_unit<pebibit_per_second, dim_bitrate, pebibit, isq::si::second> {};

struct kilobit_per_second : deduced_unit<kilobit_per_second, dim_bitrate, kilobit, isq::si::second> {};
struct megabit_per_second : deduced_unit<megabit_per_second, dim_bitrate, megabit, isq::si::second> {};
struct gigabit_per_second : deduced_unit<gigabit_per_second, dim_bitrate, gigabit, isq::si::second> {};
struct terabit_per_second : deduced_unit<terabit_per_second, dim_bitrate, terabit, isq::si::second> {};
struct petabit_per_second : deduced_unit<petabit_per_second, dim_bitrate, petabit, isq::si::second> {};

template<typename T>
concept Bitrate = QuantityOf<T, dim_bitrate>;

template<UnitOf<dim_bitrate> U, QuantityValue Rep = double>
using bitrate = quantity<dim_bitrate, U, Rep>;

inline namespace literals {

// bits
constexpr auto operator"" _q_b_per_s(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return bitrate<bit_per_second, std::int64_t>(static_cast<std::int64_t>(l)); }
constexpr auto operator"" _q_Kib_per_s(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return bitrate<kibibit_per_second, std::int64_t>(static_cast<std::int64_t>(l)); }
constexpr auto operator"" _q_Mib_per_s(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return bitrate<mebibit_per_second, std::int64_t>(static_cast<std::int64_t>(l)); }
constexpr auto operator"" _q_Gib_per_s(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return bitrate<gibibit_per_second, std::int64_t>(static_cast<std::int64_t>(l)); }
constexpr auto operator"" _q_Tib_per_s(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return bitrate<tebibit_per_second, std::int64_t>(static_cast<std::int64_t>(l)); }
constexpr auto operator"" _q_Pib_per_s(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return bitrate<pebibit_per_second, std::int64_t>(static_cast<std::int64_t>(l)); }

constexpr auto operator"" _q_kb_per_s(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return bitrate<kilobit_per_second, std::int64_t>(static_cast<std::int64_t>(l)); }
constexpr auto operator"" _q_Mb_per_s(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return bitrate<megabit_per_second, std::int64_t>(static_cast<std::int64_t>(l)); }
constexpr auto operator"" _q_Gb_per_s(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return bitrate<gigabit_per_second, std::int64_t>(static_cast<std::int64_t>(l)); }
constexpr auto operator"" _q_Tb_per_s(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return bitrate<terabit_per_second, std::int64_t>(static_cast<std::int64_t>(l)); }
constexpr auto operator"" _q_Pb_per_s(unsigned long long l) { gsl_ExpectsAudit(std::in_range<std::int64_t>(l)); return bitrate<petabit_per_second, std::int64_t>(static_cast<std::int64_t>(l)); }

}  // namespace literals

namespace references {

inline constexpr auto b_per_s = reference<dim_bitrate, bit_per_second>{};
inline constexpr auto Kib_per_s = reference<dim_bitrate, kibibit_per_second>{};
inline constexpr auto Mib_per_s = reference<dim_bitrate, mebibit_per_second>{};
inline constexpr auto Gib_per_s = reference<dim_bitrate, gibibit_per_second>{};
inline constexpr auto Tib_per_s = reference<dim_bitrate, tebibit_per_second>{};
inline constexpr auto Pib_per_s = reference<dim_bitrate, pebibit_per_second>{};

inline constexpr auto kb_per_s = reference<dim_bitrate, kilobit_per_second>{};
inline constexpr auto Mb_per_s = reference<dim_bitrate, megabit_per_second>{};
inline constexpr auto Gb_per_s = reference<dim_bitrate, gigabit_per_second>{};
inline constexpr auto Tb_per_s = reference<dim_bitrate, terabit_per_second>{};
inline constexpr auto Pb_per_s = reference<dim_bitrate, petabit_per_second>{};

}  // namespace references

}  // namespace units::data