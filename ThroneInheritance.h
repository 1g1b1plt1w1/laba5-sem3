#ifndef THRONE_INHERITANCE_H
#define THRONE_INHERITANCE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
struct Person {
    string parent;
    vector<string> children;
    bool kingStatus = false;
    bool aliveStatus = true;
    Person() = default;
};

class ThroneInheritance {
    unordered_map<string, Person> people;
    string kingName;
    string* curOrder = nullptr;
    int curSize = 0;

    bool name_tester(const string& n);
    void dfs(const string& name, vector<string>& order) const;

public:
    ThroneInheritance(const string& kingName_);
    ~ThroneInheritance();

    void birth(const string& parentName, const string& childName);
    void death(const string& deadName);
    vector<string> getInheritanceOrder();
};

ostream& operator << (ostream& os, const vector<string>& str);

#endif
