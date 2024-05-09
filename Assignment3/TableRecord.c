#include "TableRecord.h"

//Record creation
TableRecord* createRecord(int type, char *lexicalValue, int attribute, char *declaredInScope){
  TableRecord *record = malloc(sizeof(TableRecord));

  record->type = type;
  record->attribute = attribute;
  record->lexicalValue = malloc(sizeof(char*) * strlen(lexicalValue) + 1);
  strcpy(record->lexicalValue, lexicalValue);
  record->declaredInScope = malloc(sizeof(char*) * strlen(declaredInScope) + 1);
  strcpy(record->declaredInScope, declaredInScope);

  return record;
}

//Record deletion
void deleteRecord(TableRecord *record)
{
  free(record->lexicalValue);
  free(record->declaredInScope);
}
