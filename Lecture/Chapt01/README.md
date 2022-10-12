# Chapter01 - Basic Concepts

1. Requirements
2. Analysis
3. Design
4. Refinement and coding
5. Verification

### Sort

### Compare

### Search

### Recursive

## **Data Abstraction**

### Struct

It's the collections of the elements whose data types need not be the same. -> They are explicitly defined.

``` c
struct student {
    char last_name;
    int student_id;
    char grade;
}
```

### Abstract data type(ADT).

implementation-independent.
1. Creator/Constructor
2. Transformers
3. Observers/Reporters

**The symbol `::=` -> should be read as "is defined as".**

## **Performance analysis**

* Fixed space requirements. 
  * The component refers to space requirements that do not depend on the number and size of the program's inputs and outputs.
* Variable space requirements.
  * $S(P) = c +S_{p}(I)$