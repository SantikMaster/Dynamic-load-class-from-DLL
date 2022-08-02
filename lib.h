#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

extern "C" MATHLIBRARY_API int AddNumbers(  int a, int b);


class IKlass {
public:
    virtual void destroy() = 0;
    virtual int do_stuff(int param) = 0;
    virtual void do_something_else(double f) = 0;
};

extern "C" MATHLIBRARY_API IKlass * create_klass();
