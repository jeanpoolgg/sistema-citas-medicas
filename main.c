#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 100

struct Paciente {
  char seguroSocial[20];
  char nombreCompleto[100];
  char direccion[100];
  char fechaNacimiento[11]; // Formato DD/MM/AAAA
  char sexo;
  char telefono[15];
};

struct Paciente pacientes[MAX_PACIENTES];
int numPacientes = 0;

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

int main(void)
{
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
  }


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

  }

  void cancelarCita(){

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

  }
  void reporteMes() {

  }

  void salir(){
    printf("DATOS GUARDADOS.\n");
  }


}
