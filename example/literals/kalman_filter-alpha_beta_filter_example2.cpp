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

#include <units/format.h>
#include <units/isq/si/length.h>
#include <units/isq/si/speed.h>
#include <units/isq/si/time.h>
#include <iostream>
#include <array>

/*
   kalman filter tutorial
   1d aircraft α-β filter example2 from https://www.kalmanfilter.net/alphabeta.html#ex2
*/

namespace {

template<units::Quantity Q>
struct state_variable {
  Q estimated_current_state;
  Q predicted_next_state;
};

using namespace units::isq;
using namespace units::isq::si::literals;

constexpr auto radar_transmit_interval = 5.0_q_s;
constexpr double kalman_range_gain = 0.2;
constexpr double kalman_speed_gain = 0.1;

struct state {
  state_variable<si::length<si::metre>> range;
  state_variable<si::speed<si::metre_per_second>> speed;

  constexpr void estimate(const state& previous_state, const si::length<si::metre>& measurement)
  {
    auto const innovation = measurement - previous_state.range.predicted_next_state;
    range.estimated_current_state = previous_state.range.predicted_next_state + kalman_range_gain * innovation;
    speed.estimated_current_state =
        previous_state.speed.predicted_next_state + kalman_speed_gain * innovation / radar_transmit_interval;
  }

  constexpr void predict()
  {
    range.predicted_next_state =
        range.estimated_current_state + speed.estimated_current_state * radar_transmit_interval;
    speed.predicted_next_state = speed.estimated_current_state;
  }
};

}  // namespace

int main()
{
  std::cout << "\n\n1d aircraft α-β filter example2 from https://www.kalmanfilter.net/alphabeta.html#ex2";
  std::cout << "\n\n";

  constexpr auto measurements = std::array{0.0_q_m,  // N.B measurement[0] is unknown and unused
                                           30110.0_q_m, 30265.0_q_m, 30740.0_q_m, 30750.0_q_m, 31135.0_q_m,
                                           31015.0_q_m, 31180.0_q_m, 31610.0_q_m, 31960.0_q_m, 31865.0_q_m};

  constexpr auto num_measurements = measurements.size();

  std::array<state, num_measurements> track;
  // We need an initial estimate of track[0] as there is no previous state to get a prediction from
  track[0].range.estimated_current_state = 30'000_q_m;
  track[0].speed.estimated_current_state = 40.0_q_m_per_s;

  for (auto n = 0U; n < num_measurements; ++n) {
    if (n > 0) {
      track[n].estimate(track[n - 1], measurements[n]);
    }
    track[n].predict();

    std::cout << fmt::format("measurement[{}]                    = {:.0}\n", n, measurements[n]);
    std::cout << fmt::format("range.estimated_current_state[{}]  = {:.1}\n", n, track[n].range.estimated_current_state);
    std::cout << fmt::format("speed.estimated_current_state[{}]  = {:.1}\n", n, track[n].speed.estimated_current_state);
    std::cout << fmt::format("range.predicted_next_state[{}]     = {:.1}\n", n, track[n].range.predicted_next_state);
    std::cout << fmt::format("speed.predicted_next_state[{}]     = {:.1}\n\n", n, track[n].speed.predicted_next_state);
  }
}
