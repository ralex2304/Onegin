#include "statuses.h"

Status::Statuses Status::raise(const Statuses status) {
    switch (status) {
        case NORMAL_WORK:
            assert(0 && "Status::raise(): NORMAL_WORK mustn't be raised");
            break;
        case ARGS_ERROR:
            printf("Exiting. Args error\n");
            break;
        case FILE_ERROR:
            printf("Exiting. File error\n");
            break;
        case MEMORY_EXCEED:
            printf("Exiting. Not enough memory\n");
        case OK_EXIT:
        case DEFAULT:
            break;
        default:
            assert(0 && "Error::raise(): wrong error");
            break;
    };
    return status;
}
