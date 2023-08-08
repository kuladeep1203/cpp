#include <iostream>
#include <string.h>
using namespace std;
class student
{
protected:
  char name[20];
  char roll_number[20];

public:
 void display() {}
};
class pg_student : public virtual student
{
protected:
  char course1[20];
  char course2[20];
  char course3[20];

public:
  void display()
  {
    cout << "Name=" << name << endl;
    cout << "Rollnumber=" << roll_number << endl;
    cout << "course1=" << course1 << endl;
    cout << "course2=" << course2 << endl;
    cout << "course3=" << course3 << endl;
  }
};

class research_student : public virtual student
{
protected:
  char course[20];
  char research_area[20];

public:
  void display()
  {
    cout << "Name=" << name << endl;
    cout << "Rollnumber=" << roll_number << endl;
    cout << "Course1=" << course << endl;
    cout << "Research Area=" << research_area << endl;
  }
};
class TA : public pg_student, research_student
{
private:
  char course_assigned[20];
  char role[20];
  int pg = 0, research = 0;

public:
  void set(char a[], char b[])
  {
    strcpy(name, a);
    strcpy(roll_number, b);
  }
  void set(char a[], char b[], char c[], char d[], char e[])
  {
    strcpy(course1, a);
    strcpy(course2, b);
    strcpy(course3, c);
    strcpy(course_assigned, d);
    strcpy(role, e);
    pg++;
  }
  void set(char a[], char b[], char c[], char d[])
  {
    strcpy(course, a);
    strcpy(research_area, b);
    strcpy(course_assigned, c);
    strcpy(role, d);
    research++;
  }
  void display()
  {
    cout << "name=" << name << endl;
    cout << "rollnumber=" << roll_number << endl;
    cout << "courseassigned=" << course_assigned << endl;
    cout << "role=" << role << endl;

    if (strcmp(role, "pg_student") == 0)
    {
      cout << "course1=" << course1 << endl;
      cout << "course2=" << course2 << endl;
      cout << "course3=" << course3 << endl;
    }
    if (strcmp(role, "research_student") == 0)
    {
      cout << "course=" << course << endl;
      cout << "research area=" << research_area << endl;
    }
  }
  int check(TA s[], char a[], int n)
  {
    for (int i = 0; i < n; i++)
    {
      if (strcmp(s[i].roll_number, a) == 0)
        return i;
    }
    return 1000;
  }
  int getpg()
  {
    return pg;
  }
  int getresearch()
  {
    return research;
  }
};
int main()
{
  int choice, choice1, a;
  char course_assigned[20], role[20], course1[20];
  char course2[20], course3[20], course[20];
  char research_area[20], roll_number[20], name[20];
  TA t[20];
  int i = 0;
  while (1)
  {
    cout << "1.set details\n2.display\n3.exit\n";
    cout << "enter your choice\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "enter the name\n";
      cin >> name;
      cout << "enter the rollnumber\n";
      cin >> roll_number;
      cout << "enter the course assigned\n";
      cin >> course_assigned;
      cout << "enter the role  1.research_student 2.pg_student\n";
      cin >> choice1;
      if (choice1 == 1)
      {
        strcpy(role, "research_student");
        cout << "enter the research_area\n";
        cin >> research_area;
        cout << "enter the course for research_student\n";
        cin >> course;
        if (strcmp(course, course_assigned) == 0)
          cout << "course assigned should not be equal to course pursued by the student\n";
        else
        {
          t[i].set(name, roll_number);
          a = t[i].check(t, roll_number, i + 1);
          if (t[a].getpg() != 0 || t[a].getresearch() != 0)
          {
            cout << "student already exist with the rollnumber\n";
          }
          else
          {
            t[i].set(course, research_area, course_assigned, role);
            i++;
          }
        }
      }
      if (choice1 == 2)
      {
        strcpy(role, "pg_student");
        cout << "enter first course of pg_student\n";
        cin >> course1;
        cout << "enter second course of pg_student\n";
        cin >> course2;
        cout << "enter third course of pg_student\n";
        cin >> course3;
        if (strcmp(course, course1) == 0 || strcmp(course, course1) == 0 || strcmp(course, course1) == 0)
          cout << "the course assigned should not be equal to the courses pursued by the student\n";
        else
        {
          t[i].set(name, roll_number);
          a = t[i].check(t, roll_number, i + 1);
          if (t[a].getpg() != 0 || t[a].getresearch() != 0)
          {
            cout << "student already exist with the rollnumber\n";
          }
          else
          {
            t[i].set(course1, course2, course3, course_assigned, role);
            i++;
          }
        }
      }
      break;
    case 2:
      cout << "enter the roll number\n";
      cin >> roll_number;
      a = t[i].check(t, roll_number, i + 1);
      if (a != 1000)
      {
        t[a].display();
      }
      else
        cout << "roll_number is not found\n";
      break;
    case 3:
      exit(0);
      break;
    }
  }

  return 0;
}