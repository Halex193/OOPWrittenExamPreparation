#include <iostream>
#include <string>
#include<vector>

template<class T>
class ToDo
{
    std::vector<T> collection;
public:
    void operator+=(T object)
    {
        collection.push_back(object);
    }

    auto begin()
    {
        return collection.begin();
    }

    auto end()
    {
        return collection.end();
    }

    void reversePrint(std::ostream& out)
    {
        for(int i = collection.size()-1;i>=0;i--)
        {
            out<<collection[i]<<"\n";
        }
    }
};

class Activity
{
    std::string name;
    std::string time;
public:
    Activity (const std::string& name, const std::string& time): name{name}, time{time}{}

    friend std::ostream& operator<<(std::ostream& out, const Activity& activity)
    {
        out << "Activity "<<activity.name<<" will take place at "<<activity.time<<".";
        return out;
    }
};
void ToDoList()
{
    ToDo<Activity> todo{};
    Activity tiff{ "go to TIFF movie", "20:00" };
    todo += tiff;
    Activity project{ "present project assignment", "09.20" };
    todo += project;
// iterates through the activities and prints them as follows:
// Activity present project assignment will take place at 09.20.
// Activity go to TIFF movie will take place at 20.00.
    for (auto a : todo)
        std::cout << a << '\n';
// Prints the activities as follows:
// Activity go to TIFF movie will take place at 20.00.
// Activity present project assignment will take place at 09.20.
    todo.reversePrint(std::cout);
}

int main()
{
    ToDoList();
    return 0;
}