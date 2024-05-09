#include "Table.h"
#include "TableRecord.c"

//Table creation
Table *createTable(char *scopeId) {
  int i;
  Table* table = malloc(sizeof(Table));
  table->size = 1;
  table->index = -1;
  table->records = malloc(sizeof(TableRecord **));
  if (scopeId != NULL){
      table->scopeId = malloc(sizeof(char*) * strlen(scopeId) + 1);
      strcpy(table->scopeId, scopeId);
  }
  return table;
}

//Table deletion
void deleteTable(Table *table) {
  int i;
  for (i = 0; i <= table->index; i++) {
    if (table->records[i] != NULL) {
      deleteRecord(table->records[i]);
    }
  }
  free(table->records);
  if (table->scopeId != NULL){
      free(table->scopeId);
  }
  free(table);
}

//Add to Table
void addRecordToTable(Table *table, int type, char *lexicalValue, int attribute, char *declaredInScope){

  if (table->index == table->size - 1) {

    table->size = (table->size) * 2;
    table->records =
        realloc(table->records, sizeof(TableRecord **) * (table->size));
  }

  table->records[++table->index] = createRecord(type, lexicalValue, attribute, declaredInScope);
}

//Get from Table
TableRecord *getRecordFromTable(Table *table, char *lexicalValue) {
  int i;

  for (i = 0; i <= table->index; i++) {
    if (strcmp(lexicalValue, table->records[i]->lexicalValue) == 0) {
      return table->records[i];
    }
  }

  return NULL;
}
