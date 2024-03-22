#ifndef LAB8_DOP_STRUCT_H
#define LAB8_DOP_STRUCT_H

#define max_size_str 20

typedef struct olympia_team_data {
    char fio[max_size_str];
    int age;
    int height;
    int weight;
    char sport[max_size_str];
    char rank[max_size_str];
} team;

struct olympia_team_data database[8] = {
        {"Petr", 21, 180, 76, "volleyball", "master"},
        {"Ivan", 37, 199, 93, "basketball", "the third category"},
        {"Maria", 19, 176, 60, "swimming", "master"},
        {"Victor", 56, 175, 70, "football", "pro"},
        {"Stepan", 43, 155, 93, "sumo", "pro-pro"},
        {"Sheba", 15, 162, 45, "running", "master"},
        {"Alexandr", 44, 130, 30, "football", "the first category"},
        {"Alexandra", 23, 176, 59, "volleyball", "master"}
};

#endif //LAB8_DOP_STRUCT_H