/* "name"      click  press  left
   "left"        q
   "right"       e
   "straight"    f
   "speedup"     1
   "speeddown"   0
   "go"          2             s
*/
int lturing = 0;
int rturing = 0;
void action() {
  switch (Binput) {
    case 'q':
      Serial.println("turn sharp left");
      rturing = -1;
      lturing = lturing + 1;
      switch (lturing) {
        case 0:
          directionControl(0);
          break;
        case 1:
          directionControl(9);
          break;
        /*
                case 2:
                  directionControl(15);
                  break;
        */
        default:
          directionControl(12);
          break;
      }
      break;
    case 'e':
      Serial.println("turn sharp right");
      lturing = -1;
      rturing = rturing + 1;
      switch (rturing) {
        case 0:
          directionControl(0);
          break;
        case 1:
          directionControl(-1 * 9);
          break;
        /*
                case 2:
                  directionControl(-1 * 15);
                  break;
        */
        default:
          directionControl(-1 * 12);
          break;
      }
      break;
    case 's':
      Serial.println("stop!");
      while (ControlSpeed > 15) {
        ControlSpeed = ControlSpeed - 10;
        speedControl(ControlSpeed, ControlSpeed);
        delay(100);
      }
      break;
    case 'f':
      Serial.println("go straight");
      rturing = 0;
      lturing = 0;
      directionControl(0);
      break;
    /*
        case '1':
          Serial.println("speed up!");
          ControlSpeed = ControlSpeed + 10;
          if (ControlSpeed > 80) {
            ControlSpeed = 80;
          }
          //speedControl(ControlSpeed, ControlSpeed);
          break;
        case '0':
          Serial.println("speed down!");
          ControlSpeed = ControlSpeed - 10;
          if (ControlSpeed < 30) {
            ControlSpeed = 30;
          }
          //speedControl(ControlSpeed, ControlSpeed);
          break;
    */
    case '2':
      Serial.println("go!");
      if (ControlSpeed == 15) {
        ControlSpeed = 15;
        for (int n = 0; n < 5; n++) {
          ControlSpeed = ControlSpeed + 10;
          speedControl(ControlSpeed, ControlSpeed);
          delay(100);
        }
      }
      break;
    case 'r':
      BrushlessF.write(0);
      BrushlessB.write(0);
      delay(1000);
      systemInitialize();
      break;
    default:
      Serial.println("WTF?");
      break;
  }
}
