#ifndef SETUP_H_
#define SETUP_H_


enum setupState
{
    OK,
    INIT_SETUP_ERROR,
    DISABLE_COM_ERROR,
    SETUP_FAILED
};


int Init_Setup();
int disableCommunication();

#endif
