unsigned long myTime; 
unsigned long stimInterv = 100; //stim at this freq (ms)
unsigned long myTime2; // wait for this long
unsigned long loop1on = 800; // pulse for this long
unsigned long loop1off = 4200; 
unsigned long myTime3;  
unsigned long loop2on = 10000;
unsigned long loop2off = 10000;
unsigned long writeDur; 
unsigned long ttlDur = 1; // length of ttl pulse, must be less than stim interv

int outpin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(outpin, OUTPUT);
  myTime3 = millis(); 
}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println(myTime3); 
  myTime2 = millis(); 
  while (millis() - myTime3 < loop2on) { 
    myTime = millis(); 
    while (millis() - myTime2  < loop1on) {
      if (millis() - myTime >= stimInterv) { 

        myTime = millis();
        digitalWrite(outpin, HIGH);
        delay(ttlDur); 
        digitalWrite(outpin, LOW); 
        delay(10-ttlDur);
        writeDur = millis() - myTime;  
      } 
    } 
    delay(loop1off - writeDur);
    myTime2 = millis(); 
  }
  delay(loop2off);
  myTime3 = millis(); 
}
