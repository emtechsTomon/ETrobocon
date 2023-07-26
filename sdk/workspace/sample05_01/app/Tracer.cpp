#include "Tracer.h" // <1>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2) { // <2>
}

void Tracer::init() {
  init_f("Tracer");
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

float Tracer::calc_prop_value() {
  const int8_t TargetValue = 17;//@
  const float Kp = 0.9;//@
  const int8_t bias = 0;
  int diff = colorSensor.getBrightness() - TargetValue;
  return Kp * diff + bias;c