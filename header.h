#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define MAX_WORDS 1024
#define SEPARATOR " \n\t"

extern char **environ;
char *leerEntrada();
char **split(const char *textoEntrada, int *cantidadPalabras);
void imprimirEnv(void);
char *pathEnv(char *comando);
void ejecutarComando(char **listaPalabras);
void limpiarMemoria(char *buffer, char **listaPalabras);
char *_obtenerEnv(const char *nombre);

#endif
