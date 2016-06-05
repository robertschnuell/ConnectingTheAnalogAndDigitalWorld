/*
DMY WORKSHOP by    Robert Schnuell                 and      Frederik Ueberschär
                   http://interaktives.design               http://frederik-ueberschaer.de
 
 in cooperation with Prof. Hannes Nehls
                     http://ixdlab.hs-osnabrueck.de
                     
                     
more informations:
    http://github.com/robertschnuell/ConnectingTheAnalogAndDigitalWorld
*/





//
int lightPin = D7;
int del = 0;

boolean lightStatuse = false;



//initialization (this part is only done once at the start of the microcontroller)
void setup() {
    
    
    pinMode ( lightPin, OUTPUT);   // set the pin active which is used
    Spark.function("event", event); //tell the cloud whats the name of the function 

}

void loop() {
    
    
    //
    if( del == 0) {
        
        //this query decides whats the status of the light and powering it on or switch it of
        if(lightStatuse) {
                digitalWrite(lightPin,HIGH);
            } else {
                digitalWrite(lightPin,LOW);
        }
    
    } else {
        
        //Blink the light in a given interval
        digitalWrite(lightPin,HIGH);
        delay(del); // The Code will stop here for "del" milliseconds. the pin will hold his status in this process.
        digitalWrite(lightPin,LOW);
        delay(del);
        
    }
    
}



//this function will be activated everytime the button on the website is pressed
int event(String cmd)
{
    
   
    
   
    
    
    // If the String does not includes any data the interaction  has to be an button action
    if(cmd == "") {
        
        
        
         lightStatuse = !lightStatuse;   //the status of the light is set on its revered status (on -> off & off -> on)
         
         del = 0;

        
    } else {
        del = cmd.toInt() * 100; // multiply with 100 to get 1/10 of a second (1000 milliseconds are 1 Second)
        

    }
    
    
    return 0;  //just a callback for the Cloud that everything is running fine

}
  