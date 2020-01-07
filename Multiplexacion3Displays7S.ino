int retardo=10;       // tiempo que dura encendido cada 7 seg (10 mili segundos)
int var=0;            // Valor del digito que se va a desplegar por el 7 seg.

int unidad=0;         // cuenta las unidades (derecha)
int decena=0;         // cuenta las decenas (centro)
int centena=0;        // cuenta las centenas (izquierda)
int conmutador=0;     // multiplexacion de uno a otro 7 segmentos
int conmutador2=0;    // multiplexacion de uno a otro 7 segmentos
int conmutador3=0;    // multiplexacion de uno a otro 7 segmentos

int cont=0;           // contador de ciclos de espera para cambiar de numero

void setup() {               
  pinMode(0, OUTPUT);  //seg a
  pinMode(1, OUTPUT);  //seg b
  pinMode(2, OUTPUT);  //seg c
  pinMode(3, OUTPUT);  //seg d
  pinMode(4, OUTPUT);  //seg e
  pinMode(5, OUTPUT);  //seg f
  pinMode(6, OUTPUT);  //seg g
  
  pinMode(8, OUTPUT);  // activa digito 1 derecha (unidad)
  pinMode(9, OUTPUT);  // activa digito 2 izquierda (decena)
  pinMode(10,OUTPUT);

    
}

void loop() {
  
 delay(retardo);               // tiempo que dura encendido cada 7seg antes de cambiar al otro

 cont++;                      // incrementa el contador de ciclos en Uno
 if (cont==100){              // cada cuanto tiempo (ciclos)cambia un numero
      cont=0;                 // inicializa el contador de ciclos   
    unidad=unidad+1;          // incrementa la unidad, primer 7seg
    if (unidad >= 10){        // cuando la unidad llegue a 10 incrementa la decena 
        decena=decena+1;      // incrementa la decena,  segundo 7seg
      unidad=0;               // regresa la unidad a cero
      if (decena>=6){        // cuando la decena llegue a 10 se inicializa a cero    
        centena=centena+1;
      decena=0;
        if(centena>=10) {
      centena=0;
        }
      }      
    }
 }

    //Proceso de multiplexacion entre cada display
    if(conmutador == 0){
      digitalWrite(8, 0);   
      digitalWrite(9, 1); 
      digitalWrite(10, 1);
      var=unidad;
      conmutador=1;

     
      }else{
        if(conmutador == 1){
      digitalWrite(8, 1);   
      digitalWrite(9, 0); 
      digitalWrite(10, 1);
      var=decena;
      conmutador=2;
        }else{
        digitalWrite(8, 1);   
        digitalWrite(9, 1); 
        digitalWrite(10, 0);
        var=centena;
        conmutador=0;
        }
    
      }
     

    switch (var) {
    case 1:                 //escribe en el 7seg el numero 1
      digitalWrite(0, 0);
      digitalWrite(1, 1);
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
     break;
    case 2:                //escribe en el 7seg el numero 2
      digitalWrite(0, 1);
      digitalWrite(1, 1);
      digitalWrite(2, 0);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 0);
      digitalWrite(6, 1);
     break;      
    case 3:               //escribe en el 7seg el numero 3
       digitalWrite(0, 1);
       digitalWrite(1, 1);
       digitalWrite(2, 1);
       digitalWrite(3, 1);
       digitalWrite(4, 0);
       digitalWrite(5, 0);
       digitalWrite(6, 1);
      break;
    case 4:               //escribe en el 7seg el numero 4
      digitalWrite(0, 0);
      digitalWrite(1, 1);
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
     break;
    case 5:               //escribe en el 7seg el numero 5
      digitalWrite(0, 1);
      digitalWrite(1, 0);
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
     break;
    case 6:               //escribe en el 7seg el numero 6
      digitalWrite(0, 1);
      digitalWrite(1, 0);
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
     break;
    case 7:              //escribe en el 7seg el numero 7
      digitalWrite(0, 1);
      digitalWrite(1, 1);
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 0);
      digitalWrite(6, 0);
     break;
    case 8:              //escribe en el 7seg el numero 8
      digitalWrite(0, 1);
      digitalWrite(1, 1);
      digitalWrite(2, 1);
      digitalWrite(3, 1);
      digitalWrite(4, 1);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      break;
    case 9:               //escribe en el 7seg el numero 9
      digitalWrite(0, 1);
      digitalWrite(1, 1);
      digitalWrite(2, 1);
      digitalWrite(3, 0);
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
     break;
    case 0:                //escribe en el 7seg el numero 0
       digitalWrite(0, 1);
       digitalWrite(1, 1);
       digitalWrite(2, 1);
       digitalWrite(3, 1);
       digitalWrite(4, 1);
       digitalWrite(5, 1);
       digitalWrite(6, 0);
      break;
           
    default: 
       digitalWrite(0, 0);
       digitalWrite(1, 0);
       digitalWrite(2, 0);
       digitalWrite(3, 0);
       digitalWrite(4, 0);
       digitalWrite(5, 0);
       digitalWrite(6, 0);
      
  }
  
 }
