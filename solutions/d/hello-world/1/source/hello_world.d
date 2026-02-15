module helloworld_test;
import std.stdio;
import std.conv;
import core.vararg;

string hello(...) 
{
  string name;
  if (_arguments.length > 0) {
    name = va_arg!string(_argptr);
    return text("Hello, ", name, "!").idup;
  } else {
    return "Hello, World!".idup;
  }
}
  

unittest {
const int allTestsEnabled = 0;

    assert(hello() == "Hello, World!");
static if (allTestsEnabled) {
    assert(hello("Alice") == "Hello, Alice!");
    assert(hello("Bob") == "Hello, Bob!");
    assert(hello("") == "Hello, !");
}

}
