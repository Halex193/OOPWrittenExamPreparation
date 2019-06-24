#include <iostream>
#include <string>

class Beverage
{
    std::string description;
public:
    Beverage(std::string description) : description{ description }{}

    virtual double price() = 0;

    virtual void print()
    {
        std::cout << description << " - price: " << price() << " RON";
    }

    virtual ~Beverage()
    {

    }
};

class Tea : public Beverage
{
public:
    Tea() : Beverage{"Tea"}
    {}

    double price() override
    {
        return 1.5;
    }
};

class Coffee : public Beverage
{
public:
    Coffee() : Beverage{"Coffee"}
    {}

    double price() override
    {
        return 2.5;
    };
};

class BeverageWithMilk : public Beverage
{
    Beverage *beverage;
    int milkCount;
public:
    BeverageWithMilk(Beverage *beverage, int milkCount) : Beverage{"Beverage with milk"}, beverage{beverage}, milkCount{milkCount}{}

    double price() override
    {
        return beverage->price() + milkCount * 0.5;
    }

    void print() override
    {
        beverage->print();
        std::cout << " - milk: " << milkCount;
        std::cout << " => " << price() << " RON";
    }

    ~BeverageWithMilk()
    {
        delete beverage;
    }
};

class BeverageMachine
{
public:
    void prepare(const std::string &beverageType, int milkCount)
    {
        Beverage *beverage;
        if (beverageType == "Tea")
        {
            beverage = new Tea{};
        } else if (beverageType == "Coffee")
        {
            beverage = new Coffee{};
        }

        if (milkCount > 0)
        {
            beverage = new BeverageWithMilk{beverage, milkCount};
        }
        beverage->print();
        std::cout << std::endl;
        delete beverage;
    }
};

int main()
{
    BeverageMachine machine{};
    machine.prepare("Tea", 0);
    machine.prepare("Coffee", 1);
    machine.prepare("Coffee", 2);
    return 0;
}