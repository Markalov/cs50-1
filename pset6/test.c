#include<stdio.h>

struct student;

void printstuff(struct student* s);

struct student
{
    int age;
    char* name;
};

int main(void)
{
    struct student s1;
    s1.age = 3;
    s1.name = "Keaton";

    struct student s2 = {6, "Weston"};

    printstuff(&s1);
    printstuff(&s2);
}

void printstuff(struct student* s)
{
    printf("Name: %s\nAge:%d\n", (*s).name, s->age);
}
