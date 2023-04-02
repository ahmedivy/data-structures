#include <iostream>
#include <cstring>

class String
{
private:
    uint32_t size;
    char *data;

public:
    String() = default;

    String(const char *str)
    {
        printf("Created!\n");
        size = strlen(str);
        data = new char[size];
        memcpy(data, str, size);
    }

    String(const String &other)
    {
        printf("Copied!\n");
        size = other.size;
        data = new char[size];
        memcpy(data, other.data, size);
    }

    String(String &&other) noexcept
    {
        printf("Moved!\n");
        size = other.size;
        data = other.data;

        other.size = 0;
        other.data = nullptr;
    }

    ~String()
    {
        printf("Deleted!\n");
        delete data;
    }

    void print()
    {
        for (uint32_t i = 0; i < size; i++)
            printf("%c", data[i]);
        printf("\n");
    }
};

class Entity
{
private:
    String name;

public:
    Entity() = default;

    Entity(const String &name) : name(name) {}

    Entity(String &&name) : name(std::move(name)) {}

    void printName()
    {
        name.print();
    }
};

int main()
{
    Entity entity("Ahmed");
    entity.printName();

    return 0;
}