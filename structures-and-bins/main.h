#ifndef LAB8_MAIN_H
#define LAB8_MAIN_H

#define max_size_str 30

typedef struct olympia_team_data {
    char fio[max_size_str];
    int age;
    float height;
    float weight;
    char sport[max_size_str];
    char rank[max_size_str];
} team;

struct olympia_team_data database[3] = {
        {"Petrov Petr Petrovich", 21, 180, 76, "volleyball", "master"},
        {"Ivanov Ivan Ivanovich", 37, 199, 92, "basketball", "the first category"},
        {"Mashina Maria Mariyvna", 19, 176, 60, "swimming", "master"}
};

#endif //LAB8_MAIN_H
