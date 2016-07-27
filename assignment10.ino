#include <Smartcar.h>

SR04 sensor1, sensor2;// 1 = left, 2 = right

const int TRIGGER_1 = A0; // Χρησιμοποιήστε τα pin που θέλετε
const int ECHO_1 = A1; 
const int TRIGGER_2 = A2;
const int ECHO_2 = A3;
int leftTOTAL = 0;
int rightTOTAL = 0;
int rMeasurements = 10;
int lMeasurements = 10;

void setup() {
  Serial.begin(9600);
  sensor1.attach(TRIGGER_1, ECHO_1);
  sensor2.attach(TRIGGER_2, ECHO_2);
}

void loop() {
  int leftDistance = sensor1.getDistance();
  int rightDistance =sensor2.getDistance();
  
  if (leftDistance > 0) {
    leftTOTAL = leftTOTAL + leftDistance;// Αν η αριστερή απόσταση είναι μεγαλύτερη από το 0, πρόσθεσέ την στις τιμές από τον αριστερό αισθητήρα
    lMeasurements = lMeasurements -1;//Μείωσε κατά μια τις αριστερές μετρήσεις, μέχρι να γίνουν 10
    if (lMeasurements == 0){
      int lAVERAGE = leftTOTAL/10;
      leftTOTAL = 0;//Αν γίνουν 10 μετρήσεις από τον αριστερό αισθητήρα, καθάρισε το συνολικό ποσο των μετρήσεών του
      lMeasurements = 10;
    }
  }
  if (rightDistance > 0) {
    rightTOTAL = rightTOTAL + rightDistance;//Το ίδιο για τον δεξή αισθητήρα και τις μετρήσεις του
    rMeasurements = rMeasurements -1;//Το ίδιο για τις αριστερές μετρήσεις, μέχρι να γίνουν 10
    if (rMeasurements == 0){
      int rAVERAGE = rightTOTAL/10;
      rightTOTAL = 0;
      rMeasurements = 10;
    }
  }
}
