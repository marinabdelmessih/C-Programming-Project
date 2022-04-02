#ifndef SIMPLEDB_H_INCLUDED
#define SIMPLEDB_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#include "Std_datatypes.h"
#include "SDB_defined_datatypes.h"


Boolean SDB_IsFull(void);
u8 SDB_GetUsedSize(void);
Boolean SDB_AddEntry(u8 id,u8 year,u8 *subjects,u8 *grades);
void SDB_DeleteEntry(u8 id);
Boolean SDB_ReadEntry(u8 id,u8 *year,u8 *subjects,u8 *grades);
void SDB_GetIdList(u8 *counter,u8 *arr);
Boolean SDB_IsIdExist(u8 id);
void print_database(void);

#endif // SIMPLEDB_H_INCLUDED
