#!/bin/bash
echo "Starting novelty_search complexity cost experiments"
echo "------------------------------------"
echo "finishing experiment set 4"
for x in {4..10}
do
	echo "Running experiment 4:($x/10)."
	./robogen-server 8004 &>/dev/null &
	./robogen-evolver $RANDOM noveltyResults/complexityCost/Experiment4/novelty_output4 ../projectSimulations/novelty_search/evolConf4.txt --save-all --complexity-cost
	echo "Experiment 4:($x/10) finished."
done
echo "Experiment set 4 finished..."
for i in {5..9} 
do
	echo "Running experiment set $i"
	for x in {1..10}
	do
		echo "Running experiment $i:($x/10)."
		./robogen-server 800$i &>/dev/null &
		./robogen-evolver $RANDOM noveltyResults/complexityCost/Experiment$i/novelty_output$i ../projectSimulations/novelty_search/evolConf$i.txt --save-all --complexity-cost
		echo "Experiment $i:($x/10) finished."
	done
	echo "Experiment set $i finished..."
done
echo "Successfully completed all experiments"