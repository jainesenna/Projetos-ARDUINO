// Essas variáveis ​​armazenam o padrão flash
// e o estado atual do LED
 
int ledPin1 =  12;     // o número do pino do LED
int ledState1 = LOW;   // ledState usado para definir o LED 
unsigned long previousMillis1 = 0; // irá armazenar a última vez que o LED foi atualizado
long OnTime1 = 250;  // milissegundos de tempo no prazo 
long OffTime1 = 750;  // milissegundos de tempo de folga 
 
int ledPin2 =  8;  // o número do pino do LED 
int ledState2 = LOW;  // ledState usado para definir o LED
unsigned long previousMillis2 = 0; // irá armazenar a última vez que o LED foi atualizado
long OnTime2 = 330;   
long OffTime2 = 400;
 
void setup() 
{
// define o pino digital como saída:
  pinMode(ledPin1, OUTPUT);      
  pinMode(ledPin2, OUTPUT);      
}
 
void loop()
{
  // verifique se está na hora de mudar o estado do LED
  unsigned long currentMillis = millis();
 
  if((ledState1 == HIGH) && (currentMillis - previousMillis1 >= OnTime1))
  {
    ledState1 = LOW;  // Desligue isso 
    previousMillis1 = currentMillis;  // Remember the time
    digitalWrite(ledPin1, ledState1);  // Atualize o LED atual  
  }
  else if ((ledState1 == LOW) && (currentMillis - previousMillis1 >= OffTime1))
  {
    ledState1 = HIGH;   // ligue  
    previousMillis1 = currentMillis;   
    digitalWrite(ledPin1, ledState1);    
  }
  
  if((ledState2 == HIGH) && (currentMillis - previousMillis2 >= OnTime2))
  {
    ledState2 = LOW;   
    previousMillis2 = currentMillis;  
    digitalWrite(ledPin2, ledState2);   
  }
  else if ((ledState2 == LOW) && (currentMillis - previousMillis2 >= OffTime2))
  {
    ledState2 = HIGH;   
    previousMillis2 = currentMillis;    
    digitalWrite(ledPin2, ledState2);   
  }
}
