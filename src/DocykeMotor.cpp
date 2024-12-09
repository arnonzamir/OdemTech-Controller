#include "DocykeMotor.h"

DocykeMotor::DocykeMotor(uint8_t enable, uint8_t direction, uint8_t velocity)
    : enablePin(enable), directionPin(direction), velocityPin(velocity), isEnabled(false) {
    
    pinMode(enablePin, OUTPUT);
    pinMode(directionPin, OUTPUT);
    
    // Configure LEDC for PWM
    ledcSetup(pwmChannel, pwmFreq, pwmResolution);
    ledcAttachPin(velocityPin, pwmChannel);
    
    // Initial state
    digitalWrite(enablePin, LOW);
    digitalWrite(directionPin, LOW);
    ledcWrite(pwmChannel, 0);
}

void DocykeMotor::enable() {
    digitalWrite(enablePin, LOW);  // Pull low first
    delay(200);                     // Small delay for stability
    digitalWrite(enablePin, HIGH); // Then pull high
    isEnabled = true;
}

void DocykeMotor::disable() {
    digitalWrite(enablePin, LOW);
    isEnabled = false;
}

void DocykeMotor::setDirection(bool isBackward) {
    digitalWrite(directionPin, isBackward ? HIGH : LOW);
}

void DocykeMotor::setSpeed(uint8_t speed) {
    if (speed > 255) speed = 255;  // Ensure speed is within valid range
    ledcWrite(pwmChannel, speed);
}

bool DocykeMotor::getEnabled() const {
    return isEnabled;
} 