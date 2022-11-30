# C++ to Python Transpiler
_Credits: [Vincenzo Ancona](https://github.com/vancona95) and [Danilo Danese](https://github.com/Danesed)_

This project is an implementation of a transpiler (source-to-source compiler) from a restriction of C++ to Python for the Formal Languages and Compilers course (prof. Floriano Scioscia, Politecnico di Bari).


## Requirements

In order to run this project, the following packages are needed:
```
flex~=2.6.4
bison~=3.8.2
gcc~=11.3.0
```

## Before Running 

After downloading this repository, unzip the file.

The `a.out` file, necessary to run the transpiler, is already present in the unzipped folder.

In case you want to compile it again, execute the following commands in order to move to the project directory and regenerate the file:


```
cd FLC_Transpiler
bison parser.y -d && flex scanner.l && gcc lex.yy.c parser.tab.c -lm -lfl 2>/dev/null
```



## Execution

In the `test` folder of this repository, you will find several subfolders.

Each subfolder refers to a different kind of instruction to test (e.g. if, functions, classes etc.) and contains some `.cpp` files for testing the functioning of the transpiler: 

- the ones in the subfolder `/VALID` will generate a fully-correct translation of the input code in the output `python_transpiled.py` file;
- the ones in the subfolder `/WRONG` will result in the print of lexical/syntax/semantic errors in the standard output and the `python_transpiled.py` output file will not be generated.

In order to test each input file, we included a `transpiler.sh` file which simply redirects the `.cpp` input file to the `a.out` file in the main folder.

To launch the `transpiler.sh` file, just execute the following command on the terminal from the same folder of the file:

```
sh transpiler.sh
```
