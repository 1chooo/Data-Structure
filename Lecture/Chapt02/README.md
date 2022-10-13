# Chapter02 - Arrays and Structures

## Arrays

<index, value>

## Structures and Unions

permits the data to vary in type.

``` c
/* Both are the same */

typedef struct humanBeing {
  char name[10];
  int age;
  float salary;
};

typedef struct {
  char name[10];
  int age;
  float salary;
} humanBeing;
```