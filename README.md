# UCT Honours Project Investigating the Impact of a Complexity Cost on the Complexity of Robots Evolved for Locomotion Under Novelty Search and Objective Search

This project makes use of and extends the open source [Robogen](https://github.com/lis-epfl/robogen) platform for the simulated co-evolution of robot bodies and brains.  
The folder 'robogen' contains all the code used to run the experiments for this project and should be run on Linux.  
The folder 'robogen-windows' is included as the precompiled executable robogen-file-viewer (for viewing evolved robots in their simulation environments) was not available for linux.  

## Installation and Compilation

Robogen has numerous dependencies and tools that need to be installed. Instructions for doing so can be found at http://robogen.org/docs/robogen-with-source/.  

To compile on linux (using CMake):  
```
cd to the robogen/build directory
cmake -DCMAKE_BUILD_TYPE=Release -G"Unix Makefiles" ../src/
make -j3
```
## Usage Instructions
Navigate to the robogen/build directory.  
First you need to run the server:  
`./robogen-server portNumber`  
Secondly, start the evolution on the same port as the server:  
`./robogen-evolver <randomSeed, INT> <outputDirectory,String> <evolutionConfigurationFile, String> [--save-all] [--complexity-cost] ` 
The optional --save-all tag will save each individual of the population for each generation to the outputDirectory.  
The --complexity-cost tag was used to run evolutions with a simulation time penalty based on the complexity of the individual being evaluated.  

All of the evolution configuration files used for this project can be found in robogen/projectSimulations/  
The evolution configurations for novelty search are found in robogen/projectSimulations/novelty_search/  
The novelty search experiments were conducted by running two scripts found in robogen/build: `./novelty_search.sh` and `./novelty_search_complexity_cost.sh`  
Likewise, the evolution configurations for objective-based search are found in robogen/projectSimulations/objective_search/  
The objective search experiments were conducted by running two scripts found in robogen/build: `./objective_based.sh` and `objective_based_complexity_cost.sh`  

To use robogen-file-viewer on windows:
Navigate to the robogen-windows/run directory
`./robogen-file-viewer <robot.json or .txt file> <scenarioConfiguration .txt file>`

## Example Usage
Example for running an evolution using objective-based search and the first simulation environment. (the --complexity-cost argument could optionally be added)  
```
./robogen-server 8000  
./robogen-evolver 1 results/ ../projectSimulations/objective_based/evolConf0.txt --save-all  
```
  
To test run both objective search and novelty search with and without an imposed cost on complexity for populations of 10 for 5 generations:  
simply run `./testRun.sh` in robogen/build  
The output of these runs can be found in testRunResults/  
  
Example usage of robogen-file-viewer on Windows:  
`./robogen-file-viewer ../examples/simpleRobot.txt ../projectSimulations/objective_based/sim_configs/conf0.txt`  

## Learning algorithm class structure overview
