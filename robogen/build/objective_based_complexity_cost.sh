#!/bin/bash
echo "Starting objective_based experiments"
echo "------------------------------------"
num=0
for i in {0..9} 
do
	echo "Running experiment set $i"
	num=$(($i + 12))
	for x in {1..10}
	do
		echo "Running experiment $i:($x/10)."
		./robogen-server 80$num &>/dev/null &
		./robogen-evolver $RANDOM objectiveResults/complexityCost/Experiment$i/objective_output$i ../projectSimulations/objective_based_cost/evolConf$i.txt --save-all --complexity-cost
		echo "Experiment $i:($x/10) finished."
	done
	echo "Experiment set $i finished..."
done
for i in {10..11} 
do
	echo "Running experiment set $i"
	for x in {1..10}
	do
		num=$(($i + 12))
		echo "Running experiment $i:($x/10)."
		./robogen-server 80$num &>/dev/null &
		./robogen-evolver $RANDOM objectiveResults/complexityCost/Experiment$i/objective_output$i ../projectSimulations/objective_based_cost/evolConf$i.txt --save-all --complexity-cost
		echo "Experiment $i:($x/10) finished."
	done
	echo "Experiment set $i finished..."
done
echo "Successfully completed all experiments"