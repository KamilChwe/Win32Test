#include "KeyboardHandler.h"

using namespace std;

// TODO - Configurable keys

// Key Input Logic
// When the user presses a key check what key is pressed and perform an action
void keyLogic(WPARAM keyCode) {
	// Turn the int input into a character
	char key = char(keyCode);
	switch (key) {

	// Current key inputs
	case 'w':
		MessageBox(NULL,
			_T("You pressed W"),
			_T("Keyboard Handler"),
			NULL);
		break;

	case 'a':
		MessageBox(NULL,
			_T("You pressed A"),
			_T("Keyboard Handler"),
			NULL);
		break;

	case 's':
		MessageBox(NULL,
			_T("You pressed S"),
			_T("Keyboard Handler"),
			NULL);
		break;

	case 'd':
		MessageBox(NULL,
			_T("You pressed D"),
			_T("Keyboard Handler"),
			NULL);
		break;
	}
}