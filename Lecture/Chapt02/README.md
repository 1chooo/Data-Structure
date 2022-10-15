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

`struct {int i, j; flaot a, b;};` `struct {int i; int j; flaot a; float b;};`

### Self-Referential Structure

``` c
typedef struct list {
  char data;
  List *link;
} List;
```

## The Polynomial Abstract Data Type

EX: 

$A(x) = 3 x^{20} + 2x^{5} + 4$ and $B(x) = x^{4} + 10 x^{3} + 3x^{2} + 1$

$A(x) + B(x) = \sum (a_i + b_i) x^i$

$A(x)B(x) = \sum ((a_i x^i)\sum b_j x^j)$