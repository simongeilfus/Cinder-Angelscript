Cinder-Angelscript
===================
Thin wrapper around angelscript for use with the latest cinder release. Use it to make an interface between a cinder application and angelcode scripts.

**[http://www.angelcode.com/angelscript/](http://www.angelcode.com/angelscript/)**

_The current version of angelscript seems to have some issues when building on OSX/32Bits._  
_All xcode samples are setup to use 64Bits architecture instead._

  
```c++
void HelloWorld()
{
    // create a script that represents a function named "who"
    string scriptString = "string who(){\
                                return \"Angelscript\";\
                            }";
    
    // create and compile the script                  
    as::ScriptRef script = as::Script::create( scriptString, "" );

    // call the function and cast what the function returns to
    // a string. The full function signature needs to be specified
    console() << "Hello " << script->call<string>( "string who()" ) << endl;
}
```

**From Angelcode website:**

The AngelCode Scripting Library, or AngelScript as it is also known, is an extremely flexible cross-platform scripting library designed to allow applications to extend their functionality through external scripts. It has been designed from the beginning to be an easy to use component, both for the application programmer and the script writer.

Efforts have been made to let it call standard C functions and C++ methods with little to no need for proxy functions. The application simply registers the functions, objects, and methods that the scripts should be able to work with and nothing more has to be done with your code. The same functions used by the application internally can also be used by the scripting engine, which eliminates the need to duplicate functionality.

For the script writer the scripting language follows the widely known syntax of C/C++, but without the need to worry about pointers and memory leaks. Contrary to most scripting languages, AngelScript uses the common C/C++ datatypes for more efficient communication with the host application.


**Samples:**   
***Basic:***   
[Hello World from file](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)   
[Hello World from string](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)   
[Hello World with print function](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)   
   
[Settings primitives](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)   
[Settings static types](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)   
   
[Get Variable Value](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)   
[Set Variable Value](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)   
   
***Registrating interface:***   

[Get Variable Address](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)
[Set Variable Address](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)

[Register POD Object](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)
[Register global functions](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)
[Register methods as global](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)

***Others:***
[Prototyping Cinder](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)
[Prototyping Processing](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)

[Settings dynamic](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)
[Immediate Mode UI](https://github.com/simongeilfus/Cinder-Angelscript/blob/master/samples/Get%20Variable%20Address/src/GetVariableAddressApp.cpp)
