//
// Created by Justin on 14/01/2019.
//

#include "../includes/OS.h"
#include "Arduino.h";
OS_new(char *name, char *version){
    OS *os = malloc(sizeof(OS));
    if(os) {
        os->nameOS = name;
        os->versionOS = version;
    }
}

OS_print(OS *os){
    Serial.println("Welcome on %s, version : %s", os->nameOS? os->versionOS);
}