#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <pwd.h>

int main(void)
{
   pid_t id_proceso;
   pid_t id_padre;
   struct utsname uname_data;
   struct passwd *pw;
   struct sysinfo sys_info;

   id_proceso = getpid();
   id_padre = getppid();
   uname(&uname_data);
   pw = getpwuid(getuid());
   sysinfo(&sys_info);

   printf("Identificador de proceso: %d\n", id_proceso);
   printf("Identificador del proceso padre: %d\n", id_padre);
   printf("Nombre del host: %s\n", uname_data.nodename);
   printf("Nombre de usuario: %s\n", pw->pw_name);
   printf("Versión del sistema operativo: %s %s\n", uname_data.sysname, uname_data.release);
   printf("Arquitectura del hardware: %s\n", uname_data.machine);
   printf("Memoria total del sistema: %lu KB\n", sys_info.totalram / 1024);

   return 0;
}
