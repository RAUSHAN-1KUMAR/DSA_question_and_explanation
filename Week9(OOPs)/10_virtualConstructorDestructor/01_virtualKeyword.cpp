/*
Virtual:- way to achieve runtime polymorphism
*/

/*
Virtual tables:-
    - formed for every class having at least one virtual function and for its derived classes.
    - it is static arrays, hence one instance for a class.
    - Vptr(a hidden member pointer) is added by compiler to classes with virtual and its derived classes.
    - Depending upon the object type VPtr is bonded to a VTable.

VTables are created at compile time.

When object of a particular type is created at runtime. There will be a VPtr which will be initialize to point to a static Vtable at the time of construction.
*/