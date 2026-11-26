// =====================================================================================
// Exercises_01_MoveSemantics.cpp
// =====================================================================================

#include <array>
#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <print>
#include <algorithm> 
#include <string>
#include <execution>
#include <span>
#include <iostream>

namespace Exercises_MoveSemantics {

    namespace Exercise_01 {

        class Person
        {
        private:
            std::string m_name;         // name of person
            std::vector<int> m_values;  // some arbitrary person values
            std::size_t m_counter;

        public:
            Person() : m_counter{ 1 } {}
            Person(const std::string& name) : m_name{ name }, m_counter{ 1 } {}

            Person(Person&& other) noexcept {
            
                m_name = std::move(other.m_name);
                m_values = std::move(other.m_values);
            }


            ~Person() {
                std::println("Eine Person weniger ........");
            }

            void addValue(int value) {
                m_values.push_back(value);
            }

            friend std::ostream& operator<< (std::ostream& os, const Person& cust) {
                os << "{ " << cust.m_name << ": ";
                for (auto val : cust.m_values) {
                    os << val << ' ';
                }
                os << "}";
                return os;
            }
        };

        /*
        * When passing an object to a function, or returning an object from a function,
        * it's possible to do a move (rather than a copy) if:
        *
        * = the object is an rvalue
        * = the object's class defines the special member move functions
        */

        static void testExercise() {

            // create a person with some initial values
            Person dagobert{ "Dagobert Duck" };
            for (int value : { 1, 2, 3, 4, 5, 6, 7, 8, 9 }) {
                dagobert.addValue(value);
            }

            // print person
            std::cout << "Person: " << dagobert << std::endl;

            // insert person into a collection
            std::vector<Person> persons;
            persons.push_back( std::move ( dagobert )  );

            // print person again
        //    std::cout << "Person: " << dagobert << std::endl;
        }
    }
}

void exercises_move_semantics()
{
    using namespace Exercises_MoveSemantics;

    Exercise_01::testExercise();
}

// =====================================================================================
// End-of-File
// =====================================================================================