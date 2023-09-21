#include "grade_school.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void init_roster(roster_t *roster) { roster->count = 0; }

int compare_students(const void *a, const void *b) {
  const student_t *s1 = a;
  const student_t *s2 = b;

  if (s1->grade < s2->grade)
    return -1;
  else if (s1->grade > s2->grade)
    return 1;
  return strcmp(s1->name, s2->name);
}

bool add_student(roster_t *roster, char *name, uint8_t grade) {
  if (roster->count >= MAX_STUDENTS)
    return false;

  for (size_t i = 0; i < roster->count; i++) {
    if (strcmp(roster->students[i].name, name) == 0)
      return false;
  }

  strcpy(roster->students[roster->count].name, name);
  roster->students[roster->count].grade = grade;
  roster->count++;

  qsort(&roster->students, roster->count, sizeof(student_t), compare_students);

  return true;
}
roster_t get_grade(roster_t *roster, uint8_t grade) {
  roster_t grade_r = {.count = 0};

  for (size_t i = 0; i < roster->count; i++) {
    student_t *s = &roster->students[i];
    if (s->grade == grade) {
      memcpy(&grade_r.students[grade_r.count], s, sizeof(student_t));
      grade_r.count++;
    }
  }
  return grade_r;
}
