#include <iostream>
#include <future>

// include the future header file for thr async

// NAME - ASYNCHRONOUS EXECUTION

/*
2 TASKS

CALCULATE FACTORIAL OF 5
CALCULATE SQUARE OF A NUMBER GIVEN BY THE USER


THREAD--WE PASS THE ARGUMENTS THROUGH PARAMETER
SO UPTO THAT THREAD CANNOT BE INITIATED UNTIL THE USER GIVES THE INPUT

*/

int square(std::future<int> &ft)
{
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Hello from square.I have started my work\n"
              << std::endl;
    int number = ft.get();
    return number * number;
}

int factorial(int number)
{
    

    if (number < 0)
    {
        throw std::runtime_error("Negative number error\n");
    }

    else if (number == 0 || number == 1)
    {
        return 1;
    }
    else
    {
        return number * factorial(number - 1);
    }
}

int main()
{
    // STEP 1 :MAKES A PROMISE
    std::promise<int> pr;

    // STEP 2:A FUTURE LINKED TO THE PROMISE
    std::future<int> ft = pr.get_future();

    /*

    * OS::LAUNCH THREAD(IF POSSIBLE AS A NEW)
    *
    */
    std::future<int> result_ft = std::async(std::launch::async, &square, std::ref(ft));

   
    // this input can be taken before the factorial function to take it previous

    

    std::cout <<"The factorial is : "<< factorial(5) << "\n";
     std::cout << "Enter the number" << std::endl;
    int val = 0;
    std::cin >> val;
    pr.set_value(val);

    std::cout << "Square of number is :" << result_ft.get() << "\n";

    // std::cout << factorial(5)<<std::endl;

    // std::cout<<result_ft.get()<<std::endl;

    return 0;
}

// EXPLANATION OF CODE

/*
        1)CLIENT-SERVER ARCHITECTURE

        2)FUTURE-PROMISE MODEL


        SQUARE CALCULATION

        MAIN NEED TO DELEGATE THE TASK OF SQUARE CALCULATION

        --->A NEW THREAD FOR SQUARE WILL BE REGISTERED WITH OS

        -->>NORMAL THREAD DON'T START UNTIL USER PROVIDE PARAMETERS

        -->>IN ASYNC THREAD IT MAKES A PROMISE AND TELLS THAT IT WILL PROVIDE
            IT IN FUTURE -->>THE STEPS ARE AS FOLLOWS


*/

/*thread me call karna return value future mai save karna*/

/*
//main thread--create a promise object
promise is fulfilled in future so in 2nd line ft gets created
we make a request for a new thread

main will say now execute factorial
square will go for slepp for 2 sec
factorial for 3 sec
this are the overlapping delays
from square function  it will print the statement it will demand for the value
factorial will be callled and it will be printed in very less duration
and we will wait for the input




*/