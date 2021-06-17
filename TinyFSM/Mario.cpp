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
      cout << "state : STATE_ATACCKING action : " << endl;
      handelAtacck(action);
      break;
    case STATE_STANDING:
      cout << "state : STATE_STANDING action : " << endl;
      handleStand(action);
      break;
    case STATE_JUMPING:
      cout << "state : STATE_JUMPING action : " << endl;
      handelJump(action);
      break;
    case STATE_DIVING:
      cout << "state : STATE_DIVING action : " << endl;
      handelDive(action);
      break;
  }
}

void Mario::handleStand(OPERATION action) { state = STATE_JUMPING; }
void Mario::handelJump(OPERATION action) {
  if (action == OPER_STAND) {
    state = STATE_STANDING;
  } else if (action == OPER_ATACCK) {
    state = STATE_ATACCKING;
  } else {
    cout << "invalid operation !" << endl;
    handelJump(input());
  }
}

void Mario::handelAtacck(OPERATION action) {
  if (action == OPER_DIVE) {
  }
}
void Mario::handelDive(OPERATION action) { state = STATE_STANDING; }

void Mario::moveX(int direction) {
  if (direction)
    this->posX++;
  else
    this->posX--;
}

void Mario::moveY(int direction) {
  if (direction)
    this->posY++;
  else
    this->posY--;
}