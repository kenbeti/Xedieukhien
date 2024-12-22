#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

// Các chân điều khiển động cơ
#define IN1  32
#define IN2  33
#define IN3  25
#define IN4  26
#define ENA  27
#define ENB  14

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(115200);
  SerialBT.begin("ESP32_Car"); // Tên Bluetooth của ESP32
  Serial.println("Đang chờ kết nối Bluetooth...");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();  // Đọc lệnh từ Bluetooth
    Serial.print("Lệnh nhận được: ");
    Serial.println(command);

    // Điều khiển động cơ dựa trên lệnh nhận được
    switch (command) {
      case 'F': // Tiến
        forward();
        break;
      case 'B': // Lùi
        backward();
        break;
      case 'L': // Rẽ trái
        left();
        break;
      case 'R': // Rẽ phải
        right();
        break;
      case 'S': // Dừng
        stopMotor();
        break;
      default:
        break;
    }
  }
}

// Các hàm điều khiển động cơ
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
