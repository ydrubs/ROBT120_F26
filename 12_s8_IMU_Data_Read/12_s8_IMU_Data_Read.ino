#include <Wire.h>
#include <FastIMU.h>

MPU6500 imu;
calData calib = { 0 };

AccelData accelData;
GyroData gyroData;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(100000);
  delay(2000);

  Serial.println("Starting FastIMU MPU6500 test...");

  int err = imu.init(calib);

  if (err != 0) {
    Serial.print("IMU init error: ");
    Serial.println(err);
    while (1) {
    }
  }

  Serial.println("IMU initialized successfully");
}

void loop() {
  imu.update();

  imu.getAccel(&accelData);
  imu.getGyro(&gyroData);

  Serial.print("Accel X: ");
  Serial.print(accelData.accelX);
  Serial.print("  Y: ");
  Serial.print(accelData.accelY);
  Serial.print("  Z: ");
  Serial.print(accelData.accelZ);

  Serial.print("   Gyro X: ");
  Serial.print(gyroData.gyroX);
  Serial.print("  Y: ");
  Serial.print(gyroData.gyroY);
  Serial.print("  Z: ");
  Serial.println(gyroData.gyroZ);

  delay(200);
}