
//--------LM35--------//
const int LM35 = A0;
float temperatura = 0;
int sensor = 0;
#define LM35_A 1
//--------------------//
//--------LDR---------//
//const int LDR = A1;
int estado = 0;
float luminosidade = 0;
#define LDR_A 2
//--------------------//
//--------POT---------//
//const int potenciometro = A2;
int sensorValue = 0;
int outputValue = 0;
#define POT_A 3
//--------------------//
//------ATIVACAO------//

/*boolean atvLM35 = false;
  boolean atvLDR = true;
  boolean atvPOT = false;
  //--------------------//
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(INTERNAL);
  pinMode(LDR, INPUT);
  pinMode(potenciometro, INPUT);
}



void loop() {
  #ifdef LM35_A
    sensor = analogRead(LM35);
    temperatura = sensor * 0.1075268817;
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println("*C");
    delay(500);
  #endif

  #ifdef LDR_A
    estado = analogRead(LDR);
    luminosidade = map(estado, 0, 1023, 0, 255);
    Serial.print("Valor lido do LDR: ");
    Serial.print(estado);
    Serial.print("** Luminosidade: ");
    Serial.println(luminosidade);
  #endif

  #ifdef POT_A
    sensorValue = analogRead(potenciometro);
    outputValue = map(sensorValue, 0, 1023, 0, 255);
    Serial.print("sensor = ");
    Serial.print(sensorValue);
    Serial.print("\t output = ");
    Serial.println(outputValue);
    delay(2);
  #endif
}
