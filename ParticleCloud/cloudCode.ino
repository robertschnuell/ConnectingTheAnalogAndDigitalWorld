/*
DMY WORKSHOP by    Robert Schnuell                 and      Frederik Ueberschär
                   http://interaktives.design               http://frederik-ueberschaer.de
 
 in cooperation with Prof. Hannes Nehls
                     http://ixdlab.hs-osnabrueck.de
                     
                     
more informations:
    http://github.com/robertschnuell/ConnectingTheAnalogAndDigitalWorld
*/





//
int lightPin = D0;

boolean lightStatuse = false;



//initialization (this part is only done once at the start of the microcontroller)
void setup() {
    
    
    pinMode ( lightPin, OUTPUT);   // set the pin active which is used
    Spark.function("event", event); //tell the cloud whats the name of the function 

}


//this function will be activated everytime the button on the website is pressed
int event()
{
    
   
    
    lightStatuse = !lightStatuse;   //the status of the light is set on its revered status (on -> off & off -> on)
    
    
    //this query decides whats the status of the light and powering it on or switch it of
    if(lightStatuse) {
        digitalWrite(lightPin,HIGH);
    } else {
        digitalWrite(lightPin,LOW);
    }
    
    return 0;  //just a callback for the Cloud that everything is running fine

}
  