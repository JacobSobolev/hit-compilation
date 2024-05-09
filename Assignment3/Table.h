#ifndef TABLE
#define TABLE

#include "TableRecord.h"

typedef struct {
  char* scopeId;
  int size;
  int index;
  TableRecord **records;
} Table;

Table *createTable(char *scopeId);
void deleteTable(Table *table);

void addRecordToTable(Table *table, int type, char *lexicalValue, int attribute, char *declaredInScope);
TableRecord *getRecordFromTable(Table *table, char *lexicalValue);

#endif
