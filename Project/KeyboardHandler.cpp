#include "KeyboardHandler.h"

void checkKey(WPARAM key) {
	switch (key) {
	case 119:
		MessageBox(NULL,
			_T("You pressed w"),
			_T("Key Input"),
			NULL);
		break;
	case 97:
		MessageBox(NULL,
			_T("You pressed a"),
			_T("Key Input"),
			NULL);
		break;
	case 115:
		MessageBox(NULL,
			_T("You pressed s"),
			_T("Key Input"),
			NULL);
		break;
	case 100:
		MessageBox(NULL,
			_T("You pressed d"),
			_T("Key Input"),
			NULL);
		break;
	}
}