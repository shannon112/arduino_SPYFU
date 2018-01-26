void getBluetooth() {
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  Binput = BTSerial.read();
  Serial.print("Binput= ");
  Serial.println(Binput);
}
