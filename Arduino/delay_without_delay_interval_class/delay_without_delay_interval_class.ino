class Interval {
  private:
    unsigned long lastTime;
    unsigned long interval;
    void (*func)();

  public:
    Interval(void (*f)(), unsigned long i) {
      lastTime = 0;
      interval = i;
      func = f;
    }

    void set(void (*f)(), unsigned long i) {
      lastTime = 0;
      interval = i;
      func = f;
    }

    void check() {
      unsigned long now = millis();
      if (now - lastTime >= interval) {
        lastTime = now;
        func();
      }
    }
};


void myFunction() {
  // Do something
  Serial.println("Hello World!");
}

void myFunction2(){
  // Do something
  Serial.println("Hello World! 2");
}

// Example usage
Interval myInterval(myFunction, 2000); // call myFunction every 1000ms (1 second)
Interval myInterval2(myFunction2, 3000); // call myFunction every 1000ms (1 second)

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
}

void loop() {
  myInterval.check(); // check if it's time to call the function again
  myInterval2.check(); // check if it's time to call the function again
}

