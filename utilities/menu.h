//
// Created by uzair on 3/19/22.
//

#ifndef CMS_MENU_H
#define CMS_MENU_H

#include <iostream>
#include <vector>
using namespace std;

class Menu {
private:
public:
    Menu();
    void departmentMenu() const;
    void courseMenu() const;
    void subjectMenu() const;
    void teacherMenu() const;
    void studentMenu() const;
    void libraryMenu() const;

    void displayMain(vector<string>) const;

    ~Menu();
};

#endif //CMS_MENU_H
