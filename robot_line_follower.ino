int dinamo_kanan1=10;  //kaki 1 dinamo kanan  1 
int dinamo_kanan2=9;  //kaki 2 dinamo kanan 2 
int dinamo_kiri1=5;  //kaki 1 dinamo kiri 
int dinamo_kiri2=4; //kaki 2 dinamo kiri 
int sensor_kanan=13;   //sensor kanan digital 
int sensor_kiri=12;   //sensor kiri digital 
int nilai_sensor_kanan=0; 
int nilai_sensor_kiri=0; 
int led=13;
int kecepatan_kanan=11; 
int kecepatan_kiri=3; 

int vspeed=100;    
int tspeed=255;
int tdelay=20;

void  setup()
{
 pinMode(dinamo_kanan1,OUTPUT);
 pinMode(dinamo_kanan2,OUTPUT);
 pinMode(dinamo_kiri1,OUTPUT);
  pinMode(dinamo_kiri2,OUTPUT);
 pinMode(led,OUTPUT);
 pinMode(sensor_kanan,INPUT);
 pinMode(sensor_kiri,INPUT);
  
 delay(5000);
}

void loop()
{
 nilai_sensor_kanan=digitalRead(sensor_kanan);
 nilai_sensor_kiri=digitalRead(sensor_kiri);
  
  if(nilai_sensor_kiri==LOW && nilai_sensor_kanan==LOW)
  {
   maju(); //maju forward
  }

  if(nilai_sensor_kiri==HIGH  && nilai_sensor_kanan==LOW)
  {
  belok_kiri(); //belok kiri left
  }
 
  if(nilai_sensor_kiri==LOW && nilai_sensor_kanan==HIGH)
  { 
  belok_kanan(); //belok kanan right
  }
  
  if(nilai_sensor_kiri==HIGH && nilai_sensor_kanan==HIGH)
  {
  berhenti(); //berhenti stop
  }
}

void maju()//fungsi maju
 {
  digitalWrite(dinamo_kanan1,HIGH);
  digitalWrite(dinamo_kanan2,LOW);
  digitalWrite(dinamo_kiri1,HIGH);
  digitalWrite(dinamo_kiri2,LOW);
  analogWrite (kecepatan_kanan,vspeed);
  analogWrite (kecepatan_kiri,vspeed);
 } 

void mundur()//fungsi mundur
  {
  digitalWrite(dinamo_kanan1,LOW);
  digitalWrite(dinamo_kanan2,HIGH);
  digitalWrite(dinamo_kiri1,LOW);
  digitalWrite(dinamo_kiri2,HIGH);
  analogWrite (kecepatan_kanan,vspeed);
  analogWrite (kecepatan_kiri,vspeed);
  }

void belok_kanan()//fungsi belok kanan
 {
  digitalWrite(dinamo_kanan1,LOW);
  digitalWrite(dinamo_kanan2,HIGH);
  digitalWrite(dinamo_kiri1,HIGH);
  digitalWrite(dinamo_kiri2,LOW);
  analogWrite (kecepatan_kanan,tspeed);
  analogWrite (kecepatan_kiri,tspeed);
  delay(tdelay);
 } 

void belok_kiri()//fungsi belok kiri
 {
  digitalWrite(dinamo_kanan1,HIGH);
  digitalWrite(dinamo_kanan2,LOW);
  digitalWrite(dinamo_kiri1,LOW);
  digitalWrite(dinamo_kiri2,HIGH);
  analogWrite (kecepatan_kanan,tspeed);
  analogWrite (kecepatan_kiri,tspeed);
  delay(tdelay);
}  

void berhenti()//fungsi berhenti
 {
  analogWrite (kecepatan_kanan,0);
  analogWrite  (kecepatan_kiri,0);
 }
