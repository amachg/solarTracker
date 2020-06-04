/*

Φωτοαντίσταση LDR (light dependent resistor) από θειούχο κάδμιο (cadmium sulfide - CdS).
Η φωτοαντίσταση είναι μια μεταβλητή αντίσταση η τιμή της οποίας 
αλλάζει ανάλογα με το φως που πέφτει πάνω σε αυτή.
Η τιμή της αντίστασης μικραίνει όταν στον χώρο υπάρχει πολύς φωτισμός, αντίθετα μεγαλώνει όσο μικραίνει ο φωτισμός.
Για παράδειγμα:
  0 Lx -> 1-5 ΜΩ
 10 Lx -> 8-20 KΩ
100 Lx -> 1-2 KΩ

LDR Pin 1 –> Arduino 5V, μέσω αντίστασης 10K & Arduino ακροδέκτης A0 
LDR Pin 2 –> Arduino Γη, ακροδέκτης GND 

*/
#include <Braccio.h>
// Βιβλιοθήκη "Braccio"
// Περιλαμβάνει το "servo.h" από τη βιβλιοθήκη "Servo".

Servo basi;       // Κινητήρας βάσης
Servo omos;       // Κινητήρας ώμου

const int LDR_B_Pin = A0;     // ακροδέκτης Βορρά
const int LDR_N_Pin = A1;     // Νότου
const int LDR_A_Pin = A2;     // Ανατολής
const int LDR_D_Pin = A3;     // Δύσης

const int megistiMetrisiAisthitira = 1023;

// κάτω φράγμα απόρριψης θορύβου μέτρησης, >15 για σκοτάδι, ~0 για πολύ φως
const int nevrikotitaKinisis = 20;
const int vradititaKinisis = 1;     // καθυστέρηση μεταξύ βημάτων, 1-50-3000 χιλιοστοδευτερόλεπτα (ms)
const int vimaServo = 1;

int gwnia_basis = 90;        // γωνία άξονα κινητήρα βάσης
int gwnia_omou  = 90;        // γωνία ώμου

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Serial OK");

  basi.attach(11);    // βύσμα M1-> ελεγκτής ακροδέκτης 11 (digital pwm)
  omos.attach(10);    // βύσμα M2-> ελεγκτής ακροδέκτης 10 (digital pwm)  
  digitalWrite(SOFT_START_CONTROL_PIN, HIGH);
  
  basi.write(90);     // Αρχική κλίση άξονα, 90 μοίρες
  omos.write(90);
  delay(5000);        // καθυστέρηση σε χιλιοστοδευτερόλεπτα (ms)
  
  Serial.println("Vraxionas OK");    
}

void loop() {
  delay(vradititaKinisis);
  
  int LDR_B_Reading = analogRead(LDR_B_Pin);
  int LDR_N_Reading = analogRead(LDR_N_Pin);
  int LDR_A_Reading = analogRead(LDR_A_Pin);
  int LDR_D_Reading = analogRead(LDR_D_Pin);
  
  int lux_B = megistiMetrisiAisthitira - LDR_B_Reading;
  int lux_N = megistiMetrisiAisthitira - LDR_N_Reading;
  int lux_A = megistiMetrisiAisthitira - LDR_A_Reading;
  int lux_D = megistiMetrisiAisthitira - LDR_D_Reading;
  
  Serial.println("BORRAS-NOTOS\tANATOLH-DYSH");
  Serial.print(lux_B); Serial.print("-"); Serial.print(lux_N); Serial.print("\t\t");
  Serial.print(lux_A); Serial.print("-"); Serial.println(lux_D);
  
  int lux_B_N = lux_B - lux_N +13; // βαθμονόμηση: διόρθωση ισορροπίας Β-Ν ανάλογα συνθηκών
  int lux_A_D = lux_A - lux_D +10; // όμοια για Α-Δ
   
  Serial.println("Diaf_BOR-NOT\tDiaf_ANAT-DYS");
  Serial.print(lux_B_N); Serial.print("\t\t"); Serial.println(lux_A_D);
 /* 
  Serial.print("To fos erxetai apo ");
  if (lux_B_N > 0)
    Serial.print("B");
  else if (lux_B_N < 0)
    Serial.print("N");
  if (lux_A_D > 0)
    Serial.print("A");
  else if (lux_A_D < 0)
    Serial.print("D");  
  Serial.println(" katey8ynsi");*/
 
  if (abs(lux_B_N) >= nevrikotitaKinisis) {
    int temp = gwnia_omou - vimaServo * sgn(lux_B_N); //  lux_B_N / nevrikotitaKinisis
    //Serial.print("temp_B_N: "); Serial.println(temp);   
    if (15 < temp and temp < 165) {
      gwnia_omou = temp;
      omos.write(gwnia_omou);
    }
  }
  if (abs(lux_A_D) >= nevrikotitaKinisis) {
    int temp = gwnia_basis - vimaServo * sgn(lux_A_D); //  lux_A_D / nevrikotitaKinisis 
   // Serial.print("temp_A_D: "); Serial.println(temp);    
    if (0 < temp and temp < 180) {
      gwnia_basis = temp;
      basi.write(gwnia_basis);
    }
  }
  Serial.print("omou: "); Serial.print(gwnia_omou); Serial.print("\t");
  Serial.print("basis: "); Serial.println(gwnia_basis); 
  Serial.println();
}

int sgn(int val) {return (0 < val) - (val < 0);}
