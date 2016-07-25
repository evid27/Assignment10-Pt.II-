#include <Smartcar.h>

SR04 sensor1, sensor2, sensor3;// 1 = front, 2 = left, 3 = right
SoftwareSerial bluetooth(6,7);

const int TRIGGER_1 = 6; // Χρησιμοποιήστε τα pin που θέλετε
const int ECHO_1 = 7; 
const int TRIGGER_2 = 5;
const int ECHO_2 = 4;
const int TRIGGER_3 = 9;
const int ECHO_ = 8;

void setup() {
  Serial.begin(9600);
//bluetooth.begin(9600);  
  sensor1.attach(TRIGGER_1, ECHO_1);
  sensor2.attach(TRIGGER_2, ECHO_2);
  sensor3.attach(TRIGGER_3, ECHO_3);
}

void loop() {
  int frontDistance = sensor1.getDistance(10);
  int leftDistance =sensor2.getDistance(10);
  int rightDistance = sensor3.getDistance(10);
  int TOTAL = frontDistance + leftDistance +  rightDistance;
  int A.M.  = TOTAL/3;
//  bluetooth.print(A.M.);
}
