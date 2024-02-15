# cs203_lab5_headers
Header files for computer organization lab 5, unable to post full code as lab is still being given.

from lab assignment:

"For this lab, you will be creating a stored memory computer with two different memory regions (a stack and code
regions) and a CPU. The registers do not need to be stored as strings, instead you can use unsigned short
variables, but you will need to manipulate these variables with bit-wise operators only. You cannot use C-level
addition, subtraction, or negation. The memory of your machine will be an array of data structures representing
individual memory locations, with each location being the metaphorical size of one word (but in actuality, each
location will store all the information about that location in a structure)."

This lab focused on expanding virtual environment from lab 4 with a more complex assembly language. It involved creating a "stack" as an array of memory contents structs, which were built to store all relevant information about an item in memory, such as the command and arguments if the memory held an instruction.
