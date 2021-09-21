#include <TimerOne.h>

int motor = 2; //DC 모터 2핀 사용
int pump = 3; //DC 펌프 3핀 사용
int Check = 4; //수위센서 배변 상태 확인 4핀 사용

void setup() {
  pinMode(motor, OUTPUT); //motor 출력으로 사용
  pinMode(pump, OUTPUT); //pump 출력으로 사용
  pinMode(Check, INPUT); //check 입력으로 사용

  digitalWrite(motor, LOW); //motor LOW(off) 초기화
  digitalWrite(pump, LOW); //pump LOW(off) 초기화
}

void loop() {
  int check = digitalRead(Check);
  if(check == 1){ //배변 상태가 1이라면 실행
    IF_CHECK();
  }
}

void IF_CHECK() {
  digitalWrite(pump, HIGH); //5초동안 pump on
    delay(5000); //delay 5s
    digitalWrite(pump, LOW); //pump off
    
    digitalWrite(motor, HIGH); //4초동안 motor on
    delay(4000); //delay 4s
    digitalWrite(motor, LOW); //motor off 
}
