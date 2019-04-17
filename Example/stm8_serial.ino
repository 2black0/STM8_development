signed int x = 0;
char *nilai="Nilai X =";
int timer;

void setup() {
  Serial_begin(115200);
  pinMode(LED_BUILTIN, OUTPUT_FAST);
}

void loop() {
  timer = millis();
  x = x + 1;
  digitalWrite(LED_BUILTIN, HIGH);
  Serial_print_s("Led OFF pada detik = ");
  Serial_print_i(timer);
  Serial_print_s("mS dan ");
  Serial_print_s(nilai);
  Serial_println_i(x);
  delay(2000);

  timer = millis();
  x = x + 1;
  digitalWrite(LED_BUILTIN, LOW);
  Serial_print_s("Led ON pada saat = ");
  Serial_print_i(timer);
  Serial_print_s("mS dan ");
  Serial_print_s(nilai);
  Serial_println_i(x);
  delay(2000);
  
  if (x == 10){
    x = 0;
    }
}
