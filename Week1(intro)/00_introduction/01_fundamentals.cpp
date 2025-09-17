/*
--> program files, ex:- notebook.exe, VLC player, video and audio player, etc.
--> data files, ex:- my.txt, audio, video, documents, etc.
--> all programmm files and data files are stored inside SSD or HDD(permament storage).
--> If we want to run any program file then that program file must be present inside the main memory(RAM) so that the CPU can be executed, So the program file is brought from the hard disk to the main memory(working/primary memory or work space).
--> whatever we give the input, for example from the keyboard it doesn't directly go to the main memory that is it first go to the input buffer(a storage for input data) and then the progarm can read the content from the buffer. Same in case of output also, output buffer and then on the screen. So, here the buffer act like a communication point between a divice and a programm running inside the main memory.
--> How system works on binary number(0 and 1) that is on low voltage and high voltage?
--> Difference between normal calculator and programmable calculator is:- if we want to calculate average of given number then in case of normal calculator we have to do all procedure of finding an average number but in case of programmable calculator we just have to give the numbers only,that is called program. So, in case of programmable calculator their is a set of instruction given(program) to do task as per the given data and requirement.
--> our language is English but CPU can understand only binary number that is 0 and 1. So, how can we talk to machine or give our instructions to machines. So, what we do now? we need an intermediate language(called programming languages) like C,C++,java,python,etc and whatever our procedures or instructions are, we convert it into programming language and this programming language will be converted into machine language(binary) with the help of compiler or interpreter. [natural language -> programming language -> machine language]
--> The work of compiler and interpreter is:- first is to check our programm(source code) is error free or not, if it is error free then only itwill convert it into machine code language(executable file ex:- file.exe).
--> The tools required for writing, compiling & running C++ programs:
    1. Source code editor - For writing the program in an efficient way. Ex:- VS Code
    2. Compiler - For compiling and running the program. Ex:- In VS Code we us MinGW compiler
--> compiler:-
    1. Compilers do compiling(Compiling is the transformation from source code(human readable) into manchine code(computer executable)).
    2. Compilation or translation of source code to machine code is done only once.(it can be done twice if updation is needed)
    3. Compiler generates a separate executable file and then execution is done.
    4. Whenever we want to run our programm we don't need compiler, we need that exe file.
    5. In case of an error present in our source code then our program will not get compiled.
--> Interpreter:-
    1. There is no transformaiton of source code into machine code, here directly execution is done.
    2. In case of javaScript, chrome works as a interpreter, it will translate one statement at a time into machine code and then execute it.
    3. It will not create a exe file for javaScript.
    4. Here intepreter is executed, it means interpreter translates as well as executes.
    5. Interpreter is needed everytime whenever execution is required because here like compiler exe file is not generated.
--> Difference between compiler and interpreter:
    1. Interpreter translates one statement at a time into machine code but compiler scans the entire program and translate whole of it into machine code.
    2. Interpreter is needed everytime for the execution of source code(Ex:- Pythone language) but in case of compiler, once compiled it is not needed(Ex:- C/C++).
    3. In case of interpreter, partial execution if error on next instruction but in case of compiler, no execution if an error on any instructions.
    4. compiled programm are faster than interpreted program.
    5. interpreter languages are easier than compiler languages.
*/


