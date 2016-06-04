/*
DMY WORKSHOP by    Robert Schnuell                 and      Frederik Ueberschär
                   http://interaktives.design               http://frederik-ueberschaer.de
 
 in cooperation with Prof. Hannes Nehls
                     http://ixdlab.hs-osnabrueck.de
                     
                     
more informations:
    http://github.com/robertschnuell/ConnectingTheAnalogAndDigitalWorld
*/




int lightPin = D0;

boolean lightStatuse = false;



//INIT
void setup() {
    
    pinMode ( lightPin, OUTPUT);
    Spark.function("event", event);

}





int event()
{
    
   
    
    lightStatuse = !lightStatuse;
    
    
    if(lightStatuse) {
        digitalWrite(lightPin,HIGH);
    } else {
        digitalWrite(lightPin,LOW);
    }
    
    return 0;

}
  