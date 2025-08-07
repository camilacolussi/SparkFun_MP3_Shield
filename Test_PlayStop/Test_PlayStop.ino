#include <SPI.h>
#include <SdFat.h>
#include <FreeStack.h>
#include <SFEMP3Shield.h>

SdFat sd;
SFEMP3Shield MP3player;

void setup() {
  Serial.begin(9600);
  
  //Initialize the SdCard.
  if(!sd.begin(SD_SEL, SPI_FULL_SPEED)) sd.initErrorHalt();
  // depending upon your SdCard environment, SPI_HAVE_SPEED may work better.
  if(!sd.chdir("/")) sd.errorHalt("sd.chdir");

  // Initialize the MP3 shield
  MP3player.begin();
}

void loop() {
      Serial.println("Playing");
  playTrack(1); // Call playTrack Function
  delay(5000); // wait 5 seconds  
}

void playTrack(int trackNumber) {
  MP3player.stopTrack();   // Stop any currently playing tracks

  // Play the specified track
  MP3player.playTrack(trackNumber);
}
