// Timing Challenge
// Implements a simple timer that can start, stop, and reset, with adjustable duration.

unsigned long startTime = 0;   // Stores the timer start time
bool timerRunning = false;     // Timer running state
unsigned long timerDuration = 10000; // Timer duration in milliseconds (default 10 seconds)

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Example control flow (could be triggered by buttons or serial commands in real use)
  if (Serial.available()) {
    char command = Serial.read();
    switch (command) {
      case 's': // Start timer
        startTimer();
        break;
      case 't': // Stop timer
        stopTimer();
        break;
      case 'r': // Reset timer
        resetTimer();
        break;
      case '+': // Increase timer duration
        adjustTimer(1000); // Increase by 1000 milliseconds
        break;
      case '-': // Decrease timer duration
        adjustTimer(-1000); // Decrease by 1000 milliseconds
        break;
    }
  }

  // Check and display timer status
  if (timerRunning && millis() - startTime >= timerDuration) {
    Serial.println("Timer Complete!");
    timerRunning = false; // Stop the timer automatically
  }
}

// Start the timer
void startTimer() {
  if (!timerRunning) {
    startTime = millis(); // Record the start time
    timerRunning = true;
    Serial.println("Timer Started");
  }
}

// Stop the timer
void stopTimer() {
  if (timerRunning) {
    timerRunning = false;
    Serial.println("Timer Stopped");
  }
}

// Reset the timer
void resetTimer() {
  timerRunning = false;
  Serial.println("Timer Reset");
}

// Adjust timer duration
void adjustTimer(long adjustment) {
  timerDuration += adjustment;
  Serial.print("New Timer Duration: ");
  Serial.println(timerDuration);
}

// Conceptual explanation:
// This program would interface with real-time components of an Arduino, such as using the millis() function to track elapsed time.
// User inputs to control the timer could come from physical buttons or other sensors, which would trigger these functions.
// Adjustments to the timer duration and other commands would allow dynamic control over timer operations during runtime.
