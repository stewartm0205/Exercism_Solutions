#include "grade_school.h"
#include <string.h>
#include <stdio.h>

int add_student(roster_t* class, char* name, uint8_t grade) {
   
    size_t si;
    size_t ip=MAX_STUDENTS;
    for (si=0; si<class->count; si++) {
        if (class->students[si].grade>grade||
            (class->students[si].grade==grade &&
             strcmp(name,class->students[si].name)<0)){
            ip=si; 
            break;
        }
        if (!strcmp(name,class->students[si].name)) break;
    }
  
    if (si==class->count){
        class->count=si+1;
        class->students[si].grade=grade;
        strcpy(class->students[si].name,name);
        return 1;
    }
    if (ip==MAX_STUDENTS) return 0;
    
    for (si=class->count; si>ip; si--){
        class->students[si] = class->students[si-1];
    }

    class->students[ip].grade=grade;
    strcpy(class->students[ip].name,name);
    class->count++;
    return 1;
}
roster_t get_grade(roster_t* class, uint8_t desired_grade){
    roster_t grade_class;
    size_t gci=0;
    for (size_t si=0; si<class->count; si++) {
        if (class->students[si].grade==desired_grade){
            grade_class.students[gci++]=class->students[si];
        }
    } 
    grade_class.count=gci;
    return grade_class;
}
int init_roster(roster_t* class){
    class->count=0;
    return 0;
}
