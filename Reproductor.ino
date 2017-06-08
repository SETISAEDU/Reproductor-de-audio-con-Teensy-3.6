//Reproductor de audio con Teensy 3.6 

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav1;     
AudioOutputAnalogStereo  dacs1;          
AudioConnection          patchCord1(playSdWav1, 0, dacs1, 0);
AudioConnection          patchCord2(playSdWav1, 1, dacs1, 1);
// GUItool: end automatically generated code

// Utilisados para la SD de  Teensy 3.6
#define SDCARD_CS2_PIN    43
#define SDCARD_MISI2_PIN  44
#define SDCARD_MISO2_PIN  45
#define SDCARD_SCK2_PIN   46

String Menu;
boolean Fin_1 = true; 
boolean Fin_2 = true;
boolean Fin_3 = true;
boolean Fin_4 = true;
boolean Fin_5 = true;


void setup ()
{
  Serial.begin(9600);               //Configuramos la velocidad de comunicacion
  AudioMemory(8);                   //Definimos la memoria de trabajo para las conexiones de audio
  //Configuraciones para los DACs
  dacs1.analogReference(INTERNAL); 
  
  if (!(SD.begin(BUILTIN_SDCARD))) { //Verifica si la tarjeta SD se encuentra inicializada
    while (1) {
      Serial.println("No se puede acceder a la tarjeta SD"); 
      delay(500);
    }
  }
  Serial.println ("Acceso permitido"); // Tarjeta SD inicializada correctamente
 
  
  Serial.println("Escriba el numero de la lista que se desea reproducir");
  Serial.println("1 - Pista de audio 1");
  Serial.println("2 - Pista de audio 2");
  Serial.println("3 - Pista de audio 3");
  Serial.println("4 - Pista de audio 4");
  Serial.println("5 - Pista de audio 5");
}

void loop ()
{
  
  
  
  
  if (Serial.available()) //Datos disponibles en el puerto serial
  {
    Menu = Serial.readString(); //Lectura de datos

    if(Menu == "1" && Fin_1) // Verifica el audio seleccionado por el usuario
    {
    playFile("PistaN1.WAV");  // Los nombres de los archivos de audio se escribiran siempre en mayusculas
    Fin_1 = false;
    Fin_2 = true;
    Fin_3 = true;
    Fin_4 = true;
    Fin_5 = true;
    }
     if(Menu == "2" && Fin_2) 
    {
    playFile("PistaN2.WAV");   // Los nombres de los archivos de audio se escribiran siempre en mayusculas
    Fin_2 = false;
    Fin_1 = true;
    Fin_3 = true;
    Fin_4 = true;
    Fin_5 = true;
    }
     if(Menu == "3" & Fin_3) 
    {
    playFile("PistaN3.WAV");   // Los nombres de los archivos de audio se escribiran siempre en mayusculas
    Fin_3 = false;
    Fin_1 = true;
    Fin_2 = true;
    Fin_4 = true;
    Fin_5 = true;
    }
     if(Menu == "4" & Fin_4) 
    {
    playFile("PistaN4.WAV");   // Los nombres de los archivos de audio se escribiran siempre en mayusculas
    Fin_4 = false;
    Fin_1 = true;
    Fin_2 = true;
    Fin_3 = true;
    Fin_5 = true;
    }
     if(Menu == "5" & Fin_5) 
    {
    playFile("PistaN5.WAV");  // Los nombres de los archivos de audio se escribiran siempre en mayusculas
    Fin_5 = false;
    Fin_1 = true;
    Fin_2 = true;
    Fin_3 = true;
    Fin_4 = true;
    }
  }
   
}


void playFile(const char *filename) 
{
  Serial.print("Playing file: ");
  Serial.println(filename);
  playSdWav1.play(filename); //Inicializa la reproduccion del archivo WAV
 
   
//  while (playSdWav1.isPlaying()) {
//   }
 }
