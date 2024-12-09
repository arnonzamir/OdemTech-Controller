#ifndef DOCYKE_MOTOR_H
#define DOCYKE_MOTOR_H

#include <Arduino.h>

class DocykeMotor {
private:
    const uint8_t enablePin;
    const uint8_t directionPin;
    const uint8_t velocityPin;
    bool isEnabled;
    
    // PWM properties
    const int pwmChannel = 0;  // LEDC channel (0-15)
    const int pwmFreq = 5000;  // 5 KHz frequency
    const int pwmResolution = 8;  // 8-bit resolution (0-255)

public:
    DocykeMotor(uint8_t enable, uint8_t direction, uint8_t velocity);
    void enable();
    void disable();
    void setDirection(bool isBackward);
    void setSpeed(uint8_t speed);
    bool getEnabled() const;
};

#endif 