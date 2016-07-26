#include <Smartcar.h>

SR04 sensor1, sensor2;// 1 = left, 2 = right, 
//SoftwareSerial bluetooth(6,7);

const int TRIGGER_1 = 6; // Χρησιμοποιήστε τα pin που θέλετε
const int ECHO_1 = 7; 
const int TRIGGER_2 = 5;
const int ECHO_2 = 4;
int TOTAL = 0;

void setup() {
  Serial.begin(9600);
//bluetooth.begin(9600);  
  sensor1.attach(TRIGGER_1, ECHO_1);
  sensor2.attach(TRIGGER_2, ECHO_2);
  sensor3.attach(TRIGGER_3, ECHO_3);
}

void loop() {
  int leftDistance = sensor1.getDistance(10);
  int rightDistance =sensor2.getDistance(10);
  
  if (leftDistance > 0) {
    TOTAL = (TOTAL + leftDistance)*10;
  }
  if (rightDistance >0 ) {
    TOTAL = (TOTAL + rightDistance)*10;
  }
  int TOTAL = frontDistance + leftDistance +  rightDistance;
  int A.M.  = TOTAL/10;
//  bluetooth.print(A.M.);
}
