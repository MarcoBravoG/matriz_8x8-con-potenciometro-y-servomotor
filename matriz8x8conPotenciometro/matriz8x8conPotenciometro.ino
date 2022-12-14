//ejemplo para crear animaciones en módulo matriz LED con Arduino basado en MAX7219
#include <MD_MAX72xx.h>
#include<Servo.h>
#define HARDWARE_TYPE MD_MAX72XX::DR0CR0RR1_HW
#define NUM_OF_MATRIX 1

#define CLK_PIN   4
#define DATA_PIN  2
#define CS_PIN    3

//#define DELAY_ANIMATION 1500
Servo myServo;
int PotServo=A0;
int PotPin=A5;
int PotVal;
int PotVal2;
int angle;

//const byte ghost1[] = {0x18,0x24,0x42,0x99,0x99,0x42,0x24,0x18};

//const byte ghost1[] = {0x18,0x24,0x42,0x99,0x99,0x42,0x24,0x18};
//const byte ghost2[] = {0x18,0x24,0x42,0x99,0x99,0x42,0x24,0x18};
//const byte ghost3[] = {0x18,0x24,0x42,0x99,0x99,0x42,0x24,0x18};
//const byte ghost4[] = {0x18,0x24,0x42,0x99,0x99,0x42,0x24,0x18};
//const byte ghost5[] = {0x18,0x24,0x42,0x99,0x99,0x42,0x24,0x18};
//const byte ghost6[] = {0x18,0x24,0x42,0x99,0x99,0x42,0x24,0x18};

/*
 const byte ghost1[] = {0x18,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x18};
const byte ghost2[] = {0x18,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x18};
const byte ghost3[] = {0x18,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x18};
const byte ghost4[] = {0x18,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x18};
const byte ghost5[] = {0x18,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x18};
const byte ghost6[] = {0x18,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x18};

/*
const byte ghost1[] = {0x00,0x00,0x7E,0xE7,0xE7,0x7E,0x00,0x00};
const byte ghost2[] = {0x00,0x00,0x7E,0xE7,0xE7,0x7E,0x00,0x00};
const byte ghost3[] = {0x00,0x00,0x7E,0xE7,0xE7,0x7E,0x00,0x00};

const byte ghost4[] = {0x00,0x00,0x7E,0xE7,0xE7,0x7E,0x00,0x00};
const byte ghost5[] = {0x00,0x00,0x7E,0xE7,0xE7,0x7E,0x00,0x00};
const byte ghost6[] = {0x00,0x00,0x7E,0xE7,0xE7,0x7E,0x00,0x00};
*/
/*
 const byte ghost1[] = {0x00,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x00};
const byte ghost2[] = {0x00,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x00};
const byte ghost3[] = {0x00,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x00};
const byte ghost4[] = {0x00,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x00};
const byte ghost5[] = {0x00,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x00};
const byte ghost6[] = {0x00,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x00};

*/

 const byte ghost1[] = {0x18,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x18};
const byte ghost2[] = {0x00,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x00};
const byte ghost3[] = {0x00,0x00,0x7E,0xE7,0xE7,0x7E,0x00,0x00};
const byte ghost4[] = {0x00,0x00,0x00,0x7E,0x7E,0x00,0x00,0x00};
const byte ghost5[] = {0x00,0x00,0x7E,0xE7,0xE7,0x7E,0x00,0x00};
const byte ghost6[] = {0x00,0x3C,0x7E,0xE7,0xE7,0x7E,0x3C,0x00};

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, NUM_OF_MATRIX);

char letter = 'a';

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  // inicializar el objeto mx
  mx.begin();

  // poniendo la matriz en modo de prueba
  mx.control(MD_MAX72XX::TEST, true);
  delay(200);

  // desactivando el modo de prueba
  mx.control(MD_MAX72XX::TEST, false);

  // Establecer intencidad a un valor de 5
  mx.control(MD_MAX72XX::INTENSITY, 5);

}

/**
 * Recibe un arreglo con la configuración de 
 * las filas y las dibuja en la matriz
**/
void drawRows( const byte fig[] ){
  for( int i = 0; i < 8; i++ ){
    mx.setRow(0, i, fig[i]);
  }
}

/**
 * Muestra animación con fantasma de PACMAN
**/
void animateGhost1(){
  // limpiar la pantalla
  //mx.clear();

  // dibujar gráfico 1
  drawRows(ghost1);

}

void animateGhost2()
{
  // limpiar la pantalla
 // mx.clear();

  // dibujar gráfico 2
  drawRows(ghost2);
 
 // delay(2*DELAY_ANIMATION);
}


void animateGhost3()
{
  // limpiar la pantalla
 // mx.clear();
  // dibujar gráfico 3
  drawRows(ghost3);
}

void animateGhost4()
{
  // limpiar la pantalla
 // mx.clear();
  // dibujar gráfico 3
  drawRows(ghost4);
}




void loop() {
PotVal=analogRead(PotPin);
PotVal2=analogRead(PotServo);

Serial.print("PotVal2:");
Serial.print(PotVal2);
angle=map(PotVal2,0,1023,0,179);
Serial.print ("angle= ");
Serial.println (angle);
myServo.write(angle);



if (PotVal >0 &&PotVal <100){
  animateGhost1();  
  Serial.print("PotVal:");
Serial.println(PotVal);
}

if (PotVal >100 && PotVal<200){
  animateGhost2(); 
  Serial.print("PotVal:");
Serial.println(PotVal); 
}

if (PotVal>200 && PotVal<220){
  animateGhost3();  
  Serial.print("PotVal:");
  Serial.println(PotVal);
}

if (PotVal>220){
  animateGhost4();  
  Serial.print("PotVal:");
  Serial.println(PotVal);
}
delay (100);
//  animateGhost();  
}

  
  
