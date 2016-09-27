#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

int main(int argc, char *argv[])
{
	int stdout = 1;
	char *fmt = "%d  %d  %d  %s\n";
	if (argc > 1) {
		printf(stdout, "Usage: ps\n");
		exit();
	}

    struct ProcessInfo processInfoTable[NPROC];
    int numProcessesGotten = getprocs(processInfoTable);

    // printf(stdout, "Num processes: %d\n", numProcessesGotten);
    for (int i = 0; i < numProcessesGotten; i++) {

        char name[16];
        strcpy(name, processInfoTable[i].name);
        int ppid = -1;
        if (strcmp(name, "init") != 0) {
            ppid = processInfoTable[i].ppid;
        }
        int state = processInfoTable[i].state;
        int sz = processInfoTable[i].sz;
    	printf(stdout, fmt, ppid, state, sz, processInfoTable[i].name);
    }

	exit();
}
