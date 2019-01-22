//
// Created by Justin on 10/01/2019.
//

#ifndef NOYAU_FIFO_H
#define NOYAU_FIFO_H

#include "./FIFO.h"
#include "ProcessDescriptor.h"

typedef struct {
    char* OSName,
    char* VersionOS,
    FIFO* listProcessDescriptor,
    FIFO* queueExploitation,
    ProcessDescriptor* actifProcess,
} OS;



#endif //FIFO_H
