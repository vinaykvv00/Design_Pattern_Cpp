
#include <iostream>
#include <memory>
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

std::shared_ptr<IGameObject> MakeGameObjectFactory(ObjectType type)
{
    if (type == ObjectType::PLANE)
        return std::make_shared<Plane>();
    else if (type == ObjectType::BOAT)
        return std::make_shared<Boat>();
    return nullptr;
}

int main()
{
    std::shared_ptr<IGameObject> plane = MakeGameObjectFactory(ObjectType::PLANE);
    std::shared_ptr<IGameObject> boat = MakeGameObjectFactory(ObjectType::BOAT);

    plane->update();
    plane->render();

    boat->update();
    boat->render();

    return 0;
}