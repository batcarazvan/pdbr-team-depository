

#include <stdlib.h> // div, div_t

void setup() {
    digitalWrite(A0, HIGH);
    Serial.begin(115200);
}

void loop() {
    static int numChans = 1;
   /* while(Serial.available() > 0) {
        char c = Serial.read();
        if(c >= '1' && c <= '6') {
            numChans = c - '0';
        }
    }*/
    PrintInt(analogRead(A0));
    Serial.write('\r'); // CR
}



//conversion to ascii
void PrintInt(int i) {
    static const char asciiDigits[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    div_t n;
    int print = 0;
    if(i < 0) {
        Serial.write('-');
        i = -i;
    }
    if(i >= 10000) {
        n = div(i, 10000);
        Serial.write(asciiDigits[n.quot]);
        i = n.rem;
        print = 1;
    }
    if(i >= 1000 || print) {
        n = div(i, 1000);
        Serial.write(asciiDigits[n.quot]);
        i = n.rem;
        print = 1;
    }
    if(i >= 100 || print) {
        n = div(i, 100);
        Serial.write(asciiDigits[n.quot]);
        i = n.rem;
        print = 1;
    }
    if(i >= 10 || print) {
        n = div(i, 10);
        Serial.write(asciiDigits[n.quot]);
        i = n.rem;
    }
    Serial.write(asciiDigits[i]);
}
