#ifndef TABLE_RECORD
#define TABLE_RECORD

typedef struct {
  int type;
  int attribute;
  char *lexicalValue;
  char *declaredInScope;
}TableRecord;

TableRecord *createRecord(int type, char *lexicalValue, int attribute, char *declaredInScope);
void deleteRecord(TableRecord *record);

#endif
