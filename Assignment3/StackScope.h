#ifndef STACK_SCOPE
#define STACK_SCOPE

#include "Table.h"

typedef struct {
  int index;
  int size;
  Table **stackItems;
} StackScope;

void createStackScope(StackScope *stack);

Table *pushToStackScope(StackScope *stack, char* scopeId);
Table *popFromStackScope(StackScope *stack);
Table *getFromStackScope(StackScope *stack, char* scopeId);

void deleteStackScope(StackScope *stack);
TableRecord *searchRecordInStackScope(StackScope *stack, char * lexicalValue);

#endif
