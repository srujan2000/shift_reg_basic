void setup() {
  char data = 0x0F;
  init();
  out_ds(0x00);
  out_clk(0x00);
  out_latch(0x00);

  for(int i=0;i<8;i++){
    out_ds((data>>i)&0x01);
    clk_enable();
  }
  latch_enable();
  delay1();
}

void init(){
  char *ddr1 = (char*)0x30;
  *ddr1 = 0x01;

  char *ddr2 = (char*)0x107;
  *ddr2 = 0x01;
  
  char *ddr3 = (char*)0x10A;
  *ddr3 = 0x01;
}

void out_ds(char data){
  char *out = (char*)0x31;
  *out = data;
}

void out_clk(char data){
  char *out = (char*)0x108;
  *out = data;
}

void out_latch(char data){
  char *out = (char*)0x10B;
  *out = data;
}

void clk_enable(){
  out_clk(0x01);
  delay1();
  out_clk(0x00);
  delay1();
}

void latch_enable(){
  out_latch(0x01);
  delay1();
  out_latch(0x00);
  delay1();
}

void delay1(){
  volatile long i;
  for(i=0;i<100000;i++);
}



void loop() {
  // put your main code here, to run repeatedly:

}
