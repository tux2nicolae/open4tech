#pragma once

#include<iostream> 
#include<vector>
#include<algorithm>

struct student
{
  std::string name;
  int age;
};

void CountSort()
{
  const std::vector<std::string> & names{
    "Andrei",
    "Cristina",
    "Paula",
    "Ramona",
    "Matei",
    "Robert",
    "Ion",
    "Anca",
    "Mirela",
    "Georgiana",
    "Florian",
    "Vasile",
    "Mona",
    "Mihaela",
    "Laurentiu"
  };

  // generate random data
  std::vector<student> students;
  for (int i = 0; i < 10000; ++i)
    students.push_back({ names[rand() % names.size()], rand() % 100 });

  // count all ages 
  std::vector<int> positions(100, 0);
  for (const student& student : students)
  {
    positions[student.age]++;
  }

  // calculate insert positions
  for (size_t i = 1; i < positions.size(); ++i)
  {
    positions[i] += positions[i - 1];
  }

  // put data in sorted
  std::vector<student> sortedStudents(students.size());
  for (auto& student : students)
  {
    sortedStudents[positions[student.age] - 1] = std::move(student);
    positions[student.age]--;
  }
}
