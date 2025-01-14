SOLID Principles - 
S - Single Responsibility Principle
    Each Class Should Have only one reason to change
    class should have single responsibility
    modularity and testing and reusability and separation of concerns
O - Open/Close Principle
    Say 2 types of employee have different payCalculation then
    we make the interface of employee that will be implemented 
    by the different types of classes that are types of employees
    then the pay calculator class will just have a function of parameter Employee and whichever will be calling the calculatePay of this PayCalculator class it will delegate it via 
    interface to the respective class implementation.
    This make it open for extention
    Closed of modification so that the core logic wont be changed and the each type of employee will implement 
L - Liskov Substitution Principle
    2 types of employees that one is sub-type of other but the sub-type should not have 1 of the function then this can't be done logically
    So we seperate the interfaces 
    one with one function other interface extending the previous one and adding the other function so now which Employee will need both functions will implement the 2nd interface and the types who dont will implement the 1st interface
    presponsibility seperation with polymorphism
I - Interface Segregation Principle
    more interfaces better than single one cauz some functions of that interface might not be needed from the manager employee or contract employee so classes will implement the only logic that it implements
    cleaner interface and reduced coupling
D - Dependency Inversion Principle
    high level module should not depend on low level module 
    both should depend on abstraction or interfaces
    now say the employee was sending email earlier now he wants to send sms then this is tightly coupled with the employee class so what we do is we make a notifier interface that sms-notifier and email-notifier will implement and then the employee class notify function will have param as Notifier interface and the function call of the interface inside this function and from where ever this function is called that passing param will say that it was for email-notifier or sms-notifier
    so now the calling place of this function just needs to change the email-notifier to sms-notifier and send that in params of this function making code more loosely - coupled
    helps in testing as well for mocking the 3rd party notifier now
