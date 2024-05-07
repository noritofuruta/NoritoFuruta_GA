#include <Ps3Controller.h>
#include "notify.h"

int player = 0;

void onConnect(){
  // 接続されたときに呼び出されるコールバック関数
  Serial.println("Connected!.");
}

void onDisconnect() {
  // 切断されたときに呼び出されるコールバック関数
  Serial.println("DisConnected!.");
}

void setup()
{
  Serial.begin(115200);
  //Ps3.attach(notify);
  // コールバック関数の登録(オプション)
  Ps3.attachOnConnect(onConnect);
  // コールバック関数の登録(オプション)
  Ps3.attachOnDisconnect(onDisconnect);
  Ps3.begin("dc:a6:32:82:b2:50");
  Serial.println("Ready.");
}

void loop()
{
  if (Ps3.isConnected()) {
    Serial.println("Connected!");

//    // Turn rumble on full intensity for 1 second
//    Ps3.setRumble(100.0, 1000);
//    delay(2000);

    // Turn rumble on full intensity indefinitely
    Ps3.setRumble(50);
    delay(2000);

    // Turn off rumble
    Ps3.setRumble(0.0);
  


    if (Ps3.data.button.select) {
      Serial.println("select ボタン圧下");
    }
    if (Ps3.data.button.l3 ) {
      Serial.println("l3 ボタン圧下");
    }
    if (Ps3.data.button.r3) {
      Serial.println("r3 ボタン圧下");
    }
    if (Ps3.data.button.start) {
      Serial.println("start ボタン圧下");
    }

    if (Ps3.data.button.up ) {
      Serial.println("up ボタン圧下");
    }
    if (Ps3.data.button.right) {
      Serial.println("right ボタン圧下");
    }
    if (Ps3.data.button.down ) {
      Serial.println("down ボタン圧下");
    }
    if (Ps3.data.button.left) {
      Serial.println("left ボタン圧下");
    }

    if (Ps3.data.button.l2 ) {
      Serial.println("l2 ボタン圧下");
    }
    if (Ps3.data.button.r2) {
      Serial.println("r2 ボタン圧下");
    }
    if (Ps3.data.button.l1 ) {
      Serial.println("l1 ボタン圧下");
    }
    if (Ps3.data.button.r1) {
      Serial.println("r1 ボタン圧下");
    }

    if (Ps3.data.button.cross) {
      Serial.println("cross ボタン圧下");
    }
    if (Ps3.data.button.square) {
      Serial.println("square ボタン圧下");
    }
    if (Ps3.data.button.triangle) {
      Serial.println("triangle ボタン圧下");
    }
    if (Ps3.data.button.circle) {
      Serial.println("circle ボタン圧下");
    }

    if (Ps3.data.button.ps) {
      Serial.println("ps ボタン圧下");
    }

    Serial.print("128,-128,LX=,"); //プロッタ用基準線
    Serial.print(Ps3.data.analog.stick.lx);
    Serial.print(",LY=,");
    Serial.print(Ps3.data.analog.stick.ly);
    Serial.print(",RX=,");
    Serial.print(Ps3.data.analog.stick.rx);
    Serial.print(",RY=,");
    Serial.print(Ps3.data.analog.stick.ry);
    Serial.print(",SX=,");
    Serial.print(Ps3.data.sensor.accelerometer.x);
    Serial.print(",SY=,");
    Serial.print(Ps3.data.sensor.accelerometer.y);
    Serial.print(",SZ=,");
    Serial.print(Ps3.data.sensor.accelerometer.z);
    Serial.println();

    //-------------------- Player LEDs -------------------
    Serial.print("Setting LEDs to player "); Serial.println(player, DEC);
    Ps3.setPlayer(player);

    player += 1;
    if (player > 10) player = 0;


  }

  delay(2000);
}
