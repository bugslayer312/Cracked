#include <iostream>
#include <queue>
#include <list>

enum class AnimalType {
    Cat,
    Dog,
    Undefined
};

struct Animal {
    AnimalType Type;
    int Order;

    Animal():Type(AnimalType::Undefined) {
    }
    Animal(AnimalType type) :
        Type(type), Order(++LastArrived) {}
private:
    static int LastArrived;
};

int Animal::LastArrived = 0;

std::ostream& operator<<(std::ostream& os, Animal const& animal) {
    if (animal.Type == AnimalType::Undefined) {
        os << "[Not found]";
    }
    else {
        os << '[' << (animal.Type == AnimalType::Cat ? "Cat" : "Dog") << ',' << animal.Order << ']';
    }
    return os;
}

class AnimalShelter {
    std::list<std::queue<Animal>> m_animals;

    Animal dequeueConcrete(AnimalType type) {
        std::queue<Animal> mismath;
        Animal result;
        bool found = false;
        auto it = m_animals.begin();
        while (!found && it != m_animals.end()) {
            auto& curQueue = *it;
            while (!curQueue.empty()) {
                Animal const& cur = curQueue.front();
                curQueue.pop();
                if (cur.Type == type) {
                    found = true;
                    result = cur;
                    break;
                }
                mismath.push(cur);
            }
            if (curQueue.empty()) {
                it = m_animals.erase(it);
            }
            else {
                ++it;
            }
        }
        if (!mismath.empty()) {
            m_animals.push_front(std::move(mismath));
        }
        return result;
    }
public:
    void enqueue(AnimalType type) {
        if (m_animals.empty()) {
            m_animals.push_back(std::queue<Animal>({Animal(type)}));
        }
        else {
            m_animals.back().push(Animal(type));
        }
    }

    Animal dequeueAny() {
        if (m_animals.empty()) {
            return Animal();
        }
        Animal result = m_animals.front().front();
        m_animals.front().pop();
        if (m_animals.front().empty()) {
            m_animals.pop_front();
        }
        return result;
    }

    Animal dequeueCat() {
        return dequeueConcrete(AnimalType::Cat);
    }

    Animal dequeueDog() {
        return dequeueConcrete(AnimalType::Dog);
    }
};

int main() {
    AnimalShelter ash;
    ash.enqueue(AnimalType::Cat);
    ash.enqueue(AnimalType::Cat);
    ash.enqueue(AnimalType::Cat);

    std::cout << ash.dequeueDog() << ' ' << ash.dequeueAny() << ' ' << ash.dequeueCat() << std::endl;

    ash.enqueue(AnimalType::Cat);
    ash.enqueue(AnimalType::Dog);

    std::cout << ash.dequeueCat() << ' ' << ash.dequeueDog() << ' ' << ash.dequeueAny() << ash.dequeueAny() << ' ' << std::endl;

    return 0;
}
