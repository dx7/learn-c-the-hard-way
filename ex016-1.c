#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

struct Person {
  int age;
  char *name;
};

struct Person *Person_create(char *name, int age)
{
  struct Person *person = malloc(sizeof(struct Person));

  assert(person != NULL);

  person->name = strdup(name);
  person->age = age;

  printf("3 %p\n", person->name);

  return person;
}

void Person_destroy(struct Person *person)
{
  assert(person != NULL);

  free(person->name);
  free(person);
}

int main(int argc, char *argv[])
{
  struct Person *person = Person_create("Rafael", 30);

  printf("%s\n", person->name);

  Person_destroy(person);

  printf("%s\n", person->name);

  puts("Done.");

  return 0;
}
