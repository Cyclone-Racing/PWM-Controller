/*
Code to set the pulse width for a motor or other PWM controlled device
Uses an Arduino nano for PWM output and a potentiometer to determine the PW
*/

int Vin; // Stores inital analog value
int Percent; // Converts to a Percent
int PWM; // Stores PWM value

char message[32]; // Message buffer

void setup() {
    Serial.begin(115200);
}

void loop() {
    Vin = analogRead(A0); // Potentiometer is connected to A0
    // 0-1023 range
    Percent = (Vin * 100) / 1023; // Convert to %
    PWM = (Percent * 255) / 100; // Convert to PWM value
    digitalWrite(13, PWM); // Write PWM value to pin 13
    sprintf(message, "%d%", Percent); // Format message string
    Serial.println(message); // Print message string to serial port for debug
}