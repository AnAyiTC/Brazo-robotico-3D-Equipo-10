#include <Servo.h> 
// definimos los pines de los servos
//base
#define pinServ1 2
//brazo
#define pinServ2 3
//antebrazo
#define pinServ3 4
//muñeca
#define pinServ4 5
//pinza
#define pinServ5 6

// definimos los potenciometros
#define pot1 A0
#define pot2 A1
#define pot3 A2
#define pot4 A3
#define pot5 A4

// nombramos a los servos
Servo serv1,serv2,serv3,serv4, serv5;
int motor1,motor2,motor3,motor4, motor5;
unsigned long mostradorTimer = 1;
const unsigned long intervaloMostrador = 4000;

void setup() {

  //monitor serial
  Serial.begin(9600); 

  // asignamos los pines a los servos
  serv1.attach(pinServ1);
  serv2.attach(pinServ2);
  serv3.attach(pinServ3);
  serv4.attach(pinServ4);
  serv5.attach(pinServ5);
}

void loop(){

  // lectura de los potenciometros
  motor1 = map(analogRead(pot1),0,1023,10,170);
  motor2 = map(analogRead(pot2),0,1023,10,110);
  motor3 = map(analogRead(pot3),0,1023,50,99);
  motor4 = map(analogRead(pot4),0,1023,50,110);
  motor5 = map(analogRead(pot5),0,1023,10,40);

  // posicionamiento de potenciómetros en los servos
  serv1.write(motor1); 
  serv2.write(motor2);
  serv3.write(motor3);
  serv4.write(motor4);
  serv5.write(motor5);

   if ((millis() - mostradorTimer) >= intervaloMostrador) {

  // enviamos al monitor serial las ubicaciones del los motores
  Serial.println("**********************************************");
  
  Serial.print("Pot1:");
  Serial.print(analogRead(pot1));
  Serial.print(" Angulo Motor1:");
  Serial.println(motor1);

  Serial.print("Pot2:");
  Serial.print(analogRead(pot2));
  Serial.print(" Angulo Motor2:");
  Serial.println(motor2);

  Serial.print("Pot3:");
  Serial.print(analogRead(pot3));
  Serial.print(" Angulo Motor3:");
  Serial.println(motor3);

  Serial.print("Pot4:");
  Serial.print(analogRead(pot4));
  Serial.print(" Angulo Motor4:");
  Serial.println(motor4);
   
  Serial.print("Pot5:");
  Serial.print(analogRead(pot5));
  Serial.print(" Angulo Motor5:");
  Serial.println(motor5);
  mostradorTimer = millis();
  }

  // tempo de espera para reiniciar
  delay(100);

}