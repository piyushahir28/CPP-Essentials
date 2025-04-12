# Things we generally don't know.

- **Is C++ Machine Independent?**
  A C++ executable is not platform-independent (compiled programs on Linux won’t run on Windows), however, they are machine-independent. Let us understand this feature of C++ with the help of an example. Suppose you have written a piece of code that can run on Linux/Windows/Mac OSx which makes the C++ Machine Independent but the executable file of the C++ cannot run on different operating systems. So in general we can say it is Machine independent.

- Is it necessary to initialize a **static member variable** outside the class using the **scope resolution operator** (`::`)?
  Yes, it is necessary to initialize a static member variable outside the class using the scope resolution operator (`::`). This is because static member variables are shared among all instances of the class and need to be defined in a single location. The syntax for initializing a static member variable is as follows:

- **Virtual Function Inling**: C++ compiler cannot inline the virtual function. The reason is that the calls to a virtual function is resolved at runtime instead of compile-time. Virtual means waiting until runtime and inline means during compilation, if the compiler doesn’t know which function will be called, how it can perform inlining?
