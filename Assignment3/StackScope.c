#include "StackScope.h"
#include "Table.c"

//Stack creation 
void createStackScope(StackScope *stack) {
  stack->size = 1;
  stack->index = -1;
  stack->stackItems =  malloc(sizeof(Table **));
}

//Stack Push implementation
Table *pushToStackScope(StackScope *stack, char* scopeId) {
  if (stack->index == stack->size - 1) {
    stack->size = stack->size * 2;
    stack->stackItems =
        realloc(stack->stackItems, sizeof(Table **) * (stack->size));
  }

  stack->stackItems[++stack->index] = createTable(scopeId);

  return stack->stackItems[stack->index];
}

//Stack Pop implementation
Table *popFromStackScope(StackScope *stack) {
  int i = stack->index;
  if (i >= 0) {
    if (stack->stackItems[i] != NULL) {
      deleteTable(stack->stackItems[i]);
    }
    stack->index--;
    if (stack->index > 0 && (stack->size / (stack->index + 1)) >= 2) {
      stack->size = stack->size / 2;
      stack->stackItems =
          realloc(stack->stackItems, sizeof(Table **) * (stack->size));
    }
    if (stack->index >= 0){
      return stack->stackItems[stack->index];
    }
  }
  return NULL;
}

//Delete from Stack
void deleteStackScope(StackScope *stack) {
  int i;

  for (i = stack->index; i >= 0; i--) {
    popFromStackScope(stack);
  }
  free(stack->stackItems);
}

//Search in Stack
TableRecord *searchRecordInStackScope(StackScope *stack, char *lexicalValue){
  TableRecord *record = NULL;
  int i;
  for (i = stack->index; i >= 0 && record == NULL; i--) {
    record = getRecordFromTable(stack->stackItems[i], lexicalValue);
  }

  return record;
}

//Get from Stack
Table *getFromStackScope(StackScope *stack, char* scopeId){
  Table *table = NULL;
  int i;
  for (i = stack->index; i >= 0 && table == NULL; i--) {
    if (strcmp(scopeId, stack->stackItems[i]->scopeId) == 0){
      table = stack->stackItems[i];
    }
  }

  return table;
}
