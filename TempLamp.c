/* TemperatureLamp Model Module File */

// LED connected to digital pin 9
const int greenLEDPin = 9;

// LED connected to digital pin 10
const int blueLEDPin = 10;

// LED connected to digital pin 11
const int redLEDPin = 11;

// Temperature Sensor
const int sensorPin = A0;

// Sets the analog output of sensorPin
int sensorVal = analogRead(sensorPin);

// value to write to the red LED
int redValue = 255;

// value to write to the green LED
int greenValue = 0;

// value to write to the blue LED
int blueValue = 0;

// model setup
void setup() {
    // init serial
    Serial.begin(9600);

    // set rgb pin modes
    pinMode(redLEDPin, OUTPUT);
    pinMode(greenLEDPin, OUTPUT);
    pinMode(blueLEDPin, OUTPUT);
}

// forever loop through sensor analog data to
// determine its temperature band and rgb value
void loop() {
    // grab sensor feed
    int sensorVal = analogRead(sensorPin);

    float tempVolts = sensorVal * 5.0 / 1024.0;
    Serial.print(", Volts: ");
    Serial.println(tempVolts);
    Serial.print(", degrees C: ");
    float tempC = (tempVolts - 0.5) * 100.0;
    Serial.println(tempC);
    Serial.print(", degrees F: ");
    float tempF = tempC * 9.0 / 5.0 + 32.0;
    Serial.println(tempF);

    // float temperature = tempC;
    float temperature = tempF;

    if (temperature <= 150 && temperature >= 100) {
        redValue = 178;
        greenValue = 25;
        blueValue = 12;
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, greenValue);
        analogWrite(blueLEDPin, blueValue);

    } else if (temperature >= 90 && temperature <= 99) {
        redValue = 255;
        greenValue = 20;
        blueValue = 0;
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, greenValue);
        analogWrite(blueLEDPin, blueValue);

    } else if (temperature >= 80 && temperature <= 89) {
        redValue = 229;
        1greenValue = 29;
        blueValue = 0;
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, greenValue);
        analogWrite(blueLEDPin, blueValue);

    } else if (temperature >= 70 && temperature <= 79) {
        redValue = 217;
        greenValue = 14;
        blueValue = 0;
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, greenValue);
        analogWrite(blueLEDPin, blueValue);

    } else if (temperature >= 60 && temperature < 69) {
        redValue = 32;
        greenValue = 14;
        blueValue = 0;
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, greenValue);
        analogWrite(blueLEDPin, blueValue);

    } else if (temperature >= 50 && temperature <= 59) {
        redValue = 116;
        greenValue = 55;
        blueValue = 32;
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, greenValue);
        analogWrite(blueLEDPin, blueValue);

    } else if (temperature >= 40 && temperature <= 49) {
        redValue = 32;
        greenValue = 72;
        blueValue = 88;
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, greenValue);
        analogWrite(blueLEDPin, blueValue);

    } else if (temperature >= 30 && temperature <= 39) {
        redValue = 40;
        greenValue = 88;
        blueValue = 169;
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, greenValue);
        analogWrite(blueLEDPin, blueValue);

    } else if (temperature >= 20 && temperature <= 29) {
        redValue = 0;
        greenValue = 21;
        blueValue = 255;
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, greenValue);
        analogWrite(blueLEDPin, blueValue);

    } else if (temperature >= 10 && temperature <= 19) {
        redValue = 0;
        greenValue = 17;
        blueValue = 255;
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, greenValue);
        analogWrite(blueLEDPin, blueValue);

    } else if (temperature >= 0 && temperature <= 9) {
        redValue = 0;
        greenValue = 17;
        blueValue = 255;
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, greenValue);
        analogWrite(blueLEDPin, blueValue);

    } else if (temperature >= -50 && temperature <= 0) {
        redValue = 0;
        greenValue = 17;
        blueValue = 255;
        analogWrite(redLEDPin, redValue);
        analogWrite(greenLEDPin, greenValue);
        analogWrite(blueLEDPin, blueValue);
    }
}
