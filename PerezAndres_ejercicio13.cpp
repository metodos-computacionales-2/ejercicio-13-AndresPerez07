#include <iostream>
using namespace std;
float *mult(float *matriz1,float *matriz2,int filas1, int filas2, int cols1, int cols2);
void imprime (float *matriz, int filas, int cols);
float *nilpotente (int n);
int main(int argc, char const *argv[]) {
  int n = atoi(argv[1]);
  int filas1 = 3;
  int cols1 = 1;
  int filas2 = 1;
  int cols2 = 3;
  float *matriz1 = new float [filas1*cols1];
  float *matriz2 = new float [filas2*cols2];
  float *producto = new float [filas1*cols2];
  float *nilpo = new float [n*n];

  matriz1[0*cols1+0] = 1;
  matriz1[1*cols1+0] = 2;
  matriz1[2*cols1+0] = 3;
  matriz2[0*cols2+0] = 1;
  matriz2[0*cols2+1] = 2;
  matriz2[0*cols2+2] = 3;

  producto = mult(matriz1, matriz2, filas1, filas2, cols1, cols2);
  //imprime(producto, filas1, cols2);
  nilpo = nilpotente(n);
  imprime(nilpo,n,n);
  delete [] matriz1;
  delete [] matriz2;
  delete [] producto;
  delete [] nilpo;
  return 0;
}
float *mult(float *matriz1,float *matriz2,int filas1, int filas2, int cols1, int cols2){
  if (cols1 != filas2){
    cout << "No se puede hacer perro" << endl;
  }
  float *resultado = new float[filas1*cols2];
  for (size_t i = 0; i < filas1; i++) {
    for (size_t k = 0; k < cols2; k++) {
      float suma = 0;
      for (size_t j = 0; j < cols1; j++) {
        suma = suma + matriz1[i*cols1+j]*matriz2[j*cols2+k];
        // cout << suma << endl;
      }
      resultado[i*cols2+k]=suma;
      // cout << resultado[i*cols2+k] << endl;
    }
  }
  return resultado;
}
void imprime (float *matriz, int filas, int cols){
  for (size_t i = 0; i < filas; i++) {
    for (size_t j = 0; j < cols; j++) {

      if (j==cols-1){
        cout << " " << matriz[i*cols+j] << endl;
      }
      else {
          cout << " " << matriz[i*cols+j];
      }
    }
  }
}
float *nilpotente (int n){
  float *matriznil = new float(n*n);
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      if (i==0){

        if (j== n-1){
          matriznil[i*n+j] = 1-n;
        }
        else {
        matriznil[i*n+j] = 2;

        }
      }
      else {
        if (j== i-1){
          matriznil[i*n+j]= n+2;
        }
        else {
          if(j==n-1){
            matriznil[i*n+j] = -n;
          }
          else{
            matriznil[i*n+j] = 1;
          }
        }
      }
    }
  }
  return matriznil;
}
