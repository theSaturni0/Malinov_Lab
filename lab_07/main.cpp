/*
    //-----------

        // 1

        int a = 5; 
        int b = 10;

        int& a_ref1 = a;
        a_ref1 = 7;
        // a = 7
        a_ref1 = b;
        // a = 10

    //-----------

        // 2

        const int& a_ref2 = a;
        // a_ref2 = 2; - expression must be a modifiable lvalue

        
        void swap(int& a, int& b) {
            int temp = a;
            a = b;
            b = temp;
        }

        void read(const int& a, int& b) {
            b = a + 10;
        }
        
    //-----------

        // 3

        void increment1(int a1) {
            a1++;
            // a = a + 1
        }

        // a = a


        void increment2(int& a2) {
            a2++;
            // a = a + 1
        }

        // a = a + 1


        void increment3(int* a3) {
            *a3++;
            // *a = a + 1
        }

        // a = a + 1

    //-----------

        //6

        int& getLocalVariable() {
            int localVar = 42;  // Локальная переменная
            cout << "Адрес localVar: " << &localVar << endl;
            return localVar;
        }

        int& ref = getLocalVariable() // - UNDEFINED BEHAVIOUR

    //-----------

        //7 and 8

        int sum(int a, int b) {
            return a + b;
        }

        int difference(int a, int b) {
            return a - b;
        }

        int product(int a, int b) {
            return a * b;
        }

        //---

        int (*operation)(int, int) = sum
        int result = operation(5, 3)
        result == 8

        operation = &difference
        int result = operation(5, 3)
        result == 2

        operation = product
        int result = operation(5, 3)
        result == 15

    //-----------

        //10 and 11

        auto product = [](int a, int b) { 
            return a * b; 
        };

        int c = product(2, 3)

        auto product = [](int a, int b) -> int { 
            return a * b; 
        };

        function<int(int, int)> product = [](int a, int b) { 
            return a * b; 
        };

        auto captureByValue = [=]() {
        
        }

        auto captureByReference = [&]() {
        
        }

        auto mixedCapture = [a, &b]() {

        }
    
    //-----------

        //14

        void callback1 {
        
        }

        void func(void (*callback)()) {
            ...
            callback();
            ...
        }

        ///


        void func(callback1) {
            ...
            callback1;
            ...
        }

        





