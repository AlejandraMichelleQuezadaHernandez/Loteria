#include <ctime>
#include <iostream>
using namespace std;

struct Jugador {
  string Nombre;
  int edad;
};

void RegistrarPersona(struct Jugador jugador);
void DibujoMatriz();
double Factorial(int x);
double CalcularProbabilidad(int &adivino);

int main() {
  int opcion;
  Jugador jugador;
  // Sirve para inicializar el random.
  srand(time(0));

  cout << "Bienvenidos a la loteria discreta" << endl;
  RegistrarPersona(jugador);

  do {
    cout << endl;
    cout << "1-Reglas del juego" << endl;
    cout << "2-Jugar la loteria" << endl;
    cout << "3-Nombre de las integrantes" << endl;
    cout << "4-Salir" << endl;
    cout << "Ingrese su opcion: " << endl;
    cin >> opcion;
    switch (opcion) {
      case 1:
        cout << "1- Se registra el nombre del participante a jugar." << endl;
        cout << "2-La computadora indicara numeros al azar en cada cuadrante. "
                "(Dentro del rango de 1-25)"
             << endl;
        cout
            << "3-Ingresar el numero a adivinar que se encuentra en la loteria."
            << endl;
        cout << "4-Se le mostrar la probabilidad de ganar a medida se ingresan "
                "los numeros."
             << endl;
        cout << "5-Tambien ganara cierta cantidad de dinero si adivina el "
                "numero e ira incrementando en $25."
             << endl;
        cout << "6-Para ganar, debera adivinar tres numeros en toda la matriz."
             << endl;
        break;
      case 2:
        DibujoMatriz();
        break;
      case 3:
        cout << "Alisson Alessandra Villacorta Salazar - 00062224" << endl;
        cout << "Andrea Yesenia Turcios Aparicio - 00042524" << endl;
        cout << "Alejandra Michelle Quezada Hernandez - 00066224" << endl;
        cout << "Sofia Stephanie Recinos Barrera - 00010124" << endl;
        break;
      case 4:
        cout << "Gracias por jugar :))" << endl;
        break;
      default:
        break;
    }
  } while (opcion != 4);

  return 0;
}

void RegistrarPersona(struct Jugador jugador) {
  cout << "\nIngrese su nombre: ";
  cin.ignore();
  getline(cin, jugador.Nombre);
  cout << "\nIngrese su edad: ";
  cin >> jugador.edad;
}

void DibujoMatriz() {
  int adivinar[3][3];
  int mostrar[3][3] = {0};
  int matriz[3][3];
  int intentos = 0, adivino = 0, fallo = 0;
  int numero;
  int monedas = 0;
  bool encontrado = false;
  float probablidad = 0;
  double num;
  // modificacion
  int numarre[9];
  int cont = 0;
  int numgenerado = 0;
  bool datos_repetidos = true;
  bool num_repetido = false;

  numgenerado = rand() % 25 + 1;
  numarre[cont] = numgenerado;

  do {
    numgenerado = rand() % 25 + 1;
    if ((cont == 0) & (numgenerado != numarre[cont])) {
      cont = cont + 1;
      numarre[cont] = numgenerado;
      datos_repetidos = false;
    } else {
      datos_repetidos = false;
      for (int i = 0; i <= cont; i++) {
        if (numarre[i] == numgenerado) {
          datos_repetidos = true;
        }
      }
      if (datos_repetidos == false) {
        cont = cont + 1;
        numarre[cont] = numgenerado;
        datos_repetidos = false;
      }
    }
  } while ((datos_repetidos = false) || (cont < 8));

  cont = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      // Para prueba
      adivinar[i][j] = numarre[cont];
      cont = cont + 1;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (mostrar[i][j] != 0) {
        cout << mostrar[i][j] << '\n';
      } else {
        cout << " x ";
      }
    }
    cout << endl;
  }

  do {
    cout << endl;
    cout << "Ingrese un numero del 1 al 25: ";
    cin >> numero;
    num_repetido = false;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (mostrar[i][j] == numero) {
          num_repetido = true;
          break;
        }
      }
      if (num_repetido) {
        break;
      }
    }

    if (num_repetido) {
      cout << "Numero repetido, ingrese uno nuevamente.\n";
      continue;
    }

    if (numero < 1 || numero > 25) {
      cout << "Intenta de nuevo con numeros dentro del rango." << endl;
      continue;
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if ((adivinar[i][j] == numero)) {
          num_repetido = false;
          encontrado = true;
          mostrar[i][j] = numero;
          monedas += 25;
          adivino++;
        } else {
          fallo++;
        }
      }
    }

    if (encontrado == true) {
      cout << "Adivinaste el numero" << endl;
      cout << "Monedas ganadas: $" << monedas << endl;
      num = CalcularProbabilidad(adivino);
      encontrado = false;
    } else {
      cout << "No adivinaste el numero" << endl;
      cout << "Saldo actual: $" << monedas << endl;
      num = CalcularProbabilidad(adivino);
    }

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (mostrar[i][j] != 0) {
          cout << mostrar[i][j] << " ";
        } else {
          cout << "x ";
        }
      }
      cout << endl;
    }

    intentos++;
  } while (intentos < 3);
    if (adivino == 3)
    {
        cout << "Felicidades, adivinaste el numero en 3 intentos" << endl;
    }else{
        cout <<"Perdiste :(, intentalo de nuevo."<<endl;
    }
    
    
    
  cout << endl;
  cout << "Loteria completa: " << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << adivinar[i][j] << "  ";
    }
    cout << endl;
  }
}

double Factorial(int x) {
  if (x == 0) {
    x = 1;
    return x;
  }
  if (x == 1) {
    return x;
  } else {
    return x * Factorial(x - 1);
  }
}

double CalcularProbabilidad(int &adivino) {
  double probabilidad_total = 0;
  double multiplicacion = 0;

  double denominador1 = Factorial(25) / (Factorial(3) * Factorial(25 - 3));
  if (denominador1 == 0) {
    cout << "Error: Denominador es cero, no se puede calcular la probabilidad."
         << endl;
    return 0;
  }

  if (adivino == 0) {
    double numerador1 = Factorial(16) / (Factorial(3) * Factorial(16 - 3));
    probabilidad_total = numerador1 / denominador1;
    cout << "La probabilidad de adivinar 0 numeros es: " << probabilidad_total
         << '\n';
  } else if (adivino == 1) {
    double numerador1 = Factorial(16) / (Factorial(2) * Factorial(16 - 2));
    double numerador2 = Factorial(9) / (Factorial(9 - 1) * Factorial(1));
    multiplicacion = (numerador1 * numerador2);
    probabilidad_total = multiplicacion / denominador1;
    cout << "La probabilidad de adivinar 1 numero es: " << probabilidad_total
         << '\n';
  } else if (adivino == 2) {
    double numerador1 = Factorial(16) / (Factorial(1) * Factorial(16 - 1));
    double numerador2 = Factorial(9) / (Factorial(9 - 2) * Factorial(2));
    multiplicacion = (numerador1 * numerador2);
    probabilidad_total = multiplicacion / denominador1;

    cout << "La probabilidad de adivinar 2 numeros es: " << probabilidad_total
         << '\n';
  } else if (adivino == 3) {
    double numerador1 = Factorial(9) / (Factorial(9 - 3) * Factorial(3));
    probabilidad_total = numerador1 / denominador1;
    cout << "La probabilidad de adivinar 3 numeros es: " << probabilidad_total
         << '\n';
  }

  return probabilidad_total;
}