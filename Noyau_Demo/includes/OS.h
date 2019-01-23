//
// Created by Justin on 10/01/2019.
//

#ifndef NOYAU_FIFO_H
#define NOYAU_FIFO_H

#include "./FIFO.h"
#include "./ProcessDescriptor.h"

typedef struct {
    char *nameOS;
    char *versionOS;

    ProcessDescriptor *actifProcess;
    FIFO *listProcessDescriptor;
    FIFO *queueExploitation;
} OS;

OS* OS_new(char *name, char*version);
void OS_print(OS *os);

#endif //FIFO_H
