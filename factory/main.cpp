
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

class FactoryGameObjects
{
public:
    static std::shared_ptr<IGameObject> CreateObject(ObjectType type)
    {
        if (type == ObjectType::PLANE)
        {
            s_plane++;
            return std::make_shared<Plane>();
        }
        else if (type == ObjectType::BOAT)
        {
            s_boats++;
            return std::make_shared<Boat>();
        }
        return nullptr;
    }

    static void PrintCounts()
    {
        std::cout << "Planes: " << s_plane << ", Boats: " << s_boats << std::endl;
    }

private:
    FactoryGameObjects() = default;
    ~FactoryGameObjects() = default;
    FactoryGameObjects(const FactoryGameObjects &o) = default;

    static int s_plane;
    static int s_boats;
};

int FactoryGameObjects::s_plane = 0;
int FactoryGameObjects::s_boats = 0;

int main()
{
    // std::shared_ptr<IGameObject> plane = MakeGameObjectFactory(ObjectType::PLANE);
    // std::shared_ptr<IGameObject> boat = MakeGameObjectFactory(ObjectType::BOAT);

    std::shared_ptr<IGameObject> myplane = FactoryGameObjects::CreateObject(ObjectType::PLANE);
    std::shared_ptr<IGameObject> myboat = FactoryGameObjects::CreateObject(ObjectType::BOAT);
    std::shared_ptr<IGameObject> myboat2 = FactoryGameObjects::CreateObject(ObjectType::BOAT);
    std::shared_ptr<IGameObject> myboat3 = FactoryGameObjects::CreateObject(ObjectType::BOAT);

    // plane->update();
    // plane->render();

    // boat->update();
    // boat->render();

    FactoryGameObjects::PrintCounts();
    // output planes1, boats3
    return 0;
}