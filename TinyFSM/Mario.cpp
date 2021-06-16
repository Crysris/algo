#include "Mario.h"

#include "../etc/util.h"

void Mario::init() {
  state = STATE_STANDING;
  action();
}

void Mario::action() {
  int i = 0;
  while (i < 10000000) {
    // cout << i << " ";
    stateIn(input());
    i++;
  }
}
OPERATION Mario::input() {
  int chr;
  OPERATION oper = OPER_NULL;
  while (cin >> chr) {
    switch (chr) {
      case 1:
        oper = OPER_STAND;
        break;
      case 2:
        oper = OPER_JUMP;
        break;
      case 3:
        oper = OPER_ATACCK;
        break;
      case 4:
        oper = OPER_DIVE;
        break;
    }
    if (oper != OPER_NULL) return oper;
    cout << "invalid operation !" << endl;
  }

  return oper;
}

void Mario::stateIn(OPERATION action) {
  switch (state) {
    case STATE_ATACCKING:
      cout << "state : STATE_ATACCKING action : " << action << endl;
      handelAtacck();
      break;
    case STATE_STANDING:
      cout << "state : STATE_STANDING action : " << action << endl;
      handleStand();
      break;
    case STATE_JUMPING:
      cout << "state : STATE_JUMPING action : " << action << endl;
      handelJump();
      break;
    case STATE_DIVING:
      cout << "state : STATE_DIVING action : " << action << endl;
      handelDive();
      break;
  }
}

void Mario::handleStand() { state = STATE_JUMPING; }
void Mario::handelJump() { state = STATE_ATACCKING; }
void Mario::handelAtacck() { state = STATE_DIVING; }
void Mario::handelDive() { state = STATE_STANDING; }
