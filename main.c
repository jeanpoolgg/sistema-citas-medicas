#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 100
#define MAX_CITAS 100

struct Paciente {
  char seguroSocial[20];
  char nombreCompleto[100];
  char direccion[100];
  char fechaNacimiento[11]; // Formato DD/MM/AAAA
  char sexo;
  char telefono[15];
};

struct Cita {
    int numeroCita;
    char fecha[11]; // Formato DD/MM/AAAA
    char hora[6];    // Formato HH:MM
    char nombrePaciente[100];
};

struct Paciente pacientes[MAX_PACIENTES];
struct Cita citas[MAX_CITAS];
int numPacientes = 0;
int numCitas = 0;

void menuPrincipal();

void subMenuCitas();
void subMenuMantenimiento();
void subMenuReportes();
void salir();

void citas();
void agregarCita();
void cancelarCita();

void mantenimiento();
void agregarPaciente();
void borrarPaciente();
void actualizarPaciente();
void consultarPaciente();

void reportes();
void reporteDiario();
void reporteSemana();
void reporteMes();

int main(void) {
  int opcion;
  menuPrincipal();
  scanf("%d", &opcion);

  while (opcion != 4) {
    switch (opcion) {
      case 1:
        citas();
        break;
      case 2:
        mantenimiento();
        break;
      case 3:
        reportes();
        break;
      default:
        printf("Opcion no disponible.\n");
    }
    menuPrincipal();
    scanf("%d", &opcion);
  }
  salir();
  printf("==== FIN DEL PROGRAMA ====.\n");
  return 0;


  /* ======================= MENUS ==================== */


  void menuPrincipal() {
    printf("\n\n*** CONSULTORIO VIDA SANA *** \n1. Citas.\n2. Mantenimiento.\n3. Reportes.\n4. Salir.\n\nEscriba su seleccion: ");
  }

  void subMenuCitas() {
    printf("\n\n-- CITAS -- \n1. Agregar cita.\n2. Cancelar cita.\n3. Retroceder.\n\nEscriba su seleccion: ");
  }

  void subMenuMantenimiento(){
    printf("\n\n-- MANTENIMIENTO -- \n1. Agregar paciente.\n2. Borrar paciente.\n3. Actualizar paciente.\n4. Consultar paciente.\n5. Retroceder.\n\nEscriba su seleccion: ");
  }

  void subMenuReportes(){
    printf("\n\n-- REPORTES -- \n1. Por dia.\n2. Por semana.\n3. Por mes.\n4. Retroceder.\n\nEscriba su seleccion: ");
  }


  /* ======================= CITAS ==================== */


  void citas(){
    int opcion;
    subMenuCitas();
    scanf("%d", &opcion);

    while (opcion != 3) {
      switch (opcion) {
        case 1:
          agregarCita();
          break;
        case 2:
          cancelarCita();
          break;
        default:
          printf("Opcion no disponible.\n");
      }
      subMenuCitas();
      scanf("%d", &opcion);
    }
  }

  void agregarCita(){
    if (numCitas >= MAX_CITAS) {
      printf("No se pueden agregar más citas. Se ha alcanzado el límite máximo.\n");
      return;
    }
    struct Cita nuevaCita;
    printf("\n--- AGREGAR CITA ---\n");
    printf("Ingrese el número de cita: ");
    scanf("%d", &nuevaCita.numeroCita);
    printf("Ingrese la fecha de la cita (DD/MM/AAAA): ");
    scanf("%s", nuevaCita.fecha);
    printf("Ingrese la hora de la cita (HH:MM): ");
    scanf("%s", nuevaCita.hora);
    printf("Ingrese el nombre completo del paciente: ");
    getchar(); // Limpiar el buffer de entrada
    fgets(nuevaCita.nombrePaciente, sizeof(nuevaCita.nombrePaciente), stdin);
    nuevaCita.nombrePaciente[strcspn(nuevaCita.nombrePaciente, "\n")] = '\0';

    citas[numCitas++] = nuevaCita;
    printf("Cita agregada exitosamente.\n");
  }

  void cancelarCita(){
    if (numCitas == 0) {
      printf("No hay citas para cancelar.\n");
      return;
    }
    int numCita;
    printf("\n--- CANCELAR CITA ---\n");
    printf("Ingrese el número de cita a cancelar: ");
    scanf("%d", &numCita);

    int encontrado = 0;
    for (int i = 0; i < numCitas; i++) {
      if (citas[i].numeroCita == numCita) {
        for (int j = i; j < numCitas - 1; j++) {
            citas[j] = citas[j + 1];
        }
        encontrado = 1;
        numCitas--;
        printf("Cita cancelada exitosamente.\n");
        break;
      }
    }
    if (!encontrado) {
      printf("No se encontró ninguna cita con ese número.\n");
    }
  }


  /* ======================= MANTENIMIENTO ==================== */

  void mantenimiento() {
    int opcion;
    subMenuMantenimiento();
    scanf("%d", &opcion);

    while (opcion != 5) {
      switch (opcion) {
        case 1:
          agregarPaciente();
          break;
        case 2:
          borrarPaciente();
          break;
        case 3:
          actualizarPaciente();
          break;
        case 4:
          consultarPaciente();
          break;
        default:
          printf("Opcion no disponible.\n");
      }
      subMenuMantenimiento();
      scanf("%d", &opcion);
    }
  }

  void agregarPaciente(){
  }

  void borrarPaciente(){

  }

  void actualizarPaciente() {

  }

  void consultarPaciente() {

  }


  /* ======================= REPORTES ==================== */

  void reportes() {
    int opcion;
    subMenuReportes();
    scanf("%d", &opcion);

    while (opcion != 4) {
      switch (opcion) {
        case 1:
          reporteDiario();
          break;
        case 2:
          reporteSemana();
          break;
        case 3:
          reporteMes();
          break;
        default:
          printf("Opcion no disponible.\n");
      }
      subMenuReportes();
      scanf("%d", &opcion);
    }
  }

  void reporteDiario() {

  }

  void reporteSemana() {
    printf("\n--- REPORTE SEMANAL ---\n");
    // Aquí puedes agregar la lógica para generar el reporte semanal de citas
  }

  void reporteMes() {
    printf("\n--- REPORTE MENSUAL ---\n");
    // Aquí puedes agregar la lógica para generar el reporte mensual de citas
  }

  void salir(){
    printf("DATOS GUARDADOS.\n");
  }

}
