const int ledPin = 2;
unsigned long timer = 0;  // 通用计时器
int stage = 0;            // 当前阶段（0=S1, 1=O, 2=S2, 3=Pause）
int count = 0;            // 当前阶段闪烁次数

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long now = millis();  // 获取当前时间

  // 阶段0：第一个S（短闪3次）
  if (stage == 0) {
    if (now - timer >= 200) {    // 每200ms切换一次
    timer = now;
      digitalWrite(ledPin, !digitalRead(ledPin));  // 翻转LED
      if (digitalRead(ledPin) == LOW) {  // 每次熄灭算一次闪烁
        count++;
        if (count >= 3) {  // 闪完3次
          stage = 1;       // 进入O阶段
          count = 0;
          timer = now;    // 重置计时器
        }
      }
    }
  }

  // 阶段1：O（长闪3次）
  else if (stage == 1) {
    if (now - timer >= 600) {    // 每600ms切换一次
      timer = now;
      digitalWrite(ledPin, !digitalRead(ledPin));
      if (digitalRead(ledPin) == LOW) {
        count++;
        if (count >= 3) {
          stage = 2;             // 进入第二个S阶段
          count = 0;
          timer = now;
        }
      }
    }
  }

  // 阶段2：第二个S（短闪3次）
  else if (stage == 2) {
    if (now - timer >= 200) {
      timer = now;
      digitalWrite(ledPin, !digitalRead(ledPin));
      if (digitalRead(ledPin) == LOW) {
        count++;
        if (count >= 3) {
          stage = 3;             // 进入长停顿
          count = 0;
          timer = now;
        }
      }
    }
  }

  // 阶段3：长停顿（2秒）
  else if (stage == 3) {
    if (now - timer >= 2000) {   // 停顿2秒
      stage = 0;                 // 回到第一个S，循环
      timer = now;
    }
  }
}