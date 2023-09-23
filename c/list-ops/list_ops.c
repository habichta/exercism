#include "list_ops.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]) {

  size_t listRequiredMemory = sizeof(list_t) + length * sizeof(list_element_t);
  list_t *list = (list_t *)malloc(listRequiredMemory);

  list->length = length;

  for (size_t i = 0; i < length; i++) {
    list->elements[i] = elements[i];
  }

  return list;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2) {

  size_t lengthL1 = list1->length;
  size_t lengthL2 = list2->length;
  size_t length = lengthL1 + lengthL2;

  size_t listRequiredMemory = sizeof(list_t) + length * sizeof(list_element_t);
  list_t *list = (list_t *)malloc(listRequiredMemory);

  list->length = length;

  for (size_t i = 0; i < lengthL1; i++) {
    list->elements[i] = list1->elements[i];
  }

  for (size_t i = 0; i < lengthL2; i++) {
    list->elements[lengthL1 + i] = list2->elements[i];
  }

  return list;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
  size_t length = list->length;

  list_element_t filteredListElements[length];
  size_t validCount = 0;
  for (size_t i = 0; i < length; i++) {
    bool valid = filter(list->elements[i]);
    if (valid) {
      filteredListElements[validCount] = list->elements[i];
      validCount++;
    }
  }

  return new_list(validCount, filteredListElements);
}

// returns the length of the list
size_t length_list(list_t *list) { return list->length; }

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {

  size_t length = list->length;

  list_element_t mappedValues[length];
  for (size_t i = 0; i < length; i++) {
    mappedValues[i] = map(list->elements[i]);
  }

  return new_list(length, mappedValues);
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {

  size_t length = list->length;

  list_element_t result = initial;
  for (size_t i = 0; i < length; i++) {
    result = foldl(result, list->elements[i]);
  }

  return result;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {

  size_t length = list->length;

  list_element_t result = initial;
  for (size_t i = 1; i <= length; i++) {
    result = foldr(list->elements[length - i], result);
  }

  return result;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list) {

  size_t length = list->length;

  list_element_t mappedValues[length];
  for (size_t i = 1; i <= length; i++) {
    mappedValues[length - i] = list->elements[i - 1];
  }

  return new_list(length, mappedValues);
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list) { free(list); }
