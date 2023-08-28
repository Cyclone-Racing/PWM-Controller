/*
Code to set the pulse width for a motor or other PWM controlled device
Uses an Arduino nano for PWM output and a potentiometer to determine the PW
*/

int Vin;
int Percent;
int PWM;

char message[32];

void setup() {
    Serial.begin(115200);
}

void loop() {
    Vin = analogRead(A0); // Potentiometer is connected to A0
    // 0-1023 range
    Percent = (Vin * 100) / 1023; // Convert to %
    PWM = (Percent * 255) / 100;
    digitalWrite(13, PWM);
    sprintf(message, "%d%", Percent);
    Serial.println(message);
}