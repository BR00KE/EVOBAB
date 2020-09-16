#!/bin/bash
echo "Starting objective_based experiments"
echo "------------------------------------"
for i in {0..9} 
do
	echo "Running experiment set $i"
	for x in {1..10}
	do
		echo "Running experiment $i:($x/10)."
		./robogen-server 800$i &>/dev/null &
		./robogen-evolver $RANDOM results/baseline/Experiment$i/objective_output$i ../projectSimulations/objective_based/evolConf$i.txt --save-all 
		echo "Experiment $i:($x/10) finished."
	done
	echo "Experiment set $i finished..."
done
for i in {10..11} 
do
	echo "Running experiment set $i"
	for x in {1..10}
	do
		echo "Running experiment $i:($x/10)."
		./robogen-server 80$i &>/dev/null &
		./robogen-evolver $RANDOM results/baseline/Experiment$i/objective_output$i ../projectSimulations/objective_based/evolConf$i.txt --save-all 
		echo "Experiment $i:($x/10) finished."
	done
	echo "Experiment set $i finished..."
done
echo "Successfully completed all experiments"