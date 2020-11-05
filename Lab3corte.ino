//Programa Laboratorio 5.
//Andrés Gómez CODIGO 2154714 David Sandoval codigo 2142786
//Version 1.1
//clases
class inputs{ // creamos clase para las entradas
 private:
 
 int S0;  //DIPSW1
 int S1;  //DIPSW2
 int S2;  //DIPSW3
 int S3;  //DIPSW4
 int Z;   //ENTRADA ANÁLOGA
 public:
 
 void set_input_ports( int s00, int s01, int s02, int s03,int an) //SET DE LOS PUERTOS DE ENTRADA

 {

  S0=s00;
  S1=s01;
  S2=s02;
  S3=s03;
  Z=an;

 }
 void config_inputs()//declaramos que los puertos son entradas

 {

 pinMode(S0, INPUT);//entradas digitales
 pinMode(S1, INPUT);
 pinMode(S2, INPUT);
 pinMode(S3, INPUT);
 pinMode(Z,  INPUT);//entrada analoga



 }
  int read_input(int in)// leer y retornar el valor digital leido

 {
 int val;
 val=digitalRead(in);// lee el puerto indicado
 return val;


 }
 int read_analog_input(int in)// lee y retorna el valor analogo convertido a digital

 {
 int val;
 val=analogRead(in);;// lee el puerto analogo indicado
 return val;


 }

  
  
};



class led_control{// clase para las salidas

 private:

 int led1;//LED1
 int led2;//LED2
 int led3;//LED3
 int led4;//LED4


 public:


 void set_led_ports(int p1, int p2, int p3, int p4) //SET DE LOS PUERTOS DE SALIDA


 {

 led1=p1;
 led2=p2;
 led3=p3;
 led4=p4;

 }

 void config_leds()// DECLARAMOS QUE PUERTOS SON DE SALIDA

 {

 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led4, OUTPUT);


 }

 void set_leds(int led) // funcion para prender led

 {

 digitalWrite(led, HIGH);



 }

 void clear_leds(int led)// funcion para apagar led


 {

 digitalWrite(led, LOW);

 

 }


 };

//creamos los objetos a utilizar
inputs entradas;
led_control leds_ejemplo;



void setup()//configuracion

 {
 entradas.set_input_ports(5,4,3,2,7); //indicamos los puertos de entrada segun se tenga en el montaje fisico
  
 entradas.config_inputs();// se configuran estos puertos como entrada

 leds_ejemplo.set_led_ports(10,9,8,7);//indicamos los puertos de salida segun se tenga en el montaje fisico

 leds_ejemplo.config_leds();// se configuran estos puertos como salida
 Serial.begin(9600);// iniciar velocidad de intercambio de datos con el monitor serial
  

 }



void loop()// principal

 {
  // inicia el ciclo del programa principal
  // declaramos los valores para usar en las funciones
int S0=2;
int S1=3;
int S2=4;
int S3=5;
int val=0;
int Z=7;
val=entradas.read_analog_input(Z);// lee entrada analoga
Serial.println(val);//imprime la entrada analoga
delay(1);// delay de 1 ms para percibir los datos en el monitor serial
 if (entradas.read_input(S3) == HIGH ){// evalua el dpsw3 para saber que modo elige
      modo1();// passthrough
      }
 
 else{
      modo2();//Analog Reference.
      }
      
 }

 void modo2(){// modo Analog Reference.
  //declara los valores que se van a mandar a las funciones

int S0=2;
int S1=3;
int S2=4;
int S3=5;
int Z=7;
int led1=10;
int led2=9;
int led3=8;
int led4=7;
int tol;
leds_ejemplo.clear_leds(7);
tol=tolerancia();// se recibe el valor para elegir el caso
switch(tol){

  case 7:


         //para +- 7%
              
              if (entradas.read_analog_input(Z)>573) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3);
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if (entradas.read_analog_input(Z)<573 && entradas.read_analog_input(Z)>498)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2);
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<498)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1);
                leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              }
              break;
              
        case 6:
              //para +- 6%

               if (entradas.read_analog_input(Z)>568) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3);
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if (entradas.read_analog_input(Z)<568 && entradas.read_analog_input(Z)>503)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2);
                 leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<503)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1);
                 leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              }           
              break;
       case 5://para +- 5% 

               if (entradas.read_analog_input(Z)>562) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3);
                 leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if (entradas.read_analog_input(Z)<562 && entradas.read_analog_input(Z)>509)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2);
                 leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<509)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1);
                 leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              }       
              break;
        case 4://para +- 4%

               if (entradas.read_analog_input(Z)>557) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3); 
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if (entradas.read_analog_input(Z)<557 && entradas.read_analog_input(Z)>514)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2);
                 leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<514)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1);
                leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              } 
              break;

       case 3://para +- 3%

               if (entradas.read_analog_input(Z)>552) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3);
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if (entradas.read_analog_input(Z)<552 && entradas.read_analog_input(Z)>520)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2); 
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<520)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1); 
                leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              }
              break;
              
         case 2://para +- 2%

               if (entradas.read_analog_input(Z)>547) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3); 
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if (entradas.read_analog_input(Z)<547 && entradas.read_analog_input(Z)>525)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2); 
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<525)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1);
                 leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              }
              break;

          case 1://para +- 1%

              if (entradas.read_analog_input(Z)>541) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3);
                 leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if(entradas.read_analog_input(Z)<541 && entradas.read_analog_input(Z)>530)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2);
                 leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<530)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1);
                 leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              } 
              break;  
         default: // 0 de tolerencia

             if (entradas.read_analog_input(Z)==536)// solo prende con el valor de referencia
              {
                leds_ejemplo.set_leds(led2);
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              } 
              else{
                leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              break;  
              


}
  
 }
 void modo1(){ // modo  Passthrough.
  //declaramos los valores que se van a mandar a las funciones
int S0=2;
int S1=3;
int S2=4;
int S3=5;

    if (entradas.read_input(S3) == HIGH ){// si dpsw3 esta activo
      leds_ejemplo.set_leds(7);
      }
      else{
      leds_ejemplo.clear_leds(7);
      }
    if (entradas.read_input(S1) == HIGH ){// si dpsw1 esta activo
      leds_ejemplo.set_leds(9);
      }
      else{
      leds_ejemplo.clear_leds(9);
      }
    if (entradas.read_input(S2) == HIGH ){// si dpsw2 esta activo
      leds_ejemplo.set_leds(8);
      }
      else{
      leds_ejemplo.clear_leds(8);
      }
    if (entradas.read_input(S0) == HIGH ){// si dpsw0 esta activo
      leds_ejemplo.set_leds(10);
      }
      else{
      leds_ejemplo.clear_leds(10);
      }
 }
 int tolerancia(){ //funcion para devolver el valor de la tolerancia seleecionada
  //declaramos valores que se envian a las funciones
int S0=2;
int S1=3;
int S2=4;
int S3=5;
int caso=0;//valor a devolver
 if (entradas.read_input(S2)==HIGH && entradas.read_input(S1)==HIGH && entradas.read_input(S0)==HIGH){// si es 7 en binario
  caso=7;
  return caso;
 }
  if (entradas.read_input(S2)==HIGH && entradas.read_input(S1)==HIGH && entradas.read_input(S0)==LOW){// si es 6 en binario
  caso=6;
  return caso;
 }
  if (entradas.read_input(S2)==HIGH && entradas.read_input(S1)==LOW && entradas.read_input(S0)==HIGH){// si es 5 en binario
  caso=5;
  return caso;
 }
  if (entradas.read_input(S2)==HIGH && entradas.read_input(S1)==LOW && entradas.read_input(S0)==LOW){// si es 4 en binario
  caso=4;
  return caso;
 }
  if (entradas.read_input(S2)==LOW && entradas.read_input(S1)==HIGH && entradas.read_input(S0)==HIGH){// si es 3 en binario
  caso=3;
  return caso;
 }
  if (entradas.read_input(S2)==LOW && entradas.read_input(S1)==HIGH && entradas.read_input(S0)==LOW){// si es 2 en binario
  caso=2;
  return caso;
 }
  if (entradas.read_input(S2)==LOW && entradas.read_input(S1)==LOW && entradas.read_input(S0)==HIGH){// si es 1 en binario
  caso=1;
  return caso;
 }
return caso;// si es 0 en binario, ninguno esta activo
 }
 
