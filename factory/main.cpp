
#include <iostream>
#include <string>

class IGameObject
{
public:
    virtual ~IGameObject() = default;
    virtual void update() = 0;
    virtual void render() = 0;
};

class Plane : public IGameObject
{
public:
    Plane() = default;
    ~Plane() override = default;
    void update() override
    {
        // Implement update logic for Plane
    }

    void render() override
    {
        // Implement render logic for Plane
    }
};

class Boat : public IGameObject
{
public:
    Boat() = default;
    ~Boat() override = default;
    void update() override
    {
        // Implement update logic for Boat
    }

    void render() override
    {
        // Implement render logic for Boat
    }
};

enum class ObjectType
{
    PLANE,
    BOAT
};

IGameObject *MakeGameObjectFactory(ObjectType type)
{
    if (type == ObjectType::PLANE)
        return new Plane();
    else if (type == ObjectType::BOAT)
        return new Boat();
    return nullptr;
}

int main()
{
    IGameObject *plane = MakeGameObjectFactory(ObjectType::PLANE);
    IGameObject *boat = MakeGameObjectFactory(ObjectType::BOAT);

    plane->update();
    plane->render();

    boat->update();
    boat->render();

    delete plane;
    delete boat;
    return 0;
}