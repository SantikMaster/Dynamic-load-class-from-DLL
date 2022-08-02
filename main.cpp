// Dll_included.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "lib.h"
#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

// A factory of IKlass-implementing objects looks thus
typedef IKlass* (__cdecl* iklass_factory)();


int main()
{
    // Load the DLL
    HINSTANCE dll_handle = ::LoadLibrary(TEXT("C:\\Projects\\libTester\\x64\\Release\\DLL1_2.dll"));
    if (!dll_handle) {
        cerr << "Unable to load DLL!\n";
        return 1;
    }

    // Get the function from the DLL
    iklass_factory factory_func = reinterpret_cast<iklass_factory>(
        ::GetProcAddress(dll_handle, "create_klass"));
    if (!factory_func) {
        cerr << "Unable to load create_klass from DLL!\n";
        ::FreeLibrary(dll_handle);
        return 1;
    }

    // Ask the factory for a new object implementing the IKlass
    // interface
    IKlass* instance = factory_func();

    // Play with the object
    int t = instance->do_stuff(5);
    cout << "t = " << t << endl;
    instance->do_something_else(100.3);
    int t2 = instance->do_stuff(0);
    cout << "t2 = " << t2 << endl;

    // Destroy it explicitly
    instance->destroy();
    ::FreeLibrary(dll_handle);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
