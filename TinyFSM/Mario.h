#ifndef MARIO_H
#define MARIO_H

enum MARIO_STS { STATE_STANDING, STATE_JUMPING, STATE_ATACCKING, STATE_DIVING };
enum OPERATION { OPER_STAND, OPER_JUMP, OPER_ATACCK, OPER_DIVE, OPER_NULL };

class Mario {
 public:
  bool isJumping;
  bool isDiving;
  bool isAtaccking;
  MARIO_STS state;
  // Mario();
  // ~Mario();
  void init();
  void action();

 private:
  void stateIn(OPERATION action);
  void handleStand();
  void handelJump();
  void handelDive();
  void handelAtacck();
  OPERATION input();
};

#endif