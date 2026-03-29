/*
    void method() const;
    When const appears at the end of a method (after the parentheses),
    it means: "this method promises not to modify the object it belongs to."

    void method(int&, int&);
    Normally when you pass a variable to a function, C++ makes a copy of it.
    The & means "pass by reference" — instead of a copy, the function gets the actual variable itself.

    void method(int&, int&, int&) const
    - Takes 3 integer references it can write into
    - Will not modify the class object itself

    ~className()
    Destructor called when object is DESTROYED
    If your class uses `new` anywhere → you need a destructor with `delete`.

    Stacks are First in Last Out.
    If the stack is empty, top = -1
*/
