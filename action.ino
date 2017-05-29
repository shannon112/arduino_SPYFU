void action() {
  switch (Binput) {
    case 'q':
      Serial.println("turn sharp left");
      directionControl(verybigDegree);
      //speedControl(FverylowSpeed, BverylowSpeed);
      break;
    case 'e':
      Serial.println("turn sharp right");
      directionControl(-1 * verybigDegree);
      //speedControl(FverylowSpeed, BverylowSpeed);
      break;
    case 'a':
      Serial.println("turn left");
      directionControl(bigDegree);
      //speedControl(FlowSpeed, BlowSpeed);
      break;
    case 'd':
      Serial.println("turn right");
      directionControl(-1 * bigDegree);
      //speedControl(FlowSpeed, BlowSpeed);
      break;
    case 's':
      Serial.println("stop!");
      //directionControl(0);
      speedControl(5, 5);
      break;
    case 'w':
      Serial.println("go straight");
      directionControl(0);
      //speedControl(FbrustSpeed, BbrustSpeed);
      break;
    case 'r':
      Serial.println("fuel");
      //directionControl(0);
      speedControl(ControlSpeed, ControlSpeed);
      break;
    case '1':
      Serial.println("speed up!");
      ControlSpeed = ControlSpeed + 10;
      if (ControlSpeed > 160) {
        ControlSpeed = 160;
      }
      speedControl(ControlSpeed, ControlSpeed);
      break;
    case '0':
      Serial.println("speed down!");
      ControlSpeed = ControlSpeed - 10;
      if (ControlSpeed < 40) {
        ControlSpeed = 40;
      }
      speedControl(ControlSpeed, ControlSpeed);
      break;
    default:
      Serial.println("WTF?");
      break;
  }
}
