#!/bin/bash
echo "Starting objective_based experiments"
echo "------------------------------------"
trap "exit" INT TERM ERR
trap "kill 0" EXIT
for i in {0..5} 
do
	echo "Running experiment $i"
	./robogen-server 800$i &>/dev/null &
	./robogen-evolver 1 objective_output$i ../projectSimulations/objective_based/evolConf$i.txt --save-all &>/dev/null &
	echo "Experiment successfully started, running in background..."
done
wait
for i in {6..9} 
do
	echo "Running experiment $i"
	./robogen-server 800$i &>/dev/null &
	./robogen-evolver 1 objective_output$i ../projectSimulations/objective_based/evolConf$i.txt --save-all &>/dev/null &
	echo "Experiment successfully started, running in background..."
done
wait
for i in {10..11} 
do
	echo "Running experiment $i"
	./robogen-server 80$i &>/dev/null &
	./robogen-evolver 1 objective_output$i ../projectSimulations/objective_based/evolConf$i.txt --save-all &>/dev/null &
	echo "Experiment successfully started, running in background..."
done
wait
echo "Successfully completed all experiments"