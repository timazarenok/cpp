#ifndef TAMOGOCHI_H_INCLUDED
#define TAMOGOCHI_H_INCLUDED
#include <exception>
#define between(a, min, max) a > min && a < max
#include <map>

namespace Minmax_values
{

struct Parametr
{
    std::size_t m_max;
    std::size_t m_min;
    Parametr() = default;
    Parametr(std::size_t max, std::size_t min): m_max(max), m_min(min) {}


    bool is_valid(std::size_t value)
    {
        return between(value, m_min, m_max);
    }

};

std::map<std::string, Parametr> parametrs{{std::string("Hunger"), Parametr(0, 100)},
    {std::string("Health"), Parametr(0, 100)},
    {std::string("Mood"), Parametr(0, 200)}};


template<class T, class R, class Param>
void set_parametr(T value, R parametr, Param p)
{
    if(!p.is_valid(value))
    {
        throw std::invalid_argument("Error");
    }
    parametr = value;
}

template<class T, class R, class Param>
void add_parametr(T value, R parametr, Param p)
{
    T temp = parametr;
    temp += value;
    if(!p.is_valid(temp))
    {
        parametr = p.m_max;
    }
    else
    {
        parametr = temp;
    }
}

template<class T, class R, class Param>
void sub_parametr(T value, R parametr, Param p)
{
    T temp = parametr;
    temp -= value;
    if(!p.is_valid(temp))
    {
        parametr = p.m_min;
    }
    else
    {
        parametr = temp;
    }
}

}



struct AnimalTraits
{
    std::size_t m_mood;
    std::size_t m_hunger;
    std::size_t m_health;


    AnimalTraits(std::size_t mood = 100, std::size_t hunger = 100, std::size_t health = 100):
        m_mood(mood), m_hunger(hunger), m_health(health) {}

    AnimalTraits& set_hunger(std::size_t h)
    {
        Minmax_values::set_parametr(h, m_hunger, Minmax_values::parametrs["Hunger"]);
        return *this;
    }

    AnimalTraits& set_mood(int m)
    {
        Minmax_values::set_parametr(m, m_mood, Minmax_values::parametrs["Mood"]);
        return *this;
    }

    AnimalTraits& set_health(std::size_t h_t)
    {
        Minmax_values::set_parametr(h_t, m_health, Minmax_values::parametrs["Health"]);
        return *this;
    }

    AnimalTraits& add_health(std::size_t value)
    {
        Minmax_values::add_parametr(value, m_health, Minmax_values::parametrs["Health"]);
        return *this;
    }

    AnimalTraits& add_hunger(std::size_t value)
    {
        Minmax_values::add_parametr(value, m_hunger, Minmax_values::parametrs["Hunger"]);
        return *this;
    }

    AnimalTraits& add_mood(std::size_t value)
    {
        Minmax_values::add_parametr(value, m_mood, Minmax_values::parametrs["Mood"]);
        return *this;
    }

    AnimalTraits& sub_health(std::size_t value)
    {
        Minmax_values::sub_parametr(value, m_health, Minmax_values::parametrs["Health"]);
        return *this;
    }

    AnimalTraits& sub_hunger(std::size_t value)
    {
        Minmax_values::sub_parametr(value, m_hunger, Minmax_values::parametrs["Hunger"]);
        return *this;
    }

    AnimalTraits& sub_mood(std::size_t value)
    {
        Minmax_values::sub_parametr(value, m_mood, Minmax_values::parametrs["Mood"]);
        return *this;
    }


};

struct Animal
{
    enum Animal_type {puppy, kitten, giraffe, fish};
    Animal_type m_animal_type;

    AnimalTraits m_animal_traits;
    Animal() = default;
    Animal(Animal_type animal_type, AnimalTraits animal_traits): m_animal_type(animal_type), m_animal_traits(animal_traits) {}
    void feed(std::size_t value)
    {
        m_animal_traits.sub_hunger(value);
        m_animal_traits.add_mood(value/2);
        m_animal_traits.add_health(value/4);
    }

    void sleep(std::size_t value)
    {
        m_animal_traits.add_health(value);
        m_animal_traits.sub_hunger(value/4);
        m_animal_traits.add_mood(value/4);
    }

    void play(std::size_t value)
    {
        m_animal_traits.add_hunger(value/2);
        m_animal_traits.add_mood(value);
        m_animal_traits.sub_health(value/4);
    }

    bool is_life()
    {
        return m_animal_traits.m_health == 0;
    }


};






#endif // TAMOGOCHI_H_INCLUDED
