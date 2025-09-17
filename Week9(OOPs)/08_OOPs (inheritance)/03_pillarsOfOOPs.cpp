/*
1. Abstraction:
    -- Abstraction is the concept of hiding the complex implementation details and showing only the necessary features of an object. This helps in reducing complexity and allows the programmer to focus on interactions at a higher level.
    -- Example: When using a car, you only need to know how to drive it (steering, accelerating, braking) without needing to understand the intricate workings of the engine.


2. Encapsulation: it is a way to implement abstraction by hiding internal details and exposing only necessary.
    -- Encapsulation means wrapping data and functions that operate on that data into a single unit (a class), and hiding the internal details (using private, protected).
    -- bundling of data and methods, Encapsulation is the mechanism of restricting access to certain components of an object and only exposing certain parts through public methods
    -- Example: In a class representing a bank account, the balance would be a private variable, and the methods to deposit or withdraw money would be public. This ensures that the balance can only be modified in controlled ways


3. Inheritance:
    -- Inheritance allows one class to derive from another, inheriting its data and behavior.
    -- promotes code reusability and establishes a relationship between the two classes.
    -- Inheritance is a mechanism where a new class (child class) is derived from an existing class (parent class). The child class inherits fields and methods of the parent class.
    -- Example: A Dog class can inherit from an Animal class. The Dog class would inherit attributes like age and methods like eat and sleep from the Animal class.


4. Polymorphism:
    -- Polymorphism allows objects of different classes to be treated as objects of a common superclass. It is the ability to present the same interface for different underlying forms (data types). The most common use of polymorphism is when a parent class reference is used to refer to a child class object.
    -- Example: Suppose there is a base class called Shape with a method draw(). Subclasses like Circle, Rectangle, and Triangle implement the draw() method in their own way. With polymorphism, you can write a method that takes a Shape reference and calls draw(), and the appropriate method for the specific shape type will be executed.
*/


/*
🔍 What is Polymorphism?
    - Polymorphism means “many forms” — it's the ability of one function, object, or operator to behave differently in different situations, especially when inherited.

In C++, polymorphism allows you to use a base class pointer or reference to refer to objects of derived classes, and call the appropriate function based on the actual object — not just the pointer type.



Polymorphism:-
    1. compile-time polymorphism(static polymorphism):-
        - Compile-time polymorphism is resolved during compilation. The most common examples of compile-time polymorphism in C++ are function overloading and operator overloading.

    2. Run-Time polymorphism(Dynamic Polymorphism):-
        - Run-time polymorphism is resolved during program execution. The most common example of run-time polymorphism in C++ is achieved through inheritance and virtual functions i.e., due to function overriding.
*/

