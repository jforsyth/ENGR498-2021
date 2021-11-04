/**
   Arduino source file for ECE 420 Assignment #1
*/

//include header for sleep library
#include <avr/sleep.h>

/**
   setup() executes once at boot
*/
void setup() {

  //configure on-board LED as OUTPUT
  pinMode(13, OUTPUT);

  //Initialize Serial/UART for 9600 baud
  Serial.begin(9600);

  //15s delay so we can recover from
  //power down mode
  delay(15000);
  
  //print a message to know we're alive
  Serial.println("Hello world!");

  /**
     Place a long delay here so that the device is not always asleep.
     Failure to do so will cause the device to "brick" and you cannot
     re-program via the SPI bootloader
  */
  delayLoop();
}

/**
   A delay function that blinks the LED while a count down is going on
*/
void delayLoop()
{
  Serial.println("Begin the count down!");
  long startTime = millis();
  const long totalDelay = 5000;

  bool timeExpired = (millis() - startTime) > totalDelay;
  while (!timeExpired)
  {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);

    timeExpired = (millis() - startTime) > totalDelay;
  }
}

/**
   loop is executed continuously
*/
void loop() {

  /**
     Follow the process in the ATMEL documentation to do to sleep.
     Try out different sleep modes.
     https://www.microchip.com/webdoc/AVRLibcReferenceManual/group__avr__sleep.html

    The 5 different modes are:
            SLEEP_MODE_IDLE
            SLEEP_MODE_ADC
            SLEEP_MODE_PWR_SAVE
            SLEEP_MODE_STANDBY
            SLEEP_MODE_PWR_DOWN
  */


  //set the desired sleep mode
  /**
       Your code here
  */

  //stop interrupts (execute atomically)
  /**
       Your code here
  */

  /**
     Follow the code template from the AVR Sleep
     documentation
  */
  boolean someCondition = true;
  if (someCondition)
  {

    //print message and delay so serial is flushed.
    //Otherwise message will not complete
    Serial.println("Good night!");
    Serial.flush();
    delay(1000);

    //enable sleep mode by setting the sleep bit
    /**
       Your code here
    */

    //re-enable interrupts. If you do not, then you will never
    //awake from sleep...
    /**
       Your code here
    */

    //execute the sleep instruction and actually go to sleep
    /**
       Your code here
    */

    //WAKE UP! First thing to do is disable sleep so we
    //don't do it again.
    /**
       Your code here
    */
  }

  //restore interrupts now that processor is awake
  /**
       Your code here
  */

  //Print a message saying you're back!
  Serial.println("I'm alive!");

  //delay again before entering sleep
  delayLoop();
}
