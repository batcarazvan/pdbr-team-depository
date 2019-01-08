void setup (){
  Serial.begin(4800);
}

void loop(){
  int val=analogRead(A0);
  Serial.println(val);
}
