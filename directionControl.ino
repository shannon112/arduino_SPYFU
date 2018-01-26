void directionControl(int degree) { //左負右正
  int ddegree = middleDegree - 1 * degree;
  myServo.write(ddegree);
  //Serial.println(ddegree);
}
