// Number of buttons to handle
const int buttonsCount = 4;

// Arduino PINs to use
const int pins[buttonsCount] = {
	2,
	3,
	4,
	5
};

// Keys to send (order has to match the pins array)
const byte keys[buttonsCount] = {
	KEY_UP_ARROW,
	KEY_DOWN_ARROW,
	KEY_LEFT_ARROW,
	KEY_RIGHT_ARROW
};

// Debounce delay
const long debounceDelay = 50;

bool status[buttonsCount] = {LOW};
long lastDebounces[buttonsCount] = {0};

void setup() {
	for (int i = 0; i < buttonsCount; ++i) {
		pinMode(pins[i], INPUT);
	}

	Keyboard.begin();
}

void loop() {
	for (int i = 0; i < buttonsCount; ++i) {
		handleButton(i, digitalRead(pins[i]), millis());
	}
}

/**
 * \brief Send a key press/release if needed
 *
 * \param buttonNumber Button ID to handle
 * \param pinStatus PIN status (LOW/HIGH)
 * \param now Time in millis
 */
void handleButton(const int buttonNumber, const int pinStatus, const long now) {
	if (pinStatus != status[buttonNumber] && now - debounceDelay > lastDebounces[buttonNumber]) {
		status[buttonNumber] = pinStatus;
		if (pinStatus == HIGH) {
			Keyboard.press(keys[buttonNumber]);
		} else {
			Keyboard.release(keys[buttonNumber]);
		}
		lastDebounces[buttonNumber] = now;
	}
}

