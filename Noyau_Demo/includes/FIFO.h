//
// Created by Justin on 10/01/2019.
//

#ifndef NOYAU_FIFO_H
#define NOYAU_FIFO_H

#include "ProcessDescriptor.h"

typedef struct {

    /*int head,
    int queue,*/
//    ProcessDescriptor content[NB_PROCESS];
    int count;
    int actifProcessIndice;
} FIFO;



#endif //FIFO_H
