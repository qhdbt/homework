const int ledPin=2;
unsigned long previousMillis=0; // 上次状态改变的时间
const long interval=1000; // 间隔1000ms（亮1000ms+灭1000ms）

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis=millis(); // 当前时间
  if (currentMillis-previousMillis>=interval) {
    previousMillis=currentMillis; // 更新上次时间
    digitalWrite(ledPin,!digitalRead(ledPin)); // 翻转LED状态
    Serial.println(digitalRead(ledPin)?"LED ON":"LED OFF");
  }
}