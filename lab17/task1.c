#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 15
#define NAME_BUFER_SIZE (MAX_NAME_LENGTH + 1)

typedef struct Human {
    char name[NAME_BUFER_SIZE];
    unsigned int age;
} Human;

typedef struct Student Student;
struct Student {
    char *name;
    unsigned int age;
    unsigned int course;
    unsigned int tails;
    int (*init)(Student *, const char *, unsigned int, unsigned int, unsigned int);
    void (*destroy)(Student *);
    void (*print)(const Student *);
};

int InitStudent(Student *student, const char *name, unsigned int age,
                unsigned int course, unsigned int tails);
void DestroyStudent(Student *student);
void PrintStudent(const Student *student);
char *ReadName();

int main() {
    Student petr = {0};
    Student student = {0};
    Student vasilii = {0};
    unsigned int course, tails;

    printf("Enter a name for student: ");
    char *name = ReadName();
    if (name == NULL) {
        fprintf(stderr, "Invalid student name.\n");
        return 1;
    }
    printf("Enter his course: ");
    if (scanf("%u", &course) != 1) {
        free(name);
        fprintf(stderr, "Invalid course.\n");
        return 1;
    }
    printf("Enter his tails number: ");
    if (scanf("%u", &tails) != 1) {
        free(name);
        fprintf(stderr, "Invalid tails number.\n");
        return 1;
    }

    if (!InitStudent(&petr, "Petr", 0, 2, 4) ||
        !InitStudent(&student, name, 0, course, tails) ||
        !InitStudent(&vasilii, "Vasya", 20, 1, 5)) {
        free(name);
        fprintf(stderr, "Failed to allocate memory for a student name.\n");
        DestroyStudent(&petr);
        DestroyStudent(&student);
        DestroyStudent(&vasilii);
        return 1;
    }

    free(name);
    printf("There are 3 students:\n");
    petr.print(&petr);
    student.print(&student);
    vasilii.print(&vasilii);

    petr.destroy(&petr);
    student.destroy(&student);
    vasilii.destroy(&vasilii);
    return 0;
}

int InitStudent(Student *student, const char *name, unsigned int age,
                unsigned int course, unsigned int tails) {
    student->init = InitStudent;
    student->destroy = DestroyStudent;
    student->print = PrintStudent;

    char *copy = malloc(strlen(name) + 1);
    if (copy == NULL) {
        return 0;
    }
    strcpy(copy, name);

    free(student->name);
    student->name = copy;
    student->age = age;
    student->course = course;
    student->tails = tails;
    return 1;
}

void DestroyStudent(Student *student) {
    free(student->name);
    student->name = NULL;
    student->age = 0;
    student->course = 0;
    student->tails = 0;
}

void PrintStudent(const Student *student) {
    printf("Student:\nName: %s	 Course: %u	 Tails: %u\n",
           student->name != NULL ? student->name : "(not initialized)",
           student->course, student->tails);
}

char *ReadName() {
    size_t capacity = NAME_BUFER_SIZE;
    size_t length = 0;
    char *name = malloc(capacity);
    if (name == NULL) {
        return NULL;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (length == capacity - 1) {
            capacity += capacity / 2;
            char *new_name = realloc(name, capacity);
            if (new_name == NULL) {
                free(name);
                return NULL;
            }
            name = new_name;
        }
        name[length++] = (char)ch;
    }
    name[length] = 0;
    return name;
}
