# Event-Handler

Flexible event handler library for C++.

## -- THE PROBLEM THIS ADDRESSES --

Oftentimes I find myself wanting to track when certain functions evaluate to true or false, or have a certain number return. However to do this is very difficult without modifying code. I was writing a wrapper for a game controller code when I couldn't figure out how to asynchronously run tasks based on arbitrary function returns (like if I click three buttons and a certain condition is met, then run X function). I ended up writing and rewriting this 15ish times to make it as portable as possible, and now it has the following abilities:

- Can run any function depending on any function
- Can handle as many events as you'd like *with any function or parameter type*
- Can work with other libraries without interfering (within reason)
- Can run asynchronous function calling

## -- USES --

Huge amount but the big ones are debugging and conditional function calls. I'm personally using it for Reverse Engineering automation to dump memory when it has the value of a flag prefix (like HTB or picoCTF). But it's really diverse in ability. 

## -- TO USE --

Create a child class of Event. This child class is going to need three things:

A) A variable, either a function pointer or a std::function to check
B) An argument in the constructor passing in that variable and the parameters needed for the function
C) A unique ID (if not unique, it will notify you and exit the program!)

Implement check with whatever logic you'd like. Often times, you want to just call the function you inputted and do different things depending on the output. But up to you if you want to do extra checks (like if the function call is to give you a list of register values and if $RDI = 5 you return True)

Then you have to make a vector of shared_ptrs to the Event class (*NOT YOUR CUSTOM CLASS, THE EVENT CLASS*), initialize the pointers, and pass it into an EventHandler constructor.

From there, you can check events by IDs, or you can dump all the events at once and check the IDs yourself. Do with that information as you will. 

## -- TO COMPILE -- 

g++ ptrace_ASM_dump.cpp -L. -l eventhandler
