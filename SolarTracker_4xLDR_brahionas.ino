// Ηλιοτροπικός συλλέκτης δύο αξόνων
// Sun oriented solar panel 2 DoF
// με
// ρομποτικό 2 βαθμών ελευθερίας, κάθετη και οριζόντια περιστροφή με σερβοκινητήρες
// 2 DOF robotic with vertical and horizontal turning using servos springrc-SR431 (~5.5-6.5v)
// και
// Τέσσερις πλακέτες GY-30 ή GY-302 με φωτοαισθητήρες BH1750
// Four Breakboards GY-30 or GY-302 with light sensors BH1750


// Βιβλιοθήκη σερβοκινητήρων. RC-Servo Library.
#include <Servo.h>

Servo basi;    // Κινητήρας βάσης
Servo panel;   // Κινητήρας πάνελ

int gonia_basis = 90;
int gonia_panel = 90;
  
// ακροδέκτες σερβοκινητήρων
const byte motor1_Pin = 2;
const byte motor2_Pin = 3;

// Βιβλιοθήκη I²C for AVR. I²C Library for AVR.
#include <Wire.h>

// Η τυπική διεύθυνση I²C (TWI) της συσκευής BH1750 είναι 0x23. Μπορεί να αλλάξει στην 0x5C,
// συνδέοντας τον ακροδέκτη διεύθυνσης (ADDR ή ADD) σε HIGH.
// The I2C address is 0x23 (ADDR pin is low or floating) or 0x5C (ADDR pin is high).
// Μπορεί να αλλάζουν δυναμικά, αν συνδεθούν σε ψηφιακές ακίδες.

const byte sensorAddressLOW   = 0x23;
const byte sensorAddressHIGHT = 0x5C;

// ακροδέκτες φωτοαισθητήρων
const byte sensor1_Pin = 10;      //  Βορράς
const byte sensor2_Pin = 11;      //  Νότος
const byte sensor3_Pin = 12;      //  Ανατολή
const byte sensor4_Pin = 13;      //  Δύση

// Ποσοστιαίο κατόφλι διαφοράς φωτεινότητας, δρα σαν φίλτρο απόρριψης μικροκινήσεων.
const int katofliKinisis = 10;          // ποσοστό %, πρέπει >=5
const int kathisterisi_kinisis = 30;    // καθυστέρηση σε χιλιοστοδευτερόλεπτα, μάλλον >=60
const int vimaServo = 1;                // βήμα περιστροφής σερβοκινητήρα (1..2)

void setup() {
  
  // Στήσε σειριακή θύρα επικοινωνίας με υπολογιστή
  
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("Serial port, OK"));
  
  // Συνδέσου στον δίαυλο I²C των φωτοαισθητήρων, με έλεγχο των γραμμών
  // Join I²C bus, testing the lines
  // Οι ακροδέκτες στον δίαυλο I2C-TWI είναι στις θέσεις:
  // A4 (SDA), A5 (SCL) σε μικροελεγκτή Uno και 20 (SDA), 21 (SCL) σε Mega2560
  // I2C-TWI pins are located on A4 (SDA), A5 (SCL) on Uno
  // and 20 (SDA), 21 (SCL) on Mega2560 boards.
  
  if ((digitalRead(A4) == HIGH) && (digitalRead(A5) == HIGH)) { 
    Wire.begin();
    Serial.println(F("I2C bus Lines are HIGH, OK"));
    delay(10);
  }
  else Serial.println(F("I2C bus FAILED. Lines are LOW"));

  // Στήσε σερβοκινητήρες.
  
  // Αρχική γωνία κλίσης άξονα βάσης & πάνελ.
  // Βρίσκονται πριν τις attach για να αποφύγω την απότομη κίνηση των σερβο στο ξεκίνημα.
  basi.write(gonia_basis);
  panel.write(gonia_panel);
  //Αντιστοιχία σέρβο σε ακροδέκτες ελεγκτή
  basi.attach(motor1_Pin);
  panel.attach(motor2_Pin);
  Serial.println("Servos, OK\n");
  delay(500);

  // Αρχικοποίησε τους αισθητήρες. ### ΑΠΑΡΑΙΤΗΤΟ! ###
  // Initialize sensors. ### REQUIRED ###
  
  Init_all_BH1750();
}

void loop() {
  
  int lux_B = metraPhotometro(sensor1_Pin);     //  Βορράς
  int lux_N = metraPhotometro(sensor2_Pin);     //  Νότος
  int lux_A = metraPhotometro(sensor3_Pin);     //  Ανατολή
  int lux_D = metraPhotometro(sensor4_Pin);     //  Δύση
  int diaf_B_N = lux_B - lux_N;
  int diaf_A_D = lux_A - lux_D;
  int pososto_diafBN = (double)100 * diaf_B_N / lux_B;
  int pososto_diafAD = (double)100 * diaf_A_D / lux_A;

  // Καταγραφή απόλυτης φωτινότητας, διαφορών και κατεύθυνσης του φωτός
  // Log absolute lux, difference and light direction
/*
  Serial.println("BORRAS-NOTOS\tANATOLH-DYSH");
  Serial.print(lux_B); Serial.print("-"); Serial.print(lux_N); Serial.print("\t\t");
  Serial.print(lux_A); Serial.print("-"); Serial.println(lux_D);

  Serial.println("Diaf_BOR-NOT\tDiaf_ANAT-DYS");
  Serial.print(String(diaf_B_N) + " (" + pososto_diafBN + "%)\t\t");
  Serial.println(String(diaf_A_D) + " (" + pososto_diafAD + "%)");

  Serial.print("To fos erxetai apo katey8ynsi ");
  if (diaf_B_N > 0)
    Serial.print("B");
  else if (diaf_B_N < 0)
    Serial.print("N");
    
  if (diaf_A_D > 0)
    Serial.print("A");
  else if (diaf_A_D < 0)
    Serial.print("D");  
  Serial.println();
*/
  // Κίνησε τα σερβο προς αυτή την κατεύθυνση. Κατάγραψε γωνίες αρθρώσεων
  // Move to this direction. Log joints angles

  if (abs(pososto_diafBN) > katofliKinisis) {
    gonia_panel = gonia_panel - vimaServo * prosimo(diaf_B_N);
    panel.write(gonia_panel);  // Ο έλεγχος gonia ε [0,180] γίνεται μέσα στη Servo::write
    //Serial.println(String("Gonia Pano-kato: ") + gonia_panel + " deg");
  }
  if (abs(pososto_diafAD) > katofliKinisis) {
    gonia_basis = gonia_basis + vimaServo * prosimo(diaf_A_D);
    basi.write(gonia_basis);
    //Serial.println(String("Gonia Deksia-Aristera: ") + gonia_basis + " deg");
  }

  // καθυστέρηση βρόχου επανάληψης
  delay(kathisterisi_kinisis);
/*  // ή αναμονή πλήκτρου SEND
  Serial.println("Pata SEND.");
  while(Serial.available()){Serial.read();}
  while (!Serial.available()) {}
  */
}

int prosimo(int val) {return (0 < val) - (val < 0);}

uint16_t metraPhotometro(const byte sensorPin) {
  // Διάβασε το αντίστοιχο φωτόμετρο, υψώνοντας την τάση του ακροδέκτη διεύθυνσής του.
  // Read the corresponding device by raising the address pin.
  
  digitalWrite(sensorPin, HIGH);
  delay(1);
  const uint16_t lux = read_BH1750(sensorAddressHIGHT);
  //Serial.println(String(F("Fotometro sto pin D")) + sensorPin + F(" -> ") + lux + F(" lux"));
  digitalWrite(sensorPin, LOW);
  delay(1);
  return lux;
}

uint16_t read_BH1750(const byte sensorAddress) {
  uint16_t data = 0;
  byte numberOfBytes = Wire.requestFrom(sensorAddress, 2u);
  if (numberOfBytes == 2) {
    // Διάβασε δυο μπάιτ από τον αισθητήρα και συνδύασέ τα σε μια λέξη.
    // Read two bytes from the sensor, which are low and high parts of the data
    const byte highByte = Wire.read();
    const byte lowByte  = Wire.read();
    // Converts high-order (leftmost) & low-order (rightmost) byte to the word data type.
    data = word( highByte, lowByte);
  }
    else Serial.println(F("ERROR: I2C wire request failure!"));
    
  // πρέπει ο αριθμός της μέτρησης να διαιρείται με 1,2 για να μετατραπεί σε μονάδες Lux.
  return data / 1.2;
}

void Init_all_BH1750() {
  // Όρισε τους ψηφιακούς ακροδέκτες διεύθυνσης, ως εξόδου. Προκαθορισμένη, είναι η χαμηλή τάση.
  // Sets the digital address pins as output pins. They are by default at low voltage.
  pinMode(sensor1_Pin, OUTPUT);
  pinMode(sensor2_Pin, OUTPUT);
  pinMode(sensor3_Pin, OUTPUT);
  pinMode(sensor4_Pin, OUTPUT);
  
  digitalWrite(sensor1_Pin, HIGH);
  Serial.println(F("Sensor #1"));
  Init_BH1750(sensorAddressHIGHT);
  digitalWrite(sensor1_Pin, LOW);
  
  digitalWrite(sensor2_Pin, HIGH);
  Serial.println(F("Sensor #2"));
  Init_BH1750(sensorAddressHIGHT);
  digitalWrite(sensor2_Pin, LOW);
 
  digitalWrite(sensor3_Pin, HIGH);
  Serial.println(F("Sensor #3"));
  Init_BH1750(sensorAddressHIGHT);
  digitalWrite(sensor3_Pin, LOW);
   
  digitalWrite(sensor4_Pin, HIGH);
  Serial.println(F("Sensor #4"));
  Init_BH1750(sensorAddressHIGHT);
  digitalWrite(sensor4_Pin, LOW);
}

int Init_BH1750(const byte sensorAddress) {
  // Αρχικοποίησε τον αισθητήρα, με 4 ελέγχους, εκκίνηση, επαναφορά, σταμάτημα και τρόπου λειτουργίας
  // 4 checks if the communication with the sensor is okay.
  int error = 0;

  // Power on and wait for measurement command. "Power On" Command is possible to be omitted. 
  error = write_BH1750(sensorAddress, 0x01);
  if (error != 0)
    return( error);
  Serial.println(F("Sensor Power-on, OK"));
  
  // Θέσε τη συσκευή BH1750 σε λειτουργία "Συνεχούς υψηλής ανάλυσης" (120ms, 1Lux)
  // Sets device BH1750 to Continuous High Resolution mode (120ms, 1Lux)
  error = write_BH1750(sensorAddress, 0x10);
  if (error != 0)
    return( error);
  Serial.println(F("Sensor resolution set to 1 Lux, OK\n"));

  return (error);  
}

int write_BH1750(const byte sensorAddress, byte val) {
  Wire.beginTransmission(sensorAddress);
  Wire.write(val);
  int error = Wire.endTransmission();
  delay(kathisterisi_kinisis/100);
  if( error != 0) {
    Serial.print(F("ERROR: I2C wire writing to address 0x")); Serial.print(sensorAddress, HEX);
    Serial.print(F(" value ")); Serial.println(val, HEX);
  }
  return( error); 
}

