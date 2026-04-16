#include <Wire.h>
#include <FastIMU.h>
#include <math.h>

MPU6500 imu;
calData calib = { 0 };

AccelData accelData;

// Function prototypes
void updateIMU();
float calculatePitch(float ax, float ay, float az);
float getPitch();

void setup() {
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(100000);
  delay(2000);

  Serial.println("Starting IMU...");

  int err = imu.init(calib);

  if (err != 0) {
    Serial.print("IMU init error: ");
    Serial.println(err);
    while (1) {}
  }

  Serial.println("IMU ready");
}

void loop() {
  float pitch = getPitch();

  Serial.print("Pitch: ");
  Serial.println(pitch, 2);

  // Example decision logic
  if (pitch > 15) {
    Serial.println("Tilted forward");
  } else if (pitch < -15) {
    Serial.println("Tilted backward");
  } else {
    Serial.println("Level");
  }

  Serial.println("------------------");

  delay(200);
}

void updateIMU() {
  imu.update();
  imu.getAccel(&accelData);
}

float calculatePitch(float ax, float ay, float az) {
  return atan2(ax, sqrt(ay * ay + az * az)) * 180.0 / PI;
}

float getPitch() {
  updateIMU();

  float ax = accelData.accelX;
  float ay = accelData.accelY;
  float az = accelData.accelZ;

  return calculatePitch(ax, ay, az);
}