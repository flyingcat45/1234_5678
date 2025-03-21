#include <Arduino.h>

int led = 10;

// run once
void setup() {
    pinMode(led, OUTPUT);    // 設定 LED 腳位為輸出模式
    Serial.begin(9600);      // 設定串列通訊速率為 9600 bps
    Serial.println("System Initialized!"); // 初始化完成
}

// run endless
void loop() {
    if (Serial.available() > 0) {  // 檢查是否有資料可讀取
        char receivedChar = Serial.read();  // 讀取單個字元
        Serial.print("Received: "); 
        Serial.println(receivedChar);  // 顯示收到的字元

        if (receivedChar == 'o') {  // 如果收到 'o'
            digitalWrite(led, HIGH);
            Serial.println("LED ON"); // 確認 LED 亮起
            delay(500);
        } else {
            digitalWrite(led, LOW);
            Serial.println("LED OFF"); // 確認 LED 關閉
        }
    }
}

