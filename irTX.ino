int readvalue;
int LEDpin=3;
int address[8] = {1, 0, 0, 0, 0, 0, 0, 1};
int invaddress[8] = {0, 1, 1, 0, 0, 1, 1, 0};
int power[8] = {1, 0, 0, 0, 0, 0, 0, 1};
int invpower[8] = {0, 1, 1, 1, 1, 1, 1, 0};

boolean stringComplete = false; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(3, OUTPUT); 

}
void loop() {
	
  // put your main code here, to run repeatedly: 
  digitalWrite(LEDpin, LOW); 
  if(readvalue==1&stringComplete){

    sendpulse();

    for(int i=1; i==9; i+1){
      if(address[i]){
        send1();
      }
      else{
        send0();
      }
    }  
    for(int i=1; i==9; i+1){
      if(invaddress[i]){
        send1();
      }
      else{
        send0();
      }
    }  
    for(int i=1; i==9; i+1){
      if(power[i]){
        send1();
      }
      else{
        send0();
      }
    }  

    for(int i=1; i==9; i+1){
      if(invpower[i]){
        send1();
      }
      else{
        send0();
      }
    }  

  }  
  if(stringComplete){
    stringComplete=false;
  }  
  digitalWrite(LEDpin, LOW); 
}  



void serialEvent() {
  while (Serial.available()) {
    readvalue= Serial.parseInt();
    stringComplete = true;
    Serial.println(readvalue); 
  }
}

void sendpulse() {
  digitalWrite(LEDpin, HIGH);
  delayMicroseconds(9000);
  digitalWrite(LEDpin, LOW);
  delayMicroseconds(4500);
}

void send1() {
  digitalWrite(LEDpin, HIGH);
  delayMicroseconds(562);
  digitalWrite(LEDpin, LOW);
  delayMicroseconds(1688);  
}

void send0() {
  digitalWrite(LEDpin, HIGH);
  delayMicroseconds(562);
  digitalWrite(LEDpin, LOW);
  delayMicroseconds(563);  
}

void endcommand() {
  digitalWrite(LEDpin, HIGH);
  delayMicroseconds(562);
  digitalWrite(LEDpin, LOW);
}