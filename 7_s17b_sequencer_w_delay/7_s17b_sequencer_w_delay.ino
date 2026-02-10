const int buzzerPin = 9;    // Pin for the piezo buzzer
const int buttonPin = 2;    // Pin for the button
int buttonState = 0;

unsigned long pressStart = 0;
unsigned long pressDuration = 0;
unsigned long silenceStart = 0;
unsigned long silenceDuration = 0;
bool isRecording = false;
bool isSilent = false;

// Store up to 10 notes (frequency, duration) and silences (duration)
const int maxNotes = 4;
int frequencies[maxNotes];
int durations[maxNotes];
int silences[maxNotes];
int noteIndex = 0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Using internal pull-up resistor
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Button pressed (active LOW)
  if (buttonState == LOW && !isRecording) {
    pressStart = millis();
    
    int frequency = random(200, 1000); // Example frequency (replace with actual method if needed)
    tone(buzzerPin, frequency);
    isRecording = true;
    
    // Record silence before this note
    if (isSilent && noteIndex > 0) {
      silenceDuration = millis() - silenceStart;
      silences[noteIndex - 1] = silenceDuration;
      Serial.print("Silence recorded: ");
      Serial.println(silenceDuration);
      isSilent = false;
    }

    Serial.print("Playing tone: ");
    Serial.println(frequency);
  }

  // Button released
  if (buttonState == HIGH && isRecording) {
    pressDuration = millis() - pressStart;
    noTone(buzzerPin);

    // Store the frequency and duration of the note
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

    // Start recording silence after the note
    silenceStart = millis();
    isSilent = true;
  }

  // Playback sequence when maxNotes is reached
  if (noteIndex == maxNotes) {
    delay(2000); // Small delay before playback
    Serial.println("Playing back recorded sequence...");

    for (int i = 0; i < maxNotes; i++) {
      // Play silence before the note
      if (i > 0) {
        Serial.print("Silence for: ");
        Serial.println(silences[i - 1]);
        delay(silences[i - 1]); // Silence duration
      }

      // Play the note
      tone(buzzerPin, frequencies[i], durations[i]);
      delay(durations[i]);
      noTone(buzzerPin);
      delay(100); // Small delay between notes
    }

    noteIndex = 0; // Reset index after playback
  }
}
