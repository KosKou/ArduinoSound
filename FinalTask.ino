/*  Declaracion de Variables  */
/*  Developed by: Banner Gonzales
    Code Number:  1625238*/

/*=====================
Variables Declaration
=====================*/
#include <Keypad.h>
/*Begin Keypad code*/
const byte filas = 4;
const byte columnas = 4;
byte pinsFilas[filas] = {9,8,7,6};
byte pinsColumnas[columnas] = {5,4,3,2};

char teclas[filas][columnas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
char tecla;
Keypad teclado = Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas, filas, columnas);
/*End Keypad Code*/
/*Button*/
const int Button = 10;
int val = 0;    //Variable used to get the button state.
int state = 0;  //Defines the value of the state.
int old_val = 0;//Defines a previous valuo of button.
/*Buzzer*/
const int Buzzer = 11;
/*Scala*/
  int scala = 0;
/*Values Init*/
void setup() {
  Serial.begin(9600); //Begin Serial Port Manager
//Button
  pinMode(Button, INPUT); //Wil get values
  //Buzzer
}

void loop() {
  noTone(Buzzer);
  getButtonState();           //Execute Method
  /*Validate*/
  if (state==1){  //If button has been pressed
    //Something
      tecla = teclado.getKey();
      if(tecla != NO_KEY){
        Serial.println(tecla);
        getScala(tecla);
        if(scala != 0){
          coreTactil(tecla);          
        }
      }
    noTone(Buzzer);
  }
  else{           //If not
    //Something
    noTone(Buzzer);
  }
}

//Method to change button status
void getButtonState(){
  val = digitalRead(Button);              //Read button status
  if ((val == HIGH) && (old_val == 0)){ //The old_val could be LOW too. ==LOW
    Serial.println("Boton Apretado");
      state=1-state;                    //Move state value
      delay(10);                        //Wait
  } 
  old_val = val;                        //Save previous value.
}

//Method to KeyPad Usage
void coreTactil(char e){
  String var = "";
  var = var + e;
  if(var.equals("1")){setNote("Do");}
  if(var.equals("2")){setNote("Re");}
  if(var.equals("3")){setNote("Mi");}
  if(var.equals("4")){setNote("Fa");}
  if(var.equals("5")){setNote("Sol");}
  if(var.equals("6")){setNote("La");}
  if(var.equals("7")){setNote("Si");}
}

//Method to set Tone
void setNote(String note){  
  if(scala == 1){
    //Third Scale
    if(note == "Do"){tone(Buzzer, 130,813); delay(300);}
    if(note == "Re"){tone(Buzzer, 146,832); delay(300);}
    if(note == "Mi"){tone(Buzzer, 164,814); delay(300);}
    if(note == "Fa"){tone(Buzzer, 174,614); delay(300);}
    if(note == "Sol"){tone(Buzzer, 195,998); delay(300);}
    if(note == "La"){tone(Buzzer, 220,000); delay(300);}
    if(note == "Si"){tone(Buzzer, 246,942); delay(300);}
    
  }else if(scala == 2){
    //Quarter Scale
    if(note == "Do"){tone(Buzzer, 261,626); delay(300);}
    if(note == "Re"){tone(Buzzer, 293,665); delay(300);}
    if(note == "Mi"){tone(Buzzer, 329,628); delay(300);}
    if(note == "Fa"){tone(Buzzer, 349,228); delay(300);}
    if(note == "Sol"){tone(Buzzer, 391,995); delay(300);}
    if(note == "La"){tone(Buzzer, 440,000); delay(300);}
    if(note == "Si"){tone(Buzzer, 493,883); delay(300);}
  }else if(scala == 3){
    //Fifth Scale
    if(note == "Do"){tone(Buzzer, 523,251); delay(300);}
    if(note == "Re"){tone(Buzzer, 587,330); delay(300);}
    if(note == "Mi"){tone(Buzzer, 659,255); delay(300);}
    if(note == "Fa"){tone(Buzzer, 698,800); delay(300);}
    if(note == "Sol"){tone(Buzzer, 783,991); delay(300);}
    if(note == "La"){tone(Buzzer, 880,000); delay(300);}
    if(note == "Si"){tone(Buzzer, 987,767); delay(300);}
  }else if(scala == 4){
    //Sixth Scale
    if(note == "Do"){tone(Buzzer, 1046,502); delay(300);}
    if(note == "Re"){tone(Buzzer, 1174,659); delay(300);}
    if(note == "Mi"){tone(Buzzer, 1318,510); delay(300);}
    if(note == "Fa"){tone(Buzzer, 1396,913); delay(300);}
    if(note == "Sol"){tone(Buzzer, 1567,982); delay(300);}
    if(note == "La"){tone(Buzzer, 1760,000); delay(300);}
    if(note == "Si"){tone(Buzzer, 1975,533); delay(300);}
  }
  noTone(Buzzer);
}
//Method getScala
void getScala(char e){
  String var = "";
  var = var + e;
  if(var.equals("A")){scala = 1;}
  if(var.equals("B")){scala = 2;}
  if(var.equals("C")){scala = 3;}
  if(var.equals("D")){scala = 4;}
}

