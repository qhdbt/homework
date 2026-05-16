// SOS 示例思路
const int ledPin = 2; 
unsigned long timer = 0;
void setup() {
  pinMode(ledPin, OUTPUT);  // 设置引脚模式为输出
}
void loop() {
  unsigned long now = millis();  // 获取当前时间
// S: 短闪3次
for(int i=0; i<3; i++) { if (now - timer >= 200)digitalWrite(ledPin, HIGH); timer = now;now = millis(); if (now - timer >= 200)digitalWrite(ledPin, LOW); timer = now;now = millis(); }
if (now - timer >= 500)digitalWrite(ledPin, LOW);timer = now;now = millis(); // 字母间隔
// O: 长闪3次
for(int i=0; i<3; i++) {  if (now - timer >= 600)digitalWrite(ledPin, HIGH); timer = now;now = millis();  if (now - timer >= 200)digitalWrite(ledPin, LOW);timer = now;now = millis(); }
if (now - timer >= 500)digitalWrite(ledPin, LOW);timer = now;now = millis();
// S: 短闪3次
for(int i=0; i<3; i++) { if (now - timer >= 200)digitalWrite(ledPin, HIGH);timer = now;now = millis();if (now - timer >= 200)digitalWrite(ledPin, LOW);timer = now; now = millis(); }
if (now - timer >= 2000)digitalWrite(ledPin, LOW);timer = now;now = millis();// 单词间隔
}