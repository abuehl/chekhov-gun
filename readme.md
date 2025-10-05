I'm referring to the ["Chekhov's gun" example](https://youtu.be/HHgyH3WNTok?t=888) as
presented by Shachar Shemesh in his C++Now 2025 Talk "Undefined Behavior From the
Compiler’s Perspective".

    #include <iostream>

    int evil() {
        std::cout << "All your bit are belongs to us\n";
        return 0;
    }

    static int (*fire)();

    void load_gun() {
        fire = evil;
    }

    int main() {
        fire();
    }

If compiled without optimizer, the program segfaults (because  `fire` is initialized to 0).

With optimizer turned on, the program emits the string. Because the compiler unconditionally
knows that  `fire` is 0. It knows that dereferencing  `nullptr` is UB. So it is free, not use `fire`
and directly print "All your bit are belongs to us\n". The compiler is exploiting this specific UB.

