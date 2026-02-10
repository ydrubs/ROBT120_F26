const int buzzerPin = 9;    // Pin for the piezo buzzer
const int buttonPin = 2;    // Pin for the button
int buttonState = 0;

unsigned long pressStart = 0;
unsigned long pressDuration = 0;
bool isRecording = false;

// Store up to 10 notes (frequency and duration)
const int maxNotes = 10;
int frequencies[maxNotes];
int durations[maxNotes];
int noteIndex = 0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Using internal pull-up resistor
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Button pressed (active LOW since we use INPUT_PULLUP)
  if (buttonState == LOW && !isRecording) {
    pressStart = millis();
    int frequency = random(200, 1000); // Example frequency (you could add potentiometer for variation)
    tone(buzzerPin, frequency);
    isRecording = true;
    Serial.print("Playing tone: ");
    Serial.println(frequency);
  }

  // Button released
  if (buttonState == HIGH && isRecording) {
    pressDuration = millis() - pressStart;
    noTone(buzzerPin);

    // Store the frequency and duration
    if (noteIndex < maxNotes) {
      frequencies[noteIndex] = random(200, 1000); // Example stored frequency
      durations[noteIndex] = pressDuration;
      noteIndex++;
    }
    Serial.print("Recorded tone: ");
    Serial.print(frequencies[noteIndex - 1]);
    Serial.print(", Duration: ");
    Serial.println(durations[noteIndex - 1]);

    isRecording = false;
  }

  // Example playback after recording 10 notes
  if (noteIndex == maxNotes) {
    delay(2000); // Small delay before playback
    Serial.println("Playing back recorded sequence...");

    for (int i = 0; i < maxNotes; i++) {
      tone(buzzerPin, frequencies[i], durations[i]);
      delay(durations[i]);
      noTone(buzzerPin);
      delay(100); // Small delay between notes
    }

    noteIndex = 0; // Reset index after playback
  }
}
