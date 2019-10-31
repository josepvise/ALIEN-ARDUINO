/*
 * MIDCOURSE PROJECT
 * UAETEA I
 * Cèlia Marquès, Marina Roig i Josep Villanueva.
 * Teacher: Joan Gómez.
 */

// First of all we define all the variables.
// TRIG and ECO are for the Ultra Sonic sensor which needs to be connected in those pins.
int TRIG = 10;
int ECO = 9;

// Define all the LED's in its Pin.
int LED = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 8;
int LED5 = 7;
int LED6 = 6;
int LED7 = 5;
int LED8 = 4;

// Define two more variables, one for the duration of the UltraSonic Sensor and other one for the distance that it detects.
int DURACION;
int DISTANCIA;

// Finally last variable for the motorPin.
int motorPin = 3;


void setup() {
  // put your setup code here, to run once:
  //We define which are INPUTS and which are OUTPUTS, before the loops runs.
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

// It's necessary to program, considering your UltraSonic model.
// Schematic downloaded from GitHub.
  digitalWrite(TRIG, HIGH);
  delay(4);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  delay(200);

// First of all we define that in 60 of distance or less, turn on the LED's and intermittent.
  if (DISTANCIA <= 60 && DISTANCIA >= 0) {
    digitalWrite(LED, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    delay(DISTANCIA * 9);
    digitalWrite(LED, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

// Secondly, we program the same with other LED's and other distance (40, in this case).
  }
  if (DISTANCIA <= 40 && DISTANCIA >= 0) {
    digitalWrite(LED6, HIGH);
    digitalWrite(LED7, HIGH);
    digitalWrite(LED8, HIGH);
    digitalWrite(LED5, HIGH);
    delay(DISTANCIA * 9);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED5, LOW);
  }

// Finally we program the motorPin to rotate at 20 or less.
  if (DISTANCIA <= 20 && DISTANCIA >= 0) {
    analogWrite(motorPin, 100);
    delay(400);
    analogWrite(motorPin, 0);
  }
}
