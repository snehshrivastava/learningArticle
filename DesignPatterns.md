[Reference Video](https://www.youtube.com/watch?v=AB0gaAg9jwI&list=PLt4nG7RVVk1h9lxOYSOGI9pcP3I5oblbx&index=5)
Design Patterns - 
    1. Singleton Design Pattern - 
        Creational design pattern - a way that creates objects in a manner that's suitable for the situation.
        Only one instance of the class should exist.
        Other classes should be able to get the instance of Singleton class.
        Used for logging, cache, sessions, drivers.
        e.g. - constructor should be private so no one else can create the instance
        public static method to return the instance
        instance type should be private cauz var should not be modifiable and static cauz directly will be called from class name
        to make it thread safe we add the public static synchronized
        synchronized keyword will make the whole function synchronized
    2. Factory Design pattern - 
        creational design pattern
        used when we have multiple sub-classes of a super-class and based on input we want to return one class instance
        provides abstraction between implementation and client classes
        remove the instantiation of client classes from client code
    3. Builder Design Pattern - 
        creational design pattern 
        required when many parameters used in constructor
        offload the work to a builder class passing the parameters to the builder class and for optional and changing values use setter to set them. Afterwards calling build to get the instance of the original required class
    4. Prototype Design Pattern
        Creational design pattern
        to have multiple objects for a same class
        the class that is required needs to implement the Clonable class and Override the clone function to return the new instance of the current class with same data
    5. Proxy Design Pattern
        Structural design pattern - improves the structure the code
        where we want access-control there it is used
        Make 2 implementation of interface one with the normal function implementation and other with the access-control check calling this function
    6. Adapter Design Pattern - Shit
        structural design pattern
        Adapter and adaptee adapter be interface initialization and then we make internal call to adaptee so the front shown funtion be same
    7. Observer Design Pattern
        structural
        mainly like subscribing to topic and notifing all the users that have been subscribed for specific updates
    8. IoC Principle & Dependency Inversion Principle
        IoC - Inversion of control - here what we do is that new Class object should not be created directly insted should be getting it from another class to remove the tight coupling between them
        to invert the control now we will make a data factory class through which we will return the new class object from a static method 
        Dependency inversion priciple - high level module should not depend on low level module rather it should depend on the abstraction
        so where we were getting the new Class object retured that should me cpaturing the interface of the class whose object is getting created
    9. Dependency Injection (DI) design pattern
        its design pattern used to implement IoC
        It allows the creation of dependent objects outside of the class and provides these objects to as class through different ways
        types of injection -
            for above IoC example itself if the object is getting send via constructor parameter then it is constructor injection
            if the class object is set from the instance by keeping the property public then property injection
            if setting it via calling a method that is called method injection
    10. Decorator Design Pattern
        Structural design pattern
        Used when we want to modify the functionality of an Object runtime and it should not change individual object functionality
        say we wanna have a property added to the object at run-time for this we make a interface say dress that is getting implemented via basic dress and say from this basic dress we want more property of fancy dress casual dress
        then we make a decorator class that will implementing the above interface then 
        so for this casualDress that will be extending the decorator class will have constructor with super(c) so that the passed params are passed to parent class and for the function that we invoked with added properties should also be first calling the parent function to run the properties first
        benifit is that decorator is getting extended everywhere and we call super for the decorator class to be run
