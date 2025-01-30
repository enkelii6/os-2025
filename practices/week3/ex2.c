#include <stdio.h>
#include <x86intrin.h>

int main(void) {
    int cpuInfo[4] = {0};

    __cpuid(cpuInfo, 0);
    if (cpuInfo[0] >= 0x16) {
        // Get processor frequency information
        __cpuid(cpuInfo, 0x16);

        /* Example values from Intel Core i7-6700K:
         * EAX = 0x00000FA0 (4000 MHz base frequency)
         * EBX = 0x00001068 (4200 MHz max frequency) 
         * ECX = 0x00000064 (100 MHz bus frequency)
         */

        printf("Register values:\n");
        printf("  EAX: 0x%08x\n", cpuInfo[0]);
        printf("  EBX: 0x%08x\n", cpuInfo[1]); 
        printf("  ECX: 0x%08x\n\n", cpuInfo[2]);

        printf("CPU Frequencies:\n");
        printf("  Base:      %4d MHz\n", cpuInfo[0]);
        printf("  Maximum:   %4d MHz\n", cpuInfo[1]);
        printf("  Bus/Ref:   %4d MHz\n", cpuInfo[2]);
    } else {
        printf("Error: CPUID level 0x16 not supported on this processor\n");
    }

    return 0;
}
