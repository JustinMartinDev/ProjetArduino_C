//
// Created by Justin on 10/01/2019.
//

#ifndef NOYAU_PROCESSDESCRIPTOR_H
#define NOYAU_PROCESSDESCRIPTOR_H

typedef struct {

    int pid,
    int priority, //[0,255]
    int status,

    long int* ptrPile,
    long int* ptrPileWrittable,
    void* ptrProcess
    void* listArg
//    int pos;

} ProcessDescriptor;



#endif //NOYAU_PROCESSDESCRIPTOR_H
