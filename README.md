Pet Management System in C++
This is a simple Pet Management System implemented in C++. It demonstrates basic Object-Oriented Programming concepts such as inheritance, polymorphism, and dynamic memory management. The program allows managing pets (dogs, cats, and other types), adding pets interactively via user input, listing all pets with their details and sounds, and finding the oldest pet.

Features
Define pets with attributes: name, age, and type.

Support for different pet types via inheritance (Dog, Cat, and generic Pet).

Polymorphic behavior with overridden makeSound() method.

Add pets dynamically from user input.

List all pets with details and sounds.

Identify and display the oldest pet.

Proper memory management with cleanup of dynamic allocations.

Usage
Clone the repository:

bash
git clone https://github.com/yourusername/pet-management-cpp.git
cd pet-management-cpp
Compile the program:

bash
g++ -o pet_management main.cpp
Run the executable:

bash
./pet_management
Follow the prompts to add new pets, view all pets, and find the oldest pet.

Code Structure
Pet: Base class representing a generic pet.

Dog and Cat: Derived classes that override the makeSound() function.

main(): Contains the core logic for adding pets, displaying info, and managing memory.

Utility functions:

countPets() — Returns the total number of pets.

oldestPet() — Finds and returns the oldest pet.

addPetByUser() — Handles user input for adding new pets.

Future Improvements
Add support for saving/loading pets from a file.

Implement more pet types.

Enhance input validation and error handling.

Use smart pointers (std::unique_ptr) for better memory safety.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Contact
Created by muratcannergiz0@ — feel free to reach out for questions or contributions!
