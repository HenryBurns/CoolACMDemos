Why does this call Foo::goo?

The short answer is name mangling. C++ converts Foo::goo to a simplified unique function name (\_ZN3Foo3gooEv).
By using extern "C", we say "Do not mangle this function name. Instead explicitly look up the function \_ZN3Foo3gooEv."

Notice that \_ZN3Foo3gooEv(Foo *) takes a Foo*. That's the this pointer used in Foo::goo()
(The this pointer is passed along with any member function [assuming it doesn't get inlined]).

The message string here exists solely so that Foo::goo doesn't just get inlined into main().
