# User Guide
This document contains the steps required to establish the unit testing for the gymBuddi where modifiable sections will be highlighted. The following guide is designed for installation and operation through Ubuntu operating systems.  

The unit tests require the installation of CMake, Make, and GoogleTest. The Ubuntu installation command for CMake is as shown below. 

```
sudo apt-get install cmake
```

Similarly, the installation command for Make is as shown below. 

```
sudo apt-get install make
```

GoogleTest is available as a git repository which was cloned to provide the testing framework. This GoogleTest repository contains it's own CMakeLists.txt file which makes integration within any project extremely simple. This repository should be cloned into the lib folder therefore, it should be selected before performing the git clone command. 

```
cd lib
git clone https://github.com/google/googletest/
```

With all of the required packages installed, the unit tests can be compiled. The layout of the unitTesting folder was implemented for organisational purposes. The initial step is to select the build directory as this is where the compiled CMake files will be stored. This avoids the potential for file cluttering. 

```
cd build
```

CMake can now be initialised using the command listed below. This command locates all of the outputted compiler files, and the Makefile, into the build folder. 

```
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
```

Once CMake has successfully compiled, Make can then be initialised. 

```
make all
```

For the gymBuddi project, there are seven unit tests which are compiled using the single executable file within the tst folder. This can be located using the $find command below. 

```
$ find . -executable -type f
```

This file should yield the following output. 

```
./tst/gymBuddi_tst
./../src/gymBuddi_run
```

Assuming everything compiled as intended, the unit testing code should run using the following command. 

```
./src/gymBuddi_run
```

The process should then be repeated for the test files which can be assessed using the command listed below. 

```
./tst/ExampleProject_tst 
```

The output of this run command should provide an indication on whether the unit tests passed or not.



## Unit Test Modification

The CMakeLists.txt file within the unitTesting & tst folders have been constructed so that the unit testing process can be performed irrespective of the test files. However, the CMakeLists.txt file located within the src folder may need to be reviewed if modifications are present.  

