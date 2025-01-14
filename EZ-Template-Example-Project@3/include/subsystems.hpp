#pragma once

#include "api.h"

// Your motors, sensors, etc. should go here.  Below are examples

inline pros::MotorGroup intake({-11, 8});
inline ez::Piston mogo_mech('A', false);
// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');