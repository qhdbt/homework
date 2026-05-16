// SOS 示例思路
const int ledPin = 2; 
void setup() {
  pinMode(ledPin, OUTPUT);  // 设置引脚模式为输出
}
void loop() {
// S: 短闪3次
for(int i=0; i<3; i++) { digitalWrite(ledPin, HIGH); delay(200); digitalWrite(ledPin, LOW); delay(200); }
delay(500); // 字母间隔
// O: 长闪3次
for(int i=0; i<3; i++) { digitalWrite(ledPin, HIGH); delay(600); digitalWrite(ledPin, LOW); delay(200); }
delay(500);
// S: 短闪3次
for(int i=0; i<3; i++) { digitalWrite(ledPin, HIGH); delay(200); digitalWrite(ledPin, LOW); delay(200); }
delay(2000); // 单词间隔
}