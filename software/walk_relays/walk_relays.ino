const int NR_RELAYS = 16;
const int relays[NR_RELAYS] = {22,24,26,28,30,32,34,36,23,25,27,29,31,33,35,37};

void setup() {
    Serial.begin(115200);

    for (int i = 0; i < NR_RELAYS; i++) {
        pinMode(relays[i], OUTPUT);
        digitalWrite(relays[i],HIGH);
    }

    pinMode(13,OUTPUT);
}

void loop() {
    for (int i = 0; i < NR_RELAYS; i++) {
        Serial.println(relays[i]);
        digitalWrite(13,!digitalRead(13));

        digitalWrite(relays[i],LOW);
        Serial.println(i);
        delay(1000);
        digitalWrite(relays[i],HIGH);
    }
    for (int i = 0; i < NR_RELAYS; i++) {
        digitalWrite(relays[i],HIGH);
    }
    delay(1000);
}
